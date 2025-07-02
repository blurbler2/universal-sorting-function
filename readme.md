# Universelle Sortierfunktion

Dieses Programm implementiert eine universelle Sortierfunktion namens `insertion_sort_universell`, die beliebige Arrays mit beliebigen Datentypen und beliebiger Sortier-Relation sortieren kann.

Die Sortierfunktion verwendet das Insertionsort-Verfahren und arbeitet mit einem generischen `void *`-Pointer und einer Vergleichsfunktion, die entscheidet, ob zwei Elemente in der gewünschten Relation stehen.

## 📁 Projektstruktur

```
universal-sorting-function/
├── src/
│   ├── main.c         # Hauptprogramm mit Standard-Beispielen
│   ├── main_10.c      # Beispielprogramm für 1/0-Variante (Aufgabenstellung)
│   ├── sort.c         # Sortier-Implementierung (beide Varianten)
│   └── sort.h         # Header (Structs, Funktionsdeklarationen)
├── tests/
│   ├── test_main.c    # Test-Runner (ruft Testfunktionen auf)
│   ├── test_sort.c    # Testfunktionen für das Sortieren
│   └── test_sort.h    # Header für Testfunktionen
├── README.md          # Diese Datei
└── .gitignore         # Git-Ignore-Datei
```

## 🛠️ Kompilieren und Ausführen

### Standard-Hauptprogramm (-1/0/1 Variante)
```bash
cd src
gcc -o main main.c sort.c -I.
./main
```

### 1/0-Variante (Aufgabenstellung)
```bash
cd src
gcc -o main_10 main_10.c sort.c -I.
./main_10
```

### Tests kompilieren und ausführen
```bash
gcc -o test_sort tests/test_main.c tests/test_sort.c src/sort.c -lm
./test_sort
```

**Erwartete Ausgabe bei erfolgreichen Tests:**
```
🎉 ALLE TESTS ERFOLGREICH BESTANDEN!
📊 Testabdeckung: 100%
✅ Unit Tests: 6/6 bestanden
✅ Integration Tests: 6/6 bestanden
✅ Widerstands-Tests: 3/3 bestanden
✅ Robustheits-Tests: 2/2 bestanden
✅ Performance-Tests: 2/2 bestanden
✅ Legacy Tests: 1/1 bestanden
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

### 5. **Performance Tests** (Optional)
- **Ziel**: Überprüfen der Laufzeitkomplexität
- **Testfälle**:
  - Verschiedene Array-Größen (10, 100, 1000, 10000 Elemente)
  - Best-Case, Average-Case, Worst-Case Szenarien

### Beispiel:
```c
// In sort.c
int compare_string_asc(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b) > 0;
}

// In sort.h
int compare_string_asc(const void* a, const void* b);

// In test_sort.c
void test_string_sort() {
    // Test-Implementierung
}
```

## 📋 Voraussetzungen

- **Compiler**: Standard-C-Compiler (gcc, clang, MSVC)
- **Bibliotheken**: Nur Standard-C-Bibliothek (keine externen Abhängigkeiten)
- **Betriebssystem**: Plattformunabhängig (Windows, macOS, Linux)

## 🔍 Technische Details

### Sortierfunktionen

#### Standard-Variante: `insertion_sort_universell` (-1/0/1)
Universelle Insertionsort-Funktion für beliebige Datentypen mit Standard-C-Interface.

**Parameter:**
- `void *base`: Pointer auf das erste Element des zu sortierenden Arrays
- `size_t nitems`: Anzahl der Elemente im Array
- `size_t size`: Größe eines einzelnen Elements in Bytes
- `int (*compar)(const void *, const void *)`: Vergleichsfunktion

#### Aufgabenstellung-Variante: `insertion_sort_10` (1/0)
Variante, die exakt den Anforderungen der Aufgabenstellung entspricht.

**Parameter:**
- `void *base`: Pointer auf das erste Element des zu sortierenden Arrays
- `size_t nitems`: Anzahl der Elemente im Array
- `size_t size`: Größe eines einzelnen Elements in Bytes
- `int (*compar)(const void *, const void *)`: Vergleichsfunktion (gibt 1/0 zurück)

**Laufzeitkomplexität:**
- **Best Case**: O(n) - bereits sortiert
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - umgekehrt sortiert

### Vergleichsfunktionen

#### Standard-Vergleichsfunktionen (-1/0/1)

| Funktion | Beschreibung | Rückgabewert |
|----------|--------------|--------------|
| `compare_int_asc/desc` | Integer-Vergleich | -1 wenn a < b, 1 wenn a > b, 0 wenn gleich |
| `compare_float_asc/desc` | Float-Vergleich | -1 wenn a < b, 1 wenn a > b, 0 wenn gleich |
| `compare_resistance_asc/desc` | Widerstandsvergleich | -1 wenn R1 < R2, 1 wenn R1 > R2, 0 wenn gleich, -1 bei Fehler |

#### 1/0-Vergleichsfunktionen (Aufgabenstellung)

| Funktion | Beschreibung | Rückgabewert |
|----------|--------------|--------------|
| `compare_int_asc_10` | Integer aufsteigend (<) | 1 wenn a < b, 0 sonst |
| `compare_float_desc_10` | Float absteigend (>=) | 1 wenn a >= b, 0 sonst |
| `compare_resistance_asc_10` | Widerstand aufsteigend (R1 < R2) | 1 wenn R1 < R2, 0 sonst |

### Sonderfälle bei Widerständen

| Fall | Spannung | Strom | Ausgabe | Behandlung |
|------|----------|-------|---------|------------|
| Normal | ≠ 0 | ≠ 0 | `R=Wert (V=..., I=...)` | Standardberechnung |
| Kurzschluss | = 0 | ≠ 0 | `Kurzschluss - Spannung ist 0` | R = 0 |
| Unendlich | ≠ 0 | = 0 | `Fehler: Strom darf nicht 0 sein` | R = ∞ |
| Undefiniert | = 0 | = 0 | `Fehler: Strom darf nicht 0 sein` | R = ∞ |

## 📈 Beispielhafte Ausgabe

### Standard-Variante (main.c)
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

### 1/0-Variante (main_10.c)
```
=== 1/0-VARIANTE DER SORTIERFUNKTION (Aufgabenstellung) ===

1. INT ARRAY - Relation: < (aufsteigend)
==========================================
Ints vor Sortierung:               [57, 15, 25, 96, 85, 48, 52, 83, 63, 29, 18, 53]
Ints nach Sortierung (<):          [15, 18, 25, 29, 48, 52, 53, 57, 63, 83, 85, 96]
Verifizierung: ✅ Korrekt sortiert

2. FLOAT ARRAY - Relation: >= (absteigend)
==========================================
Floats vor Sortierung:                  [ 52.80, 86.00, 58.50, 67.20, 73.90, 13.90, 69.60, 49.60, 72.20, 57.30, 90.60, 54.10 ]
Floats nach Sortierung (>=):            [ 90.60, 86.00, 73.90, 72.20, 69.60, 67.20, 58.50, 57.30, 54.10, 52.80, 49.60, 13.90 ]
Verifizierung: ✅ Korrekt sortiert
```


## 📚 Referenzen

- [Insertionsort - Wikipedia](https://de.wikipedia.org/wiki/Insertionsort)
- [C Standard Library qsort](https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm)
- [C Generic Selections](https://en.cppreference.com/w/c/language/generic)
