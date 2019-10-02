from Bobbins import Bobbins

bobbins = Bobbins('bobbins.xml')
print bobbins.getBobbin(0).toString()
print
print bobbins.getWidth(0)
print bobbins.getLength(0)
print bobbins.getHeight(0)
print
print bobbins.findIndexByWidth(2.7)
print bobbins.findIndexByLength(54)
print bobbins.findIndexByHeight(0.6)
print
print bobbins.getWidth(5,'especial')
print bobbins.getLength(2,'especial')
print bobbins.getHeight(2,'especial')
print
print bobbins.findIndexByWidth(2.7,'especial')
print bobbins.findIndexByLength(714,'especial')
print bobbins.findIndexByHeight(0.6,'especial')