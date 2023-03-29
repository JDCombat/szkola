with open("./szkola/informatyka/stab wounds/pliki/dane2.txt", "r") as f:
    ilosc = int(f.readline())
    for x in range (1,ilosc):
        plik = f.read().split()
        for x in plik:
            if plik[x]