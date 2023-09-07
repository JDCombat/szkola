def s(liczba: int):  # funkcja s() opisana w zadaniu
    suma = 0
    for cyfra in str(liczba):
        suma += int(cyfra)
    return suma


def m(liczba: int):  # funkcja m() opisana w zadaniu
    if liczba <= 9:
        return 1
    else:
        return m(s(liczba)) + 1


print(m(578))  # zadanie opisane w zadaniu