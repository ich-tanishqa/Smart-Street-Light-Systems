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
	xbee.readPacket();
	if (xbee.getResponse().isAvailable()) {
	if (xbee.getResponse().getApiId() == RX_64_RESPONSE) {

	xbee.getResponse().getRx64Response(rx);
	rdata = rx.getData();
	String x = "" ;
	for(int i=0; i<20; i++) {
		x += (char) rdata[i];
	}

	if((-48 +  (x.charAt(0)))==1) {
	digitalWrite(13, 1-('1'-'1'));
	} 
 else {
	digitalWrite(13, 1-('1'-'0'));
}

}
}
}
