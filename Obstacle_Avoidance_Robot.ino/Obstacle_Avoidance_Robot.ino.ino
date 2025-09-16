  digitalWrite(triggerPin, LOW); 
 
// echoPin 이 HIGH를 유지한 시간 
 
  duration = pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2; 
 
 
if(distance < 20) { //장애물 감지 (20cm 이내) 
   
  stop(); 
  delay(1000); 
  back(); 
  delay(500); 
 
int rnd = random(0,2); //장애물 감지시 좌/우회전 랜덤처리 
 
  if(rnd == 0){ 
    right(); 
 
  }else { 
    left(); 
  } 
 
  }else{ //장애물 없음 
    forward(); 
  } 
} 
 
 
void forward() { 
  digitalWrite(IN1 , HIGH); 
  digitalWrite(IN2 , LOW); 
  digitalWrite(IN3 , HIGH); 
  digitalWrite(IN4 , LOW); 
  digitalWrite(IN5 , HIGH); 
  digitalWrite(IN6 , LOW); 
  digitalWrite(IN7 , HIGH); 
  digitalWrite(IN8 , LOW); 
  analogWrite(ENA , speedBR); 
  analogWrite(ENB , speedBL); 
  analogWrite(ENA2 , speedFR); 
  analogWrite(ENB2 , speedFL); 
} 
void stop() { 
  digitalWrite(IN1 , LOW);   
  digitalWrite(IN2 , LOW); 
  digitalWrite(IN3 , LOW); 
  digitalWrite(IN4 , LOW); 
  digitalWrite(IN5 , LOW); 
  digitalWrite(IN6 , LOW); 
  digitalWrite(IN7 , LOW); 
  digitalWrite(IN8 , LOW); 
} 
void right() { 
  digitalWrite(IN1 , LOW); 
  digitalWrite(IN2 , HIGH); 
  digitalWrite(IN3 , HIGH); 
  digitalWrite(IN4 , LOW); 
  digitalWrite(IN5 , LOW); 
  digitalWrite(IN6 , HIGH); 
  digitalWrite(IN7 , HIGH); 
  digitalWrite(IN8 , LOW); 
  analogWrite(ENA , speedFL); 
  analogWrite(ENB , speedFR); 
  analogWrite(ENA2 , speedBL); 
  analogWrite(ENB2 , speedBR); 
} 
void left() { 
  digitalWrite(IN1 , HIGH); 
  digitalWrite(IN2 , LOW); 
  digitalWrite(IN3 , LOW); 
  digitalWrite(IN4 , HIGH); 
  digitalWrite(IN5 , HIGH); 
  digitalWrite(IN6 , LOW); 
  digitalWrite(IN7 , LOW); 
  digitalWrite(IN8 , HIGH); 
  analogWrite(ENA , speedFL); 
  analogWrite(ENB , speedFR); 
  analogWrite(ENA2 , speedBL); 
  analogWrite(ENB2 , speedBR); 
} 
void back() { 
  digitalWrite(IN1 , LOW); 
  digitalWrite(IN2 , HIGH); 
  digitalWrite(IN3 , LOW); 
  digitalWrite(IN4 , HIGH); 
  digitalWrite(IN5 , LOW); 
  digitalWrite(IN6 , HIGH); 
  digitalWrite(IN7 , LOW); 
  digitalWrite(IN8 , HIGH); 
  analogWrite(ENA , speedFL); 
  analogWrite(ENB , speedFR); 
  analogWrite(ENA2 , speedBL); 
  analogWrite(ENB2 , speedBR);  
} 
