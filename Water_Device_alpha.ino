#define HUMIDITY_SENSORS  1
#define WATERING_THRESHOLD 5

// relay states for digitalwrite
#define RELAY_ON 0
#define RELAY_OFF 1

int relay_pins[HUMIDITY_SENSORS] = {2};
int Humidity_Pins[HUMIDITY_SENSORS] = {0};

void setup() {
  // setup serial
 Serial.begin(9600);

  for (int i = 0; i < HUMIDITY_SENSORS; ++i)
  {
    // Turn off all pumps
    digitalWrite(relay_pins[i], RELAY_OFF);  
    pinMode(relay_pins[i], OUTPUT);
    
  }
  delay(4000);
}

void loop() {

  for (int i =0; i < HUMIDITY_SENSORS; ++i)
  {
    int val = analogRead(Humidity_Pins[i]);
    delay(3000);
    Serial.print(i+1);
    Serial.print(":");
    Serial.println(val);   

    if ((10-(val/100)) < WATERING_THRESHOLD)
    {
      digitalWrite(relay_pins[i], RELAY_ON);// set the Relay ON
    }
    else
    {
      digitalWrite(relay_pins[i], RELAY_OFF);// set the Relay OFF
    }
  }
}
