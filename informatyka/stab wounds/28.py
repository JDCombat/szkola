n = 3333

lista = [i for i in range(1, n + 1)]


def flawiusz(lista: list, start: int):
    if len(lista) <= 1:
        return lista[0]
    else:
        tmp = len(lista)
        if start % 2 == 0:
            lista = [i for inum, i in enumerate(lista) if inum % 2 == 0]
        else:
            lista = [i for inum, i in enumerate(lista) if inum % 2 != 0]
        if (tmp - start) % 2 == 0:
            start = 0
        else:
            start = 1
        return flawiusz(lista, start)


print(flawiusz(lista, 0))