# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'WindowHelp.ui'
#
# Created: Wed Oct 03 14:04:11 2018
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
from PyQt4.QtCore import QUrl
import os

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_DialogHelp(object):
    def setupUi(self, DialogHelp):
        DialogHelp.setObjectName(_fromUtf8("DialogHelp"))
        DialogHelp.resize(757, 454)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8("iconPower.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        DialogHelp.setWindowIcon(icon)
        self.webView = QtWebKit.QWebView(DialogHelp)
        self.webView.setGeometry(QtCore.QRect(0, 0, 757, 561))
        self.webView.setAutoFillBackground(True)
        self.webView.setUrl(QtCore.QUrl(_fromUtf8("about:blank")))
        self.webView.setObjectName(_fromUtf8("webView"))

        self.retranslateUi(DialogHelp)
        QtCore.QMetaObject.connectSlotsByName(DialogHelp)

    def retranslateUi(self, DialogHelp):
        DialogHelp.setWindowTitle(_translate("DialogHelp", "Ajuda sobre Helena", None))
        self.webView.load( QUrl.fromLocalFile( os.path.join(os.path.dirname(__file__), 'help.html') ) )

from PyQt4 import QtWebKit
