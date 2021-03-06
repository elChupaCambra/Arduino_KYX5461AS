/*
 * KYX-5416AS library for simplifying printing to these types of displays.
 * Created by Claudio Cambra, 2020.
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 */

#include "Arduino.h"
#include "KYX5461AS.h"

KYX5461AS::KYX5461AS(int boardA, int boardB, int boardC, int boardD, int boardE, int boardF, int boardG, int boardDp, int boardD1, int boardD2, int boardD3, int boardD4) {
	_pinA = boardA;
	_pinB = boardB;
	_pinC = boardC;
	_pinD = boardD;
	_pinE = boardE;
	_pinF = boardF;
	_pinG = boardG;
	_pinDp = boardDp;
	_D1 = boardD1;
	_D2 = boardD2;
	_D3 = boardD3;
	_D4 = boardD4;
	
	pinMode(_pinA, OUTPUT);     
	pinMode(_pinB, OUTPUT);     
	pinMode(_pinC, OUTPUT);     
	pinMode(_pinD, OUTPUT);     
	pinMode(_pinE, OUTPUT);     
	pinMode(_pinF, OUTPUT);     
	pinMode(_pinG, OUTPUT); 
	pinMode(_pinDp, OUTPUT);
	pinMode(_D1, OUTPUT);  
	pinMode(_D2, OUTPUT);  
	pinMode(_D3, OUTPUT);  
	pinMode(_D4, OUTPUT);
}

void KYX5461AS::reset() {
  digitalWrite(_D1, HIGH);
  digitalWrite(_D2, HIGH);
  digitalWrite(_D3, HIGH);
  digitalWrite(_D4, HIGH);
  digitalWrite(_pinA, LOW);   
  digitalWrite(_pinB, LOW);   
  digitalWrite(_pinC, LOW);   
  digitalWrite(_pinD, LOW);   
  digitalWrite(_pinE, LOW);   
  digitalWrite(_pinF, LOW);   
  digitalWrite(_pinG, LOW);
  digitalWrite(_pinDp, LOW);
}

