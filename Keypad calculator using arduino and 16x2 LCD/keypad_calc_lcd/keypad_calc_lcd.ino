#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;

char key[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};

byte rowPins[ROWS] = {0,1,2,3};
byte colPins[COLS] = {4,5,6,7};

Keypad kpd = Keypad(makeKeymap(key),rowPins,colPins,ROWS,COLS);

const int rs = 8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

long n1,n2,num;

char k_press,op;

boolean ans = false;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Welcome to the Arduino Calculator");
  lcd.setCursor(0,1);
  lcd.print("Let's start...");
  delay(2500);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  k_press = kpd.getKey();

  if(k_press != NO_KEY)
  {
    findKeys();
  }

  if(ans == true)
  {
    calculateAnswer();
  }
  showAnswer();

}

void findKeys()
{
  lcd.clear();
  if(k_press == 'C')
  {
    num = 0;
    n1=0;
    n2=0;
    ans=false;
  }

  if(k_press=='1')
  {
    if(num==0)
      num=1;
    else
      num=(num*10)+1;
  }

  if(k_press=='4')
  {
    if(num==0)
      num=4;
    else
      num=(num*10)+4;
  }

  if(k_press=='7')
  {
    if(num==0)
      num=7;
    else
      num=(num*10)+7;
  }

  if(k_press=='0')
  {
    if(num==0)
      num=0;
    else
      num=(num*10)+0;
  }

  if(k_press=='2')
  {
    if(num==0)
      num=2;
    else
      num=(num*10)+2;
  }

  if(k_press=='5')
  {
    if(num==0)
      num=5;
    else
      num=(num*10)+5;
  }

  if(k_press=='8')
  {
    if(num==0)
      num=8;
    else
      num=(num*10)+8;
  }

  if(k_press=='=')
  {
    
      n2=num;
      ans=true;
  }

  if(k_press=='3')
  {
    if(num==0)
      num=3;
    else
      num=(num*10)+3;
  }

  if(k_press=='6')
  {
    if(num==0)
      num=6;
    else
      num=(num*10)+6;
  }

  if(k_press=='9')
  {
    if(num==0)
      num=9;
    else
      num=(num*10)+9;
  }

  if(k_press == '+' || k_press == '-' || k_press == '*' || k_press == '/')
  {
    n1=num;
    num=0;

    if(k_press == '+')
       op = '+';

     if(k_press == '-')
       op = '-';

     if(k_press == '*')
       op = '*';

     if(k_press == '/')
       op = '/';

      delay(100);
  }
}

void calculateAnswer()
{
  if(op == '+')
     num = n1+n2;

   if(op == '-')
     num = n1-n2;

   if(op == '*')
     num = n1*n2;

   if(op == '/')
     num = n1/n2;
}

void showAnswer()
{
  lcd.setCursor(0,0);
  lcd.print(n1);
  lcd.print(op);
  lcd.print(n2);

  if(ans == true)
  {
    lcd.print("=");
    lcd.print(num);
  }

  lcd.setCursor(0,1);
  lcd.print(num);
}
