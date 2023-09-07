n=int(input('Podaj liczbe\t'))

def silnia(n):
    if n == 0:
        return 1
    else:
        return n*silnia(n-1)
wynik = silnia(n)
print(f"silnia({n}) to {wynik}")

