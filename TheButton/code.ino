#define LED_R 2
#define LED_G 3
#define LED_B 4
#define TRANSPORT 5
#define BTN 0
#define LED 1

int btnTextId;
int btnColorId;
int ledColorId;

void setup() {
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(BTN, INPUT_PULLUP);
    pinMode(TRANSPORT, OUTPUT);
    setting();
}

void setting() {

}

void loop() {
    if(digitalRead(TRANSPORT)) return;
    if(!digitalRead(BTN)) {
        led();
        while(true) {
            if(digitalRead(BTN)) break;
        }
        ledReset();
    }
}

void led() {
    digitalWrite(LED_R, (ledColorId & 1) == 1);
    digitalWrite(LED_G, (ledColorId & 2) == 2);
    digitalWrite(LED_B, (ledColorId & 4) == 4);
}

void ledReset() {
    digitalWrite(LED_R, 0);
    digitalWrite(LED_G, 0);
    digitalWrite(LED_B, 0);
}

void error() {
    long ms = millis();
    digitalWrite(TRANSPORT, 1);
    while(true) {
        if(millis() - ms > 500)
        {
            digitalWrite(TRANSPORT, 0);
            break;
        }
    }
}

void success() {
    digitalWrite(TRANSPORT, 1);
    digitalWrite(LED, 1);
}