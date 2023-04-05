f = open(".\szkola\informatyka\stab wounds\pliki\\wielkie_sprzatanie.txt", "r", encoding="UTF-8")
for i in range(8):
    x = f.readline().split()
    for k in 
    x.replace("_", " ")
    for i in range(len(x)):
        x[i] = x[i].lower()
    x[0] = x[0].capitalize()
    x[1] = x[1].capitalize()
    x[0] +=':'
    x[-2] +=','
    print(x)
