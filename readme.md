# Universelle Sortierfunktion

Dieses Programm implementiert eine universelle Sortierfunktion namens `insertion_sort_universell`, die beliebige Arrays mit beliebigen Datentypen und beliebiger Sortier-Relation sortieren kann.

Die Sortierfunktion verwendet das Insertionsort-Verfahren und arbeitet mit einem generischen `void *`-Pointer und einer Vergleichsfunktion, die entscheidet, ob zwei Elemente in der gewünschten Relation stehen.

## 📁 Projektstruktur

```
universal-sorting-function/
├── src/
│   ├── main.c         # Hauptprogramm mit Beispielen
│   ├── sort.c         # Sortier-Implementierung
│   └── sort.h         # Header (Structs, Funktionsdeklarationen)
├── tests/
│   ├── test_main.c    # Test-Runner (ruft Testfunktionen auf)
│   └── test_sort.c    # Testfunktionen für das Sortieren
├── README.md          # Diese Datei
└── .gitignore         # Git-Ignore-Datei
```

## 🛠️ Kompilieren und Ausführen

### Hauptprogramm
```bash
cd src
gcc -o main main.c sort.c -I.
./main
```

### Tests kompilieren und ausführen
```bash
gcc -o test_sort tests/test_main.c tests/test_sort.c src/sort.c -lm
./test_sort
```

**Erwartete Ausgabe bei erfolgreichen Tests:**
```
All tests passed successfully.
```

## 🧪 Teststrategie

### 1. **Unit Tests für Vergleichsfunktionen**
- **Ziel**: Sicherstellen, dass jede Vergleichsfunktion korrekt funktioniert
- **Testfälle**:
  - Normale Werte (positive, negative, null)
  - Grenzwerte (MIN/MAX Werte)
  - Identische Werte
  - Edge Cases (Division durch Null bei Widerständen)

### 2. **Integration Tests für Sortierfunktion**
- **Ziel**: Überprüfen der korrekten Sortierung verschiedener Datentypen
- **Testfälle**:
  - Leere Arrays
  - Arrays mit einem Element
  - Arrays mit mehreren Elementen
  - Arrays mit Duplikaten
  - Bereits sortierte Arrays
  - Umgekehrt sortierte Arrays

### 3. **Spezielle Tests für Widerstände**
- **Ziel**: Behandlung von Sonderfällen bei der Widerstandsberechnung
- **Testfälle**:
  - **Strom = 0**: Sollte -1 zurückgeben (Fehler)
  - **Spannung = 0**: Sollte korrekt als Kurzschluss behandelt werden
  - **Beide = 0**: Sollte als Fehler behandelt werden

### 4. **Robustheitstests**
- **Ziel**: Überprüfen der Stabilität bei ungültigen Eingaben
- **Testfälle**:
  - Null-Pointer
  - Ungültige Array-Größen
  - Ungültige Element-Größen

## 📋 Voraussetzungen

- **Compiler**: Standard-C-Compiler (gcc, clang, MSVC)
- **Bibliotheken**: Nur Standard-C-Bibliothek (keine externen Abhängigkeiten)
- **Betriebssystem**: Plattformunabhängig (Windows, macOS, Linux)

## 🔍 Technische Details

### Universelle Sortierfunktion: `insertion_sort_universell`

Universelle Insertionsort-Funktion für beliebige Datentypen. Die Funktion führt Insertionsort aus, indem sie jedes Element des Arrays an die richtige Position vor ihm einfügt.

**Parameter:**
- `void *base`: Pointer auf das erste Element des zu sortierenden Arrays
- `size_t nitems`: Anzahl der Elemente im Array
- `size_t size`: Größe eines einzelnen Elements in Bytes
- `int (*compar)(const void *, const void *)`: Vergleichsfunktion

**Laufzeitkomplexität:**
- **Best Case**: O(n) - bereits sortiert
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - umgekehrt sortiert

### Vergleichsfunktionen

| Funktion | Beschreibung | Rückgabewert |
|----------|--------------|--------------|
| `compare_int_asc/desc` | Integer-Vergleich | 1 wenn a > b, 0 sonst |
| `compare_float_asc/desc` | Float-Vergleich | 1 wenn a > b, 0 sonst |
| `compare_resistance_asc/desc` | Widerstandsvergleich | 1 wenn R1 > R2, 0 sonst, -1 bei Fehler |

### Sonderfälle bei Widerständen

| Fall | Spannung | Strom | Ausgabe | Behandlung |
|------|----------|-------|---------|------------|
| Normal | ≠ 0 | ≠ 0 | `R=Wert (V=..., I=...)` | Standardberechnung |
| Kurzschluss | = 0 | ≠ 0 | `Kurzschluss - Spannung ist 0` | R = 0 |
| Unendlich | ≠ 0 | = 0 | `Fehler: Strom darf nicht 0 sein` | R = ∞ |
| Undefiniert | = 0 | = 0 | `Fehler: Strom darf nicht 0 sein` | R = ∞ |

## 📈 Beispielhafte Ausgabe

```
Widerstände vor Sortierung:
[
        R=0.018 (V=1.80, I=100.00), 
        R=0.011 (V=1.10, I=100.00), 
        Kurzschluss - Spannung ist 0 (V=0.00, I=1.50), 
        Fehler: Strom darf nicht 0 sein - Division durch Null (V=1.50, I=0.00)
];

Widerstände nach Sortierung aufsteigend:
[
        Kurzschluss - Spannung ist 0 (V=0.00, I=1.50), 
        R=0.008 (V=3.30, I=400.00), 
        R=0.022 (V=0.90, I=40.00), 
        Fehler: Strom darf nicht 0 sein - Division durch Null (V=1.50, I=0.00)
];
```


## 📚 Referenzen

- [Insertionsort - Wikipedia](https://de.wikipedia.org/wiki/Insertionsort)
- [C Standard Library qsort](https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm)
- [C Generic Selections](https://en.cppreference.com/w/c/language/generic)
