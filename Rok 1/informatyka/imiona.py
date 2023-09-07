imiona = ["Jakub", "Mikołaj", "Bartosz"]
imiona2 = ["Filip", "Oskar", "Bartosz"]
wszystkieimiona = imiona + imiona2

print(wszystkieimiona)
wszystkieimionabezpowtorzen = list(set(imiona + imiona2))
print(wszystkieimionabezpowtorzen)

posortowane = sorted(wszystkieimionabezpowtorzen)
print(posortowane)

posortowaneR = sorted(wszystkieimionabezpowtorzen, reverse=True)
print(posortowaneR)
