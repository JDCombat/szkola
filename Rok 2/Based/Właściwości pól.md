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
