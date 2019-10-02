# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'WindowMain.ui'
#
# Created: Sun Sep 30 00:23:22 2018
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

import sys
from PyQt4.QtGui import QApplication, QDialog

from WindowNew import Ui_QWidgetNew
from WindowWire import Ui_DialogWire
from WindowBobbin import Ui_DialogBobbin
from WindowHelp import Ui_DialogHelp
from WindowAbout import Ui_DialogAbout

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

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(800, 600)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8("iconPower.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        MainWindow.setWindowIcon(icon)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        self.menuEdit = QtGui.QMenu(self.menubar)
        self.menuEdit.setObjectName(_fromUtf8("menuEdit"))
        self.menuMaterials = QtGui.QMenu(self.menubar)
        self.menuMaterials.setObjectName(_fromUtf8("menuMaterials"))
        self.menuHelp = QtGui.QMenu(self.menubar)
        self.menuHelp.setObjectName(_fromUtf8("menuHelp"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.actionWires = QtGui.QAction(MainWindow)
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8("iconWire.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionWires.setIcon(icon1)
        self.actionWires.setObjectName(_fromUtf8("actionWires"))
        self.actionLaminas = QtGui.QAction(MainWindow)
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(_fromUtf8("iconLamina.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionLaminas.setIcon(icon2)
        self.actionLaminas.setObjectName(_fromUtf8("actionLaminas"))
        self.actionBobbins = QtGui.QAction(MainWindow)
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap(_fromUtf8("iconBobbin.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionBobbins.setIcon(icon3)
        self.actionBobbins.setObjectName(_fromUtf8("actionBobbins"))
        self.actionPreference = QtGui.QAction(MainWindow)
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap(_fromUtf8("iconSetting.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionPreference.setIcon(icon4)
        self.actionPreference.setObjectName(_fromUtf8("actionPreference"))
        self.actionOpen_project = QtGui.QAction(MainWindow)
        icon5 = QtGui.QIcon()
        icon5.addPixmap(QtGui.QPixmap(_fromUtf8("iconDocumentOpen.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionOpen_project.setIcon(icon5)
        self.actionOpen_project.setObjectName(_fromUtf8("actionOpen_project"))
        self.actionClose_project = QtGui.QAction(MainWindow)
        icon6 = QtGui.QIcon()
        icon6.addPixmap(QtGui.QPixmap(_fromUtf8("iconClose.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionClose_project.setIcon(icon6)
        self.actionClose_project.setObjectName(_fromUtf8("actionClose_project"))
        self.actionExit = QtGui.QAction(MainWindow)
        icon7 = QtGui.QIcon()
        icon7.addPixmap(QtGui.QPixmap(_fromUtf8("iconExit.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionExit.setIcon(icon7)
        self.actionExit.setObjectName(_fromUtf8("actionExit"))
        self.actionNew = QtGui.QAction(MainWindow)
        icon8 = QtGui.QIcon()
        icon8.addPixmap(QtGui.QPixmap(_fromUtf8("iconNew.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionNew.setIcon(icon8)
        self.actionNew.setObjectName(_fromUtf8("actionNew"))
        self.actionSalvar = QtGui.QAction(MainWindow)
        icon9 = QtGui.QIcon()
        icon9.addPixmap(QtGui.QPixmap(_fromUtf8("iconSave.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionSalvar.setIcon(icon9)
        self.actionSalvar.setObjectName(_fromUtf8("actionSalvar"))
        self.actionShowHelp = QtGui.QAction(MainWindow)
        icon10 = QtGui.QIcon()
        icon10.addPixmap(QtGui.QPixmap(_fromUtf8("iconHelp.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionShowHelp.setIcon(icon10)
        self.actionShowHelp.setObjectName(_fromUtf8("actionShowHelp"))
        self.actionAboutHelenaPower = QtGui.QAction(MainWindow)
        icon11 = QtGui.QIcon()
        icon11.addPixmap(QtGui.QPixmap(_fromUtf8("iconAbout.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionAboutHelenaPower.setIcon(icon11)
        self.actionAboutHelenaPower.setObjectName(_fromUtf8("actionAboutHelenaPower"))
        self.menuFile.addAction(self.actionNew)
        self.menuFile.addAction(self.actionOpen_project)
        self.menuFile.addAction(self.actionSalvar)
        self.menuFile.addAction(self.actionClose_project)
        self.menuFile.addAction(self.actionExit)
        self.menuEdit.addAction(self.actionPreference)
        self.menuMaterials.addAction(self.actionWires)
        self.menuMaterials.addAction(self.actionLaminas)
        self.menuMaterials.addAction(self.actionBobbins)
        self.menuHelp.addAction(self.actionShowHelp)
        self.menuHelp.addAction(self.actionAboutHelenaPower)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuEdit.menuAction())
        self.menubar.addAction(self.menuMaterials.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())
		
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "Helena Power", None))
        self.menuFile.setTitle(_translate("MainWindow", "Arquivo", None))
        self.menuEdit.setTitle(_translate("MainWindow", "Editar", None))
        self.menuMaterials.setTitle(_translate("MainWindow", "Materiais", None))
        self.menuHelp.setTitle(_translate("MainWindow", "Ajuda", None))
        self.actionWires.setText(_translate("MainWindow", "Fios", None))
        self.actionLaminas.setText(_translate("MainWindow", "Laminas", None))
        self.actionBobbins.setText(_translate("MainWindow", "Carreteis", None))
        self.actionPreference.setText(_translate("MainWindow", "Preferencias", None))
        self.actionOpen_project.setText(_translate("MainWindow", "Abrir projeto", None))
        self.actionClose_project.setText(_translate("MainWindow", "Fechar projeto", None))
        self.actionExit.setText(_translate("MainWindow", "Sair", None))
        self.actionNew.setText(_translate("MainWindow", "Novo Projeto", None))
        self.actionSalvar.setText(_translate("MainWindow", "Salvar Projeto", None))
        self.actionShowHelp.setText(_translate("MainWindow", "Exibir Ajuda", None))
        self.actionAboutHelenaPower.setText(_translate("MainWindow", "Sobre o Helena Power", None))
        
        self.actionNew.triggered.connect(self.showNew)
        self.actionExit.triggered.connect(QtGui.qApp.quit)
        
        self.actionWires.triggered.connect(self.showWire)
        self.actionBobbins.triggered.connect(self.showBobbin)
        
        self.actionShowHelp.triggered.connect(self.showHelp)
        self.actionAboutHelenaPower.triggered.connect(self.showAbout)
        
    def showNew(self):
        window = QDialog()
        ui = Ui_QWidgetNew()
        ui.setupUi(window)
        window.exec_()
    
    def showWire(self):
        window = QDialog()
        ui = Ui_DialogWire()
        ui.setupUi(window)
        window.exec_()
    
    def showBobbin(self):
        window = QDialog()
        ui = Ui_DialogBobbin()
        ui.setupUi(window)
        window.exec_()
    
    def showAbout(self):
        window = QDialog()
        ui = Ui_DialogAbout()
        ui.setupUi(window)
        window.exec_()

    def showHelp(self):
        window = QDialog()
        ui = Ui_DialogHelp()
        ui.setupUi(window)
        window.exec_()