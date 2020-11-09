/*
 * File:   main.c
 * Author: Ing Christian Barajas
 * Proyecto diseñado para poner en marcha la tarjeta fabricada en China por JLCPCB
 * debido a que el compilador de CCS no trabaja bien con las entradas analogas.
 * 
 * BotLABco
 * Created on 11 de octubre de 2020, 03:47 PM
 */

#include <xc.h>
#include "config.h"
#include "BotLAB.h"

const int LED = 24;
const int myChannel = 0;
const int numChannels = 1;

int valueAnalog;
char letra;

void main(void) {
    SerialBegin(9600);
    setupAnalogDigitalInput(numChannels);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    while (1) {
        valueAnalog = analogRead(myChannel);
        SerialPrint("Valor: ");
        SerialPrintln(String(valueAnalog));
        if (valueAnalog > 512) {
            digitalWrite(LED, HIGH);
            __delay_ms(2);
            digitalWrite(LED, LOW);
            __delay_ms(7.8);
        } else {
            digitalWrite(LED, HIGH);
            __delay_ms(1.65);
            digitalWrite(LED, LOW);
            __delay_ms(8.2);
        }
    }
    return;
}
