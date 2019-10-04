# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'WindowPreference.ui'
#
# Created: Thu Oct 04 15:12:13 2018
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

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

class Ui_DialogPreference(object):
    def setupUi(self, DialogPreference):
        DialogPreference.setObjectName(_fromUtf8("DialogPreference"))
        DialogPreference.resize(598, 193)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8("iconSetting.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        DialogPreference.setWindowIcon(icon)
        self.label_fileBobbin = QtGui.QLabel(DialogPreference)
        self.label_fileBobbin.setGeometry(QtCore.QRect(20, 10, 181, 16))
        self.label_fileBobbin.setObjectName(_fromUtf8("label_fileBobbin"))
        self.toolButton_fileBobbin = QtGui.QToolButton(DialogPreference)
        self.toolButton_fileBobbin.setGeometry(QtCore.QRect(210, 10, 25, 19))
        self.toolButton_fileBobbin.setObjectName(_fromUtf8("toolButton_fileBobbin"))
        self.lineEdit_fileBobbin = QtGui.QLineEdit(DialogPreference)
        self.lineEdit_fileBobbin.setGeometry(QtCore.QRect(240, 10, 351, 20))
        self.lineEdit_fileBobbin.setObjectName(_fromUtf8("lineEdit_fileBobbin"))
        self.label_fileLamina = QtGui.QLabel(DialogPreference)
        self.label_fileLamina.setGeometry(QtCore.QRect(30, 40, 161, 16))
        self.label_fileLamina.setObjectName(_fromUtf8("label_fileLamina"))
        self.toolButton_fileLamina = QtGui.QToolButton(DialogPreference)
        self.toolButton_fileLamina.setGeometry(QtCore.QRect(210, 40, 25, 19))
        self.toolButton_fileLamina.setObjectName(_fromUtf8("toolButton_fileLamina"))
        self.lineEdit_fileLamina = QtGui.QLineEdit(DialogPreference)
        self.lineEdit_fileLamina.setGeometry(QtCore.QRect(240, 40, 351, 20))
        self.lineEdit_fileLamina.setObjectName(_fromUtf8("lineEdit_fileLamina"))
        self.toolButton_fileWire = QtGui.QToolButton(DialogPreference)
        self.toolButton_fileWire.setGeometry(QtCore.QRect(210, 70, 25, 19))
        self.toolButton_fileWire.setObjectName(_fromUtf8("toolButton_fileWire"))
        self.label_fileWire = QtGui.QLabel(DialogPreference)
        self.label_fileWire.setGeometry(QtCore.QRect(40, 70, 161, 16))
        self.label_fileWire.setObjectName(_fromUtf8("label_fileWire"))
        self.lineEdit_fileWire = QtGui.QLineEdit(DialogPreference)
        self.lineEdit_fileWire.setGeometry(QtCore.QRect(240, 70, 351, 20))
        self.lineEdit_fileWire.setObjectName(_fromUtf8("lineEdit_fileWire"))
        self.fontComboBox_textFields = QtGui.QFontComboBox(DialogPreference)
        self.fontComboBox_textFields.setGeometry(QtCore.QRect(240, 100, 187, 22))
        self.fontComboBox_textFields.setObjectName(_fromUtf8("fontComboBox_textFields"))
        self.label = QtGui.QLabel(DialogPreference)
        self.label.setGeometry(QtCore.QRect(140, 100, 101, 16))
        self.label.setObjectName(_fromUtf8("label"))
        self.buttonBox_preference = QtGui.QDialogButtonBox(DialogPreference)
        self.buttonBox_preference.setGeometry(QtCore.QRect(420, 150, 156, 23))
        self.buttonBox_preference.setStandardButtons(QtGui.QDialogButtonBox.Cancel|QtGui.QDialogButtonBox.Ok)
        self.buttonBox_preference.setObjectName(_fromUtf8("buttonBox_preference"))

        self.retranslateUi(DialogPreference)
        QtCore.QMetaObject.connectSlotsByName(DialogPreference)

    def retranslateUi(self, DialogPreference):
        DialogPreference.setWindowTitle(_translate("DialogPreference", "Helena - Preferencias", None))
        self.label_fileBobbin.setText(_translate("DialogPreference", "Arquivo dos dados dos CARRETEIS:", None))
        self.toolButton_fileBobbin.setText(_translate("DialogPreference", "...", None))
        self.label_fileLamina.setText(_translate("DialogPreference", "Arquivo dos dados das LAMINAS:", None))
        self.toolButton_fileLamina.setText(_translate("DialogPreference", "...", None))
        self.toolButton_fileWire.setText(_translate("DialogPreference", "...", None))
        self.label_fileWire.setText(_translate("DialogPreference", "Arquivo dos dados das FIOS:", None))
        self.label.setText(_translate("DialogPreference", "Fonte dos Campos:", None))

