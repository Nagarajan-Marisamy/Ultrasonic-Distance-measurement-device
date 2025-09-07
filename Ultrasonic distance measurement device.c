#include <Wire.h> 

#include <U8g2lib.h> 

#define TRIG_PIN 6 

#define ECHO_PIN 7 

#define BUTTON_PIN 2   

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); 

intunitMode = 0;   

bool buttonPressed = false; 

float lastDistance = -1; 

float smoothedDistance = -1; 

void setup() { 

  pinMode(TRIG_PIN, OUTPUT); 

  pinMode(ECHO_PIN, INPUT); 

  pinMode(BUTTON_PIN, INPUT_PULLUP); 

  Serial.begin(115200); 

  u8g2.begin(); 

 // **Startup Screen** 

  u8g2.clearBuffer(); 

  u8g2.setFont(u8g2_font_10x20_tf); 

  u8g2.setCursor(10, 20); 

  u8g2.print("ULTRASONIC"); 

  u8g2.setCursor(10, 40); 

  u8g2.print("DISTANCE"); 

  u8g2.setCursor(10, 60); 

  u8g2.print("METER"); 

  u8g2.sendBuffer(); 

  delay(2000); 

} 

void loop() { 

  float distance = measureDistance(); 

 // **Detect Sudden Object Change & Reset Filter** 

  if (distance == -1) { 

    lastDistance = -1; 

    smoothedDistance = -1; 

  } else { 

    if (lastDistance != -1 && abs(distance - lastDistance) > 10) {   

      smoothedDistance = distance;  // Skip smoothing if object moves suddenly 

    } else { 

      smoothedDistance = (smoothedDistance == -1) ? distance : (0.7 * smoothedDistance) + (0.3 * distance); 

 } 

    lastDistance = distance; 

  } 

 // **Button Handling for Unit Switch** 

  if (digitalRead(BUTTON_PIN) == LOW) {   

    delay(50); 

    if (digitalRead(BUTTON_PIN) == LOW && !buttonPressed) {   

      unitMode = (unitMode + 1) % 4;   

      buttonPressed = true; 

    } 

  } else { 

    buttonPressed = false; 

  } 

displayDistance(smoothedDistance); 

} 

// **Function to Measure Distance** 

float measureDistance() { 

  constintnumSamples = 5; 

  float distances[numSamples]; 

for (inti = 0; i<numSamples; i++) { 

    digitalWrite(TRIG_PIN, LOW); 

    delayMicroseconds(2); 

digitalWrite(TRIG_PIN, HIGH); 

delayMicroseconds(10); 

 digitalWrite(TRIG_PIN, LOW); 

long duration = pulseIn(ECHO_PIN, HIGH, 30000);  // Adjusted timeout 

    float dist = (duration > 0) ? duration * 0.034 / 2 : -1;   

distances[i] = dist; 

    delay(5); 

  } 

float medianDistance = getMedian(distances, numSamples); 

 // **Detect "No Object" Condition** 

  if (medianDistance == -1 || medianDistance> 400) { 

    return -1;   

  } 

  return medianDistance; 

} 

// **Helper Function: Median Filtering** 

float getMedian(float arr[], int size) { 

  for (inti = 0; i< size - 1; i++) { 

    for (int j = i + 1; j < size; j++) { 

      if (arr[i] >arr[j]) { 

        float temp = arr[i]; 

arr[i] = arr[j]; 

        arr[j] = temp; 

      } 

    } 

  } 

  return arr[size / 2];   

} 

// **Display Distance on OLED** 

void displayDistance(float distance) { 

  u8g2.clearBuffer(); 

   u8g2.drawBox(0, 0, 128, 15); 

  u8g2.setFont(u8g2_font_6x12_tf); 

  u8g2.setDrawColor(0); 

  u8g2.setCursor(25, 10); 

  u8g2.print("DISTANCE METER"); 

  u8g2.setDrawColor(1); 

if (distance == -1) { 

    u8g2.setFont(u8g2_font_10x20_tf); 

    u8g2.setCursor(25, 40); 

    u8g2.print("NO OBJECT");  // Now updates immediately when object disappears 

  } else { 

    u8g2.setFont(u8g2_font_logisoso32_tf); 

float displayValue; 

    const char* unitText; 

 switch (unitMode) { 

      case 0: displayValue = distance; unitText = "cm"; break; 

      case 1: displayValue = distance * 0.3937; unitText = "in"; break; 

      case 2: displayValue = distance / 100.0; unitText = "m"; break; 

      case 3: displayValue = distance * 0.0328; unitText = "ft"; break; 

    } 

intxPos = (displayValue>= 100) ? 5 : 20;   

    u8g2.setCursor(xPos, 55); 

    if (displayValue>= 10) { 

      u8g2.print((int)displayValue); 

    } else { 

      u8g2.print(displayValue, 1); 

    } 

 u8g2.print(unitText); 

  } 

 u8g2.sendBuffer(); 

} 
