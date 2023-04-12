def fuu(p, k):
    w = pow((p/100), k)

    if w >= 0.4 and w < 0.5:
        return 2
    elif w >= 0.5 and w < 0.75:
        return 3
    elif w>= 0.75 and w< 0.85:
        return 4
    elif w>= 0.85 and w < 0.95:
        return 5
    elif w>=0.95:
        return 6

print(fuu(20,0.5), end=";")
print(fuu(31, 0.3), end=";")
print(fuu(49,0.2), end=";")
print(fuu(89,1.5))
