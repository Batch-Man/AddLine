@echo off
SetLocal Enabledelayedexpansion
cls
Title AddLine Demo File - www.thebateam.org
Cd Files
Echo.
Echo ----Current Data in Demo_File.txt--------
Echo.
Type "Demo_File.txt"
Echo.
Echo -----------------------------------------
:GetData
Set _Line=
Set /p "_Line=Enter Line to Add: "
If not Defined _Line (Goto :GetData)
:GetLoc
Set _Loc=
Set /p "_Loc=Enter the location to add at [Line Number]: "
If not Defined _Loc (Goto :GetLoc)

REM Checking if the entered value is number
Set _Copy_Loc=%_Loc%
For /L %%A in (0,1,9) do (Set "_Copy_Loc=!_Copy_Loc:%%~A=x!")

Set "_Copy_Loc=!_Copy_Loc:x=!"

IF /i "!_Copy_Loc!" NEQ "" (Goto :GetLoc)

AddLine "Demo_File.txt" "%_Loc%" "%_Line%"
Echo.
Echo ----Current Data in Demo_File.txt--------
Echo.
Type "Demo_File.txt"
Echo.
Echo -----------------------------------------
pause >nul