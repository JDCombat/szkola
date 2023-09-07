file = open('./pliki/dane.txt', 'r')
lista = file.read().split(' ')
lista = [int(el) for el in lista]
maximum = 1

for elnum, el in enumerate(lista):
    for indexnum, index in enumerate(lista[elnum + 1:]):
        gap = el - index
        liczba = index
        licznik = 2
        for numbernum, number in enumerate(lista[indexnum + 2:]):
            if liczba - number == gap:
                licznik += 1
                liczba = number
        if licznik > maximum:
            maximum = licznik

print(maximum)