int KYX5461AS::print(char numToPrint, int displayDigit, bool decPoint = false) {
  int D1State, D2State, D3State, D4State;
  switch(displayDigit) {
    case 1:
      D1State = LOW;
      D2State = HIGH;
      D3State = HIGH;
      D4State = HIGH;
      break;
    case 2:
      D1State = HIGH;
      D2State = LOW;
      D3State = HIGH;
      D4State = HIGH;
      break;
    case 3:
      D1State = HIGH;
      D2State = HIGH;
      D3State = LOW;
      D4State = HIGH;
      break;
    case 4:
      D1State = HIGH;
      D2State = HIGH;
      D3State = HIGH;
      D4State = LOW;
      break;
  }

  digitalWrite(_D1, D1State);
  digitalWrite(_D2, D2State);
  digitalWrite(_D3, D3State);
  digitalWrite(_D4, D4State);

  int pinAstate, pinBstate, pinCstate, pinDstate, pinEstate, pinFstate, pinGstate;
  if(numToPrint - '0' < 10 && numToPrint - '0' >= 0) { //Check for numbers
    switch(numToPrint - '0') { //Convert charred numbers to int numbers
      case 0:
        pinAstate = HIGH;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = HIGH;   
        pinEstate = HIGH;   
        pinFstate = HIGH;   
        pinGstate = LOW;
        break;
      case 1:
        pinAstate = LOW;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = LOW;   
        pinEstate = LOW;   
        pinFstate = LOW;   
        pinGstate = LOW;
        break;
      case 2:
        pinAstate = HIGH;   
        pinBstate = HIGH;   
        pinCstate = LOW;   
        pinDstate = HIGH;   
        pinEstate = HIGH;   
        pinFstate = LOW;   
        pinGstate = HIGH;
        break;
      case 3:
        pinAstate = HIGH;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = HIGH;   
        pinEstate = LOW;   
        pinFstate = LOW;   
        pinGstate = HIGH;
        break;
      case 4:
        pinAstate = LOW;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = LOW;   
        pinEstate = LOW;   
        pinFstate = HIGH;   
        pinGstate = HIGH;
        break;
      case 5:
        pinAstate = HIGH;   
        pinBstate = LOW;   
        pinCstate = HIGH;   
        pinDstate = HIGH;   
        pinEstate = LOW;   
        pinFstate = HIGH;   
        pinGstate = HIGH;
        break;
      case 6:
        pinAstate = HIGH;   
        pinBstate = LOW;   
        pinCstate = HIGH;   
        pinDstate = HIGH;   
        pinEstate = HIGH;   
        pinFstate = HIGH;   
        pinGstate = HIGH;
        break;
      case 7:
        pinAstate = HIGH;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = LOW;   
        pinEstate = LOW; 
        pinFstate = LOW;   
        pinGstate = LOW;
        break;
      case 8:
        pinAstate = HIGH;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = HIGH;   
        pinEstate = HIGH;   
        pinFstate = HIGH;   
        pinGstate = HIGH;
        break;
      case 9:
        pinAstate = HIGH;   
        pinBstate = HIGH;   
        pinCstate = HIGH;   
        pinDstate = HIGH;   
        pinEstate = LOW;   
        pinFstate = HIGH;   
        pinGstate = HIGH;
        break;
    }
  } 
  //Section for actual characters
  else if(numToPrint == '-') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = LOW;   
    pinDstate = LOW;   
    pinEstate = LOW;   
    pinFstate = LOW;   
    pinGstate = HIGH;
  } 
  //Uppercase characters
  else if(numToPrint == 'A') {
		pinAstate = HIGH;   
    pinBstate = HIGH;   
    pinCstate = HIGH;   
    pinDstate = LOW;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = HIGH;
	} else if(numToPrint == 'C') {
		pinAstate = HIGH;
		pinBstate = LOW;
		pinCstate = LOW;
		pinDstate = HIGH;
		pinEstate = HIGH;
		pinFstate = HIGH;
		pinGstate = LOW;
	} else if(numToPrint == 'E') {
		pinAstate = HIGH;   
    pinBstate = LOW;   
    pinCstate = LOW;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = HIGH;
	} else if(numToPrint == 'F') {
		pinAstate = HIGH;   
    pinBstate = LOW;   
    pinCstate = LOW;   
    pinDstate = LOW;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = HIGH;
	} else if(numToPrint == 'G') {
		pinAstate = HIGH;   
    pinBstate = LOW;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = LOW;
	} else if(numToPrint == 'H') {
		pinAstate = LOW;   
    pinBstate = HIGH;   
    pinCstate = HIGH;   
    pinDstate = LOW;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = HIGH;
	} else if(numToPrint == 'I') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = LOW;   
    pinDstate = LOW;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = LOW;
	} else if(numToPrint == 'J') {
		pinAstate = LOW;   
    pinBstate = HIGH;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = LOW;   
    pinFstate = LOW;   
    pinGstate = LOW;
	} else if(numToPrint == 'L') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = LOW;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = LOW;
	} else if(numToPrint == 'P') {
		pinAstate = HIGH;
		pinBstate = HIGH;
		pinCstate = LOW;
		pinDstate = LOW;
		pinEstate = HIGH;
		pinFstate = HIGH;
		pinGstate = HIGH;
	} else if(numToPrint == 'U') {
		pinAstate = LOW;   
    pinBstate = HIGH;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = LOW;
	}
	//Lowercase characters
	else if(numToPrint == 'b') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = HIGH;
	} else if(numToPrint == 'c') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = LOW;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = LOW;   
    pinGstate = HIGH;
	} else if(numToPrint == 'd') {
		pinAstate = LOW;   
    pinBstate = HIGH;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = LOW;   
    pinGstate = HIGH;
	} else if(numToPrint == 'h') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = HIGH;   
    pinDstate = LOW;   
    pinEstate = HIGH;   
    pinFstate = HIGH;   
    pinGstate = HIGH;
	} else if(numToPrint == 'n') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = HIGH;   
    pinDstate = LOW;   
    pinEstate = HIGH;   
    pinFstate = LOW;   
    pinGstate = HIGH;
	} else if(numToPrint == 'o') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = LOW;   
    pinGstate = HIGH;
	} else if(numToPrint == 'q') {
		pinAstate = HIGH;
		pinBstate = HIGH;
		pinCstate = HIGH;
		pinDstate = LOW;
		pinEstate = LOW;
		pinFstate = HIGH;
		pinGstate = HIGH;
	} else if(numToPrint == 'r') {
		pinAstate = LOW;
		pinBstate = LOW;
		pinCstate = LOW;
		pinDstate = LOW;
		pinEstate = HIGH;
		pinFstate = LOW;
		pinGstate = HIGH;
	} else if(numToPrint == 't') {
		pinAstate = LOW;
		pinBstate = LOW;
		pinCstate = LOW;
		pinDstate = HIGH;
		pinEstate = HIGH;
		pinFstate = HIGH;
		pinGstate = HIGH;
	} else if(numToPrint == 'u') {
		pinAstate = LOW;   
    pinBstate = LOW;   
    pinCstate = HIGH;   
    pinDstate = HIGH;   
    pinEstate = HIGH;   
    pinFstate = LOW;   
    pinGstate = LOW;
	} else if(numToPrint == 'N') { //Setting for none
	  pinAstate = LOW;   
		pinBstate = LOW;   
		pinCstate = LOW;   
		pinDstate = LOW;   
		pinEstate = LOW;   
		pinFstate = LOW;   
		pinGstate = LOW;
	} else
		return 1;

  digitalWrite(_pinA, pinAstate);   
  digitalWrite(_pinB, pinBstate);   
  digitalWrite(_pinC, pinCstate);   
  digitalWrite(_pinD, pinDstate);   
  digitalWrite(_pinE, pinEstate);   
  digitalWrite(_pinF, pinFstate);   
  digitalWrite(_pinG, pinGstate);

  if(decPoint == true) 
    digitalWrite(_pinDp, HIGH);
  else
    digitalWrite(_pinDp, LOW);
  
  return 0;
}

