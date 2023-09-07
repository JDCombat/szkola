f = open("C:\git\szkola\informatyka\stab wounds\pliki\co_trzecia_parzysta.txt", 'r')

l=[int(x) for y in f for x in y.split() if int(x)%2==0]
print(l[2::3])