void Verifypassword(int *recievedPassword, bool *passwordState)
{
int Correctpassword[7] = {'d', 'd', 'u', 'u', 'd', 'u', 'a'};
Serial.print("Verificando...");
Serial.print('\n');
for (int i = 0; i < 7; i++)
{
  int p1 = recievedPassword[i], p2 = Correctpassword[i];

  if (p1 != p2)
  {
    Serial.print("incorrecto");
    *passwordState = false;
    return;
  }
 
}
Serial.print("correcto");
Serial.print('\n');
*passwordState = true;
}

void task0(){

enum class Task0States
 {
  INIT,
  CONFIG, 
  ARMED,
  BOOM,

};

static Task0States task0State = Task0States::INIT;
static int TimeStart = 20;
static int Time = 0;
static int password[7];
static int position = 0;

switch (task0State)
 {
    case Task0States::INIT:
    { 
      Serial.begin();
      task0State = Task0States::CONFIG;
      Serial.print("CONFIG");
      break;
    }
    case Task0States::CONFIG:
    {
     
     if (Serial.available() > 0)
     { 
       int x = Serial.read();

       if(x == 'u' && TimeStart < 30)
        { 
         TimeStart = TimeStart + 1;
         Serial.print(TimeStart);
        }
       else if(x == 'd' && TimeStart > 10)
        {
         TimeStart = TimeStart - 1;
         Serial.print(TimeStart);
        }
       else if(x == 'a')
        { 
          Serial.print("ARMED");
         task0State = Task0States::ARMED;
         Time = millis();
        }
      }
      break;
    }

    case Task0States::ARMED:
    {
      
      static bool passwordState = false;
      
      int currentTime = millis();
      
       
       if ((currentTime - Time) >= 1000)
        {
          Time = currentTime;
          TimeStart = TimeStart - 1;
          Serial.print(TimeStart);
          Serial.print('\n');
        }

        if(Serial.available() > 0)
        {
          password[position] = Serial.read();
          position++;
          if (position >= 7)
          {
            
           position = 0;
           passwordState = false;
           Verifypassword(password, &passwordState);

           
           if (passwordState == true)
           {
             TimeStart = 20;
             Serial.print("CONFIG");
             task0State = Task0States::CONFIG;
           }

          }


        }
        if (TimeStart <= 0)
        {
          task0State = Task0States::BOOM;
          Serial.print("BOOM");

        }
        break;

    }
    case Task0States::BOOM:
    {
      int currentTime = millis();
      TimeStart = 20;
      if ((currentTime - Time) >= 5000)
      {
        Serial.print("CONFIG");
        task0State = Task0States::CONFIG;
      }
      break;


    }
  }
}



void setup() { task0();
  // put your setup code here, to run once:

}

void loop() { task0();
  // put your main code here, to run repeatedly:

}