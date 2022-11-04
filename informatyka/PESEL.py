nr = input("Podaj swój numer PESEL\t")
if len(nr) == 11:
    print("tak")
else:
    print("nie")
cyfry = []
for i in int(nr):
    cyfry.append(i)

print(cyfry)

if cyfry[9] % 2 ==1:
    print("Mężczyzna")

else:
    print("Kobieta")
wagi = [1,3,7,9,1,3,7,9,1,3]
pesel10 = cyfry[0:10]
mnozenie = sum(wagi * cyfry)

# dodzielenia = 1* cyfry[0] + 3*cyfry[1] + 7*cyfry[2] + 9*cyfry[3] + 1* cyfry[4] + 3*cyfry[5] + 7*cyfry[6] + 9*cyfry[7] + 1* cyfry[8] + 3*cyfry[9]
real = mnozenie % 10
if real != 0:
    kont = 10 - real
else:
    print("Istniejesz")
if real != cyfry[10]:
    print("Forgor to exist")