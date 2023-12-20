#include <XBee.h>
#include <LiquidCrystal.h>

XBee xbee = XBee();
Rx64Response rx = Rx64Response() ;
Tx64Request tx;
XBeeAddress64 addr;
uint8_t sdata[30] ;
uint8_t* rdata;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
	pinMode(2, INPUT);
	pinMode(13, OUTPUT);

	delay(100);
	Serial.begin(38400);
	xbee.setSerial(Serial);
	delay(100);
	lcd.begin(16, 2);
	lcd.setCursor(0,0);

}
void loop() {
	String x;
	x = digitalRead(2); 

	if((-48 +  (x.charAt(0)))==1) {
	sdata[0] = '1';
	for(int i=1; i < 30; i++) {
		sdata[i] = ' ';
	}
	addr = XBeeAddress64(, );
	tx = Tx64Request(addr, sdata, sizeof(sdata));
	xbee.send(tx);
	} 
 else {
	sdata[0] = '0';
	for(int i=1; i < 30; i++) {
		sdata[i] = ' ';
	}
	addr = XBeeAddress64(, );
	tx = Tx64Request(addr, sdata, sizeof(sdata));
	xbee.send(tx);
}
	delay(500);

}
