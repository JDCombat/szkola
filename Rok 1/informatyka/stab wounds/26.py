file = open('./pliki/odwrotna.txt', 'r')
lista = file.read().strip('\n').split(' ')
znaki = ['+', '-', 'x', '/']
temp = []

for el in lista:
    if el not in znaki:
        temp.append(el)
    else:
        a = int(temp[-1])
        b = int(temp[-2])
        temp.pop(-1)
        temp.pop(-1)
        if el == '+':
            temp.append(b + a)
        elif el == '-':
            temp.append(b - a)
        elif el == 'x':
            temp.append(b * a)
        else:
            temp.append(b / a)

print(temp[0])