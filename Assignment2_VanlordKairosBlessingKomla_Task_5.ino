
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};   
int numSegments = 7;
 

byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  
    {0, 1, 1, 0, 0, 0, 0},  
    {1, 1, 0, 1, 1, 0, 1},  
    {1, 1, 1, 1, 0, 0, 1},  
    {0, 1, 1, 0, 0, 1, 1},   
    {1, 0, 1, 1, 0, 1, 1},   
    {1, 0, 1, 1, 1, 1, 1},   
    {1, 1, 1, 0, 0, 0, 0},   
    {1, 1, 1, 1, 1, 1, 1},   
    {1, 1, 1, 1, 0, 1, 1},   
};
 
 
int buzzerPin = 8;
//int numSegments = 7;
 
// showDigit function 
void showDigit(int n) {
    if(n < 0 || n > 9)return;

    for(int i=0; i < numSegments; i++){
      digitalWrite(segmentPins[i], digits[n][i]);
    }
}
 
void setup() {
    Serial.begin(9600);
 
    pinMode(buzzerPin, OUTPUT);          // for the buzzer
 
    for (int i = 0; i < numSegments; i++) {
        pinMode(segmentPins[i], OUTPUT);      // for each segment
    }
 
    Serial.println("=== Count Sequence Beginning ===");
 
    int count = 9;
    while (count>0) {
    Serial.print("Counting: ");
    Serial.println(count);
 
        showDigit(count);
 
        tone(buzzerPin, 500, 500);     // short beep
    
delay(1000);
count = count - 1;
    }

showDigit(0);
tone(buzzerPin, 1000, 1000);         
// longer completion tone
Serial.println("=== Count Sequence Complete ===");
}
void loop() { }