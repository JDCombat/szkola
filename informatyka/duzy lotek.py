import random
def koloruj(k, text):
    return f"\033[{k}m{text}\033[0m"
saldo = 0
num = []
while(True):
    print(f"\033[0m")
    for i in range(6):
        inp = int(input(f"Podaj {i +1} liczbę w przedziale 1 do 49 \n"))
        while inp < 1 or inp > 49:
            inp = int(input("BŁĄD!Podaj liczbę od 1 do 49: \n"))
        else:
            num.append(inp)

    ran = random.sample(range(1, 49), 6)
    count = 0
    print("Twoje liczby: ")
    for i in range(6):
        if num[i] in ran:
            print(f"\033[0;32m{num[i]}")
            count += 1
        else:
            print(f"\033[0;31m{num[i]}")
    print(f"\033[0m")
    if count == 6:
        print(f"\033[0;32mWygrałeś 1000000 PLN")
        saldo += 1000000
    elif count == 5:
        print(f"\033[0;32mWygrałeś 3500 PLN")
        saldo += 3500
    elif count == 4:
        print(f"\033[0;32mWygrałeś 1000 PLN")
        saldo += 1000
    elif count == 3:
        print(f"\033[0;32mWygrałeś 10 PLN")
        saldo += 10
    elif count < 3:
        print(f"\033[0;31mWygrałeś 0 PLN")


    if saldo <= 0:
        print("\033[0;31m")
    else:
        print(f"\033[0;32m")

    print(f"Masz Teraz {saldo} PLN")
    print("\033[0m")
    check = input("Czy chcesz kontynuować? Kolejny los kosztuje 5 PLN. Y/N \t")
    if check == "Y" or check == "y":
            saldo -= 5
            continue
    else:
        break