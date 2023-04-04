f = open("./szkola/informatyka/stab wounds/pliki/gwiazdki.txt", "r")
txt = f.read()

txt = txt.split('\n')
str = str(txt)
lista = str.replace("[", "").replace("]", "").replace("'", "").replace('"', "").replace(",", "").split(" ")
for i in range(0, 5):
    a = int(lista[2 * i]) + 10
    b = int(lista[2 * i + 1]) ** 2
    if a > b:
        print(a)
    else:
        print(b)
