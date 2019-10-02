class Bobbin:
	def __init__(self):
		self.__id = 0
		self.__type = 'padrao'
		self.__width = 0.0
		self.__length = 0.0
		self.__height = 0.0
	
	def setId(self, id):
		self.__id = id
	
	def getId(self):
		return self.__id
	
	def setType(self, type='padrao'):
		self.__type = type
	
	def getType(self):
		return self.__type
	
	def setWidth(self, width):
		self.__width = width
	
	def getWidth(self):
		return self.__width
	
	def setLength(self, length):
		self.__length = length
	
	def getLength(self):
		return self.__length
	
	def setHeight(self, height):
		self.__height = height
	
	def getHeight(self):
		return self.__height
	
	def getArea(self):
		return self.getWidth() * self.getLength()
	
	def getVolume(self):
		return self.getWidth() * self.getLength() * self.getHeight()
		
	def toString(self):
		txt = ''
		txt = txt + 'Bobbin ID: ' + str(self.getId()) + '\n'
		txt = txt + 'Bobbin Type: ' + str(self.getType()) + '\n'
		txt = txt + 'Bobbin Width: ' + str(self.getWidth()) + ' mm\n'
		txt = txt + 'Bobbin Length: ' + str(self.getLength()) + ' mm\n'
		txt = txt + 'Bobbin Height: ' + str(self.getHeight()) + ' mm\n'
		txt = txt + 'Bobbin Area: ' + str(self.getArea()) + ' mm*mm\n'
		txt = txt + 'Bobbin Volume: ' + str(self.getVolume()) + ' mm*mm*mm\n'
		return txt