def koloruj(r,g,b,text):
    return f"\033[38;3;{r};{g};{b}m{text}]"


n = int(input('Wpisz liczbe\t'))

for x in range(1, n+1):
    for y in range(1, n+1):
        wynik = x * y
        print(wynik,end=" ")
    print()