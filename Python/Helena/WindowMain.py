# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'WindowMain.ui'
#
# Created: Thu Oct 04 02:35:34 2018
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

import pickle
import sys
from PyQt4.QtGui import QApplication, QDialog, QWidget

from WindowNew import Ui_DialogNew
from WidgetFileOpen import WidgetFileOpen

from WindowPreference import Ui_DialogPreference
from WindowWire import Ui_DialogWire
from WindowBobbin import Ui_DialogBobbin
from WindowHelp import Ui_DialogHelp
from WindowAbout import Ui_DialogAbout

import xml.etree.ElementTree as ET

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
        MainWindow.resize(621, 610)
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
        self.toolBar = QtGui.QToolBar(MainWindow)
        self.toolBar.setAllowedAreas(QtCore.Qt.BottomToolBarArea|QtCore.Qt.TopToolBarArea)
        self.toolBar.setObjectName(_fromUtf8("toolBar"))
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.toolBar)
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
        self.actionOpen = QtGui.QAction(MainWindow)
        icon5 = QtGui.QIcon()
        icon5.addPixmap(QtGui.QPixmap(_fromUtf8("iconDocumentOpen.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionOpen.setIcon(icon5)
        self.actionOpen.setObjectName(_fromUtf8("actionOpen"))
        self.actionClose = QtGui.QAction(MainWindow)
        icon6 = QtGui.QIcon()
        icon6.addPixmap(QtGui.QPixmap(_fromUtf8("iconClose.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionClose.setIcon(icon6)
        self.actionClose.setObjectName(_fromUtf8("actionClose"))
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
        self.actionSave = QtGui.QAction(MainWindow)
        icon9 = QtGui.QIcon()
        icon9.addPixmap(QtGui.QPixmap(_fromUtf8("iconSave.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionSave.setIcon(icon9)
        self.actionSave.setObjectName(_fromUtf8("actionSave"))
        self.actionHelp = QtGui.QAction(MainWindow)
        icon10 = QtGui.QIcon()
        icon10.addPixmap(QtGui.QPixmap(_fromUtf8("iconHelp.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionHelp.setIcon(icon10)
        self.actionHelp.setObjectName(_fromUtf8("actionHelp"))
        self.actionAbout = QtGui.QAction(MainWindow)
        icon11 = QtGui.QIcon()
        icon11.addPixmap(QtGui.QPixmap(_fromUtf8("iconAbout.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.actionAbout.setIcon(icon11)
        self.actionAbout.setObjectName(_fromUtf8("actionAbout"))
        self.menuFile.addAction(self.actionNew)
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionClose)
        self.menuFile.addAction(self.actionExit)
        self.menuEdit.addAction(self.actionPreference)
        self.menuMaterials.addAction(self.actionWires)
        self.menuMaterials.addAction(self.actionLaminas)
        self.menuMaterials.addAction(self.actionBobbins)
        self.menuHelp.addAction(self.actionHelp)
        self.menuHelp.addAction(self.actionAbout)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuEdit.menuAction())
        self.menubar.addAction(self.menuMaterials.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())
        self.toolBar.addAction(self.actionNew)
        self.toolBar.addAction(self.actionOpen)
        self.toolBar.addAction(self.actionSave)
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.actionWires)
        self.toolBar.addAction(self.actionLaminas)
        self.toolBar.addAction(self.actionBobbins)
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.actionHelp)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "Helena", None))
        self.menuFile.setTitle(_translate("MainWindow", "Arquivo", None))
        self.menuEdit.setTitle(_translate("MainWindow", "Editar", None))
        self.menuMaterials.setTitle(_translate("MainWindow", "Materiais", None))
        self.menuHelp.setTitle(_translate("MainWindow", "Ajuda", None))
        self.toolBar.setWindowTitle(_translate("MainWindow", "toolBar", None))
        self.actionWires.setText(_translate("MainWindow", "Fios", None))
        self.actionLaminas.setText(_translate("MainWindow", "Laminas", None))
        self.actionBobbins.setText(_translate("MainWindow", "Carreteis", None))
        self.actionPreference.setText(_translate("MainWindow", "Preferencias", None))
        self.actionOpen.setText(_translate("MainWindow", "Abrir projeto", None))
        self.actionClose.setText(_translate("MainWindow", "Fechar projeto", None))
        self.actionExit.setText(_translate("MainWindow", "Sair", None))
        self.actionNew.setText(_translate("MainWindow", "Novo Projeto", None))
        self.actionSave.setText(_translate("MainWindow", "Salvar Projeto", None))
        self.actionHelp.setText(_translate("MainWindow", "Exibir Ajuda", None))
        self.actionAbout.setText(_translate("MainWindow", "Sobre o Helena", None))
        
        MainWindow.showMaximized()
        
        # events to File Menu #
        self.actionNew.triggered.connect(lambda: self.showNew(MainWindow))
        self.actionOpen.triggered.connect(lambda: self.showOpen(MainWindow))
        self.actionSave.triggered.connect(self.showSave)
        self.actionClose.triggered.connect(lambda: self.showClose(MainWindow))
        self.actionExit.triggered.connect(QtGui.qApp.quit)
        # events to Edit Menu #
        self.actionPreference.triggered.connect(self.showPreference)
        # events to Materials Menu #
        self.actionWires.triggered.connect(self.showWire)
        self.actionBobbins.triggered.connect(self.showBobbin)
        # events to Help Menu #
        self.actionHelp.triggered.connect(self.showHelp)
        self.actionAbout.triggered.connect(self.showAbout)
        
    def showNew(self, MainWindow):
        window = QDialog()
        ui = Ui_DialogNew()
        ui.setupUi(window)
        window.exec_()
        #self.centralwidget = WidgetFileNew(MainWindow).getQWidget()
        #MainWindow.setCentralWidget(self.centralwidget)
        #self.centralwidget.show()
    
    def showOpen(self, MainWindow):
        fileName = QtGui.QFileDialog.getOpenFileName(None,"Abrir Projeto Helena", '', "Helena Projeto (*.hp);;XML files (*.xml);;All Files (*)")
        
        if not fileName:
            return
        
        try:
            #schemaFile = QtCore.QFile(fileName)
            #schemaFile.open(QtCore.QIODevice.ReadOnly)
            #schemaData = schemaFile.readAll()
            ##print schemaData
            project = ET.parse(fileName).getroot()
            date = project.find('data')
            powerIn = project.find('potenciaEntrada').text
            voltageIn = project.find('tensaoEntrada').text
            currentIn = project.find('correnteEntrada').text
            powerOut = project.find('potenciaSaida').text
            voltageOut = project.find('tensaoSaida').text
            currentOut = project.find('correnteSaida').text
            frequency = project.find('frequencia').text
            temperatureReferece = project.find('temperaturaReferencia').text
            magneticFlux = project.find('fluxoMagnetico').text
            currentDensity = project.find('densidadeCorrente').text
            styleTransformer = project.find('padraoTransformador').text
            laminaType = project.find('tipoLamina').text
            projecta = WidgetFileOpen(MainWindow, fileName)
            projecta.setCurrentIn( '34.3' )
            centralwidget = projecta.getQWidget()
            print voltageIn
            self.centralwidgetidget = centralwidget
            #self.centralwidget.lineEdit_powerIn.setText( voltageIn )
            MainWindow.setCentralWidget(self.centralwidget)
            #self.lineEdit_powerIn.setText( voltageIn )
            # buscar os filhos para saber quem estao definidos
            #aa = MainWindow.centralWidget()
            self.centralwidget.show()
        except IOError:
            QtGui.QMessageBox.information(self, "Unable to open file", "There was an error opening \"%s\"" % fileName)
            return
    
    def showSave(self):
        fileName = QtGui.QFileDialog.getSaveFileName(None,"Salvar Projeto Helena", '', "Helena Projeto (*.hp);;XML files (*.xml);;All Files (*)")
        
        if not fileName:
            return
        
        try:
            #out_file = open(str(fileName), 'wb')
            print fileName
        except IOError:
            QtGui.QMessageBox.information(self, "Unable to open file", "There was an error opening \"%s\"" % fileName)
            return
    
    def showClose(self, MainWindow):
        self.centralwidget = QtGui.QWidget()
        MainWindow.setCentralWidget(self.centralwidget)
        self.centralwidget.show()
    
    def showPreference(self):
        window = QDialog()
        ui = Ui_DialogPreference()
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
	
	