# Projektstatus Snapshot – SenseModule

© Marcel Sauder
Datum: 2026-01-28

**Stand:** Core-Testphase abgeschlossen (Speicherung ausgenommen)

## Projekt

SenseModule

## Plattform

ESP32
Arduino Framework
PlatformIO

## Build-Status

clean
stabil
reproduzierbar

## Teststatus

Die Core-Testphase ist abgeschlossen.
Die Hardware-Testphase ist abgeschlossen, mit Ausnahme der persistenten Speicherung.

Alle getesteten Komponenten laufen gemeinsam stabil im Dauerbetrieb.
Es bestehen keine offenen funktionalen Defekte im aktuellen Scope.

## Aktueller Core-Funktionsumfang (verifiziert)

### RTC

DS3231 integriert und stabil
– Nur Lesen
– Keine Zeitsetzung
– Keine NTP- oder Wi-Fi-Abhängigkeit

### Sensoren

SHT3x (I²C) stabil
DS18B20 (1-Wire) stabil

### Display

SSD1306 OLED 128×32 (I²C)
– Rein darstellend
– Keine Logik
– Keine Interaktion

### Systemverhalten

– Gemeinsamer Betrieb aller Komponenten stabil
– Keine Buskonflikte
– Keine Race Conditions
– Keine Seiteneffekte
– Wiederholbare Initialisierung

## Architekturprinzipien (fix und verifiziert)

– Sensoren liefern ausschliesslich Rohdaten
– RTC ist ausschliesslich Zeitquelle
– Display ist passiv und zustandslos
– Zentrale Initialisierung in setup()
– Keine versteckten Abhängigkeiten zwischen Modulen
– Keine impliziten Initialisierungsreihenfolgen

## Speicher und Logging

– SD-Karten und SD-Reader vollständig verworfen

### Externer Speicher

– Entscheidung für externen SPI-Flash getroffen
– Baustein: W25Q64
– Betriebsspannung: 3,3 V

Hardware noch nicht eingetroffen.
Keine Implementierung ohne reale Hardware.

### Übergangslösung

Bis zum Eintreffen der Hardware:
– Temporäre Pufferung im RAM vorgesehen
– Statischer, deterministischer Ringbuffer
– Keine dynamische Speicherallokation

## Explizit gestrichen (final)

– SD-Karte
– 5-V-Speichermodule
– NTP
– Wi-Fi-Zeitabgleich

## Projektstatus

– Core-Funktionalität: abgeschlossen
– Testphase Core: abgeschlossen
– Hardware-Testphase Core: abgeschlossen
– Speicheranbindung: ausstehend (hardwareabhängig)

## Nächster Entwicklungsblock

– Definition des RAM-Ringbuffers
– Nach Eintreffen der Hardware:
– SPI-Anbindung W25Q64
– Persistente Speicherung
– Vorbereitung für späteren Export

Danach:
Freeze
Dokumentation
Versionierung

## Snapshot

Referenzimplementierung gesichert:
`main_core_sensors_rtc_display_ok.cpp`
