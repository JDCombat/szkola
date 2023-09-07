import os
import string
plik = open(".\szkola\informatyka\lista.txt", "r")

for line in plik:
    line = line.split('_')
    line[2] = line[2].splitlines()
    print(line[2])
    sciezka = line[0] + '/' + line[1] + '/' + str(line[2])
    os.makedirs(sciezka)

plik.close()