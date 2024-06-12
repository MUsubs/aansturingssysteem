#include "fib.hpp"

float fibonacci( int n ) {
  if ( n <= 1 ) {
    return n;
  }
  return fibonacci( n - 1 ) + fibonacci( n - 2 );
}

float measureTime( int n ) {
  unsigned long start = micros();
  fibonacci( n );
  unsigned long end = micros();
  return end - start;
}
void test(int nfib, unsigned long waiting_time_){

     float fib_n = fibonacci(nfib);
    
    Serial.print(fib_n);
    Serial.print(",");
  
    unsigned long currentTime = micros() - waiting_time_;
    Serial.print( currentTime );

    float temp = tempmonGetTemp();
    Serial.print(",");
    Serial.println(temp);
    delay(500);
}
void threadFib( int n ){
  
  // setup
  // loop
  int n_fib  = 1;
  //3 sec wachten om tijd te geven aan de python script
  bool cmd_recieved = false;
  unsigned long waiting_time = 0.0;
  while(!cmd_recieved){
    if (Serial.available() > 0) {
          String input = Serial.readStringUntil('\n'); // Lees de ontvangen data tot een newline
          Serial.print("Received: ");
          Serial.println(input);
          
          // Hier kun je de ontvangen data verwerken
          if (input == "start") {
              Serial.println("Starting Fibonacci calculations...");
              cmd_recieved = true;
              waiting_time = micros(); 
          } else {
              Serial.println("Unknown command");
          }
      }

      }
  int times = 0; 
  while(times < 6){// 2.5 min wachten
    while (n_fib < 30) {
    test(n_fib, waiting_time);
    n_fib++;
   }
    while(n_fib > 0){
    test(n_fib, waiting_time);
    n_fib--;
  }
  times++;
  }
  
  Serial.print("finished");
}
