n=int(input('Podaj ilosc liczb: '))
lista = []
for x in range(n):
    liczba = int(input(f'Wpisz {x} liczbe'))
    lista.append(liczba)

maks = lista[0]
for i in range(1,n):
    if maks < lista[i]:
        maks = lista[i]

print(f'lista = {lista}')
print(f'maks = {maks}')