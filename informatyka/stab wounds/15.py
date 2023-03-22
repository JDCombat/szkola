f = open(".\szkola\informatyka\stab wounds\pliki\\tablica.txt", "r")
slowa = f.read().split()
print(slowa[0].lower() + ";" + slowa[1].upper())
for x in range(1, slowa.__len__()):
    print(slowa[x].swapcase(), end=";")