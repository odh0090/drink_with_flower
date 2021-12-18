bool cup_filled = false;
int count = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int water_lv = analogRead(A0);
  int press_lv = analogRead(A1);
  
  if (water_lv > 500){
    cup_filled = true;
  }

  if (cup_filled == true && water_lv < 100) {
    Serial.println("leaf");
    count = count + 1;
    cup_filled = false;
    delay(1000);
  }

  if (count >= 1 && press_lv > 500) {
    for (int i = 0; i < count; i=i+1){
      Serial.println("flower");
    }
    count = 0;
  }
  
//  Serial.println(water_lv);
//  Serial.println(press_lv);
  delay(500);
}
