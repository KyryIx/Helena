from PyQt4 import QtCore, QtGui
from PyQt4.QtGui import QWidget

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

class WidgetFileOpen(QWidget):
    def __init__(self, window, fileName):
        #QWidget.__init__(self, None)
        self.qWidget = QtGui.QWidget(window)
        self.groupBox_Input = QtGui.QGroupBox(self.qWidget)
        self.groupBox_Input.setGeometry(QtCore.QRect(180, 10, 151, 111))
        self.groupBox_Input.setObjectName(_fromUtf8("groupBox_Input"))
        self.label_voltageIn = QtGui.QLabel(self.groupBox_Input)
        self.label_voltageIn.setGeometry(QtCore.QRect(10, 55, 50, 14))
        self.label_voltageIn.setObjectName(_fromUtf8("label_voltageIn"))
        self.label_powerIn = QtGui.QLabel(self.groupBox_Input)
        self.label_powerIn.setGeometry(QtCore.QRect(10, 25, 50, 14))
        self.label_powerIn.setObjectName(_fromUtf8("label_powerIn"))
        self.label_currentIn = QtGui.QLabel(self.groupBox_Input)
        self.label_currentIn.setGeometry(QtCore.QRect(10, 85, 50, 14))
        self.label_currentIn.setObjectName(_fromUtf8("label_currentIn"))
        self.lineEdit_powerIn = QtGui.QLineEdit(self.groupBox_Input)
        self.lineEdit_powerIn.setGeometry(QtCore.QRect(60, 20, 80, 20))
        self.lineEdit_powerIn.setObjectName(_fromUtf8("lineEdit_powerIn"))
        self.lineEdit_voltageIn = QtGui.QLineEdit(self.groupBox_Input)
        self.lineEdit_voltageIn.setGeometry(QtCore.QRect(60, 50, 80, 20))
        self.lineEdit_voltageIn.setObjectName(_fromUtf8("lineEdit_voltageIn"))
        self.lineEdit_currentIn = QtGui.QLineEdit(self.groupBox_Input)
        self.lineEdit_currentIn.setGeometry(QtCore.QRect(60, 80, 80, 20))
        self.lineEdit_currentIn.setObjectName(_fromUtf8("lineEdit_currentIn"))
        self.groupBox_Output = QtGui.QGroupBox(self.qWidget)
        self.groupBox_Output.setGeometry(QtCore.QRect(10, 10, 151, 111))
        self.groupBox_Output.setObjectName(_fromUtf8("groupBox_Output"))
        self.label_voltageOut = QtGui.QLabel(self.groupBox_Output)
        self.label_voltageOut.setGeometry(QtCore.QRect(10, 55, 50, 14))
        self.label_voltageOut.setObjectName(_fromUtf8("label_voltageOut"))
        self.label_powerOut = QtGui.QLabel(self.groupBox_Output)
        self.label_powerOut.setGeometry(QtCore.QRect(10, 25, 50, 14))
        self.label_powerOut.setObjectName(_fromUtf8("label_powerOut"))
        self.label_currentOut = QtGui.QLabel(self.groupBox_Output)
        self.label_currentOut.setGeometry(QtCore.QRect(10, 85, 50, 14))
        self.label_currentOut.setObjectName(_fromUtf8("label_currentOut"))
        self.lineEdit_powerOut = QtGui.QLineEdit(self.groupBox_Output)
        self.lineEdit_powerOut.setGeometry(QtCore.QRect(60, 20, 80, 20))
        self.lineEdit_powerOut.setObjectName(_fromUtf8("lineEdit_powerOut"))
        self.lineEdit_voltageOut = QtGui.QLineEdit(self.groupBox_Output)
        self.lineEdit_voltageOut.setGeometry(QtCore.QRect(60, 50, 80, 20))
        self.lineEdit_voltageOut.setObjectName(_fromUtf8("lineEdit_voltageOut"))
        self.lineEdit_currentOut = QtGui.QLineEdit(self.groupBox_Output)
        self.lineEdit_currentOut.setGeometry(QtCore.QRect(60, 80, 80, 20))
        self.lineEdit_currentOut.setObjectName(_fromUtf8("lineEdit_currentOut"))
        self.groupBox_general = QtGui.QGroupBox(self.qWidget)
        self.groupBox_general.setGeometry(QtCore.QRect(340, 10, 271, 221))
        self.groupBox_general.setObjectName(_fromUtf8("groupBox_general"))
        self.label_frequency = QtGui.QLabel(self.groupBox_general)
        self.label_frequency.setGeometry(QtCore.QRect(10, 25, 55, 14))
        self.label_frequency.setObjectName(_fromUtf8("label_frequency"))
        self.lineEdit_frequency = QtGui.QLineEdit(self.groupBox_general)
        self.lineEdit_frequency.setGeometry(QtCore.QRect(80, 20, 80, 20))
        self.lineEdit_frequency.setObjectName(_fromUtf8("lineEdit_frequency"))
        self.label_tempReference = QtGui.QLabel(self.groupBox_general)
        self.label_tempReference.setGeometry(QtCore.QRect(10, 55, 90, 14))
        self.label_tempReference.setObjectName(_fromUtf8("label_tempReference"))
        self.lineEdit_tempReference = QtGui.QLineEdit(self.groupBox_general)
        self.lineEdit_tempReference.setGeometry(QtCore.QRect(110, 50, 80, 20))
        self.lineEdit_tempReference.setObjectName(_fromUtf8("lineEdit_tempReference"))
        self.label_flux = QtGui.QLabel(self.groupBox_general)
        self.label_flux.setGeometry(QtCore.QRect(10, 85, 46, 13))
        self.label_flux.setObjectName(_fromUtf8("label_flux"))
        self.lineEdit_flux = QtGui.QLineEdit(self.groupBox_general)
        self.lineEdit_flux.setGeometry(QtCore.QRect(50, 80, 80, 20))
        self.lineEdit_flux.setObjectName(_fromUtf8("lineEdit_flux"))
        self.label_currentDensity = QtGui.QLabel(self.groupBox_general)
        self.label_currentDensity.setGeometry(QtCore.QRect(10, 115, 115, 16))
        self.label_currentDensity.setObjectName(_fromUtf8("label_currentDensity"))
        self.lineEdit_currentDensity = QtGui.QLineEdit(self.groupBox_general)
        self.lineEdit_currentDensity.setGeometry(QtCore.QRect(130, 110, 80, 20))
        self.lineEdit_currentDensity.setObjectName(_fromUtf8("lineEdit_currentDensity"))
        self.label_style = QtGui.QLabel(self.groupBox_general)
        self.label_style.setGeometry(QtCore.QRect(10, 145, 111, 16))
        self.label_style.setObjectName(_fromUtf8("label_style"))
        self.comboBox_style = QtGui.QComboBox(self.groupBox_general)
        self.comboBox_style.setGeometry(QtCore.QRect(120, 140, 141, 22))
        self.comboBox_style.setObjectName(_fromUtf8("comboBox_style"))
        self.comboBox_style.addItem(_fromUtf8(""))
        self.comboBox_style.addItem(_fromUtf8(""))
        self.comboBox_style.addItem(_fromUtf8(""))
        self.comboBox_style.addItem(_fromUtf8(""))
        self.label_lamina = QtGui.QLabel(self.groupBox_general)
        self.label_lamina.setGeometry(QtCore.QRect(10, 180, 81, 14))
        self.label_lamina.setObjectName(_fromUtf8("label_lamina"))
        self.comboBox_lamina = QtGui.QComboBox(self.groupBox_general)
        self.comboBox_lamina.setGeometry(QtCore.QRect(90, 180, 69, 22))
        self.comboBox_lamina.setObjectName(_fromUtf8("comboBox_lamina"))
        self.comboBox_lamina.addItem(_fromUtf8(""))
        self.comboBox_lamina.addItem(_fromUtf8(""))
        self.comboBox_lamina.addItem(_fromUtf8(""))
        self.tabWidget = QtGui.QTabWidget(self.qWidget)
        self.tabWidget.setGeometry(QtCore.QRect(10, 290, 601, 241))
        self.tabWidget.setObjectName(_fromUtf8("tabWidget"))
        self.result_1 = QtGui.QWidget()
        self.result_1.setObjectName(_fromUtf8("result_1"))
        self.groupBox_output_result = QtGui.QGroupBox(self.result_1)
        self.groupBox_output_result.setGeometry(QtCore.QRect(12, 10, 231, 195))
        self.groupBox_output_result.setObjectName(_fromUtf8("groupBox_output_result"))
        self.label_powerOut_result = QtGui.QLabel(self.groupBox_output_result)
        self.label_powerOut_result.setGeometry(QtCore.QRect(10, 20, 120, 16))
        self.label_powerOut_result.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_powerOut_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_powerOut_result.setObjectName(_fromUtf8("label_powerOut_result"))
        self.lineEdit_voltageOut_result = QtGui.QLineEdit(self.groupBox_output_result)
        self.lineEdit_voltageOut_result.setGeometry(QtCore.QRect(135, 45, 80, 20))
        self.lineEdit_voltageOut_result.setObjectName(_fromUtf8("lineEdit_voltageOut_result"))
        self.label_awgWireOut_result = QtGui.QLabel(self.groupBox_output_result)
        self.label_awgWireOut_result.setGeometry(QtCore.QRect(10, 110, 120, 13))
        self.label_awgWireOut_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_awgWireOut_result.setObjectName(_fromUtf8("label_awgWireOut_result"))
        self.lineEdit_awgWireOut_result = QtGui.QLineEdit(self.groupBox_output_result)
        self.lineEdit_awgWireOut_result.setGeometry(QtCore.QRect(135, 105, 80, 20))
        self.lineEdit_awgWireOut_result.setObjectName(_fromUtf8("lineEdit_awgWireOut_result"))
        self.lineEdit_turnOut_result = QtGui.QLineEdit(self.groupBox_output_result)
        self.lineEdit_turnOut_result.setGeometry(QtCore.QRect(135, 135, 80, 20))
        self.lineEdit_turnOut_result.setObjectName(_fromUtf8("lineEdit_turnOut_result"))
        self.label_densityOut_result = QtGui.QLabel(self.groupBox_output_result)
        self.label_densityOut_result.setGeometry(QtCore.QRect(10, 170, 120, 16))
        self.label_densityOut_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_densityOut_result.setObjectName(_fromUtf8("label_densityOut_result"))
        self.lineEdit_currentOut_output = QtGui.QLineEdit(self.groupBox_output_result)
        self.lineEdit_currentOut_output.setGeometry(QtCore.QRect(135, 75, 80, 20))
        self.lineEdit_currentOut_output.setObjectName(_fromUtf8("lineEdit_currentOut_output"))
        self.lineEdit_powerOut_result = QtGui.QLineEdit(self.groupBox_output_result)
        self.lineEdit_powerOut_result.setGeometry(QtCore.QRect(135, 15, 80, 20))
        self.lineEdit_powerOut_result.setObjectName(_fromUtf8("lineEdit_powerOut_result"))
        self.label_currentOut_result = QtGui.QLabel(self.groupBox_output_result)
        self.label_currentOut_result.setGeometry(QtCore.QRect(10, 80, 120, 16))
        self.label_currentOut_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_currentOut_result.setObjectName(_fromUtf8("label_currentOut_result"))
        self.label_voltageOut_result = QtGui.QLabel(self.groupBox_output_result)
        self.label_voltageOut_result.setGeometry(QtCore.QRect(10, 50, 120, 16))
        self.label_voltageOut_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_voltageOut_result.setObjectName(_fromUtf8("label_voltageOut_result"))
        self.label_turnOut_result = QtGui.QLabel(self.groupBox_output_result)
        self.label_turnOut_result.setGeometry(QtCore.QRect(10, 140, 120, 20))
        self.label_turnOut_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_turnOut_result.setObjectName(_fromUtf8("label_turnOut_result"))
        self.lineEdit_densityOut_result = QtGui.QLineEdit(self.groupBox_output_result)
        self.lineEdit_densityOut_result.setGeometry(QtCore.QRect(135, 165, 80, 20))
        self.lineEdit_densityOut_result.setObjectName(_fromUtf8("lineEdit_densityOut_result"))
        self.groupBox_input_result = QtGui.QGroupBox(self.result_1)
        self.groupBox_input_result.setGeometry(QtCore.QRect(350, 10, 231, 195))
        self.groupBox_input_result.setObjectName(_fromUtf8("groupBox_input_result"))
        self.label_powerIn_result = QtGui.QLabel(self.groupBox_input_result)
        self.label_powerIn_result.setGeometry(QtCore.QRect(10, 20, 120, 16))
        self.label_powerIn_result.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_powerIn_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_powerIn_result.setObjectName(_fromUtf8("label_powerIn_result"))
        self.lineEdit_voltageIn_result = QtGui.QLineEdit(self.groupBox_input_result)
        self.lineEdit_voltageIn_result.setGeometry(QtCore.QRect(135, 45, 80, 20))
        self.lineEdit_voltageIn_result.setObjectName(_fromUtf8("lineEdit_voltageIn_result"))
        self.label_awgWireIn_result = QtGui.QLabel(self.groupBox_input_result)
        self.label_awgWireIn_result.setGeometry(QtCore.QRect(10, 110, 120, 13))
        self.label_awgWireIn_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_awgWireIn_result.setObjectName(_fromUtf8("label_awgWireIn_result"))
        self.lineEdit_awgWireIn_result = QtGui.QLineEdit(self.groupBox_input_result)
        self.lineEdit_awgWireIn_result.setGeometry(QtCore.QRect(135, 105, 80, 20))
        self.lineEdit_awgWireIn_result.setObjectName(_fromUtf8("lineEdit_awgWireIn_result"))
        self.lineEdit_turnIn_result = QtGui.QLineEdit(self.groupBox_input_result)
        self.lineEdit_turnIn_result.setGeometry(QtCore.QRect(135, 135, 80, 20))
        self.lineEdit_turnIn_result.setObjectName(_fromUtf8("lineEdit_turnIn_result"))
        self.label_densityIn_result = QtGui.QLabel(self.groupBox_input_result)
        self.label_densityIn_result.setGeometry(QtCore.QRect(10, 170, 120, 16))
        self.label_densityIn_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_densityIn_result.setObjectName(_fromUtf8("label_densityIn_result"))
        self.lineEdit_currentIn_result = QtGui.QLineEdit(self.groupBox_input_result)
        self.lineEdit_currentIn_result.setGeometry(QtCore.QRect(135, 75, 80, 20))
        self.lineEdit_currentIn_result.setObjectName(_fromUtf8("lineEdit_currentIn_result"))
        self.lineEdit_powerIn_result = QtGui.QLineEdit(self.groupBox_input_result)
        self.lineEdit_powerIn_result.setGeometry(QtCore.QRect(135, 15, 80, 20))
        self.lineEdit_powerIn_result.setObjectName(_fromUtf8("lineEdit_powerIn_result"))
        self.label_currentIn_result = QtGui.QLabel(self.groupBox_input_result)
        self.label_currentIn_result.setGeometry(QtCore.QRect(10, 80, 120, 16))
        self.label_currentIn_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_currentIn_result.setObjectName(_fromUtf8("label_currentIn_result"))
        self.label_voltageIn_result = QtGui.QLabel(self.groupBox_input_result)
        self.label_voltageIn_result.setGeometry(QtCore.QRect(10, 50, 120, 16))
        self.label_voltageIn_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_voltageIn_result.setObjectName(_fromUtf8("label_voltageIn_result"))
        self.label_turnIn_result = QtGui.QLabel(self.groupBox_input_result)
        self.label_turnIn_result.setGeometry(QtCore.QRect(10, 140, 120, 20))
        self.label_turnIn_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_turnIn_result.setObjectName(_fromUtf8("label_turnIn_result"))
        self.lineEdit_densityIn_result = QtGui.QLineEdit(self.groupBox_input_result)
        self.lineEdit_densityIn_result.setGeometry(QtCore.QRect(135, 165, 80, 20))
        self.lineEdit_densityIn_result.setObjectName(_fromUtf8("lineEdit_densityIn_result"))
        self.tabWidget.addTab(self.result_1, _fromUtf8(""))
        self.result_2 = QtGui.QWidget()
        self.result_2.setObjectName(_fromUtf8("result_2"))
        self.label_frequency_result = QtGui.QLabel(self.result_2)
        self.label_frequency_result.setGeometry(QtCore.QRect(10, 15, 140, 16))
        self.label_frequency_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_frequency_result.setObjectName(_fromUtf8("label_frequency_result"))
        self.label_induction_result = QtGui.QLabel(self.result_2)
        self.label_induction_result.setGeometry(QtCore.QRect(10, 45, 140, 16))
        self.label_induction_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_induction_result.setObjectName(_fromUtf8("label_induction_result"))
        self.label_density_result = QtGui.QLabel(self.result_2)
        self.label_density_result.setGeometry(QtCore.QRect(10, 75, 140, 16))
        self.label_density_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_density_result.setObjectName(_fromUtf8("label_density_result"))
        self.label_weightIron_result = QtGui.QLabel(self.result_2)
        self.label_weightIron_result.setGeometry(QtCore.QRect(10, 105, 140, 16))
        self.label_weightIron_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_weightIron_result.setObjectName(_fromUtf8("label_weightIron_result"))
        self.label_weightCopper_result = QtGui.QLabel(self.result_2)
        self.label_weightCopper_result.setGeometry(QtCore.QRect(10, 135, 140, 16))
        self.label_weightCopper_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_weightCopper_result.setObjectName(_fromUtf8("label_weightCopper_result"))
        self.label_turnAverageLength_result = QtGui.QLabel(self.result_2)
        self.label_turnAverageLength_result.setGeometry(QtCore.QRect(10, 165, 140, 16))
        self.label_turnAverageLength_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_turnAverageLength_result.setObjectName(_fromUtf8("label_turnAverageLength_result"))
        self.label_coilArea_result = QtGui.QLabel(self.result_2)
        self.label_coilArea_result.setGeometry(QtCore.QRect(10, 195, 140, 16))
        self.label_coilArea_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_coilArea_result.setObjectName(_fromUtf8("label_coilArea_result"))
        self.label_lossIron_result = QtGui.QLabel(self.result_2)
        self.label_lossIron_result.setGeometry(QtCore.QRect(240, 15, 100, 16))
        self.label_lossIron_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_lossIron_result.setObjectName(_fromUtf8("label_lossIron_result"))
        self.label_lossCopper_result = QtGui.QLabel(self.result_2)
        self.label_lossCopper_result.setGeometry(QtCore.QRect(240, 45, 100, 13))
        self.label_lossCopper_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_lossCopper_result.setObjectName(_fromUtf8("label_lossCopper_result"))
        self.label_totalLoss_result = QtGui.QLabel(self.result_2)
        self.label_totalLoss_result.setGeometry(QtCore.QRect(240, 75, 100, 13))
        self.label_totalLoss_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_totalLoss_result.setObjectName(_fromUtf8("label_totalLoss_result"))
        self.label_efficiency_result = QtGui.QLabel(self.result_2)
        self.label_efficiency_result.setGeometry(QtCore.QRect(240, 105, 100, 13))
        self.label_efficiency_result.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_efficiency_result.setObjectName(_fromUtf8("label_efficiency_result"))
        self.lineEdit_frequency_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_frequency_result.setGeometry(QtCore.QRect(155, 10, 80, 20))
        self.lineEdit_frequency_result.setObjectName(_fromUtf8("lineEdit_frequency_result"))
        self.lineEdit_induction_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_induction_result.setGeometry(QtCore.QRect(155, 40, 80, 20))
        self.lineEdit_induction_result.setObjectName(_fromUtf8("lineEdit_induction_result"))
        self.lineEdit_density_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_density_result.setGeometry(QtCore.QRect(155, 70, 80, 20))
        self.lineEdit_density_result.setObjectName(_fromUtf8("lineEdit_density_result"))
        self.lineEdit_weightIron_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_weightIron_result.setGeometry(QtCore.QRect(155, 100, 80, 20))
        self.lineEdit_weightIron_result.setObjectName(_fromUtf8("lineEdit_weightIron_result"))
        self.lineEdit_weightCopper_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_weightCopper_result.setGeometry(QtCore.QRect(155, 130, 80, 20))
        self.lineEdit_weightCopper_result.setObjectName(_fromUtf8("lineEdit_weightCopper_result"))
        self.lineEdit_turnAverageLength_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_turnAverageLength_result.setGeometry(QtCore.QRect(155, 160, 80, 20))
        self.lineEdit_turnAverageLength_result.setObjectName(_fromUtf8("lineEdit_turnAverageLength_result"))
        self.lineEdit_coilArea_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_coilArea_result.setGeometry(QtCore.QRect(155, 190, 80, 20))
        self.lineEdit_coilArea_result.setObjectName(_fromUtf8("lineEdit_coilArea_result"))
        self.lineEdit_lossIron_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_lossIron_result.setGeometry(QtCore.QRect(345, 10, 80, 20))
        self.lineEdit_lossIron_result.setObjectName(_fromUtf8("lineEdit_lossIron_result"))
        self.lineEdit_lossCopper_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_lossCopper_result.setGeometry(QtCore.QRect(345, 40, 80, 20))
        self.lineEdit_lossCopper_result.setObjectName(_fromUtf8("lineEdit_lossCopper_result"))
        self.lineEdit_totalLoss_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_totalLoss_result.setGeometry(QtCore.QRect(345, 70, 80, 20))
        self.lineEdit_totalLoss_result.setObjectName(_fromUtf8("lineEdit_totalLoss_result"))
        self.lineEdit_efficiency_result = QtGui.QLineEdit(self.result_2)
        self.lineEdit_efficiency_result.setGeometry(QtCore.QRect(345, 100, 80, 20))
        self.lineEdit_efficiency_result.setObjectName(_fromUtf8("lineEdit_efficiency_result"))
        self.tabWidget.addTab(self.result_2, _fromUtf8(""))
        self.groupBox = QtGui.QGroupBox(self.qWidget)
        self.groupBox.setGeometry(QtCore.QRect(10, 130, 321, 101))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.checkBox_compensation = QtGui.QCheckBox(self.groupBox)
        self.checkBox_compensation.setGeometry(QtCore.QRect(10, 20, 91, 17))
        self.checkBox_compensation.setObjectName(_fromUtf8("checkBox_compensation"))
        self.lineEdit_compensation = QtGui.QLineEdit(self.groupBox)
        self.lineEdit_compensation.setGeometry(QtCore.QRect(110, 20, 113, 20))
        self.lineEdit_compensation.setObjectName(_fromUtf8("lineEdit_compensation"))
        self.pushButton_calculate = QtGui.QPushButton(self.qWidget)
        self.pushButton_calculate.setGeometry(QtCore.QRect(10, 240, 601, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_calculate.setFont(font)
        self.pushButton_calculate.setObjectName(_fromUtf8("pushButton_calculate"))
        
        self.groupBox_Input.setTitle(_translate("QWidgetNew", "Informacoes de Entrada", None))
        self.label_voltageIn.setText(_translate("QWidgetNew", "Tensao:", None))
        self.label_powerIn.setText(_translate("QWidgetNew", "Potencia:", None))
        self.label_currentIn.setText(_translate("QWidgetNew", "Corrente:", None))
        self.groupBox_Output.setTitle(_translate("QWidgetNew", "Informacoes de Saida", None))
        self.label_voltageOut.setText(_translate("QWidgetNew", "Tensao:", None))
        self.label_powerOut.setText(_translate("QWidgetNew", "Potencia:", None))
        self.label_currentOut.setText(_translate("QWidgetNew", "Corrente:", None))
        self.groupBox_general.setTitle(_translate("QWidgetNew", "Informacoes Gerais", None))
        self.label_frequency.setText(_translate("QWidgetNew", "Frequencia:", None))
        self.lineEdit_frequency.setText(_translate("QWidgetNew", "60.0", None))
        self.label_tempReference.setText(_translate("QWidgetNew", "Temp. referencia:", None))
        self.lineEdit_tempReference.setText(_translate("QWidgetNew", "115.0", None))
        self.label_flux.setText(_translate("QWidgetNew", "Fluxo:", None))
        self.lineEdit_flux.setText(_translate("QWidgetNew", "11300.0", None))
        self.label_currentDensity.setText(_translate("QWidgetNew", "Densidade de Corrente:", None))
        self.lineEdit_currentDensity.setText(_translate("QWidgetNew", "3.0", None))
        self.label_style.setText(_translate("QWidgetNew", "Padrao Enrolamentos:", None))
        self.comboBox_style.setItemText(0, _translate("QWidgetNew", "1 primario / 1 secundario", None))
        self.comboBox_style.setItemText(1, _translate("QWidgetNew", "1 primario / 2 secundario", None))
        self.comboBox_style.setItemText(2, _translate("QWidgetNew", "2 primario / 1 secundario", None))
        self.comboBox_style.setItemText(3, _translate("QWidgetNew", "2 primario / 2 secundario", None))
        self.label_lamina.setText(_translate("QWidgetNew", "Tipo de Lamina:", None))
        self.comboBox_lamina.setItemText(0, _translate("QWidgetNew", "Padrao", None))
        self.comboBox_lamina.setItemText(1, _translate("QWidgetNew", "Comprida", None))
        self.comboBox_lamina.setItemText(2, _translate("QWidgetNew", "Com GAP", None))
        self.groupBox_output_result.setTitle(_translate("QWidgetNew", "Saida", None))
        self.label_powerOut_result.setText(_translate("QWidgetNew", "Potencia de Saida:", None))
        self.label_awgWireOut_result.setText(_translate("QWidgetNew", "Fio AWG de Saida:", None))
        self.label_densityOut_result.setText(_translate("QWidgetNew", "Densidade de Saida:", None))
        self.label_currentOut_result.setText(_translate("QWidgetNew", "Corrente de Saida:", None))
        self.label_voltageOut_result.setText(_translate("QWidgetNew", "Tensao de Saida:", None))
        self.label_turnOut_result.setText(_translate("QWidgetNew", "N. de voltas na Saida:", None))
        self.groupBox_input_result.setTitle(_translate("QWidgetNew", "Entrada", None))
        self.label_powerIn_result.setText(_translate("QWidgetNew", "Potencia de Entrada:", None))
        self.label_awgWireIn_result.setText(_translate("QWidgetNew", "Fio AWG de Entrada:", None))
        self.label_densityIn_result.setText(_translate("QWidgetNew", "Densidade de Entrada:", None))
        self.label_currentIn_result.setText(_translate("QWidgetNew", "Corrente de Entrada:", None))
        self.label_voltageIn_result.setText(_translate("QWidgetNew", "Tensao de Entrada:", None))
        self.label_turnIn_result.setText(_translate("QWidgetNew", "N. de voltas na Entrada:", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.result_1), _translate("QWidgetNew", "Resultados 1/2", None))
        self.label_frequency_result.setText(_translate("QWidgetNew", "Frequencia:", None))
        self.label_induction_result.setText(_translate("QWidgetNew", "Inducao Magnetica:", None))
        self.label_density_result.setText(_translate("QWidgetNew", "Densidade Media:", None))
        self.label_weightIron_result.setText(_translate("QWidgetNew", "Peso do Ferro:", None))
        self.label_weightCopper_result.setText(_translate("QWidgetNew", "Peso do Cobre:", None))
        self.label_turnAverageLength_result.setText(_translate("QWidgetNew", "Comprimento Medio de Volta:", None))
        self.label_coilArea_result.setText(_translate("QWidgetNew", "Area dos enrolamentos:", None))
        self.label_lossIron_result.setText(_translate("QWidgetNew", "Perda no Ferro:", None))
        self.label_lossCopper_result.setText(_translate("QWidgetNew", "Perda no Cobre:", None))
        self.label_totalLoss_result.setText(_translate("QWidgetNew", "Perda Total:", None))
        self.label_efficiency_result.setText(_translate("QWidgetNew", "Eficiencia:", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.result_2), _translate("QWidgetNew", "Resultados 2/2", None))
        self.groupBox.setTitle(_translate("QWidgetNew", "Outras Informacoes", None))
        self.checkBox_compensation.setText(_translate("QWidgetNew", "Compensacao:", None))
        self.lineEdit_compensation.setText(_translate("QWidgetNew", "10.0", None))
        self.pushButton_calculate.setText(_translate("QWidgetNew", "Calcular Transformador", None))
    
    def getQWidget(self):
        return self.qWidget
    
    def setCurrentIn(self, value):
        self.lineEdit_voltageIn.setText( value )