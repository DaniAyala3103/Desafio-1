#ifndef JUEGO_H
#define JUEGO_H

bool hayColision(unsigned char**tablero, unsigned short pieza, int posFila, int posCol, int altoTablero, int anchoTablero);
void limpiarFilas(unsigned char**tablero, int alto, int ancho);

#endif // JUEGO_H
