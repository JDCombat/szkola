lista = open('./pliki/suma_cyfr_ksHfWZp.txt', 'r').read().split('\n')
lista.pop(0)
import sys

sys.setrecursionlimit(30000)


def sumacyfr(liczba: int):
    liczba = str(liczba)
    suma = 0
    for cyfra in liczba:
        suma += int(cyfra)
    return suma


lista = [int(i) for i in lista]
druga = []
druga.append(lista[0])
lista.pop(0)
for el in lista:
    x = 0
    while x < len(druga) and sumacyfr(el) > sumacyfr(druga[x]):
        x += 1
    druga.insert(x, el)

for el in druga:
    print(el)