
#include <Servo.h>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */
char buffer[11];
Servo servo1  ; // Create a servo object
Servo servo2  ; // Create a second servo object

void setup() {
  // put your setup code here, to run once:
servo2.attach(2); // Attaches the servo on pin 2 to the                             SMALLER SERVO          Input- A
servo1.attach(4); // Attaches the servo on pin 4 to the                             BIGGER SERVO           Input- B
Serial.begin(115200);


float theta1[30]= {
28.9254327209564, 20.3095781944864 , 14.2993366147384  ,10.1899086544932 , 7.40144652795502 , 5.50615143490417 , 4.19180045212319 , 3.22523828313097 , 2.42775083816706 , 1.66091837438764 , 0.819502110332778, -0.171653028344224 , -1.35898918781101, -2.76152886528078, -4.37317657495474, -6.16656624828302, -8.09843343656939, -10.1159775731185 ,-12.1633329828851, -14.1872041797622, -16.1409566573485, -17.9868733077548, -19.6967074626499 ,-21.2509426718450, -22.6372604458148, -23.8486595120147 ,-24.8815376479671, -25.7339039077305, -26.4037705208570 ,-26.8876891808525
}; 

float theta2[30]= { -82.6256197352048,  -80.7027671163304, -78.1589319066323, -76.2422120977675, -75.3901694465971, -75.5908448198348, -76.6165015005762, -78.1730936125241 ,-79.9829204271800, -81.8185400328994, -83.5080619223439, -84.9278289170500, -85.9921693818924, -86.6448629420816, -86.8538855883759 ,-86.6093470795868, -85.9237443003384, -84.8334047286718, -83.4000954512905 ,-81.7120493309256 ,-79.8839129926821 ,-78.0551793329410, -76.3864716514140, -75.0527383191421 ,-74.2323848940867 ,-74.0921564126504, -74.7694625525796 ,-76.3561471444426 ,-78.8886959291789 ,-82.3480725394590
};

for (int i=0; i<30; i++){
servo1.write(theta1[i]);
servo2.write(theta2[i]);
delay(200);
}
}
void loop() {
  // put your main code here, to run repeatedly:

}