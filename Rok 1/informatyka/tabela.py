def koloruj(k, text):
    return f"\033[{k}m{text}\033[0m"


n = int(input("podaj liczbe:\t"))

for x in range(1, n + 1):
    for y in range(1, n + 1):

        wynik = x * y

        if wynik < 10:
            print(koloruj(91, wynik), end=" ")
        elif wynik < 20:
            print(koloruj(92, wynik), end=" ")
        elif wynik < 30:
            print(koloruj(93, wynik), end=" ")
        elif wynik < 40:
            print(koloruj(94, wynik), end=" ")
        elif wynik < 50:
            print(koloruj(95, wynik), end=" ")
        elif wynik < 60:
            print(koloruj(96, wynik), end=" ")
        elif wynik < 70:
            print(koloruj(97, wynik), end=" ")
        elif wynik < 80:
            print(koloruj(98, wynik), end=" ")
        elif wynik < 90:
            print(koloruj(99, wynik), end=" ")
        elif wynik < 100:
            print(koloruj(100, wynik), end=" ")
        elif wynik < 110:
            print(koloruj(101, wynik), end=" ")

        else:
            print(wynik, end=" ")
    print()