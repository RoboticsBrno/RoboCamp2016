# Síť z Arduin

Vytvoříme malou kruhovou síť z Arduin, která si mezi sebou budou posílat zprávy
a pomocí nich si navzájem ovládat jas LEDek připojených na pinech 3 (LED 1) a 5
(LED 2):

    +-> [Arduino 1] --> [Arduino 2] --+
    |                                 |
    |                                 |
    +-- [Arduino 4] <-- [Arduino 3] <-+

Arduina jsou propojená SW sériovou linkou na pinech 10 a 11 (RX, TX). Vždy je
propojeno RX a TX dvou sousedních Arduin. Arduina mají navíc propojené země.
Komunikační rychlost je 9600 baudů za sekundu.

Každé Arduino má svůj unikátní celočíselný identifikátor přidělený organizátory.
Tento identifikátor musí být v programu snadno změnitelný.

Arduino musí umět obsloužit následující zprávy, přičemž formát zprávy je textový,
jednotlivá pole jsou oddělena mezerou a každá zpráva je uvozena znakem 'M' a
špičaté závorky označují kladné celé číslo (bez nuly, vyjma hopů) s danou funkcí:

- `M <ID odesílatele> <ID příjemce> <počet hopů> s <číslo ledky> <jas>` -
   nastaví jas LED`<číslo ledky>` na hodnotu `<jas>` Pokud je jas mimo rozsah
   [0, 255] nebo číslo LED není 1 nebo 2, zpráva je ignorována.

- `M <ID odesílatele> <ID příjemce> <počet hopů> a <číslo ledky> <jas>` -
  potvrzovací zpráva, která oznamuje úspešné nastavení jasu LED`<číslo ledky>` na
  hodnotu `<jas>`

Posílání zpráv funguje následovně: zpráva je vždy odeslána ze sériové linky s
vlastním ID jako ID odesílatele, s ID příjemce a počtem hopů 10. 

Příjem zpráv funguje následovně: pokud se ID zprávy shoduje s vlastním ID, je
příkaz ze zprávy vykonán a na ID odesílatele se odešle zpráva potvrzující provedení.
Pokud je `<počet hopů>` 0, je zpráva ignorována. Pokud se ID zprávy neshoduje s
vlastním ID, je zpráva předána dál - a to tak, že všechna pole, kromě `<počet hopů>`
jsou nezměněna. Počet hopů se sníží o 1 (zabraňuje se nekonečnému cyklení zpráv).

Každé Arduino notifikuje na HW sériovou linku o tom co právě dělá (přeposílá zprávu,
příjmá potvrzení, vykonává příkaz). Notifikace musí být člověkem dobře čitelné.

Každé Arduino poskytuje rozhraní (z HW sériové linky) pro posílání zpráv. Formát
ovládání není specifikován, měl by být však lidsky čitelný a srozumitelný.
Vhodný formát by mohlo být `<cílové arduino> <číslo LED> <jas>`. Také by nemělo
být možné odeslat zprávu s nevalidním jasem či počtem LED.