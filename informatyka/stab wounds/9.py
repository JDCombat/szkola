f = open(".\szkola\informatyka\stab wounds\pliki\gwiazdki.txt", "r")
txt = f.read()

txt = txt.rstrip('\n')
print(txt)