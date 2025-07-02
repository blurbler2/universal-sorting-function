# Universelle Sortierfunktion

Dieses Programm implementiert eine universelle Sortierfunktion namens insertion_sort_universell, die beliebige Arrays mit beliebigen Datentypen und beliebiger Sortier-Relation sortieren kann.

Die Sortierfunktion verwendet das Insertionsort-Verfahren und arbeitet mit einem generischen void *-Pointer und einer Vergleichsfunktion, die entscheidet, ob zwei Elemente in der gewünschten Relation stehen.


## Projektstruktur

```
.
├── src/
│   ├── sort.c         # Sortier-Implementierung
│   └── sort.h         # Header (Structs, Funktionsdeklarationen)
├── tests/
│   ├── test_sort.c    # Testfunktionen für das Sortieren
│   └── test_main.c    # Test-Runner (ruft Testfunktionen auf)
├── examples/
│   └── main.c         # Beispiel-/Demo-Programm
├── README.md          # Diese Datei
```

## Kompilieren und Ausführen

```bash
gcc src/main.c src/sort.c -o sortprog
./sortprog
```

### Tests kompilieren und ausführen

```bash
gcc -o test_sort tests/test_main.c tests/test_sort.c src/sort.c -lm
./test_sort
```

- Die Tests geben `All tests passed successfully.` aus, wenn alles funktioniert.
- Das Beispiel zeigt die Sortierausgabe für ints, floats und Widerstände.

## Weitere Tests hinzufügen
- Neue Testfunktionen in `tests/test_sort.c` ergänzen.
- Im `tests/test_main.c` aufrufen.

## Neue Features hinzufügen
- Neue Sortier-/Vergleichslogik in `src/sort.c` implementieren und in `src/sort.h` deklarieren.

## Voraussetzungen
- Standard-C-Compiler (z.B. gcc, clang)
- Keine externen Abhängigkeiten


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

- 1 zurück, wenn das erste Element "größer" als das zweite ist (für aufsteigende Sortierung) oder anders wie in der Relation definiert.

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

- Division durch Null bei Widerstandsberechnung zB `R=inf (V=1.50, I=0.00)`

## Teststrategie

- test function

## Referenzen

- Wikipedia Insertionsort: https://de.wikipedia.org/wiki/Insertionsort

- `Compare` funktion kopiert aus https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
