class Lamina:
	def __init__(self):
		self.__id = 0
		self.__type = 'padrao'
		self.__thickness = 0.0
		self.__windowArea = 0.0
		self.__weight = 0.0
	
	def setId(self, id):
		self.__id = id
	
	def getId(self):
		return self.__id
	
	def setType(self, type='padrao'):
		self.__type = type
	
	def getType(self):
		return self.__type
	
	def setThickness(self, thickness):
		self.__thickness = thickness
	
	def getThickness(self):
		return self.__thickness
	
	def setWindowArea(self, windowArea):
		self.__windowArea = windowArea
	
	def getWindowArea(self):
		return self.__windowArea
	
	def setWeight(self, weight):
		self.__weight = weight
	
	def getWeight(self):
		return self.__weight
	
	def toString(self):
		txt = ''
		txt = txt + 'Lamina ID: ' + str(self.getId()) + '\n'
		txt = txt + 'Lamina Type: ' + str(self.getType()) + '\n'
		txt = txt + 'Lamina Thickness: ' + str(self.getThickness()) + ' mm\n'
		txt = txt + 'Lamina Window Area: ' + str(self.getWindowArea()) + ' mm*mm\n'
		txt = txt + 'Lamina Weight: ' + str(self.getWeight()) + ' kg/cm\n'
		return txt