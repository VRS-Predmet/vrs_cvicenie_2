# Náplň cvičenia
- s pomocou CubeMX vytvoriť nový projekt a nastaviť počiatočnú konfiguráciu mikrokontrolera
- v názve adresy kam vytvárame projektu sa nesmie nachádzať diakritika ani medzery (može to sposobovať problemy)!
- pokračovť v plnení úloh z predchádzajúceho cvičenia (vrs_cvicenie_1)
- predstavenie nového zadania

# CubeMX a nový projekt
### 1. vytvorenie nového STM32 projektu

<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/novy_projekt.png" width="500">
</p>

### 2. zvolenie typu MCU, ktorý chceme programovať (STM32F303K8)

<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/vyber_MCU.png" width="500">
</p>

### 3. zvolenie názvu projektu (všetko ostatné je už dobre nastavené od začiatku)

- projekt je týmto krokom vytvorený a prechádza sa do prostredia CubeMX, kde sa konfigurujú periférie MCU
<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/vyber_nazvu.png" width="350">
</p>

### 4. konfigurácia periférii MCU

- nastavenie funkcie GPIO alebo ich priradenie k periférii (podľa potreby)
<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/konfiguracia_periferii.png" width="300">
</p>

- konfigurácia konkrétnych GPIO, ktoré boli zvolené v predošlom kroku
<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/konfiguracia_periferii_2.PNG" width="750">
</p>

- v nastaveniach hodín (clock configuration) nie je nutná žiadna zmena, pretože nám stačí počiatočná konfigurácia

### 5. nastavenia súvisiace s generovaním kódu

- nastavenia, ktoré cheme nastaviť ešte pred samotným generovaním kódu

- pre každú použitú perifériu bude vygenerovaný ".c" a ".h" súbor
<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/nastavenie_generovania_3.PNG" width="450">
</p>

- zvolenie "LL - low level" knižnice
<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/nastavenie_generovania_2.PNG" width="650">
</p>

### 6. generovanie kódu

- vygenerovanie kódu
<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_5/blob/master/images/code_generation.png" width="500">
</p>



# Zadanie
- #### Toto zadanie priamo nadväzuje na zadanie z predchádzajúceho cvičenia - zadanie_cv1. Vytvorte aplikáciu pre detegovanie hrany vstupného signálu privedeného na vstup MCU pričom LED pripojená na jeho výstup bude indikovať úspešnú detekciu hrany. Vstupný signál je privedený na pin GPIOA-3. Hrana je generovaná prostredníctvom tlačidla. Výstupný signál je privedený na pin GPIOA-4.

### Úlohy:
 1. #### Vytvoriť repozitár, kde nahrajete svoj projekt z predchádzajúceho zadania.
 2. #### Pracovať s vlastným repozitárom tak, aby boli vydieť "commits" (editačné zmeny). Ideálne od celej dvojice.
 3. #### V súbore "Inc/assignment.h" definovať enum "EDGE_TYPE", ktorý bude enumerovať 3 stavy: žiadna hrana (NONE = 0), nábežná hrana (RISE = 1), dobežná hrana (FALL = 2).
 4. #### V súbore "Inc/assignment.h" deklarujte a v subore "Src/main.c" definujte funkciu "edgeDetect", ktorej úlohou je detegovať hranu (stlačenie tlačidla). Funkcia vracia hodnotu typu "EDGE_TYPE" a má dva vstupné argumenty:
 
```javascript
EDGE_TYPE edgeDetect(uint8_t pin_state, uint8_t samples);
```
  - Vstupný parameter "pin_state" predstavuje aktuálny stav vstupného pinu, na ktorom sa deteguje hrana. Nadobúda hodnotu "1" alebo "0". 
  - Vstupný parameter "samples" definuje koľkokrát v rade musí byť detegovaný nový stav vstupného pinu, aby sa to považovalo za hranu - stlačenie tlačidla.
  - Príklad: 
    - predchádzajúci stav = 0, aktuálny stav = 1, samples = 5
    - aby bola detegovaná hrana, musí sa 5-krát v rade prečítať rovnaký stav tj. 0,1,1,1,1,1 - nábežná hrana bola detegovaná
    - ak by pri čítaní zo vstupného pinu nastala situácia 0,1,1,1,0,1 - pri zmene stavu z 0 na 1 sa na vstupe vyčítala hodnota 1 len 3-krát v rade, vyhodnotí sa to ako "žiadna hrana", pretože nebola splnená podmienka.
   
5. #### Upraviť program vykonávajúci sa v "main" funkcii tak, aby LED zmenila svoj stav (On -> Off, Off -> On) len vtedy, ak bol detegovaný vami zvolený typ hrany. LED bude meniť svoj stav len ak bola detegovaná nábežná hrana alebo bude meniť svoj stav len v prípade detekcie dobežnej hrany. 

 
 <p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_1/blob/master/documents/edge_detect.png" width="2000" height="250" title="LED, button and Stm32 - circuit.">
</p>
