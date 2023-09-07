file = open('./pliki/nieparzysta_5.txt', 'r')
lista = file.read().split('\n')

for l in lista:
    if int(l) % 2 != 0:
        print(f"{int(l) * 5};", end='')
    else:
        print(f"{int(int(l) / 2)};", end='')
print('')