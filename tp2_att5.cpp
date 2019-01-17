#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#define ALL_PINS_OUTPUT 0xff
#define ALL_PINS_INPUT 0x00
#define ROUGE 0x02
#define VERT 0x01
#define NONE 0x00





 int main()
{ 
  DDRA = ALL_PINS_OUTPUT; 
  DDRD = ALL_PINS_INPUT; 
  



int counter = 0;

for (;;)
{  
    if (counter == 0)
        PORTA = ROUGE;
    else if (counter == 1)
        PORTA = VERT;
    else if (counter == 2)
        PORTA = NONE;

    if (PIND & 0x04)
    {
        _delay_ms (10);
        while (PIND & 0x04)
        {
            
            bool checker = 0;
            while(checker == 0)
            {
                if (counter == 0)
                {
                    PORTA = VERT;
                    _delay_ms (1);
                    PORTA = ROUGE;
                    _delay_ms (1);
                }
                else if (counter == 1)
                    PORTA = ROUGE;

                else if (counter == 2)
                    PORTA = VERT;
                    
                if ((PIND & 0x04) == 0)
                {
                    checker = 1;
                    counter++;
                    if (counter == 3)
                        counter = 0;
                        
                }
            }
        }
    }  
}

}

