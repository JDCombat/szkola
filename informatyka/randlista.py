import random

lista = [(random.randint(1,1000)) for x in range(100)]
parzyste = [x for x in lista if x%2==0]
nieparzyste = [x for x in lista if x%2==1]

print(lista)
print(parzyste)
print(nieparzyste)


imiona = ['Julia', 'Weronika', 'Kuba', 'Robert']
imionak = [x for x in imiona if x.endswith('a')]
imionam = [x for x in imiona if x[-1] != 'a']

print(imionak)
print(imionam)

szyfr = 'szyfrcezara'

zaszyfrowane = "".join([chr((ord(x)+3-ord("a"))%26-ord("a")) for x in szyfr])
print(zaszyfrowane)
odszyfrowane = []