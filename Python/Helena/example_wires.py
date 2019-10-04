from Wires import Wires

wires = Wires('wires.xml')
print wires.getWire(2).toString()
print
print "AWG = " + str( wires.getAWG(5) )
print "Diametro = " + str( wires.getDiameter(5) )
print "Espiras por cm = " + str( wires.getTurnByCm(5) )
print "Area = " + str( wires.getArea(5) )
print "Resistencia = " + str( wires.getResistance(5) )
print "Peso = " + str( wires.getWeight(5) )
print "Comprimento = " + str( wires.getLength(5) )
print "Corrente Maxima = " + str( wires.getCurrentMax(5) )
print "Frequencia = " + str( wires.getFrequency(5) )
print
print "Indice do diametro maior que 3.5 = " + str( wires.findIndexByDiameter(3.5) )
print "Indice de espiras por cm maior que 10 = " + str( wires.findIndexByTurnByCm(10) )
print "Indice da area maior que 12.5 = " + str( wires.findIndexByArea(12.5) )
print "Indice da resistencia maior que 25 = " + str( wires.findIndexByResistance(25) )
print "Indice do peso maior que 45 = " + str( wires.findIndexByWeight(45) )
print "Indice da corrente maxima maior que 100 = " + str( wires.findIndexesByCurrentMax(100) )
print "Indice da frequencia maior que 2 = " + str( wires.findIndexByFrequency(2) )