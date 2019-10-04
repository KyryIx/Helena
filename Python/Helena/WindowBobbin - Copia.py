# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'WindowBobbin.ui'
#
# Created: Sun Sep 30 03:22:29 2018
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

class Ui_DialogBobbin(object):
    def setupUi(self, DialogBobbin):
        DialogBobbin.setObjectName(_fromUtf8("DialogBobbin"))
        DialogBobbin.resize(400, 254)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8("iconBobbin.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        DialogBobbin.setWindowIcon(icon)
        self.label_id = QtGui.QLabel(DialogBobbin)
        self.label_id.setGeometry(QtCore.QRect(10, 15, 70, 16))
        self.label_id.setObjectName(_fromUtf8("label_id"))
        self.lineEdit_id = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_id.setGeometry(QtCore.QRect(80, 10, 113, 20))
        self.lineEdit_id.setReadOnly(True)
        self.lineEdit_id.setObjectName(_fromUtf8("lineEdit_id"))
        self.label_code = QtGui.QLabel(DialogBobbin)
        self.label_code.setGeometry(QtCore.QRect(10, 45, 70, 16))
        self.label_code.setObjectName(_fromUtf8("label_code"))
        self.lineEdit_code = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_code.setGeometry(QtCore.QRect(80, 40, 113, 20))
        self.lineEdit_code.setObjectName(_fromUtf8("lineEdit_code"))
        self.label_width = QtGui.QLabel(DialogBobbin)
        self.label_width.setGeometry(QtCore.QRect(10, 75, 70, 16))
        self.label_width.setObjectName(_fromUtf8("label_width"))
        self.label_length = QtGui.QLabel(DialogBobbin)
        self.label_length.setGeometry(QtCore.QRect(10, 105, 70, 16))
        self.label_length.setObjectName(_fromUtf8("label_length"))
        self.label_height = QtGui.QLabel(DialogBobbin)
        self.label_height.setGeometry(QtCore.QRect(10, 135, 70, 16))
        self.label_height.setObjectName(_fromUtf8("label_height"))
        self.label_type = QtGui.QLabel(DialogBobbin)
        self.label_type.setGeometry(QtCore.QRect(10, 165, 80, 16))
        self.label_type.setObjectName(_fromUtf8("label_type"))
        self.label_workTemperature = QtGui.QLabel(DialogBobbin)
        self.label_workTemperature.setGeometry(QtCore.QRect(200, 165, 80, 16))
        self.label_workTemperature.setObjectName(_fromUtf8("label_workTemperature"))
        self.label_provider = QtGui.QLabel(DialogBobbin)
        self.label_provider.setGeometry(QtCore.QRect(10, 195, 61, 16))
        self.label_provider.setObjectName(_fromUtf8("label_provider"))
        self.lineEdit_width = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_width.setGeometry(QtCore.QRect(80, 70, 80, 20))
        self.lineEdit_width.setObjectName(_fromUtf8("lineEdit_width"))
        self.lineEdit_length = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_length.setGeometry(QtCore.QRect(80, 100, 80, 20))
        self.lineEdit_length.setObjectName(_fromUtf8("lineEdit_length"))
        self.lineEdit_height = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_height.setGeometry(QtCore.QRect(80, 130, 80, 20))
        self.lineEdit_height.setObjectName(_fromUtf8("lineEdit_height"))
        self.lineEdit_type = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_type.setGeometry(QtCore.QRect(80, 160, 113, 20))
        self.lineEdit_type.setObjectName(_fromUtf8("lineEdit_type"))
        self.lineEdit_workTemperature = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_workTemperature.setGeometry(QtCore.QRect(280, 160, 80, 20))
        self.lineEdit_workTemperature.setObjectName(_fromUtf8("lineEdit_workTemperature"))
        self.lineEdit_provider = QtGui.QLineEdit(DialogBobbin)
        self.lineEdit_provider.setGeometry(QtCore.QRect(80, 190, 310, 20))
        self.lineEdit_provider.setObjectName(_fromUtf8("lineEdit_provider"))
        self.groupBox_image = QtGui.QGroupBox(DialogBobbin)
        self.groupBox_image.setGeometry(QtCore.QRect(200, 10, 191, 141))
        self.groupBox_image.setObjectName(_fromUtf8("groupBox_image"))
        self.webView_image = QtWebKit.QWebView(self.groupBox_image)
        self.webView_image.setGeometry(QtCore.QRect(10, 20, 171, 111))
        self.webView_image.setUrl(QtCore.QUrl(_fromUtf8("about:blank")))
        self.webView_image.setObjectName(_fromUtf8("webView_image"))
        self.pushButton_before = QtGui.QPushButton(DialogBobbin)
        self.pushButton_before.setGeometry(QtCore.QRect(10, 220, 60, 23))
        self.pushButton_before.setObjectName(_fromUtf8("pushButton_before"))
        self.pushButton_after = QtGui.QPushButton(DialogBobbin)
        self.pushButton_after.setGeometry(QtCore.QRect(75, 220, 60, 23))
        self.pushButton_after.setObjectName(_fromUtf8("pushButton_after"))
        self.pushButton_exit = QtGui.QPushButton(DialogBobbin)
        self.pushButton_exit.setGeometry(QtCore.QRect(310, 220, 82, 23))
        self.pushButton_exit.setObjectName(_fromUtf8("pushButton_exit"))
        self.pushButton_edit = QtGui.QPushButton(DialogBobbin)
        self.pushButton_edit.setGeometry(QtCore.QRect(140, 220, 80, 23))
        self.pushButton_edit.setObjectName(_fromUtf8("pushButton_edit"))
        self.pushButton_insert = QtGui.QPushButton(DialogBobbin)
        self.pushButton_insert.setGeometry(QtCore.QRect(225, 220, 80, 23))
        self.pushButton_insert.setObjectName(_fromUtf8("pushButton_insert"))
        self.label_unit_width = QtGui.QLabel(DialogBobbin)
        self.label_unit_width.setGeometry(QtCore.QRect(163, 75, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_unit_width.setFont(font)
        self.label_unit_width.setObjectName(_fromUtf8("label_unit_width"))
        self.label_unit_length = QtGui.QLabel(DialogBobbin)
        self.label_unit_length.setGeometry(QtCore.QRect(163, 105, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_unit_length.setFont(font)
        self.label_unit_length.setObjectName(_fromUtf8("label_unit_length"))
        self.label_unit_height = QtGui.QLabel(DialogBobbin)
        self.label_unit_height.setGeometry(QtCore.QRect(163, 135, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_unit_height.setFont(font)
        self.label_unit_height.setObjectName(_fromUtf8("label_unit_height"))
        self.label_unit_temperature = QtGui.QLabel(DialogBobbin)
        self.label_unit_temperature.setGeometry(QtCore.QRect(365, 162, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_unit_temperature.setFont(font)
        self.label_unit_temperature.setObjectName(_fromUtf8("label_unit_temperature"))

        self.retranslateUi(DialogBobbin)
        QtCore.QMetaObject.connectSlotsByName(DialogBobbin)

    def retranslateUi(self, DialogBobbin):
        DialogBobbin.setWindowTitle(_translate("DialogBobbin", "Helena Power - Carreteis", None))
        self.label_id.setText(_translate("DialogBobbin", "ID:", None))
        self.label_code.setText(_translate("DialogBobbin", "Codigo:", None))
        self.label_width.setText(_translate("DialogBobbin", "Largura:", None))
        self.label_length.setText(_translate("DialogBobbin", "Comprimento:", None))
        self.label_height.setText(_translate("DialogBobbin", "Altura:", None))
        self.label_type.setText(_translate("DialogBobbin", "Tipo:", None))
        self.label_workTemperature.setText(_translate("DialogBobbin", "Temp. trabalho:", None))
        self.label_provider.setText(_translate("DialogBobbin", "Fornecedor:", None))
        self.groupBox_image.setTitle(_translate("DialogBobbin", "Imagem", None))
        self.pushButton_before.setText(_translate("DialogBobbin", "<<", None))
        self.pushButton_after.setText(_translate("DialogBobbin", ">>", None))
        self.pushButton_exit.setText(_translate("DialogBobbin", "Sair", None))
        self.pushButton_edit.setText(_translate("DialogBobbin", "Editar", None))
        self.pushButton_insert.setText(_translate("DialogBobbin", "Inserir", None))
        self.label_unit_width.setText(_translate("DialogBobbin", "mm", None))
        self.label_unit_length.setText(_translate("DialogBobbin", "mm", None))
        self.label_unit_height.setText(_translate("DialogBobbin", "mm", None))
        self.label_unit_temperature.setText(_translate("DialogBobbin", "ºC", None))

from PyQt4 import QtWebKit
