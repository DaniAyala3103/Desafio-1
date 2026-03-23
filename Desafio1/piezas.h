#ifndef PIEZAS_H
#define PIEZAS_H


//pieza O cuadrado 2*2
//0000 0110 0110 0000 => 0x0660
const unsigned short pieza_O = 0x0660;

//pieza I linea 1*4 horizontal
//0000 1111 0000 0000 => 0x0F00
const unsigned short pieza_I = 0x0F00;

//pieza T 3*2 (hacia abajo)
//0000 1110 0100 0000 => 0x0E40
const unsigned short pieza_T = 0x0E40;

//pieza S 3*2
//0000 1110 1100 0000 => 0x06C0
const unsigned short pieza_S = 0x06C0;

//pieza L 2*3
//0000 1110 1000 0000 => 0xE80
const unsigned short pieza_L = 0xE80;

void colocarPieza(unsigned char** tablero, unsigned short pieza, int posFila, int posCol, int anchoTablero);
void borrarPieza(unsigned char** tablero, unsigned short pieza, int posFila, int posCol, int anchoTablero);
unsigned short rotarDerecha(unsigned short pieza);



#endif // PIEZAS_H
