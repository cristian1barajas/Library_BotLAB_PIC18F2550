/*
 * File:   BotLAB.c
 * Author: BotLAB
 *
 * Created on 11 de octubre de 2020, 09:34 PM
 */

#include <xc.h>
#include "BotLAB.h"

#define _XTAL_FREQ 20000000

void setupAnalogDigitalInput(int inputs) {
    switch (inputs)
    {
    case 0: ADCON1 = 0X0F; break; // Ajusta todas las entradas analogas como digitales
    case 1: ADCON1 = 0X0E; break; // Ajusta 1 canal analogo
    case 2: ADCON1 = 0X0D; break; // Ajusta 2 canales analogos
    case 3: ADCON1 = 0X0C; break; // Ajusta 3 canales analogos
    case 4: ADCON1 = 0X0B; break; // Ajusta 4 canales analogos
    case 5: ADCON1 = 0X0A; break; // Ajusta 5 canales analogos
    case 6: ADCON1 = 0X09; break;  // Ajusta 6 canales analogos
    case 7: ADCON1 = 0X08; break;  // Ajusta 7 canales analogos
    case 8: ADCON1 = 0X07; break;  // Ajusta 8 canales analogos
    case 9: ADCON1 = 0X06; break;  // Ajusta 9 canales analogos
    case 10: ADCON1 = 0X05; break; // Ajusta 10 canales analogos
    case 11: ADCON1 = 0X04; break; // Ajusta 11 canales analogos
    case 12: ADCON1 = 0X03; break; // Ajusta 12 canales analogos
    case 13: ADCON1 = 0X02; break; // Ajusta todas las entradas analogas
    case 14: ADCON1 = 0X01; break; // Ajusta todas las entradas analogas
    case 15: ADCON1 = 0X00; break; // Ajusta todas las entradas analogas
    }
}

int analogRead(int channel) {
    int valueAnalog;
    switch (channel)
    {
    case 0: valueAnalog = readChannel(channel); break;
    case 1: valueAnalog = readChannel(channel); break;
    case 2: valueAnalog = readChannel(channel); break;
    case 4: valueAnalog = readChannel(channel); break;
    case 5: valueAnalog = readChannel(channel); break;
    case 6: valueAnalog = readChannel(channel); break;
    case 7: valueAnalog = readChannel(channel); break;
    case 8: valueAnalog = readChannel(channel); break;
    case 9: valueAnalog = readChannel(channel); break;
    case 10: valueAnalog = readChannel(channel); break;
    case 11: valueAnalog = readChannel(channel); break;
    case 12: valueAnalog = readChannel(channel); break;
    }
    return valueAnalog;
}

int readChannel(int channel) {
    int valueADC;
    ADCON0bits.CHS = channel;   // Selección del canal analogo
    ADCON2bits.ADCS = 0b000;    // Frecuencia de conversión
    ADCON2bits.ADFM = 1;        // Justificación a la derecha
    ADCON0bits.ADON = 1;        // ADC encendido o habilitado
    ADCON0bits.GO_nDONE = 1;    // Lanza la conversion
        while(ADCON0bits.GO_nDONE) 
        ;
            valueADC = ADRESH;
            valueADC = valueADC << 8;
            valueADC = valueADC + ADRESL;
    return valueADC;
}

void pinMode(int pin, int direction) {
    if (direction == 1)
    {
        switch (pin)
        {
        case 2: TRISAbits.RA0 = 1; break;
        case 3: TRISAbits.RA1 = 1; break;
        case 4: TRISAbits.RA2 = 1; break;
        case 5: TRISAbits.RA3 = 1; break;
        case 6: TRISAbits.RA4 = 1; break;
        case 7: TRISAbits.RA5 = 1; break;
        case 11: TRISCbits.RC0 = 1; break;
        case 12: TRISCbits.RC1 = 1; break;
        case 13: TRISCbits.RC2 = 1; break;
        case 17: TRISCbits.RC6 = 1; break;
        case 18: TRISCbits.RC7 = 1; break;
        case 21: TRISBbits.RB0 = 1; break;
        case 22: TRISBbits.RB1 = 1; break;
        case 23: TRISBbits.RB2 = 1; break;
        case 24: TRISBbits.RB3 = 1; break;
        case 25: TRISBbits.RB4 = 1; break;
        case 26: TRISBbits.RB5 = 1; break;
        case 27: TRISBbits.RB6 = 1; break;
        case 28: TRISBbits.RB7 = 1; break;
        }
    } else if (direction == 0)
    {
        switch (pin)
        {
        case 2: TRISAbits.RA0 = 0; break;
        case 3: TRISAbits.RA1 = 0; break;
        case 4: TRISAbits.RA2 = 0; break;
        case 5: TRISAbits.RA3 = 0; break;
        case 6: TRISAbits.RA4 = 0; break;
        case 7: TRISAbits.RA5 = 0; break;
        case 11: TRISCbits.RC0 = 0; break;
        case 12: TRISCbits.RC1 = 0; break;
        case 13: TRISCbits.RC2 = 0; break;
        case 17: TRISCbits.RC6 = 0; break;
        case 18: TRISCbits.RC7 = 0; break;
        case 21: TRISBbits.RB0 = 0; break;
        case 22: TRISBbits.RB1 = 0; break;
        case 23: TRISBbits.RB2 = 0; break;
        case 24: TRISBbits.RB3 = 0; break;
        case 25: TRISBbits.RB4 = 0; break;
        case 26: TRISBbits.RB5 = 0; break;
        case 27: TRISBbits.RB6 = 0; break;
        case 28: TRISBbits.RB7 = 0; break;
        }
    }
}

