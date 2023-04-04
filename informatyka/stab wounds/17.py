with open("./szkola/informatyka/stab wounds/pliki/dane2.txt", "r") as f:
    mnoz = 1
    len = 0
    alfabet = "ABCDEFGFIJKLMNOPRSTUWYZ"
    ilosc = int(f.readline())
    for i in range(0,ilosc):
        plik = f.readline().split()
        for x in range(1,plik.__len__()):
            print(plik[x])
            mnoz *= int(plik[x])
            print(mnoz)
            len += 1
    
    print(len, end="\n")
    print(mnoz, end="\n")
    srendia = float(mnoz/len)
    round(srendia, 2)
    print(srendia)