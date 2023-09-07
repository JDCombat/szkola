file = open('./pliki/pary.txt')
lista = file.read().split('\n')

for i in range(len(lista)):
    lista[i] = lista[i].split(' ')
    lista[i].pop(1)

temp = []
for i in range(len(lista)):
    temp.append(int(lista[i][0]))
lista = temp

lista = list(filter(lambda x: x >= 2 and x % 2 == 0, lista))

def pierwsze(liczby : int):
    final = []
    for num in range(liczby + 1):
        if num > 1:
            for i in range(2, num):
                if (num % i) == 0:
                    break
            else:
                final.append(num)
    return final

def goldbach(liczba: int):
    lista = pierwsze(liczba)
    for i in range(len(lista)):
        for j in range(1, len(lista) + 1):
            if lista[i] + lista[-j] == liczba:
                return f"{lista[i]};{lista[-j]}"


for el in lista:
    print(f"{el};{goldbach(el)};", end='')
print('')