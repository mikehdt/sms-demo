@echo off

cd compile

:: Time build START
:: Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
::set _time=%time: =0%
::set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
::set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs

:: Build main
echo SDCC building source
sdcc --debug -c -mz80 ../src/main.c -DPAL_MACHINE
echo SDCC building complete

:: Time build -END-
::set _time=%time: =0%
::set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
::set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
::set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
::echo.
::echo Time taken: %_sec:~-2%.%_cs:~-2% secs
::echo.

:: Link
echo SDCC linking source
sdcc -o demo.ihx --debug -mz80 --no-std-crt0 --data-loc 0xC000 -Wl-b_BANK2=0x8000 ../libs/crt0/crt0_sms.rel main.rel bank2.rel ../libs/SMSlib.lib
echo SDCC linking complete

:: Execute
echo Converting to SMS ROM
ihx2sms demo.ihx demo.sms

:: Tidy up
del *.adb > nul
del *.asm > nul
@REM del *.rel > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
del *.sym > nul

:: Move to dist
move demo.* ../dist
