a = 4
b = 8


def dzielniki(lista: list, liczba):
    for i in lista:
        if liczba % i != 0:
            lista.remove(i)



lista_a = [i for i in range(1, a + 1)]
lista_b = [i for i in range(1, b + 1)]


dzielniki(lista_a, a)
dzielniki(lista_b, b)


wspolne = []
for i in lista_a:
    for k in lista_b:
        if i == k:
            wspolne.append(i)
            break


for el in wspolne:
    print(f"{el};", end="")