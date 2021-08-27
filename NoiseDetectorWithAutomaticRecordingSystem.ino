int const trigPin = 12; int const echoPin = 4; int const buzzPin = 8;


This initialization helps to allot each pin to pin serial no.s. void setup()
{
pinMode(trigPin, OUTPUT); // trig pin will have pulses outpu pinMode(echoPin, INPUT); // echo pin should be input to get pulse width pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering Serial.begin(9600);
}


This Declaration is to configure the pins to either output or input.



void loop()
{
// Duration will be the input pulse width and distance will be the distance to the obstacle in Centimeters
int duration, distance;
// Output pulse with 1ms width on trigPin digitalWrite(trigPin, LOW);
delay(10); digitalWrite(trigPin,HIGH);

delay(2);



digitalWrite(trigPin,LOW);
// Measure the pulse input in echo pin duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)


distance = (duration/2) / 29.1; Serial.println(distance);
// if distance less than 0.5 meter and more than 0 (0 or less means over range) if (distance <= 10 && distance >= 0) {
// Buzz
digitalWrite(buzzPin, HIGH);
} else {
// Don't buzz digitalWrite(buzzPin, LOW);
}
// Waiting 60 ms won't hurt any one delay(60);
}
