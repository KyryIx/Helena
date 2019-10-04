from Laminas import Laminas
from Bobbins import Bobbins
from Wires import Wires

from Lamina import Lamina
from Bobbin import Bobbin
from Wire import Wire 
from Transformer import Transformer


data_lamina = Laminas('laminas.xml')
data_bobbin = Bobbins('bobbins.xml')
data_wire = Wires('wires.xml')

lamina = Lamina()
bobbin = Bobbin()
wireIN = Wire()
wireOUT = Wire()

lamina.setType( 'padrao' )
bobbin.setType( 'padrao' )
wireIN.setType('redondo')
wireOUT.setType('redondo')

#####################################
## Current Density value by Power   #
## +------------+-----------------+ #
## |   Power    | Current Density | #
## |    (VA)    |    (A/mm^2)     | #
## +------------+-----------------+ #
## |   0 ~ 500  |        3        | #
## +------------+-----------------+ #
## | 500 ~ 1000 |       2.5       | #
## +------------+-----------------+ #
## |1000 ~ 3000 |        2        | #
## +------------+-----------------+ #
#####################################

transformer1 = Transformer()
transformer1.setPowerOUT( 300.0 )
transformer1.setVoltageOUT( 220.0 )
transformer1.setVoltageIN( 120.0 )
transformer1.setFrequency( 50 )
transformer1.setFlux( 11300.0 )
transformer1.setCurrentDensity(3.0)
transformer1.setStyle( 1 )
transformer1.setLamina( lamina )
transformer1.setBobbin( bobbin )
transformer1.setWireIN( wireIN )
transformer1.setWireOUT( wireOUT )
transformer1.calculate()
print transformer1.toString()
#print "###################################################"
#print "###################################################"
transformer2 = Transformer()
transformer2.setPowerOUT( 1000.0 )
transformer2.setVoltageOUT( 24.0 )
transformer2.setVoltageIN( 220.0 )
transformer2.setFrequency( 50 )
transformer2.setFlux( 11300.0 )
transformer2.setCurrentDensity(2.5)
transformer2.setStyle( 1 )
transformer2.setLamina( lamina )
transformer2.setBobbin( bobbin )
transformer2.setWireIN( wireIN )
transformer2.setWireOUT( wireOUT )
transformer2.calculate()
#print transformer2.toString()