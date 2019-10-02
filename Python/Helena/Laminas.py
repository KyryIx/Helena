import xml.etree.ElementTree as ET

from Lamina import Lamina

class Laminas:
	def __init__(self, filename):
		self.__filename = filename
		self.__root = ET.parse(filename).getroot()
	
	def getFilename(self):
		return self.__filename
	
	def setFilename(self, filename):
		self.__filename = filename
		self.__root = ET.parse(filename).getroot()
	
	def getType(self, index, type='padrao'):
		type_tmp = ''
		laminas = self.__root.find(type).findall('lamina')
		for lamina in laminas:
			if int(lamina.attrib['numero']) == index:
				type_tmp = type
				break
		return type_tmp
	
	def getThickness(self, index, type='padrao'):
		thickness = []
		laminas = self.__root.find(type).findall('lamina')
		for lamina in laminas:
			if int(lamina.attrib['numero']) == index:
				thickness = [float(lamina.find('a').get('valor')),lamina.find('a').get('unidade')]
				break
		return thickness
	
	def getWindowArea(self, index, type='padrao'):
		windowArea = []
		laminas = self.__root.find(type).findall('lamina')
		for lamina in laminas:
			if int(lamina.attrib['numero']) == index:
				windowArea = [float(lamina.find('secao').get('valor')),lamina.find('secao').get('unidade')]
				break
		return windowArea

	def getWeight(self, index, type='padrao'):
		weight = []
		laminas = self.__root.find(type).findall('lamina')
		for lamina in laminas:
			if int(lamina.attrib['numero']) == index:
				weight = [float(lamina.find('peso').get('valor')),lamina.find('peso').get('unidade')]
				break
		return weight
	
	#def findIndexByThickness(self, thickness, type='padrao'):
	#	index = -1
	#	laminas = self.__root.find(type).findall('lamina')
	#	thickness_last = 1e10
	#	for lamina in laminas:
	#		thickness_tmp = float(lamina.find('a').get('valor'))
	#		if (thickness <= thickness_tmp) and (thickness_tmp < thickness_last):
	#			index = int(lamina.attrib['numero'])
	#			thickness_last = thickness_tmp
	#	return index
	
	def findIndexByThickness(self, thickness, type='padrao'):
		index = -1
		laminas = self.__root.find(type).findall('lamina')
		thickness_last = 1e10
		for lamina in laminas:
			thickness_tmp = float(lamina.find('a').get('valor'))
			if abs(thickness - thickness_tmp) < abs(thickness - thickness_last):
				index = int(lamina.attrib['numero'])
				thickness_last = thickness_tmp
		return index
	
	def findIndexByWindowArea(self, windowArea, type='padrao'):
		index = -1
		laminas = self.__root.find(type).findall('lamina')
		windowArea_last = 1e10
		for lamina in laminas:
			windowArea_tmp = float(lamina.find('secao').get('valor'))
			if (windowArea <= windowArea_tmp) and (windowArea_tmp < windowArea_last):
				index = int(lamina.attrib['numero'])
				windowArea_last = windowArea_tmp
		return index
	
	def findIndexByWeight(self, weight, type='padrao'):
		index = -1
		laminas = self.__root.find(type).findall('lamina')
		weight_last = 1e10
		for lamina in laminas:
			weight_tmp = float(lamina.find('peso').get('valor'))
			if (weight <= weight_tmp) and (weight_tmp < weight_last):
				index = int(lamina.attrib['numero'])
				weight_last = weight_tmp
		return index
	
	def getLamina(self, index, type='padrao'):
		lamina = Lamina()
		laminas = self.__root.find(self.getType(index)).findall('lamina')
		for lamina_tmp in laminas:
			if int(lamina_tmp.attrib['numero']) == index:
				lamina.setId( index )
				lamina.setType( self.getType(index) )
				lamina.setThickness( self.getThickness(index)[0] )
				lamina.setWindowArea( self.getWindowArea(index)[0] )
				lamina.setWeight( self.getWeight(index)[0] )
				break
		return lamina