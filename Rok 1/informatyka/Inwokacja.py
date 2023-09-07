import string
from string import ascii_lowercase, ascii_uppercase, whitespace
f = open(".\szkola\informatyka\inwokacja.txt" , "r" , encoding  = "UTF-8")

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
ileWierszy = 0
polskieLW = ("ąęćłóńżź")
polskieMW = ("ĄĘĆŁÓŃŻŹ")
alfabet = string.ascii_letters + polskieLW + polskieMW
alfabetlw = ascii_lowercase + polskieLW
alfabetMW = ascii_uppercase + polskieMW
samogłoski = ("aeiouyóąę") + ("AEIOUYÓĄĘ")
print(alfabet)



for litera in alfabetlw:
    ileWszystkich += tekst.count(litera)
    ile = tekst.count(litera)
    print(f" {litera} występuje {ile}")


print(alfabetMW)
for litera in alfabetMW:
    ileDuzych += tekst.count(litera)
    ile = tekst.count(litera)
    print(f"litera {litera}: {ile}")

for litera in alfabetlw:
    ileMalych += tekst.count(litera)
    ile = tekst.count(litera)
    print(f"Litera {litera}: {ile}")
inneZnaki = (",.()-!?")
znaki = 9
for znaki in inneZnaki:
    ileInnych += tekst.count(znaki)
    ile = tekst.count(znaki)
    print(f"Znak {znaki}: {ile}")

for litera in samogłoski:
    ileSamoglosek += tekst.count(litera)
    ile = tekst.count(litera)
    print(f"Samogłoska {litera}: {ile}")

spółgłoski = ("bcćdfghjklmnprstwyzżź")
for litera in spółgłoski:
    ileSpolglosek += tekst.count(litera)
    ile = tekst.count(litera)
    print(f"Spółgłoska {litera}: {ile} ")

wiersz = "\n"
ileWierszy += tekst.count(wiersz)
print(f"W tekście występuje {ileWierszy} wierszy")

for space in whitespace:
    ile = tekst.count(space)
    ileBialych += ile

jaka = input("Jaką chcesz policzyć literę: ")
ileLiter = tekst.count(jaka)
print(f"{jaka} występuje {ileLiter} razy")

print(f"Wszystkie litery: {ileWszystkich} ")
print(f"Białe litery: {ileBialych} ")
print(f"Duże litery: {ileDuzych} ")
print(f"Inne znaki: {ileInnych} ")
print(f"Wybrana litera: {ileLiter} ")
print(f"Mała litera: {ileMalych} ")
print(f"Samogłoski: {ileSamoglosek} ")
print(f"Spółgłoski: {ileSpolglosek} ")
print(f"Wiersze: {ileWierszy} ")

