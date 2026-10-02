//! \cond
/// REGION START Main Page
//! \endcond
/***************************************************************************//*!
* \mainpage Introduction
* 
* \tableofcontents
* 
* \section ind_purpose Purpose
* This document is meant for users of Arxtron's Allen Bradley PLC Tester.
* 
* It is intended to demonstrate how it can be used and configured, 
* 	where to find specific features, and what indicators/outputs mean.
*******************************************************************************/
//! \cond
/// REGION END

/// REGION START Modes
//! \endcond
/***************************************************************************//*!
* \page modes Operational Modes
* \addindex Operational Modes
* \addindex Manual Mode
* \addindex Auto Mode
* \addindex Production Mode
* \addindex Multi-state Indicators
* \addindex Light Tower
* 
* This station has two main operational modes.
* 
* **1. Manual Mode**
* All instruments and actuators are controlled through manual button presses on the
*   \ref gui_manual "Manual Operation" page.  Only \ref gui_main_user "Administrator" users
*   have access to this page.
* 
* **2. Auto (Production) Mode**
* Can only be entered when the station is \ref gui_main_home "homed" and all \ref faults "faults" cleared.
*   This mode allows the station to act automatically based on sensor and upstream/downstream
*   inputs.
* 
* The \ref gui_main "Main Interface" features some buttons with multi-state indicators.
*   They are shown as grey buttons with an outer indicator boarder.  The below table
*   goes over the general meaning behind these indicators.
* 
* The light towers on the station also reflect the indicator for the **Auto** button.
* 
* <table>
* <caption id="modes_ind_tbl">Indicator Meaning</caption>
* <tr><th>Color<th>Meaning
* <tr><td>Grey<td>Inactive
* <tr><td>Blue<td>Ready/Interlocks met
* <tr><td>Green<td>Active/OK
* <tr><td>Yellow<td>In progress
* <tr><td>Red<td>Fault/Not OK
* </table>
* 
*******************************************************************************/
//! \cond
/// REGION END

