import string
from string import ascii_lowercase
f = open("inwokacja.txt" , "r" , encoding  = "UTF-8")

tekst = f.read()
print(tekst)
ileSpolglosek = 0
ileSamoglosek = 0
ileMalych = 0
ileDuzych = 0
ileLiter = 0
ileWszystkich = 0
ileBialych = 0
ileInnych = 0

alfabet = ascii_lowercase
print(alfabet)

polskieLitery = ["ą", "ę", "ć", "ł" ,"ó", "ń", "ż", "ź", "Ż", "Ł", ]
for litera in alfabet:
    ileWszystkich += tekst.count(litera)
    ile = tekst.count(litera)
    print(f" {litera} występuje {ile}")

alfabetMW = string.ascii_letters
print(alfabetMW)
for litera in alfabetMW:
    ile = tekst.count(litera)
    print(f"litera {litera}: {ile}")
inneZnaki = [",", ".", " ", "\t", "\n", "(", ")", "-", "!"]
znaki = 9
for znaki in inneZnaki:
    ile = tekst.count(znaki)
    print(f"Znak {znaki}: {ile}")
