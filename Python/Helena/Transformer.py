from math import sqrt, ceil, pi

from Lamina import Lamina
from Bobbin import Bobbin
from Wire import Wire

from Laminas import Laminas
from Bobbins import Bobbins
from Wires import Wires

# https://docs.python.org/2/tutorial/classes.html
class Transformer:
	def __init__(self):
		self.__powerIN = 0.0# in watts
		self.__voltageIN = 0.0# in volts
		self.__currentIN = 0.0# in amperes
		self.__turnsIN = 0# number turns primary
		self.__wireIN = Wire()
		
		self.__powerOUT = 0.0# in watts
		self.__voltageOUT = 0.0# in volts
		self.__currentOUT = 0.0# in amperes
		self.__turnsOUT = 0# number turns secondary
		self.__wireOUT = Wire
		
		self.__frequency = 0.0# in hertz
		self.__flux = 0.0#in Gauss
		self.__style = 0# 1 - 1 primary and 1 secondary
		                # 2 - 2 primaries and 1 secondary or
		                #     1 primary and 2 secondaries
		                # 3 - 2 primaries and 2 secondaries
		
		self.__currentDensity = 0.0
		self.__lamina = Lamina()
		self.__bobbin = Bobbin()
	
	def getPowerIN(self):
		return self.__powerIN
	
	def setPowerIN(self, power):
		self.__powerIN = power
	
	def getVoltageIN(self):
		return self.__voltageIN
	
	def setVoltageIN(self, voltage):
		self.__voltageIN = voltage
	
	def getCurrentIN(self):
		return self.__currentIN
	
	def setCurrentIN(self, current):
		self.__currentIN = current
	
	def getTurnsIN(self):
		return self.__turnsIN
	
	def setTurnsIN(self, turns):
		self.__turnsIN = int( turns )
	
	def getWireIN(self):
		return self.__wireIN
	
	def setWireIN(self, wire):
		self.__wireIN = wire
	
	def getPowerOUT(self):
		return self.__powerOUT
	
	def setPowerOUT(self, power):
		self.__powerOUT = power
	
	def getVoltageOUT(self):
		return self.__voltageOUT
	
	def setVoltageOUT(self, voltage):
		self.__voltageOUT = voltage
	
	def getCurrentOUT(self):
		return self.__currentOUT
	
	def setCurrentOUT(self, current):
		self.__currentOUT = current
	
	def getTurnsOUT(self):
		return self.__turnsOUT
	
	def setTurnsOUT(self, turns):
		self.__turnsOUT = int( turns )
	
	def getWireOUT(self):
		return self.__wireOUT
	
	def setWireOUT(self, wire):
		self.__wireOUT = wire
	
	def getFrequency(self):
		return self.__frequency
	
	def setFrequency(self, frequency):
		self.__frequency = frequency
	
	def getFlux(self):
		return self.__flux
	
	def setFlux(self, flux):
		self.__flux = flux
	
	def getStyle(self):
		return self.__style
	
	def setStyle(self, style):
		self.__style = style
	
	def getCurrentDensity(self):
		return self.__currentDensity
	
	def setCurrentDensity(self, density):
		self.__currentDensity = density
	
	def getLamina(self):
		return self.__lamina
	
	def setLamina(self, lamina):
		self.__lamina = lamina
	
	def getBobbin(self):
		return self.__bobbin
	
	def setBobbin(self, bobbin):
		self.__bobbin = bobbin
	
	def getCurrentDensityIN(self):
		try:
			return self.getCurrentIN() / self.getWireIN().getArea()
		except ZeroDivisionError:
			return 0.0
	
	def getCurrentDensityOUT(self):
		try:
			return self.getCurrentOUT() / self.getWireOUT().getArea()
		except ZeroDivisionError:
			return 0.0
	
	def getAverageDensity(self):
		return (self.getCurrentDensityIN() + self.getCurrentDensityOUT()) / 2.0
	
	def getAverageLengthTurn(self):
		return (2 + 0.5 * pi) * self.getLamina().getThickness() + 2 * self.getBobbin().getLength()
	
	def getCoilArea(self):
		return self.getTurnsIN() * self.getWireIN().getArea() + self.getTurnsOUT() * self.getWireOUT().getArea()
	
	def getWeigthIron(self):
		return (self.getBobbin().getLength() / 10.0) * self.getLamina().getWeight()
	
	def getWeightCopper(self):
		return (self.getCoilArea()/100.0) * (self.getAverageLengthTurn()/10.0) * 8.9 / 1000.0
	
	def getLossIron(self):
		# rever esses calculos #
		wfe = 1.35 * (self.getFlux() / 10000.0)**2
		return 1.15 * wfe * self.getWeightCopper()
	
	def getLossCopper(self):
		wcu = 2.43 * self.getAverageDensity()**2
		return wcu * self.getWeightCopper()
	
	def getEfficiency(self):
		try:
			return self.getPowerOUT() / (self.getPowerOUT() + self.getLossIron() + self.getLossCopper())
		except ZeroDivisionError:
			return 0.0
	
	def toString(self):
		txt = ''
		txt = txt + '   Transformer with: '
		if self.getStyle() == 1:
			txt = txt + '1 primary and 1 secondary\n'
		elif self.getStyle() == 2:
			txt = txt + '2 primaries and 1 secondary or 1 primary and 2 secondaries\n'
		elif self.getStyle() == 3:
			txt = txt + '2 primaries and 2 secondaries\n'
		else:
			txt = txt + 'indefined type\n'
		txt = txt + '           Frequency: ' + str(self.getFrequency()) + ' Hz\n'
		txt = txt + '  Magnetic Induction: ' + str(round(self.getFlux(),2)) + ' G\n'
		txt = txt + '     Current Density: ' + str(round(self.getCurrentDensity(),2)) + ' A/mm^2\n'
		txt = txt + '   Mean Cur. Density: ' + str(round(self.getAverageDensity(),2)) + ' A/mm^2\n'
		txt = txt + '         Weigth Iron: ' + str(round(self.getWeigthIron()*1000.0,2)) + ' g\n'
		txt = txt + '       Weight Copper: ' + str(round(self.getWeightCopper()*1000.0,2)) + ' g\n'
		txt = txt + 'Turns Average Length: ' + str(round(self.getAverageLengthTurn()/10,2)) + ' cm\n'
		txt = txt + '           Coil Area: ' + str(round(self.getCoilArea(),2)) + ' mm^2\n'
		txt = txt + '           Iron Loss: ' + str(round(self.getLossIron(),2)) + ' watts\n'
		txt = txt + '         Copper Loss: ' + str(round(self.getLossCopper(),2)) + ' Watts\n'
		txt = txt + '          Total Loss: ' + str(round(self.getLossIron()+self.getLossCopper(),2)) + ' Watts\n'
		txt = txt + '          Efficiency: ' + str(round(self.getEfficiency()*100,2)) + ' %\n'
		txt = txt + '\n'
		txt = txt + 'INPUT:\n'
		txt = txt + '             Voltage: ' + str(self.getVoltageIN()) + ' V\n'
		txt = txt + '               Power: ' + str(self.getPowerIN()) + ' W\n'
		txt = txt + '             Current: ' + str(self.getCurrentIN()) + ' A\n'
		txt = txt + '            AWG wire: ' + self.getWireIN().getAWG() + '\n'
		txt = txt + '          Wire turns: ' + str(self.getTurnsIN()) + '\n'
		txt = txt + '     Current Density: ' + str(round(self.getCurrentDensityIN(),2)) + ' A/mm^2\n'
		txt = txt + '\n'
		txt = txt + 'OUTPUT:\n'
		txt = txt + '             Voltage: ' + str(self.getVoltageOUT()) + '\n'
		txt = txt + '               Power: ' + str(self.getPowerOUT()) + '\n'
		txt = txt + '             Current: ' + str(self.getCurrentOUT()) + '\n'
		txt = txt + '            AWG wire: ' + self.getWireOUT().getAWG() + '\n'
		txt = txt + '          Wire turns: ' + str(self.getTurnsOUT()) + '\n'
		txt = txt + '     Current Density: ' + str(round(self.getCurrentDensityOUT(),2)) + ' A/mm^2'
		return txt
	
	def calculate(self, baseLaminas='laminas.xml', baseBobbins='bobbins.xml', baseWires='wires.xml'):
		try:
			compensation = 0.1 # 10 percent of compensation
			currentOUT = self.getPowerOUT() / self.getVoltageOUT()
			powerIN = self.getPowerOUT() * (1.0 + compensation)
			currentIN = powerIN / self.getVoltageIN()
			
			wires = Wires(baseWires)
			wireIN = Wire()
			wireOUT = Wire()
			
			S1 = currentIN / self.getCurrentDensity()
			wireIN = wires.getWire( wires.findIndexByArea(S1) )
			S2 = currentOUT / self.getCurrentDensity()
			wireOUT = wires.getWire( wires.findIndexByArea(S2) )
			
			Sm = self.getPowerOUT() / self.getFrequency()
			vStyle = 0.00
			
			if self.getStyle() == 0:# 1 primary and 1 secondary
				vStyle = 1.00
			if (self.getStyle() == 1) or (self.getStyle() == 2):# 2 primaries and 1 secondary or 1 primary and 2 secondaries
				vStyle = 1.25
			if self.getStyle() == 3:# 2 primaries and 2 secondaries
				vStyle = 1.50
			
			Sm = sqrt( vStyle * Sm ) * 100 # convert to mm^2 #
			
			if self.getLamina().getType() == 'padrao':# standard laminas
				Sm = 7.5 * Sm
			if self.getLamina().getType() == 'comprida':# long laminas
				Sm = 6.0 * Sm
			
			Sg = 1.1 * Sm
			a = sqrt( Sg )
			
			laminas = Laminas(baseLaminas)
			bobbins = Bobbins(baseBobbins)
			
			state = True
			aTemp = a
			i     = 0
			n     = 1000
			
			lamina = Lamina()
			bobbin = Bobbin()
			N1 = 0
			N2 = 0
			
			while i < n:
				i = i + 1
				index = laminas.findIndexByThickness(aTemp)
				if index == -1:
					state = False
				
				lamina = laminas.getLamina(index)
				a = lamina.getThickness()
				
				index = bobbins.findIndexByWidthAndArea(a,Sm)
				if index == -1:
					state = False
				
				bobbin = bobbins.getBobbin(index)
				b = bobbin.getLength()
				
				Sg = a * b
				Sm = (Sg / 1.1) / 100.0 # convert to cm^2 #
				
				N1 = ceil( (self.getVoltageIN() * 1e8) / (Sm * 4.44 * self.getFlux() * self.getFrequency()) )
				N2 = ceil( ((self.getVoltageOUT() * 1e8) / (Sm * 4.44 * self.getFlux() * self.getFrequency())) * (1.0 + compensation) )
				Scu = N1 * wireIN.getArea() + N2 * wireOUT.getArea()
				
				if (lamina.getWindowArea() / Scu) < 3:
					#print 'Recalculando o transformador para uma chapa com janela maior'
					aTemp = aTemp + 0.1
				else:
					#print 'Calculo correto'
					self.setCurrentOUT( currentOUT )
					self.setPowerIN( powerIN )
					self.setCurrentIN( currentIN )
					self.setWireIN( wireIN )
					self.setWireOUT( wireOUT )
					self.setTurnsIN( N1 )
					self.setTurnsOUT( N2 )
					self.setLamina( lamina )
					self.setBobbin( bobbin )
					state = False
			
			return state
		except ZeroDivisionError:
			print 'Divisao por zero'
			return True