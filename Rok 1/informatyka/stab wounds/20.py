file = open('.\szkola\informatyka\stab wounds\pliki\maks_na_przedziale.txt', 'r')
lista = file.read().split('\n') #otwieramy plik
wynik = []
liczby = lista[1].split(' ')
lista.pop(0)
lista.pop(0)
lista.pop(0)

for i in range(len(lista)):
    lista[i] = lista[i].split(' ')

for el in lista:
    maximum = int(liczby[int(el[0])])
    for index in liczby[int(el[0]):int(el[1])]:
        if int(index) > maximum:
            maximum = int(index)
    wynik.append(maximum)

for el in wynik:
    print(el)