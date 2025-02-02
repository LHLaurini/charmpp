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
            <td align="center">10</td>
            <td align="center">3</td>
            <td align="center">80</td>
            <td align="center">14.4%</td>
        </tr>
        <tr>
            <td>Bubbles</td>
            <td align="center">?</td>
            <td align="center">?</td>
            <td align="center">?</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Harmonica</td>
            <td align="center">?</td>
            <td align="center">?</td>
            <td align="center">?</td>
            <td align="center">0%</td>
        </tr>
        <tr>
            <td>Lip Gloss</td>
            <td align="center">?</td>
            <td align="center">?</td>
            <td align="center">?</td>
            <td align="center">0%</td>
        </tr>
    </tbody>
    <tfoot>
        <tr>
            <th>Total</td>
            <th>?</td>
            <th>?</td>
            <th>?</td>
            <th>3.6% <span title="If each package contributed equally to the total (which is certainly not the case)">*</span></td>
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
        <tr><td>type</td><td colspan=2>BlurMsg</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>Cmd</td><td align="center">:heavy_check_mark:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Batch</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Every</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Exec</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>ExecProcess</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Printf</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Println</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Sequence</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>SetWindowTitle</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>Tick</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WindowSize</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>ExecCallback</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>ExecCommand</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>FocusMsg</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>Key</td><td align="center">:exclamation:</td><td>Fields cannot be accessed directly</td></tr>
        <tr><td>func</td><td>(Key)</td><td>String</td><td align="center">:heavy_check_mark:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>KeyMsg</td><td align="center">:exclamation:</td><td><code>KeyMsg</code> is an alias for <code>Key</code></td></tr>
        <tr><td>func</td><td>(KeyMsg)</td><td>String</td><td align="center">:heavy_check_mark:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>KeyType</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(KeyType)</td><td>String</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>LogOptionsSetter</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>Model</td><td align="center">:heavy_check_mark:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>MouseAction</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>MouseButton</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>MouseEvent</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(MouseEvent)</td><td>IsWheel</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(MouseEvent)</td><td>String</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>MouseMsg</td><td align="center">:x:</td><td></td></tr>
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
        <tr><td>func</td><td colspan=2>NewProgram</td><td align="center">:exclamation:</td><td><code>opts</code> parameter unimplemented</td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Kill</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Printf</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Println</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Quit</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>ReleaseTerminal</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>RestoreTerminal</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Run</td><td align="center">:heavy_check_mark:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Send</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td>(*Program)</td><td>Wait</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>ProgramOption</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithAltScreen</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithContext</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithEnvironment</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithFPS</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithFilter</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithInput</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithInputTTY</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithMouseAllMotion</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithMouseCellMotion</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithOutput</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithReportFocus</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithoutBracketedPaste</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithoutCatchPanics</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithoutRenderer</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithoutSignalHandler</td><td align="center">:x:</td><td></td></tr>
        <tr><td>func</td><td colspan=2>WithoutSignals</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>QuitMsg</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>ResumeMsg</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>SuspendMsg</td><td align="center">:x:</td><td></td></tr>
        <tr><td>type</td><td colspan=2>WindowSizeMsg</td><td align="center">:x:</td><td></td></tr>
        <tr><td colspan=4>Bubbles</td><td align="center">:x:</td><td></td></tr>
        <tr><td colspan=4>Harmonica</td><td align="center">:x:</td><td></td></tr>
        <tr><td colspan=4>Lip Gloss</td><td align="center">:x:</td><td></td></tr>
    </tbody>
</table>
