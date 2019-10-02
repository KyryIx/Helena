@ECHO OFF
REM http://pyqt.sourceforge.net/Docs/PyQt4/designer.html
REM "..\..\..\..\@Python 2.7.6.1\App\python.exe" "..\..\..\..\@Python 2.7.6.1\App\Lib\site-packages\PyQt4\uic\pyuic.py" window.ui -o window.py
"..\..\..\..\..\A_DEVELOPMENT\Python 2.7.6.1\App\python.exe" "..\..\..\..\..\A_DEVELOPMENT\Python 2.7.6.1\App\Lib\site-packages\PyQt4\uic\pyuic.py" %1 -o %~n1.py