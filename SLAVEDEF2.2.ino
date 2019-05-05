#include <Wire.h>


int check1;
char buff5[7];
char buff6[7];
char buff7[7];
char buff8[7];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Wire.begin(2); // any 7-bit Slave address
  Serial.begin(9600);
  Wire.onReceive(rispondi1); //Interrupt for handling incomming requests
  Wire.onRequest(richiesta1);

}


void loop() {
  // put your main code here, to run repeatedly:
 
  
}


void rispondi1()
{
  check1=Wire.read();
}

void richiesta1()
{
  if(check1==5)
  {
     
    float sensor_voltMQ4; //Define variable for sensor voltage
    float RS_gasMQ4; //Define variable for sensor resistance
    float ratioMQ4; //Define variable for ratio
    float sensorValueMQ4 = analogRead(A0); //Read analog values of sensor
    sensor_voltMQ4 = sensorValueMQ4 * (5.0 / 1023.0); //Convert analog values to voltage
    RS_gasMQ4 = ((5.0 * 10.0) / sensor_voltMQ4) - 10.0; //Get value of RS in a gas
    ratioMQ4 = RS_gasMQ4 / 64.60;   // Get ratio RS_gas/RS_air

    dtostrf(ratioMQ4,7,4, buff5);

    Serial.print("Valore mq4: ");
    Serial.println(buff5);
    Wire.write(buff5);
    
    
  }


  if(check1==6)
  {
     
    float sensor_voltMQ2;
    float RS_gasMQ2; // Get value of RS in a GAS
    float ratioMQ2; // Get ratio RS_GAS/RS_air
    int sensorValueMQ2 = analogRead(A1);
    sensor_voltMQ2=(float)sensorValueMQ2/1024*5.0;
    RS_gasMQ2 = (5.0-sensor_voltMQ2)/sensor_voltMQ2; // omit * RL

          
    ratioMQ2 = RS_gasMQ2/1.01;  // ratio = RS/R0
    dtostrf(ratioMQ2,7,4, buff6);
    Serial.print("Valore mq2: ");
    Serial.println(buff6);
    Wire.write(buff6);
    
    
  }




  if(check1==7)
  {
     
    float sensor_voltMQ6;
    float RS_gasMQ6; // Get value of RS in a GAS
    float ratioMQ6; // Get ratio RS_GAS/RS_air
    float LPG_PPMMQ6;
 
    int sensorValueMQ6 = analogRead(A2);
 
    sensor_voltMQ6=(float)sensorValueMQ6/1024*5.0;
 
    RS_gasMQ6 = (5.0-sensor_voltMQ6)/sensor_voltMQ6; // omit *RL /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
 
    ratioMQ6 = RS_gasMQ6/1.55;  // ratio = RS/R0
    dtostrf(ratioMQ6,7,4, buff7);
 
    Serial.print("LPG PPM = ");
    Serial.println(buff7);
    Serial.print("\n\n");
    Wire.write(buff7);
    

    
    
    
  }

  if(check1==8)
  {
     
    float sensor_voltMQ135;
    float CO2_PPM;
    float RS_gasMQ135; // Get value of RS in a GAS
    float ratioMQ135; // Get ratio RS_GAS/RS_air
    
 
    int sensorValueMQ135 = analogRead(A3);
 
    sensor_voltMQ135=(float)sensorValueMQ135/1024*5.0;
 
    RS_gasMQ135 = (5.0-sensor_voltMQ135)/sensor_voltMQ135; // omit *RL /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
 
    ratioMQ135= RS_gasMQ135/76.63;  // ratio = RS/R0
    
    
    CO2_PPM= (146.15*(2.868-ratioMQ135)+10);
    dtostrf(CO2_PPM,7,4, buff8);
 
    Serial.print("co2 PPM = ");
    Serial.println(buff8);
    Serial.print("\n\n");
    Wire.write(buff8);
    

    
    
    
  }





  


  






  
}
