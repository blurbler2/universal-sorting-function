# Universelle Sortierfunktion

Dieses Programm implementiert eine universelle Sortierfunktion namens insertion_sort_universell, die beliebige Arrays mit beliebigen Datentypen und beliebiger Sortier-Relation sortieren kann.

Die Sortierfunktion verwendet das Insertionsort-Verfahren und arbeitet mit einem generischen void *-Pointer und einer Vergleichsfunktion, die entscheidet, ob zwei Elemente in der gewünschten Relation stehen.

## Compilieren und Programm ausführen

```bash
gcc main.c sort.c -o sortprog
./sortprog
```

## Überblick

### Universelle Sortierfunktion: `insertion_sort_universell`

Universelle Insertionsort-Funktion für beliebige Datentypen. Die Funktion führt Insertionsort aus, indem sie jedes Element des Arrays an die richtige Position vor ihm einfügt.
Zum Verschieben und Vergleichen der Elemente wird memcpy und der Funktionszeiger compar benutzt.

Parameter:
- **void *base**: Pointer auf das erste Element des zu sortierenden Arrays.

- **size_t nitems**: Anzahl der Elemente im Array.

- **size_t size**: Größe eines einzelnen Elements in Bytes.

- **int (*compar)(const void *, const void *)**: Vergleichsfunktion, die zwei Elemente vergleicht.


### Vergleichsfunktionen: 

**`int compare_int_asc(const void* a, const void* b)`**
Vergleicht zwei unsigned int-Werte auf < (aufsteigend).

**`int compare_float_asc(const void *a, const void *b)`**
Vergleicht zwei float-Werte auf < (aufsteigend).

**`int compare_float_desc(const void *a, const void *b)`**
Vergleicht zwei float-Werte auf >= (absteigend).

**`int compare_resistance_asc(const void* a, const void* b)`**
Vergleicht zwei struct Resistance nach voltage / current (aufsteigend).

**`int compare_resistance_desc(const void* a, const void* b)`**
Vergleicht zwei struct Resistance nach voltage / current (absteigend).

Die Vergleichsfunktion liefert:

- 1 zurück, wenn das erste Element „größer“ als das zweite ist (für aufsteigende Sortierung) oder anders wie in der Relation definiert.

- 0 sonst.

Die Sortierfunktion ordnet das Array so, dass für alle Elemente gilt:
- data[i] R data[i+1], wobei R die gewünschte Relation ist.

## Datenstrukturen und Testdaten

Für das Testprogramm werden folgende Datentypen und Relationen verwendet:

| Datenstruktur       | Relation R (Sortierreihenfolge)                            |
| ------------------- | ---------------------------------------------------------- |
| `unsigned int`      | `<` (aufsteigend)                                          |
| `float`             | `>=` (absteigend oder gleich)                              |
| `struct Resistance` | Sortiert nach `voltage / current` (Widerstand) aufsteigend |



## Beispielhafte Ausgabe

Vor und nach dem Sortieren werden die Arrays ausgegeben, sodass der Sortiererfolg sichtbar wird.

## Technische Details

- Für das Einfügen von Elementen innerhalb des Arrays wird eine temporäre Variable mit malloc erzeugt.

- Der memcpy-Befehl kopiert Bytes, um Elemente beliebigen Typs zu verschieben.

- Die Vergleichsfunktion muss konsistent zur gewünschten Relation sein und 0 oder 1 (bzw. auch negativen/positiven Wert) liefern, abhängig von der Implementierung.

## Referenzen

- Wikipedia Insertionsort: https://de.wikipedia.org/wiki/Insertionsort

- `Compare` funktion kopiert aus https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
