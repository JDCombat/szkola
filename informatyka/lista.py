import os
f = open(".\szkola\informatyka\lista.txt", "r")
txt = f.read()
split = txt.split("_")
print(split)
path = os.getcwd()
os.makedirs("1p")
for i in split:
    if i == "gr1" or "gr2":
        os.makedirs(i)
    else