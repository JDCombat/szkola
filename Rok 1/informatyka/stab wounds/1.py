f = open('.\szkola\informatyka\stab wounds\pliki\slowa.txt', "r")

licznik = 0
for x in f:
    if x.count('a') > 3:
        licznik+=1

print(licznik)