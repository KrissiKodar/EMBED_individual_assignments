#include <Arduino.h>
#include <avr/delay.h>
#include <digital_out.h>
#include <Timer_msec.h>
#include <fifo.h>


int serial_data = 0; // for incoming serial data

Digital_out led(5);
Timer_msec timer1;

Fifo f;

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
	timer1.init(1000);
}

void loop()
{
	if (Serial.available() > 0)
	{
		// read the incoming byte:
		serial_data = Serial.read();
		
		// if serial_data is a number, put it in the fifo
		if (serial_data >= '1' && serial_data <= '9')
		{
			f.put(serial_data - '0');
		}
	}
}

ISR(TIMER1_COMPA_vect)
{
	// if fifo is full, turn on the led
	if (f.is_full())
	{
		led.set_hi();
	}
	else
	{
		led.set_lo();
	}
	if (!f.is_empty())
	{
		Serial.println(f.get());
	}
}
