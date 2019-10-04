@ECHO OFF
REM # https://ss64.com/nt/
REM # https://stackoverflow.com/questions/659647/how-to-get-folder-path-from-file-path-with-cmd
ECHO %~d0\A_DEVELOPMENT\Python 2.7.6.1\App
ECHO %~d0\A_DEVELOPMENT\Python 2.7.6.1\App\Scripts
ECHO
ECHO
REM # https://stackoverflow.com/questions/6832496/command-prompt-how-to-add-a-set-path-only-for-that-batch-file-executing
REM # https://www.windows-commandline.com/set-path-command-line/ #
SETX PATH "%~d0\A_DEVELOPMENT\Python 2.7.6.1\App;%~d0\A_DEVELOPMENT\Python 2.7.6.1\App\Scripts;%PATH%
ECHO %PATH%
ECHO  
ECHO 
SETLOCAL
SET PATH=%~d0\A_DEVELOPMENT\Python 2.7.6.1\App;%~d0\A_DEVELOPMENT\Python 2.7.6.1\App\Scripts;%PATH%
python.exe main.py
ECHO
ECHO
ENDLOCAL