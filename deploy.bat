@ECHO OFF
IF EXIST "%HOMEDRIVE%%HOMEPATH%\Documents\Arduino\libraries\Joystick\" rmdir /Q /S "%HOMEDRIVE%%HOMEPATH%\Documents\Arduino\libraries\Joystick\"
xcopy /E /I ArduinoJoystickLibrary\Joystick\*.* "%HOMEDRIVE%%HOMEPATH%\Documents\Arduino\libraries\Joystick"

IF EXIST "%HOMEDRIVE%%HOMEPATH%\Documents\Arduino\libraries\HX711\" rmdir /Q /S "%HOMEDRIVE%%HOMEPATH%\Documents\Arduino\libraries\HX711\"
xcopy /E /I HX711\*.* "%HOMEDRIVE%%HOMEPATH%\Documents\Arduino\libraries\HX711"