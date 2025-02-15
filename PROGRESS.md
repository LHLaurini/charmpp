<!-- GENERATED FILE - DO NOT EDIT -->

# Implementation progress

<table>
	<thead>
		<tr><th align="center" colspan=8>Legend</th></tr>
	</thead>
	<tbody>
		<tr>
			<td align="center">:heavy_check_mark:</td><td>Implemented</td>
			<td align="center">:warning:</td><td>Implemented (with caveats)</td>
			<td align="center">:exclamation:</td><td>Partially implemented</td>
			<td align="center">:x:</td><td>Not implemented</td>
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
        <tr>
            <td>Bubble Tea</td>
            <td align="center">30</td>
            <td align="center">0</td>
            <td align="center">80</td>
            <td align="center">37.5%</td>
        </tr>
        <tr>
            <td>Bubbles/cursor</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">14</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/filepicker</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">13</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/help</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">8</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/key</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">15</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/list</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">79</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/paginator</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">16</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/progress</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">24</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/runeutil</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">5</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/spinner</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">11</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/stopwatch</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">16</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/table</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">42</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/textarea</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">32</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/textarea/memoization</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">11</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/textinput</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">22</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/timer</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">15</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Bubbles/viewport</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">26</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Harmonica</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">12</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Lip Gloss</td>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">216</td>
            <td align="center">0%</td>
        </tr>
    </tbody>
    <tfoot>
        <tr>
            <th>Total</td>
            <th>30</td>
            <th>0</td>
            <th>657</td>
            <th>4.6%</td>
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
	<tr><td rowspan=81>Bubble Tea</td></tr>
		<tr><td>func</td><td colspan=2>LogToFile</td><td align="center">:warning:</td><td><code>go::File</code> cannot be used from C++</td></tr>
		<tr><td>func</td><td colspan=2>LogToFileWith</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>BatchMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>BlurMsg</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Cmd</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Batch</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Every</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Exec</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ExecProcess</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Printf</td><td align="center">:heavy_check_mark:</td><td>Implemented as <code>Print</code>, uses <code>std::format_string</code> instead of <code>printf</code>-style format strings</td></tr>
		<tr><td>func</td><td colspan=2>Println</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Sequence</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>SetWindowTitle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Tick</td><td align="center">:heavy_check_mark:</td><td>Callback receives no arguments. Use <code>std::chrono</code> to get the time</td></tr>
		<tr><td>func</td><td colspan=2>WindowSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ExecCallback</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ExecCommand</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>FocusMsg</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Key</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td>(Key)</td><td>String</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMsg</td><td align="center">:heavy_check_mark:</td><td><code>KeyMsg</code> is an alias for <code>Key</code></td></tr>
		<tr><td>func</td><td>(KeyMsg)</td><td>String</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyType</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td>(KeyType)</td><td>String</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>LogOptionsSetter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>MouseAction</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>MouseButton</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>MouseEvent</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td>(MouseEvent)</td><td>IsWheel</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td>(MouseEvent)</td><td>String</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>MouseMsg</td><td align="center">:heavy_check_mark:</td><td><code>MouseMsg</code> is an alias for <code>MouseEvent</code></td></tr>
		<tr><td>func</td><td>(MouseMsg)</td><td>String</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Msg</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ClearScreen</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DisableBracketedPaste</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DisableMouse</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DisableReportFocus</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>EnableBracketedPaste</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>EnableMouseAllMotion</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>EnableMouseCellMotion</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>EnableReportFocus</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>EnterAltScreen</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ExitAltScreen</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>HideCursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Quit</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ShowCursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Suspend</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Program</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewProgram</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Kill</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Printf</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Println</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Quit</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>ReleaseTerminal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>RestoreTerminal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Run</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Send</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Program)</td><td>Wait</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ProgramOption</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithAltScreen</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithContext</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithEnvironment</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithFPS</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithInput</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithInputTTY</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithMouseAllMotion</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithMouseCellMotion</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithOutput</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithReportFocus</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithoutBracketedPaste</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithoutCatchPanics</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithoutRenderer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithoutSignalHandler</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithoutSignals</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>QuitMsg</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ResumeMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>SuspendMsg</td><td align="center">:heavy_check_mark:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>WindowSizeMsg</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=15>Bubbles/<br>cursor</td></tr>
		<tr><td>func</td><td colspan=2>Blink</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>BlinkMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Mode</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Mode)</td><td>String</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>BlinkCmd</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Blur</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Focus</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Mode</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetChar</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetMode</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=14>Bubbles/<br>filepicker</td></tr>
		<tr><td>func</td><td colspan=2>IsHidden</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultKeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>DidSelectDisabledFile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>DidSelectFile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Init</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Styles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultStyles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultStylesWithRenderer</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=9>Bubbles/<br>help</td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>FullHelpView</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ShortHelpView</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Styles</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=16>Bubbles/<br>key</td></tr>
		<tr><td>func</td><td colspan=2>Matches</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Binding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewBinding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Binding)</td><td>Enabled</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Binding)</td><td>Help</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Binding)</td><td>Keys</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Binding)</td><td>SetEnabled</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Binding)</td><td>SetHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Binding)</td><td>SetKeys</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Binding)</td><td>Unbind</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>BindingOpt</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithDisabled</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithKeys</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Help</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=80>Bubbles/<br>list</td></tr>
		<tr><td>type</td><td colspan=2>DefaultDelegate</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewDefaultDelegate</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(DefaultDelegate)</td><td>FullHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(DefaultDelegate)</td><td>Height</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(DefaultDelegate)</td><td>Render</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*DefaultDelegate)</td><td>SetHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*DefaultDelegate)</td><td>SetSpacing</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(DefaultDelegate)</td><td>ShortHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(DefaultDelegate)</td><td>Spacing</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(DefaultDelegate)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>DefaultItem</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>DefaultItemStyles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewDefaultItemStyles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>FilterFunc</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>FilterMatchesMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>FilterState</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(FilterState)</td><td>String</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Item</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ItemDelegate</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultKeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Cursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>DisableQuitKeybindings</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>FilterState</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>FilterValue</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>FilteringEnabled</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>FullHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Height</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Index</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>InsertItem</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>IsFiltered</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Items</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>MatchesForItem</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>NewStatusMessage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>NextPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>PrevPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>RemoveItem</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>ResetFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>ResetSelected</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Select</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>SelectedItem</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetDelegate</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetFilteringEnabled</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetItem</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetItems</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetShowFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetShowHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetShowPagination</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetShowStatusBar</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetShowTitle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetSpinner</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetStatusBarItemName</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>SettingFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ShortHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ShowFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ShowHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>ShowPagination</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ShowStatusBar</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ShowTitle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>StartSpinner</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>StatusBarItemName</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>StopSpinner</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>ToggleSpinner</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>VisibleItems</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Width</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Rank</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>UnsortedFilter</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Styles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultStyles</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=17>Bubbles/<br>paginator</td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>GetSliceBounds</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ItemsOnPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>NextPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>OnFirstPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>OnLastPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>PrevPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetTotalPages</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Option</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithPerPage</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithTotalPages</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Type</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=25>Bubbles/<br>progress</td></tr>
		<tr><td>type</td><td colspan=2>FrameMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>DecrPercent</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>IncrPercent</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Init</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>IsAnimating</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Percent</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetPercent</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetSpringOptions</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ViewAs</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Option</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithColorProfile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithDefaultGradient</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithDefaultScaledGradient</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithFillCharacters</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithGradient</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithScaledGradient</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithSolidFill</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithSpringOptions</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithoutPercentage</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=6>Bubbles/<br>runeutil</td></tr>
		<tr><td>type</td><td colspan=2>Option</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ReplaceNewlines</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ReplaceTabs</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Sanitizer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewSanitizer</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=12>Bubbles/<br>spinner</td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ID</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Tick</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Option</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithSpinner</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithStyle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Spinner</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>TickMsg</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=17>Bubbles/<br>stopwatch</td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewWithInterval</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Elapsed</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ID</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Init</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Reset</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Running</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Start</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Stop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Toggle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ResetMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>StartStopMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>TickMsg</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=43>Bubbles/<br>table</td></tr>
		<tr><td>type</td><td colspan=2>Column</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultKeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(KeyMap)</td><td>FullHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(KeyMap)</td><td>ShortHelp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Blur</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Columns</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Cursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Focus</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Focused</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>FromValues</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>GotoBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>GotoTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Height</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>HelpView</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>MoveDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>MoveUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Rows</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>SelectedRow</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetColumns</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetCursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetRows</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetStyles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>UpdateViewport</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Width</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Option</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithColumns</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithFocused</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithKeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithRows</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithStyles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Row</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Styles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultStyles</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=33>Bubbles/<br>textarea</td></tr>
		<tr><td>func</td><td colspan=2>Blink</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultStyles</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Paste</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>LineInfo</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Blur</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorEnd</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorStart</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Focus</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Focused</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Height</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>InsertRune</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>InsertString</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Length</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Line</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>LineCount</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>LineInfo</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Reset</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetCursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetPromptFunc</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetValue</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Value</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Width</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Style</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=12>Bubbles/<br>textarea/<br>memoization</td></tr>
		<tr><td>type</td><td colspan=2>HInt</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(HInt)</td><td>Hash</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>HString</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(HString)</td><td>Hash</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Hasher</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>MemoCache</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewMemoCache</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*MemoCache)</td><td>Capacity</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*MemoCache)</td><td>Get</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*MemoCache)</td><td>Set</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*MemoCache)</td><td>Size</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=23>Bubbles/<br>textinput</td></tr>
		<tr><td>func</td><td colspan=2>Blink</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Paste</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>EchoMode</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>AvailableSuggestions</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Blur</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CurrentSuggestion</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorEnd</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>CursorStart</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Focus</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Focused</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Position</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Reset</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetCursor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetSuggestions</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetValue</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Value</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ValidateFunc</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=16>Bubbles/<br>timer</td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewWithInterval</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ID</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Init</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Running</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Start</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Stop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Timedout</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>Toggle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>StartStopMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>TickMsg</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>TimeoutMsg</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=27>Bubbles/<br>viewport</td></tr>
		<tr><td>func</td><td colspan=2>Sync</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ViewDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ViewUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>KeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultKeyMap</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Model</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>New</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>AtBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>AtTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>GotoBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>GotoTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>HalfViewDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>HalfViewUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Init</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>LineDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>LineUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>PastBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>ScrollPercent</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetContent</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>SetYOffset</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>TotalLineCount</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>View</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>ViewDown</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Model)</td><td>ViewUp</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Model)</td><td>VisibleLineCount</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=13>Harmonica</td></tr>
		<tr><td>func</td><td colspan=2>FPS</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Point</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Projectile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewProjectile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Projectile)</td><td>Acceleration</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Projectile)</td><td>Position</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Projectile)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Projectile)</td><td>Velocity</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Spring</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewSpring</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Spring)</td><td>Update</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Vector</td><td align="center">:x:</td><td></td></tr>
	<tr><td rowspan=217>Lip Gloss</td></tr>
		<tr><td>func</td><td colspan=2>ColorProfile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>HasDarkBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Height</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>JoinHorizontal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>JoinVertical</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Place</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>PlaceHorizontal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>PlaceVertical</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>SetColorProfile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>SetDefaultRenderer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>SetHasDarkBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Size</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>StyleRunes</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>Width</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>ANSIColor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>AdaptiveColor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Border</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>BlockBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DoubleBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>HiddenBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>InnerHalfBlockBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NormalBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>OuterHalfBlockBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>RoundedBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>ThickBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Border)</td><td>GetBottomSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Border)</td><td>GetLeftSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Border)</td><td>GetRightSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Border)</td><td>GetTopSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Color</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>CompleteAdaptiveColor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>CompleteColor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>NoColor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Position</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Renderer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>DefaultRenderer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewRenderer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>ColorProfile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>HasDarkBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>NewStyle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>Output</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>Place</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>PlaceHorizontal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>PlaceVertical</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>SetColorProfile</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>SetHasDarkBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(*Renderer)</td><td>SetOutput</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>Style</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>NewStyle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Align</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>AlignHorizontal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>AlignVertical</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Background</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Blink</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Bold</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Border</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderBottomBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderBottomForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderLeftBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderLeftForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderRightBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderRightForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderStyle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderTopBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>BorderTopForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Faint</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Foreground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetAlign</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetAlignHorizontal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetAlignVertical</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBlink</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBold</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorder</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderBottomBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderBottomForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderBottomSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderLeftBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderLeftForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderLeftSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderRightBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderRightForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderRightSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderStyle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderTopBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderTopForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetBorderTopSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetColorWhitespace</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetFaint</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetFrameSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetHorizontalBorderSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetHorizontalFrameSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetHorizontalMargins</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetHorizontalPadding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetInline</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetItalic</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMargin</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMarginBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMarginLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMarginRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMarginTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMaxHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetMaxWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetPadding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetPaddingBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetPaddingLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetPaddingRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetPaddingTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetReverse</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetStrikethrough</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetStrikethroughSpaces</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetTabWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetTransform</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetUnderline</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetUnderlineSpaces</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetVerticalBorderSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetVerticalFrameSize</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetVerticalMargins</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetVerticalPadding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>GetWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Height</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Inherit</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Inline</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Italic</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Margin</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MarginBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MarginBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MarginLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MarginRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MarginTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MaxHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>MaxWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Padding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>PaddingBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>PaddingLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>PaddingRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>PaddingTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Render</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Renderer</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Reverse</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>SetString</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Strikethrough</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>StrikethroughSpaces</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>String</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>TabWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Transform</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Underline</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnderlineSpaces</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetAlign</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetAlignHorizontal</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetAlignVertical</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBlink</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBold</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderBottomBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderBottomForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderLeftBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderLeftForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderRightBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderRightForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderStyle</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderTopBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetBorderTopForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetColorWhitespace</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetFaint</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetForeground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetInline</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetItalic</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMarginBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMarginBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMarginLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMarginRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMarginTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMargins</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMaxHeight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetMaxWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetPadding</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetPaddingBottom</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetPaddingLeft</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetPaddingRight</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetPaddingTop</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetReverse</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetStrikethrough</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetStrikethroughSpaces</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetString</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetTabWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetTransform</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetUnderline</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetUnderlineSpaces</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>UnsetWidth</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Value</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td>(Style)</td><td>Width</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>TerminalColor</td><td align="center">:x:</td><td></td></tr>
		<tr><td>type</td><td colspan=2>WhitespaceOption</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithWhitespaceBackground</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithWhitespaceChars</td><td align="center">:x:</td><td></td></tr>
		<tr><td>func</td><td colspan=2>WithWhitespaceForeground</td><td align="center">:x:</td><td></td></tr>
	</tbody>
</table>
