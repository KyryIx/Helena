from Laminas import Laminas

laminas = Laminas('laminas.xml')
print laminas.getLamina(2).toString()
print
print laminas.getThickness(2)
print laminas.getWindowArea(2)
print laminas.getWeight(2)
print
print laminas.findIndexByThickness(2.7)
print laminas.findIndexByWindowArea(714)
print laminas.findIndexByWeight(0.6)
print
print laminas.getThickness(6,'comprida')
print laminas.getWindowArea(6,'comprida')
print laminas.getWeight(6,'comprida')
print
print laminas.findIndexByThickness(2.7,'comprida')
print laminas.findIndexByWindowArea(0.5,'comprida')
print laminas.findIndexByWeight(0.6,'comprida')