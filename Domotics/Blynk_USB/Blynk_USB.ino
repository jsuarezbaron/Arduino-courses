#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); // RX, TX
#define BLYNK_PRINT SwSerial
#include <BlynkSimpleSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "YourAuthToken";

void setup()
{
SwSerial.begin(9600);
Blynk.begin(auth);
// Default baud rate is 9600. You could specify it like this:
//Blynk.begin(auth, 57600);
}

void loop()
{
Blynk.run();
}
