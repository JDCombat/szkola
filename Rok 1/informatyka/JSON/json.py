import json

plik = open('.\szkola\informatyka\json\Countries.json', encoding="UTF-8")
tekst = plik.read()

dane = json.loads(tekst)

for obiekt in dane:
    print(obiekt["name"])

kontynent = {}

for i in dane:
    if i['continent'] not in kontynent.keys():
        kontynent[i['continent']] = []
    kontynent[i['continent']].append(i["name"])

print(json.dumps(kontynent,indent=3))
with open('wyniki.json', 'w') as pl:
    json.dump(kontynent, pl, ensure_ascii=False).encode('UTF-8')