#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <avr/sleep.h> 
#include <util/delay.h>


void valaszt(void);

void villog(void);


ISR(PCINT0_vect){
  while (!(PINB & (1 << PB2))){
    villog();
  }
  valaszt();
}

int main(){     
  DDRB = (1<<DDB0)|(1<<DDB1)|(1<<DDB3)|(1<<DDB4);

	PCMSK |= (1<<PB2);   

	MCUCR = (1<<ISC01) |(1<<ISC00); 

	GIMSK |= (1<<PCIE);  

	sei();  	           

	set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  while(1) {
    sleep_mode();
  }

}

void valaszt(void){
uint8_t szam = random(0,70);
uint8_t ertek = szam % 10;
  switch(ertek){
    case 1: case 0:
      PORTB |= (1<<PB0); //1
      _delay_ms(500);
      PORTB = ((1<<PB0)<<8);
    break;
    case 2:
      PORTB |= (1<<PB1); //2
      _delay_ms(500);
     PORTB = ((1<<PB1)<<8);
    break;
    case 3:
      PORTB |= (1<<PB0) | (1<<PB3); //3
      _delay_ms(500);
      PORTB = ((1<<PB0)<<8) | ((1<<PB3)<<8);
    break;
    case 4:
      PORTB |= (1<<PB1) | (1<<PB3); //4
      _delay_ms(500);
      PORTB = ((1<<PB1)<<8) | ((1<<PB3)<<8);
    break;
    case 5:
      PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB3);//5
      _delay_ms(500);
      PORTB = ((1<<PB0)<<8) | ((1<<PB1)<<8) | ((1<<PB3)<<8);
    break;
    case 6: case 7:
      PORTB |= (1<<PB1) | (1<<PB3) | (1<<PB4);//6
      _delay_ms(500);
      PORTB = ((1<<PB1)<<8) | ((1<<PB3)<<8) | ((1<<PB4)<<8);
    break;
    default:
    break;
  }


}

void villog(void){
  PORTB |= (1<<PB3);
  _delay_ms(100);
  PORTB = ((1<<PB3)<<8);
  _delay_ms(100);
  PORTB |= (1<<PB4);
  _delay_ms(100);
  PORTB = ((1<<PB4)<<8);
  _delay_ms(100);
  PORTB |= (1<<PB1);
  _delay_ms(100);
  PORTB = ((1<<PB1)<<8);
  _delay_ms(100);

}