lista = list(range(1,101))
print(lista)


L = ['a', ['bb', 3, ['ddd', [2, 4]], 7], 'e']
print(L[1][2][0])

L4 = ['a', 'b', 'c', 'd', 'e', 'f']
print(L4[1:5])

L4.append('z')

L4.append(L)
print(L4)

L4.insert(-1, 'x')
print(L4)

L4.pop(-1)
print(L4)

L4 *= 3
L4.insert(1, 'nigga')
print(L4)

L4.remove('f')
print(L4)

while 'f' in L4:
    L4.remove('f')

print(L4)