int KYX5461AS::printInt(int num, bool displayTrailing = true, int delayBwNums = 4) {
  if (num < -999 || num > 9999)
    return 1;
  
  char outputArr[4];
  
  if(num >= 0) {
    outputArr[0] = (num%10000)/1000 + '0';
    outputArr[1] = (num%1000)/100 + '0';
    outputArr[2] = (num%100)/10 + '0';
    outputArr[3] = (num%10) + '0';
  } else {
    outputArr[0] = '-';
    outputArr[1] = (num%-1000)/-100 + '0';
    outputArr[2] = (num%-100)/-10 + '0';
    outputArr[3] = (num%-10)/-1 + '0';
  }
  
  for(int i = 0; i < sizeof outputArr; i++) {
		if(outputArr[i] == '0' && displayTrailing == false)
			::KYX5461AS::print('N',i+1); // Will cause nothing to be displayed
		else
			::KYX5461AS::print(outputArr[i],i+1);
    delay(delayBwNums);
  }
  
  return 0;  
}

void KYX5461AS::printNoDp(char nums[], int delayBwNums = 4) {
  for(int i = 0; i < 4; i++) {
    ::KYX5461AS::print(nums[i],i+1);
    delay(delayBwNums);
  }
}

void KYX5461AS::printAll(char nums[], bool dpPos[], int delayBwNums = 4) {
  for(int i = 0; i < 4; i++) {
    ::KYX5461AS::print(nums[i],i+1,dpPos[i]);
    delay(delayBwNums);
  }
}
