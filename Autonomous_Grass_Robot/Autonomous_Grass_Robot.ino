int IN1 = 1 , IN2 = 0;   //왼쪽 앞 모터     
int IN3 = 2 , IN4 = 3;   //오른쪽 앞 모터     
int IN5 = 4 , IN6 = 7;   //오른쪽 뒤 모터    
int IN7 = 8 , IN8 = 9;   //왼쪽 뒤 모터      
int speedBR = 120 , speedBL = 130;    //최솟값 70  10차이         
int speedFR = 120 , speedFL = 130 ;                 
int ENA = 5 , ENB = 6;          
// 오른쪽 뒤 모터 , 왼쪽 뒤 모터 
int ENA2= 10 , ENB2= 11;   // 오른쪽 앞 모터 , 왼쪽 앞 모터 
int triggerPin = 12, echoPin = 13; 
unsigned long start_time = 0; 
int cm = 6; 
void setup() { 
//Serial.begin(9600); 
pinMode(triggerPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT); 
pinMode(IN3, OUTPUT); 
pinMode(IN4, OUTPUT); 
pinMode(IN5, OUTPUT); 
pinMode(IN6, OUTPUT); 
pinMode(IN7, OUTPUT); 
pinMode(IN8, OUTPUT); 
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
 
 
void loop() { 
    // 시작은 전진 
    unsigned long start_time = millis(); 
    while (millis() - start_time < 3000) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 전진 
            start_time = millis(); 
        } else { 
            forward(); // 1초 간격으로 전진 
        } 
    } 
 
    // 좌회전 
    start_time = millis(); 
    while (millis() - start_time < 1680) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            left(); // 1초 간격으로 좌회전 
        } 
    } 
 
    //직진 
    start_time = millis(); 
    while (millis() - start_time < 1400) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            forward();  
        } 
    } 
 
    //우회전 
    start_time = millis(); 
    while (millis() - start_time < 1730) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            right();  
        } 
    } 
 
    //직진 
    start_time = millis(); 
    while (millis() - start_time < 2500) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            forward();  
        } 
    } 
 
    //정지 
    start_time = millis(); 
    while (millis() - start_time < 1000) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            stop();  
        } 
    } 
     
    //좌회전 
    start_time = millis(); 
    while (millis() - start_time < 1890) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            left();  
        } 
    } 
 
    //후진 
    start_time = millis(); 
    while (millis() - start_time < 1720) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            back();  
        } 
    } 
 
    //정지 
    start_time = millis(); 
    while (millis() - start_time < 1000) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            stop();  
        } 
    } 
 
    //직진 
    start_time = millis(); 
    while (millis() - start_time < 1600) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            forward();  
        } 
    } 
 
    //좌회전 
    start_time = millis(); 
    while (millis() - start_time < 1500) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            left();  
        } 
    } 
 
    //직진 
    start_time = millis(); 
    while (millis() - start_time < 3400) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            forward();  
        } 
    } 
 
    //정지 
    start_time = millis(); 
    while (millis() - start_time < 1000) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            stop();  
        } 
    } 
 
    //우회전 
    start_time = millis(); 
    while (millis() - start_time < 1800) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            right();  
        } 
    } 
 
    //직진 
    start_time = millis(); 
    while (millis() - start_time < 1600) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            forward();  
        } 
    } 
 
    //좌회전 
    start_time = millis(); 
    while (millis() - start_time < 1700) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            left();  
        } 
    } 
 
    //직진 
    start_time = millis(); 
    while (millis() - start_time < 800) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            forward();  
        } 
    } 
 
    //정지 
    start_time = millis(); 
    while (millis() - start_time < 1000) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            stop();  
        } 
    } 
 
    //좌회전 
    start_time = millis(); 
    while (millis() - start_time < 3600) { 
        if (measure_distance() < cm) { 
            // 장애물이 감지되면 모터 정지 
            stop(); 
            while (measure_distance() < cm) { 
                delay(100); 
            } 
            // 다시 좌회전 
            start_time = millis(); 
        } else { 
            left();  
        } 
    } 
 
} 
 
// 초음파 센서로 거리 측정 
float measure_distance() { 
    digitalWrite(triggerPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(triggerPin, LOW); 
 
    unsigned long duration = pulseIn(echoPin, HIGH); 
    float distance = ((340 * duration) / 10000) / 2; 
    return distance;