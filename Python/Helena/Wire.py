class Wire:
	def __init__(self):
		self.__id = 0
		self.__type = 'redondo'
		self.__awg = '-'
		self.__diameter = 0.0
		self.__turnByCm = 0.0
		self.__area = 0.0
		self.__resistance = 0.0
		self.__weight = 0.0
		self.__length = 0.0
		self.__currentMax = 0.0
		self.__frequency = 0.0
	
	def getId(self):
		return self.__id
	
	def setId(self, id):
		self.__id = id
	
	def getType(self):
		return self.__type
	
	def setType(self, type='redondo'):
		self.__type = type
	
	def getAWG(self):
		return self.__awg
	
	def setAWG(self, awg):
		self.__awg = awg
	
	def getDiameter(self):
		return self.__diameter
	
	def setDiameter(self, diameter):
		self.__diameter = diameter
	
	def getTurnByCm(self):
		return self.__turnByCm
	
	def setTurnByCm(self, turnByCm):
		self.__turnByCm = turnByCm
	
	def getArea(self):
		return self.__area
	
	def setArea(self, area):
		self.__area = area
	
	def getResistance(self):
		return self.__resistance

	def setResistance(self, resistance):
		self.__resistance = resistance
	
	def getWeight(self):
		return self.__weight
	
	def setWeight(self, weight):
		self.__weight = weight
	
	def getLength(self):
		return self.__length
	
	def setLength(self, length):
		self.__length = length
	
	def getCurrentMax(self):
		return self.__currentMax
	
	def setCurrentMax(self, currentMax):
		self.__currentMax = currentMax
	
	def getFrequency(self):
		return self.__frequency
	
	def setFrequency(self, frequency):
		self.__frequency = frequency
	
	def toString(self):
		txt = ''
		txt = txt + 'Wire ID: ' + str(self.getId()) + '\n'
		txt = txt + 'Wire AWG: ' + str(self.getAWG()) + '\n'
		txt = txt + 'Wire Diameter: ' + str(self.getDiameter()) + ' mm\n'
		txt = txt + 'Wire Turn per cm: ' + str(self.getTurnByCm()) + ' esp/cm\n'
		txt = txt + 'Wire Area: ' + str(self.getArea()) + ' mm*mm\n'
		txt = txt + 'Wire Resistance: ' + str(self.getResistance()) + ' ohm/km\n'
		txt = txt + 'Wire Weight: ' + str(self.getWeight()) + ' kg/km\n'
		txt = txt + 'Wire Length: ' + str(self.getLength()) + ' m/kg\n'
		txt = txt + 'Wire Current Max: ' + str(self.getCurrentMax()) + ' A [density in 3A/(mm*mm)]\n'
		txt = txt + 'Wire Frequency: ' + str(self.getFrequency()) + ' kHz\n'
		return txt