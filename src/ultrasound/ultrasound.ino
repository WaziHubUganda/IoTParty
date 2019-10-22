//Connections for ultrasonic sensor
//Connect vcc to 5V, Trig to pin 2
//Echo to pin 3 then Gnd to Gnd

//Define Trig and Echo pins
#define trigPin 2
#define echoPin 3

//Define variables
long duration;
int  distance;

void setup() {

  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Begin serial communication at a baundrate of 9600
  Serial.begin(9600);
  
  }

  void loop() {
    
    //Clear the trigPin by setting it low
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);

    //Trigger the sensor by setting the trigPin high
    //for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Read the echoPin, pulsIn() returns the duration
    //(length of the pulse) in microseconds
    duration = pulseIn(echoPin, HIGH);

    //Calculate the distance
    distance = duration * 0.034/2;

    //Print the distance on the serial monitor
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println("cm");
    delay(50);
    
    }
