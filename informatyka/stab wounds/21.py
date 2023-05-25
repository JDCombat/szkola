file = open('./pliki/mniejsza_na_lewo.txt', 'r')
lista = file.read().split('\n')
lenght = int(lista[0])
lista = lista[1].split(' ')
listamax = []

for i in range(lenght):
    max = -1
    for j in range(i):
        if int(lista[i]) > int(lista[j]) > max:
            maximum = int(lista[j])
    listamax.append(max)

for i in range(lenght):
    print(listamax[i], end=' ')