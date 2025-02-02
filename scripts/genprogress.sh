#!/usr/bin/bash -eu
set -o pipefail

# Note: don't bother improving this script -- it will eventually be deleted.

# Check for the required commands before starting
{
	bc --version		# bc
	cat --version		# Usually coreutils (sometimes busybox)
	envsubst --version	# gettext
	go version			# go
	grep --version		# grep
	sed --version		# sed
} > /dev/null

IMPLEMENTED=:heavy_check_mark:
CAVEATS=:warning:
PARTIAL=:exclamation:
NOT_IMPLEMENTED=:x:

declare -A PACKAGES
PACKAGE_NAMES=()

package()
{
	PACKAGE_NAMES+=("$1")
	PACKAGES[$1]=$2
}

func() { :; }
type() { :; }
implemented() { :; }
caveats() { :; }
partial() { :; }
not_implemented() { :; }
note() { :; }

# shellcheck source=../progress.sh
. ./progress.sh
progress

as_var()
{
	echo "${1//[^[:alpha:]]/_}"
}

make_prefix()
{
	as_var "${current_package}_${current_identifier}"
}

cd src/go

extract_names_and_deprecated_text()
{
	grep -E "^(func|type)|Deprecated" | grep -v //
}

filter_out_deprecated()
{
	sed -e '$!N;/Deprecated/!P;D' |
		# This one is a method of a deprecated type, but it's not marked as deprecated itself.
		# It's not worth handling that case (this is just a random script), so we just remove it.
		grep -v CursorMode
}

remove_generics()
{
	sed -Ee 's/\[[^]]+\]//g'
}

csv_from_non_methods()
{
	sed -Ee "s/^(func|type)\s+(\w+).+$/\1,\2/"
}

csv_from_methods()
{
	sed -Ee "s/^(func)\s+\(\w+\s+([^)]+?)\)\s+(\w+)\(.+$/\1,(\2),\3/"
}

docs()
{
	# go doc -short doesn't show methods, so we have to use go doc -all
	go doc -all "$1"                      |
		extract_names_and_deprecated_text |
		filter_out_deprecated             |
		remove_generics
}

csv_docs()
{
	docs "$1"                |
		csv_from_non_methods |
		csv_from_methods
}

gen_default_export()
{
	sed -Ee "s/.+/export ${package_prefix}_\0_status='$NOT_IMPLEMENTED'/"
}

html_from_methods()
{
	sed -Ee "s|([^,]+),([^,]+),([^,]+)|\t\t<tr><td>\1<\/td><td>\2<\/td><td>\3<\/td><td align=\"center\">\$${package_name}_\2_\3_status<\/td><td>\$${package_name}_\2_\3_note<\/td><\/tr>|"
}

html_from_non_methods()
{
	sed -Ee "s|([^,]+),([^,]+)|\t\t<tr><td>\1<\/td><td colspan=2>\2<\/td><td align=\"center\">\$${package_name}_\2_status<\/td><td>\$${package_name}_\2_note<\/td><\/tr>|"
}

fix_variables()
{
	sed -Ee ':rep; s/(\$\w*)[^<_[:alnum:]](([^<])*)</\1_\2</;t rep'
}

cat << END
<!-- GENERATED FILE - DO NOT EDIT -->

# Implementation progress

<table>
	<thead>
		<tr><th align="center" colspan=8>Legend</th></tr>
	</thead>
	<tbody>
		<tr>
			<td align="center">$IMPLEMENTED</td><td>Implemented</td>
			<td align="center">$CAVEATS</td><td>Implemented (with caveats)</td>
			<td align="center">$PARTIAL</td><td>Partially implemented</td>
			<td align="center">$NOT_IMPLEMENTED</td><td>Not implemented</td>
		</tr>
	</tbody>
</table>

## Summary

<table>
    <thead>
        <tr>
            <th rowspan=2>Package</th>
            <th colspan=3>Features</th>
            <th rowspan=2>Progress</th>
        </tr>
        <tr>
            <th>Implemented</th>
            <th>Partial</th>
            <th>Total</th>
        </tr>
    </thead>
    <tbody>
END

package()
{
	if [ "$1" = "$package_name" ]
	then
		enable_count=1
	else
		enable_count=0
	fi
}

func() { :; }
type() { :; }
implemented() { ((impl += enable_count)) || :; }
caveats() { ((impl += enable_count)) || :; }
partial() { ((part += enable_count)) || :; }
not_implemented() { :; }
note() { :; }

calc_percent()
{
	echo "$(bc -l <<< "scale=1; (1000 * ($1 + $2 / 2) / $3 + 0.5) / 10")%"
}

grand_impl=0
grand_part=0
grand_total=0

for package_name in "${PACKAGE_NAMES[@]}"
do
	package=${PACKAGES[$package_name]}

	impl=0
	part=0
	progress

	total=$(($(docs "$package" | wc -l)))

	((grand_impl+=impl))
	((grand_part+=part))
	((grand_total+=total))

	cat << END
        <tr>
            <td>${package_name}</td>
            <td align="center">$impl</td>
            <td align="center">$part</td>
            <td align="center">$total</td>
            <td align="center">$(calc_percent $impl $part $total)</td>
        </tr>
END

done

cat << END
    </tbody>
    <tfoot>
        <tr>
            <th>Total</td>
            <th>$grand_impl</td>
            <th>$grand_part</td>
            <th>$grand_total</td>
            <th>$(calc_percent $grand_impl $grand_part $grand_total)</td>
        </tr>
    </tfoot>
</table>

## Features

<table>
	<thead>
		<tr>
			<th>Package</th>
			<th colspan=3>Feature</th>
			<th>Supported</th>
			<th>Notes</th>
		</tr>
	</thead>
	<tbody>
END

package()
{
	current_package=$1
}

func()
{
	current_identifier=$*
}

type()
{
	current_identifier=$*
}

implemented()
{
	set_status
}

caveats()
{
	set_status
}

partial()
{
	set_status
}

not_implemented()
{
	set_status
}

set_status()
{
	status_var=${FUNCNAME[1]^^}
	export $(make_prefix)_status="${!status_var}"
}

note()
{
	export $(make_prefix)_note="$*"
}

for package_name in "${PACKAGE_NAMES[@]}"
do
	package=${PACKAGES[$package_name]}
	package_prefix=$(as_var "$package_name")

	cat << END
	<tr><td rowspan=$(($(docs "$package" | wc -l)+1))>${package_name//\///<br>}</td></tr>
END

	eval "$(
		csv_docs "$package"    |
			cut -d, -f 2-      |
			sed -Ee 's/\W/_/g' |
			gen_default_export
	)"

	progress

	csv_docs "$package"       |
		html_from_methods     |
		html_from_non_methods |
		fix_variables         |
		envsubst
done

cat << END
	</tbody>
</table>
END

echo "Make sure to check the output before committing!" >&2
