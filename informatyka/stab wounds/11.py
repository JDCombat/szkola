f = open(".\szkola\informatyka\stab wounds\pliki\ile.txt", "r")
tekst = f.read()
ilosc = [tekst.count(x) for x in tekst.replace(" ", "")]
for x in ilosc:
    print(x, end=";")
