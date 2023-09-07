lista = open('.\szkola\informatyka\stab wounds\pliki\kolorowe_nawiasy.txt', 'r').read().split('\n')
lista.pop(0)
for wiersz in range(len(lista)):
    lista[wiersz] = lista[wiersz].split(' ')

regularne = 0

for wiersz in range(len(lista)):
    tak = 1
    liczby = []
    for element in range(len(lista[wiersz])):
        if lista[wiersz][element][0] != '-':
            liczby.append(lista[wiersz][element])
        else:
            if not liczby:
                tak = 0
            elif lista[wiersz][element] == '-' + liczby[-1]:
                liczby.pop(-1)
            else:
                tak = 0
    if tak == 1:
        regularne += 1
print(regularne)