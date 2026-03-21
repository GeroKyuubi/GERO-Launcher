#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <GeroLauncher.h>

// --- INFO HARDWARE ---
// SDA: Pin 14 | SCL: Pin 15 (Configurazione GERO Master)
// Tasto Selezione/Uscita: Pin 25
// SD Card CS: Pin 5
// Memoria Flash: 4MB 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);

    // 1. Inizializza il Display
    Wire.begin(14, 15);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        for(;;);
    }

    // 2. Inizializza la libreria GERO
    // Impostiamo il pin 25 come tasto per tornare al Master
    Gero.begin(25);

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 20);
    display.println("APP UTENTE ATTIVA");
    display.setCursor(10, 40);
    display.println("Premi SELECT per uscire");
    display.display();
}

void loop() {
    // 3. Controllo uscita (Ritorno al Master)
    // Se l'utente preme il tasto per 2 secondi (o click deciso)
    if (Gero.checkExit()) {
        // Parametri: display per il messaggio, 5 è il CS della SD
        Gero.backToMaster(display, 5); 
    }

    // --- QUI IL CLIENTE SCRIVE IL SUO CODICE ---
    
}
