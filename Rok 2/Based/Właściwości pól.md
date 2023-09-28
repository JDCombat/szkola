### Format określa sposób wyświetlania danych na ekranie niezależnie od sposobu ich przechowywania w bazie danych.
### Dla niektórych typów danych: liczba, data/godzina, waluta mamy gotowe formaty


### Zasady tworzenia własnych formatów - przy ich tworzeniu możemy użyć następujących symboli wieloznacznych
|typ danych | symbol| znaczenie
| ------    |  ----- | -------- |
| dowolny| "tekst"| |
| |\znak specjalny| > "\\>" "\\"|
| | [kolor]| czarny, zielony, niebieski, żółty, czerwony, biały, błękitny|
| tekst | @ | wyświetla wartość występującą w tym polu|
|nota | > | zamienia małe litery na duże|
| | <| zamienia duże na małe|
|data | d | 1-31|
| |dd|01-31|
| |ddd|pią|
| |dddd|piątek|
| |m|1-12|
| |mm|01-12|
| | mmm|wrz|
| | mmmm | wrzesień
| | r | 1-366(numer dnia roku)|
| | rr | 23 (rok skrócony)|
| | rrr | 2023|
| | h | 0-23|
| | hh | 00-23|
| | n | 0-59(minuty)|
| | nn | 00-59|
| | s | 0-59|
| | ss | 00-59|
| liczba, waluta | # | Dowolna cyfra która może być wprowadzona |
| autonumerowanie | 0 | Dowolna która musi być wprowadzona |
| | % | Wyświetla liczbę w procentach |

### Tworzenie formatu dla tekstu, noty
Składa się z dwóch części oddzielonych średnikiem pierwsza część formatuje pole z zawartością drugie puste

### Dla liczby
4 części oddzielone średnikami. Pierwsza formatuje wartość dodatnią, druga wartość ujemną, trzecia wartość zero, czwarta wartość pustą
### dla pola tak/nie
Rozpoczyna się od średnika, ma dwie części. Pierwsza do prawdy druga do fałszu

### Maska wprowadzania - wymusza sposób wprowadzania danych do tabeli. Przy jej tworzeniu używamy symboli:
- 0 - zastępuje cyfrę od 0-9 która usi być wprowadzona znak + i - są niedozwolone
- 9 - zastępuje cyfrę od 0-9 która może być wprowadzona znak + i - jest niedozwolony
- \# - cyfra lub spacja która może być wprowadzona, znak + i - są dozwolone
- L - litera od a-z która musi być wprowadzona
- ? - zastępuje literę od a-z która może być wprowadzona
- A - zastępuje literę lub cyfrę która musi być wprowadzona
- a - ---------      ""      --------- może być wprowadzona
- & - dowolny znak który musi być wprowadzony
- C - --------  "" ------MOŻE ------- "" ------
- > - małe na duże
- < - na odfrut
- \ - symbol na zwykły
