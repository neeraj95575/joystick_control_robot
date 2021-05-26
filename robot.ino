#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define EN1 2
#define EN2 3

int pot11 = A0;
int pot12 = A1;
int pot22 = A2;

void setup() 
{  
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
 int value11 = analogRead(pot11);
 int value12 = analogRead(pot12);
 int val11 = map(value11, 5, 974, 0, 255);
 int val12 = map(value12, 19, 1006, 0, 255);
 int value22 = analogRead(pot22);
 int val22 = map(value22, 0, 1023, 255,0);
 
 analogWrite(EN1,val22);// control speed of motor 1
 analogWrite(EN2,val22);// control speed of motor 2
 
if(val12 <= 80) //forward
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


if(val12 >= 200) //backward
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

if(val12>= 120 && val12<=130)// stop
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

if(val11 <= 80) //left
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

if(val11>= 200)
{
  digitalWrite(IN1, LOW); //right
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

}
