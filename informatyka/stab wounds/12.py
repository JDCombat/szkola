f = open("./szkola/informatyka/stab wounds/pliki/te_same_cyfry.txt", "r")
lista = f.read().split("\n")

repeat = 0  # liczba powtórzeń

for i in range(0, len(lista)):
    litery1 = list(lista[i])
    litery1.sort()
    for j in range(i + 1, len(lista)):
        litery2 = list(lista[j])
        litery2.sort()
        if litery1 == litery2:
            repeat += 1

print(repeat)