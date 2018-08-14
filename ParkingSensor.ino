int HIJAU=5;
int KUNING=4;
int MERAH=3;
int LINE=A2;
int BUZZER=7;
int BUT=12;
int MOTOR1=9;
int MOTOR2=10;
int count;
int bin;
int res_value;
int RES=A5;
   
void setup()
{
 pinMode (HIJAU,OUTPUT);
 pinMode (KUNING,OUTPUT);
 pinMode (MERAH,OUTPUT);
 pinMode (BUZZER,OUTPUT);
 pinMode (MOTOR1,OUTPUT);
 pinMode (MOTOR2,OUTPUT);
 pinMode (BUT,INPUT);
 pinMode (LINE,INPUT);
 pinMode (RES,INPUT);
 Serial.begin(9600);     
}

void loop()
{
  int keadaan=digitalRead(BUT);
  int sens=analogRead(LINE);
  int res_value=analogRead(RES);
  res_value = map(res_value, 0, 1023, 0, 255);
  Serial.print("res_value = ");
  Serial.print(res_value);
  Serial.print("| bin = ");
  Serial.print(bin);
  Serial.print("|SENS = ");
  Serial.println(sens);

  if(keadaan==HIGH)
  {
    Serial.println("--------------GANTI GIGI--------------");
    count++;
    Serial.println(count);
    digitalWrite(KUNING, HIGH);
  }
  else
  {
    digitalWrite(KUNING, LOW);
  }
  bin=count%2;
  
  if (bin==0)
  {
    digitalWrite(BUZZER, LOW);
    digitalWrite(HIJAU,HIGH);
    digitalWrite(MERAH,LOW);
    analogWrite (MOTOR1,res_value);
    digitalWrite(MOTOR2,LOW);
  }
  else if (bin==1)
  {
    digitalWrite(MERAH,HIGH);
    digitalWrite(HIJAU,LOW);
    if (sens<500)
    {
      digitalWrite(BUZZER,HIGH);
      analogWrite (MOTOR1,0);
      analogWrite (MOTOR2,0);
    }
    else
    {
      digitalWrite(BUZZER, LOW);
      digitalWrite(MOTOR1,LOW);
      analogWrite (MOTOR2,255);
    }
  }
  delay(300);
}
   

