#include <LedControl.h>

#define DIN 12
#define CLK 11
#define CS  10
#define N_DM    1

LedControl dm = LedControl(DIN, CLK, CS, N_DM);

void setup() {
    Serial.begin(9600);
    Serial.println(dm.getDeviceCount());
    dm.shutdown(0, false);
    dm.setIntensity(0, 4);
    dm.clearDisplay(0);
}

void loop() {
    int i, j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            dm.setLed(0, i, j, true);
            delay(100);
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            dm.setLed(0, i, j, false);
            delay(100);
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            dm.setLed(0, i, j, true);
            delay(100);
            dm.setLed(0, i, j, false);
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            dm.setLed(0, j, i, true);
            delay(100);
            dm.setLed(0, j, i, false);
        }
    }
}