void digitalWrite(int pin, int state) {
    if (state == 1)
    {
        switch (pin)
        {
        case 3: PORTAbits.RA1 = 1; break;
        case 4: PORTAbits.RA2 = 1; break;
        case 2: PORTAbits.RA0 = 1; break;
        case 5: PORTAbits.RA3 = 1; break;
        case 6: PORTAbits.RA4 = 1; break;
        case 7: PORTAbits.RA5 = 1; break;
        case 11: PORTCbits.RC0 = 1; break;
        case 12: PORTCbits.RC1 = 1; break;
        case 13: PORTCbits.RC2 = 1; break;
        case 17: PORTCbits.RC6 = 1; break;
        case 18: PORTCbits.RC7 = 1; break;
        case 21: PORTBbits.RB0 = 1; break;
        case 22: PORTBbits.RB1 = 1; break;
        case 23: PORTBbits.RB2 = 1; break;
        case 24: PORTBbits.RB3 = 1; break;
        case 25: PORTBbits.RB4 = 1; break;
        case 26: PORTBbits.RB5 = 1; break;
        case 27: PORTBbits.RB6 = 1; break;
        case 28: PORTBbits.RB7 = 1; break;
        }
    } else if (state == 0)
    {
        switch (pin)
        {
        case 2: PORTAbits.RA0 = 0; break;
        case 3: PORTAbits.RA1 = 0; break;
        case 4: PORTAbits.RA2 = 0; break;
        case 5: PORTAbits.RA3 = 0; break;
        case 6: PORTAbits.RA4 = 0; break;
        case 7: PORTAbits.RA5 = 0; break;
        case 11: PORTCbits.RC0 = 0; break;
        case 12: PORTCbits.RC1 = 0; break;
        case 13: PORTCbits.RC2 = 0; break;
        case 17: PORTCbits.RC6 = 0; break;
        case 18: PORTCbits.RC7 = 0; break;
        case 21: PORTBbits.RB0 = 0; break;
        case 22: PORTBbits.RB1 = 0; break;
        case 23: PORTBbits.RB2 = 0; break;
        case 24: PORTBbits.RB3 = 0; break;
        case 25: PORTBbits.RB4 = 0; break;
        case 26: PORTBbits.RB5 = 0; break;
        case 27: PORTBbits.RB6 = 0; break;
        case 28: PORTBbits.RB7 = 0; break;
        }
    }
}

void SerialBegin(long BAUD){
    //Configuración de los pines
    TRISCbits.RC6 = 0;      //RC6 = Tx -> Salida
    TRISCbits.RC7 = 1;      //RC7 = Rx -> Entrad
    
    //Baudios
    SPBRG = (unsigned char)(((_XTAL_FREQ/BAUD)/64)-1);
    
    //Configuración 
    TXSTAbits.BRGH = 0;     //Low Speed
    TXSTAbits.SYNC = 0;     //Asincrono
    RCSTAbits.SPEN = 1;     //Habilitar Tx y Rx
    
    //Transmisión
    TXSTAbits.TX9 = 0;      //8 bits
    TXSTAbits.TXEN = 1;     //Activamos transmisión
    
    //Recepción
    RCSTAbits.RC9 = 0;      //8 bits
    RCSTAbits.CREN = 1;     //Activamos recepción
}

void SerialPrintChar(char data){
    while(TXSTAbits.TRMT == 0);
    TXREG = data;
}

char SerialRead(){
    return RCREG; 
}

void SerialPrint(char *str){
    while(*str != '\0'){
        SerialPrintChar(*str);
        str++;
    }
}

void SerialPrintln(char *str){
    while(*str != '\0'){
        SerialPrintChar(*str);
        str++;
    }
    SerialPrintChar('\r');
}

// this routine found online somewhere, then tweaked
 // returns pointer to ASCII string in a static buffer
 char String(int value) 
 {
     static char buffer[12];        // 12 bytes is big enough for an INT32
     int original = value;        // save original value
 
     int c = sizeof(buffer)-1;
 
     buffer[c] = 0;                // write trailing null in last byte of buffer    
 
     if (value < 0)                 // if it's negative, note that and take the absolute value
         value = -value;
     
     do                             // write least significant digit of value that's left
     {
         buffer[--c] = (value % 10) + '0';    
         value /= 10;
     } while (value);
 
     if (original < 0) 
         buffer[--c] = '-';
 
     return &buffer[c];
 }