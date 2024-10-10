#include<Servo.h>

int trig = 23,echo = 24;

Servo m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19,m20,m21,m22;

int agl=90,agl2=90,ct = 1,a2 = 90,a3 = 90,a4 = 90,a5 = 90,a6 = 90,a7 = 90,a8 = 90,a9 = 90,a10 = 90,a11 = 90,a12 = 90,a13 = 90,a14 = 90,a15 = 90,a16 = 90,a17 = 90,a18 = 90,a19 = 90,a20 = 90,a21 = 90,a22 = 90;

void setup() 
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  //downlegs
  m2.attach(2);
  m3.attach(3);
  m4.attach(4);
  m5.attach(5);
  m6.attach(6);
  m7.attach(7);
  
  m8.attach(8);
  m9.attach(9);
  m10.attach(10);
  m11.attach(11);
  m12.attach(12);
  m13.attach(13);
  m14.attach(14);
  m15.attach(15);
  m16.attach(16);
  m17.attach(17);
  m18.attach(18);
  m19.attach(19);

  //for head
  m20.attach(20);
  m21.attach(21);

//  delay(1000);
  ini();
//  delay(1000);
//  moveForward();
//  delay(1000);
}

int d;

void loop() 
{  
  delay(1000);
  moveForward();

  d = distance();
  Serial.print("Distance = ");
  Serial.println(d);
  if(d>=0 && d<=20)
  {
    headTailMove();
    delay(1000);
    for(int i=0; i<3; i++)
    {
      moveBackward(); 
    }
  }
}

void ini()
{
  Serial.begin(9600);
  
  delay(500);
  m20.write(90);
  delay(500);
  m21.write(90);
  delay(500);
  
  //down
  delay(500);
  m2.write(90);
  delay(500);
  m3.write(90);
  delay(500);
  m4.write(90);
  delay(500);
  m5.write(90);
  delay(500);
  m6.write(90);
  delay(500);
  m7.write(90);
  delay(500);

  //middle
  m8.write(90);
  delay(500);
  m9.write(90);
  delay(500);
  m10.write(90);
  delay(500);
  m11.write(90);
  delay(500);
  m12.write(90);
  delay(500);
  m13.write(90);
  delay(500);

  //up
  m14.write(90);
  delay(500);
  m15.write(90);
  delay(500);
  m16.write(90);
  delay(500);
  m17.write(90);
  delay(500);
  m18.write(90);
  delay(500);
  m19.write(90);
  delay(500);

  headTailMove();

}

void moveForward()
{
  //right legs up

  for(int i=1 ;i<30; i++) //corrected
  {
    agl -= 1;
    agl2 += 1;
    m8.write(agl);
    delay(5);
    m10.write(agl);
    delay(10);
    m12.write(agl2);
    delay(5);
  }

  delay(1000);
  
  if(ct==1)
  {
    ct = 2;
    for(int i=1; i<=20; i++)
    {
      //right legs forwad
      a2 -= 1;
      a4 -= 1;
      a6 += 1;
      m2.write(a2);
      delay(5);
      m4.write(a4);
      delay(5);
      m6.write(a6);
      delay(5);
  
      //left legs back
      a3 += 1;
      a5 -= 1;
      a7 -= 1;
  
      m3.write(a3);
      delay(5);
      m5.write(a5);
      delay(5);
      m7.write(a7);
      delay(5);
    }
  
  }//if ending here... 
  else
  {
    for(int i=1; i<=20; i++)
    {
      //right legs forwad
      a2 -= 1;
      a4 -= 1;
      a6 += 1;
      m2.write(a2);
      delay(5);
      m4.write(a4);
      delay(5);
      m6.write(a6);
      delay(5);
  
      //left legs back
      a3 += 1;
      a5 -= 1;
      a7 -= 1;
  
      m3.write(a3);
      delay(5);
      m5.write(a5);
      delay(5);
      m7.write(a7);
      delay(5);
    }
  }
  
  //right legs down
  for(int i=1; i<30; i++)  //corrected
  {
    agl += 1;
    agl2 -= 1;
    m8.write(agl);
    delay(5);
    m10.write(agl);
    delay(5);
    m12.write(agl2);
    delay(5);
  }

  delay(500);

  //left legs up
  for(int i=1; i<30; i++)  //corrected
  {
    agl += 1;
    agl2 -= 1;
    m11.write(agl);
    delay(5);
    m13.write(agl);
    delay(5);
    m9.write(agl2);
    delay(5);
  }

  
  for(int i=1; i<=40; i++)
  {
    //right legs back
    a2 += 1;
    a4 += 1;
    a6 -= 1;
 
    m2.write(a2);
    delay(5);
    m4.write(a4);
    delay(5);
    m6.write(a6);
    delay(5);

    //left legs forward
    a3 -= 1;
    a5 += 1;
    a7 += 1;

    m3.write(a3);
    delay(5);
    m5.write(a5);
    delay(5);
    m7.write(a7);
    delay(5);
  }
  
  //left legs down
  for(int i=1; i<30; i++) //corrected
  {
    agl -= 1;
    agl2 += 1;
    m11.write(agl);
    delay(5);
    m13.write(agl);
    delay(5);
    m9.write(agl2);
    delay(5);
  }
}

