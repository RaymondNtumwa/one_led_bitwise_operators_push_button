void setup() 
{ DDRB |= (1 << 5);   // Set Pin 13 (Port B, Bit 5) as OUTPUT 
  DDRD &= ~(1 << 2);  // Set Pin 2 (Port D, Bit 2) as INPUT
}
void loop() {
  static bool ledState = false;
  
  //1. Detect if the button is pressed(Active HIGH for Pull-down)
  
  if (PIND & (1<<2)) {
    
    //2.Debounce Delay
    delay(50);
    //3. Re-verify: Is it STILL HIGH after 50ms?
    
  if (PIND & (1 << 2)) 
  {
    //4. Toggle Logic
    ledState = !ledState;
    if (ledState) PORTB |= (1<<5);
    else PORTB &= ~(1<<5);
    
    //5.Wait for Release: Loop while the button is still HIGH
    while (PIND & (1<<2));
    delay(50); //Debounce the release
  } 
 }
}