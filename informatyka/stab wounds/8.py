import math


a = int(input())
b = int(input())
c = int(input())


# funckja
def f(x: float):
    return a * (x ** 2) + b * x + c




delta = (b ** 2) - (4 * a * c)  # b^2 -4ac

if a == 0:  
    print("to nie jest równanie kwadratowe")

if delta < 0:
    print("brak miejsc zerowych")
elif delta == 0:
    print((- b - (math.sqrt(delta))) / (2 * a))  # -b - sqrt(delta)/2a
else:
    print((- b - (math.sqrt(delta))) / (2 * a))  # -b - sqrt(delta)/2a
    print((- b + (math.sqrt(delta))) / (2 * a))  # -b + sqrt(delta)/2a