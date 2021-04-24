/*
 * To use this sketch, connect the eight pins from your LCD like thus:
 *
 * Pin 1 -> +3.3V (rightmost, when facing the display head-on)
 * Pin 2 -> Arduino digital pin 3
 * Pin 3 -> Arduino digital pin 4
 * Pin 4 -> Arduino digital pin 5
 * Pin 5 -> Arduino digital pin 7
 * Pin 6 -> Ground
 * Pin 7 -> 10uF capacitor -> Ground
 * Pin 8 -> Arduino digital pin 6
 * this playing algorisim need to be devolped :")
 */


#include <PCD8544.h>



 char StateArr[10]={'X','1','2','3','4','5','6','7','8','9'};


static PCD8544 lcd;
void Interface();
void setup() {
  //intialization of the lcd
  lcd.begin(84, 48);
  Serial.begin(9600);
 
}

void loop() {
int Move,checkResult;  //if result is 1 you win 0u lose  
char sign,place; 
Move=1; // start playing
Serial.println("u r the player 1 X the pc is player 2 O ");
do
    {
    Interface();
    Move= (Move%2) ? 1:2;//1 X for user 2 O for computer
    
    Serial.print("player: " );
    Serial.println(Move);
    sign=(Move==1)?'X':'O'; //if Move=1 X's turn else O
    if(Move==1){
    Serial.println("enter the place:");
    while(Serial.available()==0){//if you didnt recive something do nothig}
    while(Serial.available()){
     place = Serial.read();
     Serial.println(place);}
     MyTurn(Move,place,sign);  //pass that is the user turn and the place the user choose and the sing X or O 
    }
  else if (Move== 2){ //computer Turn
    ComputerTurn(Move,sign);
    }
  else {
    Serial.println("wrong input"); //if u enterd rong iput 
  }
checkResult=CheckResult(); //if checkresult -1 no one wins 
Move++; 
}while(checkResult == -1);

Interface(); //update changes

if (checkResult==1){
  --Move; 
  Serial.print("the winner is player: ");
  Serial.println(Move);
    }

else if (checkResult==0)  
  Serial.println("no winners");
 delay(2000);
  lcd.clear();
  lcd.setCursor(0,2);
  lcd.print("thank u for");
  lcd.setCursor(0,3);
  lcd.print("using our game");
  exit(0);
}
void Interface(){
lcd.clear();
lcd.setCursor(2,0);
lcd.print(" ");
lcd.print(StateArr[1]);
lcd.print(" | ");
lcd.print(StateArr[2]);
lcd.print(" | ");
lcd.print(StateArr[3]);
lcd.setCursor(0, 1);
lcd.println(" ____________ ");
lcd.setCursor(1, 2);
lcd.print(" ");
lcd.print(StateArr[4]);
lcd.print(" | ");
lcd.print(StateArr[5]);
lcd.print(" | ");
lcd.print(StateArr[6]);
lcd.setCursor(0, 3);
lcd.println(" ____________ ");
lcd.setCursor(1, 4);
lcd.print(" ");
lcd.print(StateArr[7]);
lcd.print(" | ");
lcd.print(StateArr[8]);
lcd.print(" | ");
lcd.print(StateArr[9]);
}
void MyTurn(int Move,char place,char sign){
 if(place == '1' && StateArr[1]== '1')
   StateArr[1]=sign;

else if(place=='2'&& StateArr[2]=='2')
    StateArr[2]=sign;

else if(place=='3' && StateArr[3]=='3')
    StateArr[3]=sign;

else if(place=='4' && StateArr[4]=='4')
    StateArr[4]=sign;

else if(place=='5'&& StateArr[5]=='5')
    StateArr[5]=sign;

else if(place=='6' && StateArr[6]=='6')
    StateArr[6]=sign;

else if(place=='7' && StateArr[7]=='7')
    StateArr[7]=sign;

else if(place=='8' && StateArr[8]=='8')
    StateArr[8]=sign;

else if(place=='9' && StateArr[9]=='9')
    StateArr[9]=sign;

else{
   Serial.println("wrong input my turn");
    Move--;
   
}

}
void ComputerTurn(int Move,char sign){

if(StateArr[1]== '1' && StateArr[2]== sign && StateArr[3] == sign)
   StateArr[1]=sign;
   
else if(StateArr[2]== '2' && StateArr[1]==sign && StateArr[3]==sign)
    StateArr[2]=sign;
    
else if(StateArr[3]== '3' && StateArr[2]==sign && StateArr[1]==sign)
   StateArr[3]=sign;

else if(StateArr[4]== '4' && StateArr[5]==sign && StateArr[6]==sign)
    StateArr[4]=sign;
    
else if(StateArr[5]== '5' && StateArr[4]==sign && StateArr[6]==sign)
    StateArr[5]=sign;
    
else if(StateArr[6]== '6' && StateArr[4]==sign && StateArr[5] ==sign)
   StateArr[6]=sign;
   
else if(StateArr[7]== '7' && StateArr[8]==sign && StateArr[9]==sign)
    StateArr[7]=sign;
    
else if(StateArr[8]== '8' && StateArr[7]==sign && StateArr[9]==sign)
    StateArr[8]=sign;
    
else if(StateArr[9]== '9' && StateArr[7]==sign && StateArr[8] ==sign)
   StateArr[9]=sign;
   
else if(StateArr[1]== '1' && StateArr[5]==sign && StateArr[9]==sign)
    StateArr[1]=sign;
    
else if(StateArr[5]== '5' && StateArr[1]==sign && StateArr[9]==sign)
    StateArr[5]=sign;
    
else if(StateArr[9]== '9' && StateArr[5]==sign && StateArr[1] ==sign)
   StateArr[9]=sign;

 else if(StateArr[3]== '3' && StateArr[5]==sign && StateArr[7]==sign)
    StateArr[3]=sign;
    
else if(StateArr[5]== '5' && StateArr[3]==sign && StateArr[7]==sign)
    StateArr[5]=sign;
    
else if(StateArr[7]== '7' && StateArr[5]==sign && StateArr[3] ==sign)
   StateArr[7]=sign;

else if(StateArr[1]== '1' && StateArr[4]==sign && StateArr[7]==sign)
    StateArr[1]=sign;
    
else if(StateArr[4]== '4' && StateArr[1]==sign && StateArr[7]==sign)
    StateArr[4]=sign;
    
else if(StateArr[7]== '7' && StateArr[4]==sign && StateArr[1] ==sign)
   StateArr[7]=sign;

else if(StateArr[2]== '2' && StateArr[5]==sign && StateArr[8]==sign)
    StateArr[2]=sign;
    
else if(StateArr[5]== '5' && StateArr[2]==sign && StateArr[8]==sign)
    StateArr[5]=sign;
    
else if(StateArr[8]== '8' && StateArr[2]==sign &&StateArr[5] ==sign)
   StateArr[8]=sign;

else if(StateArr[3]== '3' && StateArr[6]==sign && StateArr[9]==sign)
    StateArr[3]=sign;
    
else if(StateArr[6]== '6' && StateArr[3]==sign && StateArr[9]==sign)
    StateArr[6]=sign;
    
else if(StateArr[9]== '9' && StateArr[3]==sign && StateArr[6]==sign)
   StateArr[9]=sign;

else if (StateArr[1]== '1' && StateArr[2]== '2' && StateArr[3] == sign)
  StateArr[1]=sign;

else if (StateArr[3]== '3' && StateArr[2]== '2' && StateArr[1] == sign)
  StateArr[3]=sign;
  
else if (StateArr[1]== '1' && StateArr[3]== '3' && StateArr[2] == sign)
  StateArr[3]=sign;

else if (StateArr[4]== '4' && StateArr[5]== '5' && StateArr[6] == sign)
  StateArr[4]=sign;

else if (StateArr[4]== '4' && StateArr[6]== '6' && StateArr[5] == sign)
  StateArr[4]=sign;
  
else if (StateArr[6]== '6' && StateArr[3]== '5' && StateArr[5] == sign)
  StateArr[6]=sign;
  
else if (StateArr[7]== '7' && StateArr[8]== '8' && StateArr[9] == sign)
  StateArr[7]=sign;

else if (StateArr[7]== '7' && StateArr[9]== '9' && StateArr[8] == sign)
  StateArr[7]=sign;
  
else if (StateArr[8]== '8' && StateArr[9]== '9' && StateArr[7] == sign)
  StateArr[8]=sign;

else if (StateArr[1]== '1' && StateArr[4]== '4' && StateArr[7] == sign)
  StateArr[1]=sign;

else if (StateArr[1]== '1' && StateArr[4]== '7' && StateArr[4] == sign)
  StateArr[1]=sign;
  
else if (StateArr[7]== '7' && StateArr[3]== '4' && StateArr[1] == sign)
  StateArr[7]=sign;

else if (StateArr[1]== '1' && StateArr[2]== '2' && StateArr[3] == sign)
  StateArr[1]=sign;

else if (StateArr[2]== '2' && StateArr[5]== '5' && StateArr[8] == sign)
  StateArr[2]=sign;
  
else if (StateArr[2]== '2' && StateArr[8]== '8' && StateArr[5] == sign)
  StateArr[2]=sign;

else if (StateArr[6]== '6' && StateArr[9]== '9' && StateArr[3] == sign)
  StateArr[1]=sign;

else if (StateArr[3]== '3' && StateArr[6]== '6' && StateArr[9] == sign)
  StateArr[3]=sign;
  
else if (StateArr[3]== '3' && StateArr[9]== '9' && StateArr[6] == sign)
  StateArr[3]=sign;

else if (StateArr[1]== '1' && StateArr[5]== '5' && StateArr[9] == sign)
  StateArr[1]=sign;

else if (StateArr[1]== '1' && StateArr[9]== '9' && StateArr[5] == sign)
  StateArr[1]=sign;
  
else if (StateArr[9]== '9' && StateArr[5]== '5' && StateArr[1] == sign)
  StateArr[9]=sign;

else if (StateArr[3]== '3' && StateArr[5]== '5' && StateArr[7] == sign)
  StateArr[3]=sign;

else if (StateArr[3]== '3' && StateArr[7]== '7' && StateArr[5] == sign)
  StateArr[3]=sign;
  
else if (StateArr[7]== '7' && StateArr[5]== '5' && StateArr[3] == sign)
  StateArr[7]=sign;

else if(StateArr[1]== '1')
    StateArr[1]=sign;
    
else if(StateArr[2]== '2')
    StateArr[2]=sign;

else if(StateArr[3]== '3' )
    StateArr[3]=sign;

else if(StateArr[4]== '4' )
    StateArr[4]=sign;

else if(StateArr[5]== '5')
    StateArr[5]=sign;

else if(StateArr[6]== '6' )
    StateArr[6]=sign;

else if(StateArr[7]== '7' )
    StateArr[7]=sign;

else if(StateArr[8]== '8' )
    StateArr[8]=sign;

else if(StateArr[9]== '9' )
    StateArr[9]=sign;

else{
   Serial.println("wrong input");
    Move--;
}
}
int CheckResult(){
if (StateArr[1]== StateArr[2]&&StateArr[1]==StateArr[3])
    return 1;
else if (StateArr[4]== StateArr[5]&&StateArr[4]==StateArr[6])
    return 1;
else if (StateArr[7]== StateArr[8]&&StateArr[7]==StateArr[9])
    return 1;
else if (StateArr[1]== StateArr[4]&&StateArr[1]==StateArr[7])
    return 1;
else if (StateArr[2]== StateArr[5] && StateArr[2]== StateArr[8])
    return 1;
else if (StateArr[3]== StateArr[6]&&StateArr[3]==StateArr[9])
    return 1;
else if (StateArr[3]== StateArr[5]&&StateArr[3]==StateArr[7])
    return 1;
else if (StateArr[1]== StateArr[5]&&StateArr[1]==StateArr[9])
    return 1;
else if (StateArr[1]!='1' &&StateArr[2]!= '2' &&StateArr[3]!= '3' &&StateArr[4]!= '4'&&StateArr[5]!= '5' &&StateArr[6]!= '6' &&StateArr[7]!= '7' &&StateArr[8]!= '8' &&StateArr[9]!= '9')
    return 0;
else
    return -1;
}
