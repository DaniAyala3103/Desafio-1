#ifndef TABLERO_H
#define TABLERO_H
// Acá declaramos las funciones visuales y las de matriz
void imprimirTablero(unsigned char** tablero, int alto, int ancho);
void setbit(unsigned char** tablero, int fila, int col, int ancho);
void clearbit(unsigned char** tablero, int fila, int col, int ancho);
int getbit(unsigned char** tablero, int fila, int col, int ancho);
#endif // TABLERO_H
