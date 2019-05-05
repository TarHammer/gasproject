#include <MQ7.h>

#include <Wire.h>

//DICHIARO GLI ARRAY DI CHAR CHE CONTERRANNO IL FLOAT CONVERTITO  
char buff[7];
char buff2[7];
char buff3[7];
char buff4[7];



float monossido;
float mq9;
float mq5;
float mq3;
float mq4;
int check;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(1); // any 7-bit Slave address
  Serial.begin(9600);
  Wire.onReceive(rispondi); //quando il master inizia a scrivere, la funzione rispondi viene eseguita
  Wire.onRequest(richiesta);

}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void rispondi()
{
  check=Wire.read();//leggo la variabile inviata dal master e in base ad essa eseguo un determinato if
 
}

void richiesta()
{
  if(check==1)
  {
    MQ7 mq7(A0, 5.0);
    float valueMQ7 = mq7.getPPM();
    dtostrf(valueMQ7,7,4, buff);
    Serial.println("----------------------------------------------------");
    Serial.print("Valore Monossido: ");
    Serial.println(buff);
    Wire.write(buff);
    delay(100);
  }

  if(check==2)
  {
    //calcoli vari ed eventuali per trovare il rapporto tra 
    //il vaore di resistenza del sensore in aria "pulita"(r0) e 
    //il valore varaibile di resistenza che il valore ha in presenza di gas(rs)
    float sensor_volt;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    int sensorValue = analogRead(A1);
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL

    ratio = RS_gas/1.18;  // ratio = RS/R0
        
    dtostrf(ratio,7,4, buff2); //trasformo il float "ratio" in un array di 7 caratteri e dimensione massima 4 byte
    Serial.print("valore mq9: ");
    Serial.println(buff2);
    Wire.write(buff2);//invio al master la variabile convertita
    delay(100);
  }

  if(check==3)//MQ5
  {
    float sensor_voltMQ5;
    float RS_gasMQ5; // Get value of RS in a GAS
    float ratioMQ5; // Get ratio RS_GAS/RS_air
    int sensorValueMQ5 = analogRead(A2);
    sensor_voltMQ5=(float)sensorValueMQ5/1024*5.0;
    RS_gasMQ5 = (5.0-sensor_voltMQ5)/sensor_voltMQ5; // omit *RL

          
    ratioMQ5 = RS_gasMQ5/3.10;  // ratio = RS/3.10
    dtostrf(ratioMQ5,7,4, buff3);
         

    Serial.print("Valore mq5: ");
    Serial.println(buff3);
    Wire.write(buff3);
    
  }

  if(check==4)//MQ3
  {
    float sensor_voltMQ3;
    float RS_gasMQ3; // Get value of RS in a GAS
    float ratioMQ3; // Get ratio RS_GAS/RS_air
    int sensorValueMQ3 = analogRead(A3);
    sensor_voltMQ3=(float)sensorValueMQ3/1024*5.0;
    RS_gasMQ3 = (5.0-sensor_voltMQ3)/sensor_voltMQ3; // omit *RL

    /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
    ratioMQ3 = RS_gasMQ3/0.22;  // ratio = RS/R0
    dtostrf(ratioMQ3,7,4, buff4);
         

    Serial.print("Valore mq3: ");
    Serial.println(buff4);
    Wire.write(buff4);
    
  }




  


  

  
  
}



    
  
  

  


