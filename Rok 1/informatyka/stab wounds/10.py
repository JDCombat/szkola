tab = [8894, 36]
for x in tab:
    if x <40 and x % 4 == 0:
        print("Jestem mała i dzielę się przez 4", end=";")
    elif x <40 and x % 4 != 0:
        print("Jestem mała i nie dzielę się przez 4", end=";")
    elif x >= 40 and x%4 == 0:
        print("Jestem duża i dzielę się przez 4", end=";")
    elif x >= 40 and x%4 != 0:
        print("Jestem duża i nie dzielę się przez 4", end=";")
