#include <IRremote.h>

int RECV_PIN = 11; // IR 수신기 D11에 연결
int LED_pin1 = 7; // led 연결
int LED_pin2 = 8;

IRrecv irrecv(RECV_PIN); // IR리모콘 사용을 위한 클래스 생성
decode_results decodedSignal; // IR리모콘으로부터 받은 데이터
void setup() {
Serial.begin(9600); // 시리얼 통신 시작
irrecv.enableIRIn(); // 리모콘 수신 시작
pinMode(LED_pin1, OUTPUT); // led 출력모드로 설정
pinMode(LED_pin2, OUTPUT);
}
void loop() {
if (irrecv.decode(&decodedSignal) == true){ // IR 수신값이 있는지 판단.
    Serial.println(decodedSignal.value);            
  
    switch (decodedSignal.value) {
      // 리모콘의 ch-버튼이 눌리면 LED 1 ON
      case 0xFFA25D: digitalWrite(LED_pin1, HIGH); break;
      // 리모콘의 ch+버튼이 눌리면 LED 1 OFF
      case 0xFFE21D: digitalWrite(LED_pin1, LOW); break; 
      // 리모콘의 prev버튼이 눌리면 LED 2 ON
      case 0xFF22DD: digitalWrite(LED_pin2, HIGH); break; 
      // 리모콘의 play버튼이 눌리면 LED 2 OFF
      case 0xFFC23D: digitalWrite(LED_pin2, LOW); break; 
    }
    irrecv.resume();  // IR 다음 데이터 수신
}
}
