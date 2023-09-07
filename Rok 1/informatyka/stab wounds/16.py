file = open('.\szkola\informatyka\stab wounds\pliki\wielkie_sprzatanie.txt', 'r', encoding='utf-8')
lista = file.read().split('\n')  

for i in range(len(lista)):
    lista[i] = lista[i].strip().split(' ')
    while '' in lista[i]:
        lista[i].remove('')

for i in range(len(lista)):
    for j in range(len(lista[i])):
        lista[i][j] = lista[i][j].replace('_', '').lower()
    lista[i][0] = lista[i][0].capitalize() + ':'
    lista[i][1] = lista[i][1].capitalize()
    lista[i][-2] += ','

for i in range(len(lista)):
    for j in range(len(lista[i])):
        print(lista[i][j], end=' ')
    print(' ')
