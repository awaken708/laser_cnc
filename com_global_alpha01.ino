String inputString = "";  
byte length;
int global_x,global_y,global_a,global_z,time;
boolean stringComplete = false; 
const byte m2[4][4]=
{
  {1,0,0,1  },
  {0,1,1,0  },
  {1,1,0,0  },
  {0,0,1,1  },
};

void up()
{
  for(int i = 0;i<4;i++)
  {
    if(m2[0][i]==1){
      digitalWrite(2, HIGH);
    }
    else{
      digitalWrite(2, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(3, HIGH);
    }
    else{
      digitalWrite(3, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(4, HIGH);
    }
    else{
      digitalWrite(4, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(5, HIGH);
    }
    else{
      digitalWrite(5, LOW);
    }
    delay(time);
  }
}

void down()
{
  for(int i = 3;i>=0;i--)
  {
    if(m2[0][i]==1){
      digitalWrite(2, HIGH);
    }
    else{
      digitalWrite(2, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(3, HIGH);
    }
    else{
      digitalWrite(3, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(4, HIGH);
    }
    else{
      digitalWrite(4, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(5, HIGH);
    }
    else{
      digitalWrite(5, LOW);
    }
    delay(time);
  } 
}

void left()
{
  for(int i = 0;i<4;i++)
  {
    if(m2[0][i]==1){
      digitalWrite(6, HIGH);
    }
    else{
      digitalWrite(6, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(7, HIGH);
    }
    else{
      digitalWrite(7, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(8, HIGH);
    }
    else{
      digitalWrite(8, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(9, HIGH);
    }
    else{
      digitalWrite(9, LOW);
    }
    delay(time);
  }  
}

void right()
{
  for(int i = 3;i>=0;i--)
  {
    if(m2[0][i]==1){
      digitalWrite(6, HIGH);
    }
    else{
      digitalWrite(6, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(7, HIGH);
    }
    else{
      digitalWrite(7, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(8, HIGH);
    }
    else{
      digitalWrite(8, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(9, HIGH);
    }
    else{
      digitalWrite(9, LOW);
    }
    delay(time);
  }   
}

void zp()
{
  for(int i = 0;i<4;i++)
  {
    if(m2[0][i]==1){
      digitalWrite(38, HIGH);
    }
    else{
      digitalWrite(38, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(37, HIGH);
    }
    else{
      digitalWrite(37, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(36, HIGH);
    }
    else{
      digitalWrite(36, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(35, HIGH);
    }
    else{
      digitalWrite(35, LOW);
    }
    delay(time);
  }  
}

void zm()
{
  for(int i = 3;i>=0;i--)
  {
    if(m2[0][i]==1){
      digitalWrite(38, HIGH);
    }
    else{
      digitalWrite(38, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(37, HIGH);
    }
    else{
      digitalWrite(37, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(36, HIGH);
    }
    else{
      digitalWrite(36, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(35, HIGH);
    }
    else{
      digitalWrite(35, LOW);
    }
    delay(time);
  }   
}

void ap()
{
  for(int i = 0;i<4;i++)
  {
    if(m2[0][i]==1){
      digitalWrite(34, HIGH);
    }
    else{
      digitalWrite(34, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(33, HIGH);
    }
    else{
      digitalWrite(33, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(32, HIGH);
    }
    else{
      digitalWrite(32, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(31, HIGH);
    }
    else{
      digitalWrite(31, LOW);
    }
    delay(time);
  }  
}

void am()
{
  for(int i = 3;i>=0;i--)
  {
    if(m2[0][i]==1){
      digitalWrite(34, HIGH);
    }
    else{
      digitalWrite(34, LOW);
    }
    if(m2[1][i]==1){
      digitalWrite(33, HIGH);
    }
    else{
      digitalWrite(33, LOW);
    }
    if(m2[2][i]==1){
      digitalWrite(32, HIGH);
    }
    else{
      digitalWrite(32, LOW);
    }
    if(m2[3][i]==1){
      digitalWrite(31, HIGH);
    }
    else{
      digitalWrite(31, LOW);
    }
    delay(time);
  }   
}

void perema(int da)
{
    if(da >= global_a) {for(int i = 0; i < abs(da-global_a);i++){ap();}} else
        {for(int i = 0; i < abs(da-global_a);i++){am();}}
global_a = da;        
}

void peremz(int dz)
{
    if(dz >= global_z) {for(int i = 0; i < abs(dz-global_z);i++){zp();}} else
        {for(int i = 0; i < abs(dz-global_z);i++){zm();}}  
global_z = dz;
}

void line(int x1,int y1,int x2,int y2)
{
  int dx = abs(x1-x2);
  int dy = abs(y1-y2);
  int sx ;
  if((x2-x1)>0){
    sx=1;      
  }
  else{
    sx=-1;
  }
  int sy ; 
  if((y2-y1)>0){
    sy=1;
  }
  else{
    sy=-1;
  }
  int x = x1;
  int y = y1;
  byte check = 0;
  if(dy>dx) {
    int t = dx; 
    dx = dy; 
    dy = t; 
    check = 1;
  }
  int e = 2*dy - dx;
  for(int i = 0;i<=dx;i++){
    if(e>=0){
      e=e-2*dx; 
      if(check==1){
        x=x+sx;
        if(sx>0){
          right();
        }
        else{
          left();
        }
      }
      else{
        y=y+sy;
        if(sy>0){
          up();
        }
        else{
          down();
        }
      }
    } 
    if(check==1){
      y=y+sy;
      if(sy>0){
        up();
      }
      else{
        down();
      }
    }
    else{
      x=x+sx;
      if(sx>0){
        right();
      }
      else{
        left();
      }
    } 
    e=e+2*dy;
  }
global_x=x2;
global_y=y2;
}

void final()
{
 for(int i = 2;i<=9;i++){digitalWrite(i, LOW);}
}

void laser_on()
{
  digitalWrite(10, LOW);
  delay(200);
}

void laser_off()
{
  digitalWrite(10, HIGH);
  delay(200);
}
void col_on1() 
{
  digitalWrite(39, HIGH);
  delay(200);
}
void col_on2() 
{
  digitalWrite(40, HIGH);
  delay(200);
}
void col_off() 
{
  digitalWrite(39, LOW);
  digitalWrite(40, LOW);
  delay(200);
}
void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  pinMode(40,OUTPUT);
  pinMode(39,OUTPUT);
  
  pinMode(38,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(35,OUTPUT);
 
  pinMode(34,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(31,OUTPUT);
  
  global_x = 0;
  global_y = 0;
  global_z = 0;
  global_a = 0;  
  laser_off();
  time = 20;
}

byte get_n(byte i){
switch ( inputString[i] ) {
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  case '0':
    return 0;
  default:
    return 0;	
  }
}

int parse(char ch){
byte k=0;
int p=0;
for(k=0;k<length;k++){if(inputString[k]==ch){break;}} if(k==length){return 0;}
if(inputString[k+1]!='-'){
for(k=k+1;(inputString[k]!=',')&(inputString[k]!='.')&(inputString[k]!=' ')&(inputString[k]!=';')&(inputString[k]!='\n');k++){p=p*10+get_n(k);}} else
{for(k=k+2;(inputString[k]!=',')&(inputString[k]!='.')&(inputString[k]!=' ')&(inputString[k]!=';')&(inputString[k]!='\n');k++){p=p*10+get_n(k);} p=-1*p;}
return p;
}

boolean find(char ch){
boolean log = false;
byte k=0;
for(k=0;k<length;k++){if(inputString[k]==ch){log = true; break;}} 
return log;
}

void parse_gcode(){
switch (parse('G')) {
  case 0:
  {
  if(find('Z')) {peremz(parse('Z'));}
  if(find('A')) {perema(parse('A'));}
  if(find('X')&find('Y'))   {line(global_x,global_y,parse('X'),parse('Y'));} 
  if(find('X')&(!find('Y'))) {line(global_x,global_y,parse('X'),global_y);}
  if((!find('X'))&find('Y')) {line(global_x,global_y,global_x,parse('Y'));}
  }
  break;
  case 1:
   if((parse('X')!=0)&(parse('Y')!=0)) {line(global_x,global_y,parse('X'),parse('Y'));} break;
  case 4:
    delay(parse('P')+1000*parse('X')); break;	
  }
}

void parse_mcode(){
switch (parse('M')) {
  case 2:
    final(); laser_off(); break;
  case 3:
    laser_on(); break;
  case 4:
    laser_on(); break;
  case 5:
    laser_off(); break;
  case 7:
    col_on1(); break;
  case 8:
    col_on2(); break;
  case 9:
    col_off(); break;
  case 10:
     time = parse('T'); break;
  case 30:
    line(global_x,global_y,0,0); final(); break;	
  }
}

void loop() {
  if (stringComplete) {
    //inputString += ';';
    if(inputString[0]=='G') parse_gcode();
    if(inputString[0]=='M') parse_mcode();
    Serial.println('ok');
    inputString = "";length=0;
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    inputString += inChar;
    length++;
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
