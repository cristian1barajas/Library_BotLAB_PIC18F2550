/*
 * File:   BotLAB.h
 * Author: Ing Christian Barajas
 * Libreria para definir metodos más sencillos para la configuracián del micro.
 * 
 * BotLABco
 * Created on 11 de octubre de 2020, 03:47 PM
 */

#include <xc.h>

#define _XTAL_FREQ 20000000 // Frecuencia de oscilacion de la CPU para el uso de los Delays

#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

void setupAnalogDigitalInput(int); // Método para seleccionar cantidad de entradas analogas.
int analogRead(int);
int readChannel(int);
void pinMode(int, int);
void digitalWrite(int, int);
void SerialBegin(long BAUD);
void SerialPrintChar(char data);
char SerialRead();
void SerialPrint(char *str);
void SerialPrintln(char *str);
char String(int value);