/// REGION START User Interface
//! \endcond
/***************************************************************************//*!
* \page gui User Interface
* 
*************************************
* \section gui_main Main Interface
*************************************
* \addindex User Interface
* 
* \anchor gui_main_top
* \image html gui_main_manual-2.png "Main User Interface"
* \image latex gui_main_manual-2.png "Main User Interface"
* 
* <ol>
* <li>\ref gui_main_nav "Navigation Buttons"
* <li>\ref gui_main_home "Station Homing"
* <li>\ref gui_main_autoo "Mode and Cycle Controls"
* <li>\ref gui_main_result "Test Results"
* <li>\ref gui_main_modes "Modes and Bypasses"
* <li>\ref gui_main_conv "Index Conveyor and Robot Interlock"
* </ol>
* 
* The image shows all elements.  The Robot Interlock button is only shown when an
*   \ref gui_main_user "Administrator" is logged in.
* 
*************************************
* \subsection gui_main_nav 1. Navigation Buttons
*************************************
* \addindex Navigation Buttons
* These buttons are used to navigate between the different screens.
* 
* <ol>
* <li>\ref gui_main "Main Interface"
* <li>\ref gui_IO_safety "Safety IO"
* <li>\ref gui_IO_i "Regular IO"
* <li>\ref gui_manual "Manual Operation"
* <li>\ref gui_seqinfo "Sequence Info"
* <li>\ref gui_alarms "Alarms"
* <li>\ref gui_config "Station Config"
* </ol>
* 
* \ref gui_main_top "To Top"
* 
*************************************
* \subsection gui_main_home 2. Station Homing
*************************************
* \addindex Station Homing
* \addindex RFID Fixture Check
* 
* The station needs to be in the homed state prior to entering Auto Mode.  The homing sequence
*   is started by pressing the **Home** button while in Manual Mode.  The homing is considered
*   complete when all indicators are green.  The homing sequence has a hard time out of 2 minutes.
* 
* **RFID Fixture Check**
* Once both nest cylinders are in the home position, each nest fixture is at its RFID head.
*   The homing sequence then scans the fixture RFID tag of Nest 1 followed by Nest 2 and compares
*   each to the expected fixture value for the current module type (Short or Long) received from
*   the previous station.
* - If the tag matches, homing continues to the next step.
* - If the tag does not match, homing stops and a \ref faults "RFID mismatch fault" is raised for
*   that nest.  Install the correct fixture, or write the correct value to the tag through the
*   \ref gui_manual_rfid "RFID Scanner" controls, then reset the fault and re-run homing.
* 
* The RFID fixture check only runs as part of the homing sequence.  The fixture check is cleared,
*   and the station must be homed again before entering Auto Mode, when:
* - The E-Stop is pressed
* - The module type received from the previous station changes
* 
* When changing over to a different module type, make sure the new module type has been received
*   from the previous station before pressing **Home**.
* 
* <table>
* <caption id="gui_main_home_tbl">GUI Elements</caption>
* <tr><th>Element<th>Purpose
* <tr><td>Home (Temporary Button)<td>Starts the homing sequence.  Shows **Homing** with a yellow border
*   while the homing sequence is running, and **Home** with a green border once the station is homed
* <tr><td>Robot Rdy (Indicator)<td>The ib_Ready signal is set to high from the robot
* <tr><td>Robot Inpos (Indicator)<td>The robot is in the rest (barcode) position
* <tr><td>Reject NOK (Indicator)<td>The reject bin is not present
* <tr><td>Nest1 Home (Indicator)<td>The cylinder for nest 1 is in the home position
* <tr><td>Nest2 Home (Indicator)<td>The cylinder for nest 2 is in the home position
* <tr><td>CTS1 NOK (Indicator)<td>Leak tester 1 previous results not cleared
* <tr><td>CTS2 NOK (Indicator)<td>Leak tester 2 previous results not cleared
* <tr><td>No Cleat (Indicator)<td>Conveyor cleat is not in position
* <tr><td>Conv Homed (Indicator)<td>Conveyor has \ref gui_config "at least N empty spots"
* <tr><td>RFID 1 Match (Indicator)<td>The nest 1 fixture RFID tag matches the expected value
* <tr><td>RFID 2 Match (Indicator)<td>The nest 2 fixture RFID tag matches the expected value
* </table>
* 
* \ref gui_main_top "To Top"
* 
*************************************
* \subsection gui_main_autoo 3. Mode and Cycle Controls
*************************************
* 
* <table>
* <caption id="gui_main_auto_tbl">GUI Elements</caption>
* <tr><th>Element<th>Purpose
* <tr><td>Manual (Temporary Button)<td>Changes the PLC to Manual Mode
* <tr><td>Auto (Temporary Button)<td>Changes the PLC to Auto Mode
* <tr><td>Cycle Start (Temporary Button)<td>Starts the production sequence.  Can only be started
*   when Auto Mode is active
* <tr><td>Cycle Stop (Temporary Button)<td><ul>
*   <li>Stops the production sequence
*   <li>Held (3s) force stops the production sequence
*   <li>Cycle Stop is automatically triggered when a \ref faults "fault" occurs during sequence run
*   <li>Cycle Stop is unset when Cycle Start is pressed
*   <li>The production sequence will attempt to start at step 1000 when resumed
*   </ul>
* <tr><td>Cycle Pause (Temporary Button)<td><ul>
*   <li>Pauses the production sequence
*   <li>Cycle Pause is unset when Cycle Start is pressed
*   <li>The production sequence will attempt to start at the paused step when resumed
*   </ul>
* <tr><td>Warning Active (Banner)<td>Shown when a \ref faults "warning" is active
* </table>
* 
* \ref gui_main_top "To Top"
* 
*************************************
* \subsection gui_main_result 4. Test Results
*************************************
* Displays the last scanned barcode for each nest as well as the % Volume (%VR) and Leak Rate (LR) test results.
* 
* \ref gui_main_top "To Top"
* 
*************************************
* \subsection gui_main_modes 5. Modes and Bypasses
*************************************
* \addindex Modes and Bypasses
* 
* All buttons found here other than Next Step are toggle buttons.
*   All bypasses should be toggled on prior to pressing Cycle Start.
* 
* <table>
* <caption id="gui_main_modes_tbl">Modes and Bypasses</caption>
* <tr><th>Button<th>Purpose
* <tr><td>Step Mode/Next Step<td>Puts the production sequence in Cycle Pause and allows for manual sequence stepping
* <tr><td>Dry Cycle<td>Production sequence will operate as if parts are present
* <tr><td>3510 Bypass<td>Bypasses faults caused by 3 5 10 rules
* <tr><td>Barcode Bypass<td>Bypasses barcode scanning in production sequence
* <tr><td>MES Bypass<td>Bypasses all MES related checks
* <tr><td>Nest1/2 Bypass<td>Bypasses selected nest during production sequence
* <tr><td>RFID Bypass<td>Bypasses the RFID fixture check during homing
* </table>
* 
* \ref gui_main_top "To Top"
* 
*************************************
* \subsection gui_main_conv 6. Index Conveyor and Robot Interlock
*************************************
* \addindex Index Conveyor
* \addindex Robot Interlock
* 
* **Index Conveyor**: Indexes the conveyor 1 full position.  Only displayed in Auto Mode, for all users.
*   See \ref gui_main_auto_conv "Index Conveyor (Auto)".
* 
* **Robot Interlock**: Allows the robot to be run manually.  Only displayed when an
*   \ref gui_main_user "Administrator" is logged in, in both Manual and Auto Mode.
* 
* \ref gui_main_top "To Top"
* 
*************************************
* \section gui_main_auto Main Interface (Auto Mode)
*************************************
* \addindex User Interface (Auto Mode)
* 
* \image html gui_main_auto-2.png "Main User Interface (Auto Mode)"
* \image latex gui_main_auto-2.png "Main User Interface (Auto Mode)"
* 
* <ol>
* <li>\ref gui_main_auto_conv "Index Conveyor (Auto)"
* </ol>
* 
* The Auto button is shown green while the station is running in Auto Mode.  Homing controls are
*   hidden in Auto Mode.
* 
*************************************
* \subsection gui_main_auto_conv 1. Index Conveyor (Auto)
*************************************
* \addindex Conveyor Index Button (Auto)
* 
* Allows operators to index the conveyor manually while in Auto Mode.  Available to all users.
* 
*************************************
* \section gui_IO IO Pages
*************************************
* All IO pages follow a similar layout of LEDs and labels
* 
* \image html gui_IO.png "IO Indicators"
* \image latex gui_IO.png "IO Indicators"
* 
*************************************
* \subsection gui_IO_safety Safety IO
*************************************
* \addindex Safety IO
* 
* The Safety IO page only displays the status of all safety inputs and outputs.
* 
*************************************
* \subsection gui_IO_i Regular Inputs
*************************************
* \addindex Regular Inputs (Signal)
* 
* The Regular Input pages display the status of all input signals as well as its global trigger count.
*   These counts are reset when pressing the LED.  These counts are only used for debug purposes and
*   are not and should not be used in logic.
* 
*************************************
* \subsection gui_IO_o Regular Outputs
*************************************
* \addindex Regular Outputs (Signal)
* 
* The Regular Output page displays the status of all output signals.  The LEDs act as toggle buttons,
*   but do not override PLC logic.  As such, most signals cannot be toggled from this screen.
* 
*************************************
* \section gui_seqinfo Sequence Info
*************************************
* \addindex Sequence Info
* 
* \image html gui_seqinfo.png "Sequence Info"
* \image latex gui_seqinfo.png "Sequence Info"
* 
* Reset buttons are only visible when an \ref gui_main_user "Administrator" is logged in.
* 
* \anchor gui_seqinfo_top
* <ol>
* <li>\ref gui_seqinfo_count "Counters"
* <li>\ref gui_seqinfo_hist "History"
* <li>\ref gui_seqinfo_mem "History Reset"
* </ol>
* 
*************************************
* \subsection gui_seqinfo_count 1. Counters
*************************************
* \addindex Counters
* 
* <table>
* <caption id="gui_seqinfo_count_tbl">Counters</caption>
* <tr><th>Counter<th>Purpose<th>Reset
* <tr><td>Row<td>Number of failed units in a row<td>Non-consecutive fail
* <tr><td>Hour<td>Number of failed units per hour<td>New hour
* <tr><td>Shift<td>Number of failed units per shift<td>Shift change
* <tr><td>Fault<td>Number of faults triggered, concurrent faults may only count once<td>Shift change
* <tr><td>Infeed<td>Number of units picked up from load nest<td>Button
* <tr><td>Outfeed<td>Number of units unloaded to conveyor<td>Button
* </table>
* 
* \ref gui_seqinfo_top "To Top"
* 
*************************************
* \subsection gui_seqinfo_hist 2. History
*************************************
* 
* Sequence lists display the step history.  Test lists display the test history.
*   Navigation buttons found at the bottom will navigate only the active list.
*   Related lists are not synced in terms of positions and need to be individually
*   aligned via navigation buttons.
* 
* All lists are in reverse order, where the latest data populate the top most entry.
*   If an array is not fully populated, the top entries of the list may be empty.
* 
* \ref gui_seqinfo_top "To Top"
* 
*************************************
* \subsection gui_seqinfo_mem 3. History Reset
*************************************
* \addindex History Reset
* 
* Average indicates the average cycle time.  The reset buttons will reset all sequence
*   related data.
* 
* \ref gui_seqinfo_top "To Top"
* 
*************************************
* \section gui_alarms Alarms
*************************************
* 
* View and reset faults and warnings.
* 
*************************************
* \section gui_manual Manual Operation
*************************************
* \addindex Manual Operation
* 
* \image html gui_manual.png "Manual Operation"
* \image latex gui_manual.png "Manual Operation"
*
* All controls shown here are only available in Manual Mode.
* 
* \anchor gui_manual_top
* <ol>
* <li>\ref gui_manual_cyl "Nest Cylinders"
* <li>\ref gui_manual_barcode "Barcode Scanner"
* <li>\ref gui_manual_conv "Conveyor Indexing"
* <li>\ref gui_manual_grip "Robot Gripper"
* <li>\ref gui_manual_ovrr "Robot Override"
* <li>\ref gui_manual_move "Robot Movement"
* <li>\ref gui_manual_mode "Robot Position/Coord Mode"
* <li>\ref gui_manual_cts "Leak Testers"
* <li>\ref gui_manual_rfid "RFID Scanner"
* </ol>
* 
*************************************
* \subsection gui_manual_cyl 1. Nest Cylinders
*************************************
* 
* Manual controls for nest cylinder position.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_barcode 2. Barcode Scanner
*************************************
* 
* Manual trigger for barcode scanner.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_conv 3. Conveyor Indexing
*************************************
* 
* Manual indexing of conveyor.  Button press will index conveyor 1 full position.  Jogging not possible.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_grip 4. Robot Gripper
*************************************
* 
* Manual toggle of robot gripper.  Gripping without a DUT will cause a gripper fault.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_ovrr 5. Robot Override
*************************************
* \addindex Robot Override
* 
* Override default robot parameters based on entered values.  Overrides persist in Auto Mode.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_move 6. Robot Movement
*************************************
* \addindex Robot Positions
* 
* Toggle buttons or Target Position sets robot movement target.  Press Start to execute movement.
*   Moving to Load Nest requires upstream interlock.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_mode 7. Robot Position/Coord Mode
*************************************
* 
* Toggles robot movement between Position mode and Coord mode.  The same button switches between
*   the two modes and is only displayed in Manual Mode.
* - **Position mode:** robot moves to the selected \ref gui_manual_move "target position".
* - **Coord mode:** robot moves using coordinate input.  Robot movement unpredictable and not fully safe.
*   Use with caution.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_cts 8. Leak Testers
*************************************
* 
* Manually set leak tester program number and trigger tests.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsection gui_manual_rfid 9. RFID Scanner
*************************************
* \addindex RFID Scanner
* 
* \anchor gui_manual_rfid_top
* 
* Manual read and write of the fixture RFID tags.  Read Mode is available to all users.
*   Write Mode is only shown when an \ref gui_main_user "Administrator" user is logged in.
* 
* <ol>
* <li>\ref gui_manual_rfid_head "Antenna Selection"
* <li>\ref gui_manual_rfid_cmd "Read Mode / Write Mode"
* <li>\ref gui_manual_rfid_ind "Status Indicators"
* <li>\ref gui_manual_rfid_data "Tag Data"
* <li>\ref gui_manual_rfid_exec "Execute"
* </ol>
* 
*************************************
* \subsubsection gui_manual_rfid_head 9.1 Antenna Selection
*************************************
* 
* Selects which RFID head the command is sent to.
* - **Antenna-1 (IO-1):** Nest 1 RFID head
* - **Antenna-2 (IO-3):** Nest 2 RFID head
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsubsection gui_manual_rfid_cmd 9.2 Read Mode / Write Mode
*************************************
* 
* Selects the command to run on Execute.
* - **Read Mode:** Reads the data stored in the tag
* - **Write Mode:** Writes the entered data to the tag.  Only visible when an Administrator is logged in
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsubsection gui_manual_rfid_ind 9.3 Status Indicators
*************************************
* 
* - **Read Success:** Turns green for 3 seconds after a successful read
* - **Write Success:** Turns green for 3 seconds after a successful write
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsubsection gui_manual_rfid_data 9.4 Tag Data
*************************************
* 
* In Read mode, displays the 24 character value read from the tag after Execute is pressed.
*   In Write mode, pressing the box opens a keyboard to enter the 24 character value to write.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \subsubsection gui_manual_rfid_exec 9.5 Execute
*************************************
* 
* Runs the selected Read Mode / Write Mode command on the selected antenna.
* 
* \ref gui_manual_top "To Top"
* 
*************************************
* \section gui_config Station Config
*************************************
* \addindex Station Config
* \addindex User Authentication
* 
* \anchor gui_config_top
* \image html gui_config-2.png "Station Config"
* \image latex gui_config-2.png "Station Config"
* 
* \image html gui_config-2-after-login.png "Station Config (Administrator)"
* \image latex gui_config-2-after-login.png "Station Config (Administrator)"
* 
* <ol>
* <li>\ref gui_main_user "User Authentication"
* <li>\ref gui_config_param "Station Parameters"
* <li>\ref gui_config_cap "Auto Mode CTS Test"
* </ol>
* 
* System-wide \ref gui_main_modes "modes and bypasses" are also available at the bottom of this page.
* 
*************************************
* \subsection gui_main_user 1. User Authentication
*************************************
* Used for logging into higher level access users.  **Current User** shows the logged in user.
*   Users in the **Administrator** group will see additional controls on various pages.
*   Authenticated users will be logged out after 10 minutes of idle time.
* 
* <table>
* <caption id="gui_main_user_tbl">Users</caption>
* <tr><th>User<th>Password<th>Group
* <tr><td>MAGNA<td>MAGNA<td>Administrators
* <tr><td>Admin<td>Admin<td>Administrators
* <tr><td>DEFAULT<td><td>
* </table>
* 
* \ref gui_config_top "To Top"
* 
*************************************
* \subsection gui_config_param 2. Station Parameters
*************************************
* Only editable when an Administrator is logged in.
* 
* **Cylinder Down Delay**: Time in ms delay between triggering the cylinder down sensor and starting
*   the leak tester tests.
* **Conveyor Home Count**: Number of empty pockets required when homing conveyor.
* **Fail Bin Limit**: Number of DUTs registered to the fail bin before it is prompted for emptying.
* 
* \ref gui_config_top "To Top"
* 
*************************************
* \subsection gui_config_cap 3. Auto Mode CTS Test
*************************************
* Only visible when an Administrator is logged in.
* 
* **CTS**: Program number loaded on the leak testers.
* **DUT Type**: Type of DUT being tested, **Tall** or **Short**.
* 
* The Cap buttons (CapShuffle, CapRobot, CapFail, CapActuators, CapCTS, CapCylinders, CapPass)
*   select capability test modes.
* 
* \ref gui_config_top "To Top"
*******************************************************************************/
//! \cond
/// REGION END