void moveBackward()
{
  //left legs up
  for(int i=1; i<30; i++)  //corrected
  {
    agl += 1;
    agl2 -= 1;
    m11.write(agl);
    delay(5);
    m13.write(agl);
    delay(5);
    m9.write(agl2);
    delay(5);
  }
  
  delay(1000);
  
  if(ct==1)
  {
    ct = 2;
    for(int i=1; i<=20; i++)
    {
      //right legs forwad
      a2 -= 1;
      a4 -= 1;
      a6 += 1;
      m2.write(a2);
      delay(5);
      m4.write(a4);
      delay(5);
      m6.write(a6);
      delay(5);
  
      //left legs back
      a3 += 1;
      a5 -= 1;
      a7 -= 1;
  
      m3.write(a3);
      delay(5);
      m5.write(a5);
      delay(5);
      m7.write(a7);
      delay(5);
    }
  
  }//if ending here... 
  else
  {
    for(int i=1; i<=20; i++)
    {
      //right legs forwad
      a2 -= 1;
      a4 -= 1;
      a6 += 1;
      m2.write(a2);
      delay(5);
      m4.write(a4);
      delay(5);
      m6.write(a6);
      delay(5);
  
      //left legs back
      a3 += 1;
      a5 -= 1;
      a7 -= 1;
  
      m3.write(a3);
      delay(5);
      m5.write(a5);
      delay(5);
      m7.write(a7);
      delay(5);
    }
  }

  //left legs down
  for(int i=1; i<30; i++) //corrected
  {
    agl -= 1;
    agl2 += 1;
    m11.write(agl);
    delay(5);
    m13.write(agl);
    delay(5);
    m9.write(agl2);
    delay(5);
  }
    
  delay(500);

  //left legs up
  for(int i=1; i<30; i++)  //corrected
  {
    agl += 1;
    agl2 -= 1;
    m11.write(agl);
    delay(5);
    m13.write(agl);
    delay(5);
    m9.write(agl2);
    delay(5);
  }

  
  for(int i=1; i<=40; i++)
  {
    //right legs back
    a2 += 1;
    a4 += 1;
    a6 -= 1;
 
    m2.write(a2);
    delay(5);
    m4.write(a4);
    delay(5);
    m6.write(a6);
    delay(5);

    //left legs forward
    a3 -= 1;
    a5 += 1;
    a7 += 1;

    m3.write(a3);
    delay(5);
    m5.write(a5);
    delay(5);
    m7.write(a7);
    delay(5);
  }
  
  //right legs down
  for(int i=1; i<30; i++)  //corrected
  {
    agl += 1;
    agl2 -= 1;
    m8.write(agl);
    delay(5);
    m10.write(agl);
    delay(5);
    m12.write(agl2);
    delay(5);
  }
}

void headUp()
{
  m21.write(40);
  delay(500);
}

void headDown()
{
  m21.write(120);
  delay(500);
}

void headRight()
{
  m20.write(130);
  delay(500);
}

void headLeft()
{
  m20.write(50);
  delay(500);
}

void tailRight()
{
  m22.write(130);
  delay(500);
}

void tailLeft()
{
  m22.write(50);
  delay(500);
}

void headTailMove()
{
  headUp();
  headDown();
  delay(500);
  m21.write(90);
  headRight();
  headLeft();
  m20.write(90);
  delay(500);
  tailRight();
  tailLeft();
  m22.write(500);
  delay(500);
}

int distance()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  int t = pulseIn(echo,HIGH);
  d = t*0.017;
  return d;
}
