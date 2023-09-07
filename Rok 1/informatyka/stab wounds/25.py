file = open('./pliki/odwracanie_listy.txt', 'r')
lista = file.read().split('\n')
liczby = [i for i in range(int(lista[0]))]
lista.pop(0)
lista.pop(0)
lista = [l.split(' ') for l in lista]
for l in lista:
    liczby[int(l[0]):int(l[-1])] = reversed(liczby[int(l[0]):int(l[-1])])

print(liczby)