/// REGION START Faults
//! \endcond
/***************************************************************************//*!
* \page faults Faults and Warnings
* \addindex Faults
* \addindex Warnings
* 
* <table>
* <caption id="faults_fault_tbl">Faults</caption>
* <tr><th>Category<th>Cause<th>Recovery
* <tr><td>Utility<td>Lack of power/air/safety<td>Address according to message
* <tr><td>EIP connection<td>Instrument off/disconnected or communication error<td>Check instrument EthernetIP settings
* <tr><td>EStop fault<td>Safety program block fault<td>Manually trigger reset in program
* <tr><td>Instrument operation<td>Various causes<td>Check instrument is functioning correctly and all interlocks are met
* <tr><td>RFID mismatch<td><ul>
*   <li>Cylinder 1 RFID not matching expected value.
*   <li>Cylinder 2 RFID not matching expected value.
*   </ul><td>Install the correct fixture in the affected nest, or write the correct value to the
*   fixture tag through the \ref gui_manual_rfid "RFID Scanner" controls.  Reset the fault and re-run homing
* <tr><td>Sequence<td>Unexpected behavior/state<td>Check step history and resolve based on expected behavior
* </table>
* 
* <table>
* <caption id="faults_warn_tbl">Warnings</caption>
* <tr><th>Category<th>Cause<th>Recovery
* <tr><td>Mode active<td>Special mode or override active<td>Turn off mode and reset faults
* <tr><td>Sequence timeout<td>Sequence does not progress to next step within certain time<td>Check step history and resolve accordingly
* <tr><td>Instrument operation<td>Various causes<td>Check instrument is functioning correctly and all interlocks are met
* <tr><td>Fail bin full<td>Fail bin counter reached<td>Remove and empty fail bin
* </table>
*******************************************************************************/
//! \cond
/// REGION END
//! \endcond