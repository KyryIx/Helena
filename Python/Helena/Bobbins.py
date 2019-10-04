import xml.etree.ElementTree as ET

from Bobbin import Bobbin

class Bobbins:
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
		bobbins = self.__root.find(type).findall('carretel')
		for bobbin in bobbins:
			if int(bobbin.attrib['numero']) == index:
				type_tmp = type
				break
		return type_tmp
	
	def getWidth(self, index, type='padrao'):
		width = []
		bobbins = self.__root.find(type).findall('carretel')
		for bobbin in bobbins:
			if int(bobbin.attrib['numero']) == index:
				width = [float(bobbin.find('largura').get('valor')),bobbin.find('largura').get('unidade')]
				break
		return width
	
	def getLength(self, index, type='padrao'):
		length = []
		bobbins = self.__root.find(type).findall('carretel')
		for bobbin in bobbins:
			if int(bobbin.attrib['numero']) == index:
				length = [float(bobbin.find('comprimento').get('valor')),bobbin.find('comprimento').get('unidade')]
				break
		return length

	def getHeight(self, index, type='padrao'):
		height = []
		bobbins = self.__root.find(type).findall('carretel')
		for bobbin in bobbins:
			if int(bobbin.attrib['numero']) == index:
				height = [float(bobbin.find('altura').get('valor')),bobbin.find('altura').get('unidade')]
				break
		return height
	
	def findIndexByWidth(self, width, type='padrao'):
		index = -1
		bobbins = self.__root.find(type).findall('carretel')
		width_last = 1e10
		for bobbin in bobbins:
			width_tmp = float(bobbin.find('largura').get('valor'))
			if (width <= width_tmp) and (width_tmp < width_last):
				index = int(bobbin.attrib['numero'])
				width_last = width_tmp
		return index
	
	def findIndexByWidthAndArea(self, width, area, type='padrao'):
		index = -1
		bobbins = self.__root.find(type).findall('carretel')
		width_last = 1e10
		for bobbin in bobbins:
			width_tmp = float(bobbin.find('largura').get('valor'))
			length_tmp = float(bobbin.find('comprimento').get('valor'))
			if (width <= width_tmp) and (width_tmp < width_last) and (area <= (width_tmp*length_tmp)):
				index = int(bobbin.attrib['numero'])
				width_last = width_tmp
		return index
	
	def findIndexByLength(self, length, type='padrao'):
		index = -1
		bobbins = self.__root.find(type).findall('carretel')
		length_last = 1e10
		for bobbin in bobbins:
			length_tmp = float(bobbin.find('comprimento').get('valor'))
			if (length <= length_tmp) and (length_tmp < length_last):
				index = int(bobbin.attrib['numero'])
				length_last = length_tmp
		return index
	
	def findIndexByHeight(self, height, type='padrao'):
		index = -1
		bobbins = self.__root.find(type).findall('carretel')
		height_last = 1e10
		for bobbin in bobbins:
			height_tmp = float(bobbin.find('altura').get('valor'))
			if (height <= height_tmp) and (height_tmp < height_last):
				index = int(bobbin.attrib['numero'])
				height_last = height_tmp
		return index
	
	def getBobbin(self, index, type='padrao'):
		bobbin = Bobbin()
		bobbins = self.__root.find(type).findall('carretel')
		for bobbin_tmp in bobbins:
			if int(bobbin_tmp.attrib['numero']) == index:
				bobbin.setId( index )
				bobbin.setType( self.getType(index) )
				bobbin.setWidth( self.getWidth(index)[0] )
				bobbin.setLength( self.getLength(index)[0] )
				bobbin.setHeight( self.getHeight(index)[0] )
				break
		return bobbin