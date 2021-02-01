//Initializing pin

/*Ultrasonic*/
#define trigger_Pin 9
#define echo_Pin 8
/* IR sensor */
int IR_right = 11;  // IR right sensor
int IR_left = 10;  // IR left sensor

/*Motors*/
int motor_right_1 = 9;  // right motor output 1
int motor_right_2 = 4;  // right motor output 2

int motor_left_1= 2;  // left motor output 1
int motor_left_2 = 3;  // left motor output 2

/*variable*/
int Sensor_left =0;  // variable to store left IR value;
int Sensor_right=0;  // variable to store right IR value;
void setup() {
  // initializing input and output
  pinMode(motor_right_1,OUTPUT);
  pinMode(motor_right_2,OUTPUT);
  pinMode(motor_left_1,OUTPUT);
  pinMode(motor_left_2,OUTPUT);
  pinMode(IR_right,INPUT);
  pinMode(IR_left,INPUT);
  pinMode(trigger_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);
  
  }

void loop() {
  // execution

  Sensor_left=digitalRead(IR_left);
  Sensor_right=digitalRead(IR_right);
  

  if(Sensor_left == LOW && Sensor_right == LOW)
  {
    move_forward();
  }
  
  if(Sensor_left == LOW && Sensor_right == HIGH)
  {
    move_left();
  }

  if(Sensor_left == HIGH && Sensor_right == LOW)
  {
    move_right();
  }

  if(Sensor_left == HIGH && Sensor_right == LOW)
  {
    move_right();
  }

   if(object_present()==1)
  {
    move_stop();
  }

}

// Methods

void move_forward(){
  digitalWrite(motor_left_1,HIGH);
  digitalWrite(motor_left_2,LOW);
  digitalWrite(motor_right_1,HIGH);
  digitalWrite(motor_right_2,LOW);
}
void move_left(){
  digitalWrite(motor_left_1,LOW);
  digitalWrite(motor_left_2,HIGH);
  digitalWrite(motor_right_1,HIGH);
  digitalWrite(motor_right_2,LOW);
}
void move_right(){
  digitalWrite(motor_left_1,HIGH);
  digitalWrite(motor_left_2,LOW);
  digitalWrite(motor_right_1,LOW);
  digitalWrite(motor_right_2,HIGH);
}
void move_stop(){
  digitalWrite(motor_left_1,LOW);
  digitalWrite(motor_left_2,LOW);
  digitalWrite(motor_right_1,LOW);
  digitalWrite(motor_right_2,LOW);
}

/*How sensing the object near to 20cm*/
int object_present(){
  long duration, distance;
  digitalWrite(trigger_Pin, LOW);
  delayMicroseconds(2);              
  digitalWrite(trigger_Pin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigger_Pin, LOW);
  duration = pulseIn(echo_Pin, HIGH);
  distance = (duration/2)/29.1;

  if(distance < 20){
    return 1;
  }
  else{
    return 0;
  }
  
}





  
