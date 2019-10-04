import xml.etree.ElementTree as ET

from Wire import Wire

class Wires:
	def __init__(self, filename):
		self.__filename = filename
		self.__root = ET.parse(filename).getroot()
	
	def getFilename(self):
		return self.__filename
	
	def setFilename(self, filename):
		self.__filename = filename
		self.__root = ET.parse(filename).getroot()
	
	def getType(self, index, type='redondo'):
		type_tmp = ''
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				type_tmp = type
				break
		return type_tmp
	
	def getAWG(self, index, type='redondo'):
		awg = ''
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				awg = wire.find('awg').get('valor')
				break
		return awg
	
	def getDiameter(self, index, type='redondo'):
		diameter = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				diameter = float(wire.find('diametro').get('valor'))
				break
		return diameter
	
	def getTurnByCm(self, index, type='redondo'):
		turnByCm = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				turnByCm = float(wire.find('espirasPerCm').get('valor'))
				break
		return turnByCm
	
	def getArea(self, index, type='redondo'):
		area = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				area = float(wire.find('area').get('valor'))
				break
		return area
	
	def getResistance(self, index, type='redondo'):
		resistance = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				resistance = float(wire.find('resistencia').get('valor'))
				break
		return resistance
	
	def getWeight(self, index, type='redondo'):
		weight = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				weight = float(wire.find('peso').get('valor'))
				break
		return weight
	
	def getLength(self, index, type='redondo'):
		length = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				length = float(wire.find('comprimento').get('valor'))
				break
		return length
	
	def getCurrentMax(self, index, type='redondo'):
		currentMax = []
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				currentMaxObject = wire.find('correnteMaxima')
				densities = currentMaxObject.findall('densidade')
				for densityObject in densities:
					dict = {'density': float(densityObject.get('valor')), 'unity density': densityObject.get('unidade'), 'currentMax':float(densityObject.text), 'unity current': currentMaxObject.get('unidade') }
					currentMax.append( dict )
				break
		return currentMax
	
	def getFrequency(self, index, type='redondo'):
		frequency = 0.0
		wires = self.__root.find(type).findall('fio')
		for wire in wires:
			if int(wire.attrib['numero']) == index:
				frequency = float(wire.find('frequencia').get('valor'))
				break
		return frequency
	
	def findIndexByDiameter(self, diameter, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		diameter_last = 1e10
		for wire in wires:
			diameter_tmp = float(wire.find('diametro').get('valor'))
			if (diameter <= diameter_tmp) and (diameter_tmp < diameter_last):
				index = int(wire.attrib['numero'])
				diameter_last = diameter_tmp
		return index
	
	def findIndexByTurnByCm(self, turnByCm, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		turnByCm_last = 1e10
		for wire in wires:
			turnByCm_tmp = float(wire.find('espirasPerCm').get('valor'))
			if (turnByCm <= turnByCm_tmp) and (turnByCm_tmp < turnByCm_last):
				index = int(wire.attrib['numero'])
				turnByCm_last = turnByCm_tmp
		return index
	
	def findIndexByArea(self, area, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		area_last = 1e10
		for wire in wires:
			area_tmp = float(wire.find('area').get('valor'))
			if (area <= area_tmp) and (area_tmp < area_last):
				index = int(wire.attrib['numero'])
				area_last = area_tmp
		return index
	
	def findIndexByResistance(self, resistance, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		resistance_last = 1e20
		for wire in wires:
			resistance_tmp = float(wire.find('resistencia').get('valor'))
			if (resistance <= resistance_tmp) and (resistance_tmp < resistance_last):
				index = int(wire.attrib['numero'])
				resistance_last = resistance_tmp
		return index
	
	def findIndexByWeight(self, weight, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		weight_last = 1e10
		for wire in wires:
			weight_tmp = float(wire.find('peso').get('valor'))
			if (weight <= weight_tmp) and (weight_tmp < weight_last):
				index = int(wire.attrib['numero'])
				weight_last = weight_tmp
		return index
	
	def findIndexByLength(self, length, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		length_last = 1e10
		for wire in wires:
			length_tmp = float(wire.find('comprimento').get('valor'))
			if (length <= length_tmp) and (length_tmp < length_last):
				index = int(wire.attrib['numero'])
				length_last = length_tmp
		return index
	
	def findIndexesByCurrentMax(self, currentMax, density=3.0, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		currentMax_last = 1e10
		for wire in wires:
			densities = wire.find('correnteMaxima').findall('densidade')
			density_last = -1e10
			currentMax_tmp = -1e10
			for densityObject in densities:
				density_tmp = float(densityObject.get('valor'))
				if (density >= density_tmp) and (density_tmp > density_last):
					density_last = density_tmp
					currentMax_tmp = float(densityObject.text)
			
			if (currentMax <= currentMax_tmp) and (currentMax_tmp < currentMax_last):
				currentMax_last = currentMax_tmp
				index = int(wire.attrib['numero'])
		return index
	
	def findIndexByFrequency(self, frequency, type='redondo'):
		index = -1
		wires = self.__root.find(type).findall('fio')
		frequency_last = 1e20
		for wire in wires:
			frequency_tmp = float(wire.find('frequencia').get('valor'))
			if (frequency <= frequency_tmp) and (frequency_tmp < frequency_last):
				index = int(wire.attrib['numero'])
				frequency_last = frequency_tmp
		return index
	
	def getWire(self, index, type='redondo'):
		wire = Wire()
		wires = self.__root.find(self.getType(index)).findall('fio')
		for wire_tmp in wires:
			if int(wire_tmp.attrib['numero']) == index:
				wire.setId( index )
				wire.setType( self.getType(index) )
				wire.setAWG( self.getAWG(index) )
				wire.setDiameter( self.getDiameter(index) )
				wire.setTurnByCm( self.getTurnByCm(index) )
				wire.setArea( self.getArea(index) )
				wire.setResistance( self.getResistance(index) )
				wire.setWeight( self.getWeight(index) )
				wire.setLength( self.getLength(index) )
				wire.setCurrentMax( float( self.getCurrentMax(index)[1]['currentMax'] ) )
				wire.setFrequency( self.getFrequency(index) )
				break
		return wire