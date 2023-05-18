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

lista = open('./pliki/pokrycie.txt', 'r').read().split('\n')
liczba = int(lista[0])
lista = [int(i) for i in lista[-1].split(' ')]
for l in pierwsze(liczba):
    if l not in lista:
        print('NIE')
print('TAK')