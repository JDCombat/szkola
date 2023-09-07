file = open('.\szkola\informatyka\stab wounds\pliki\zapis.txt', 'r')
lista = file.read().split('\n')
plac = []
suma = 0

for el in lista:
    for pracownik in plac:
        suma += int(pracownik[1])
    temp = el.split(' ')
    temp.pop(0)
    if len(temp) == 2:
        plac.append(temp)
        suma += int(temp[1])
    else:
        x = 0
        while plac[x][0] != temp[0]:
            x += 1
        plac.pop(x)
print(suma)