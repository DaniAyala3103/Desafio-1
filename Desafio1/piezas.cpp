#include "piezas.h"
#include "tablero.h"

void colocarPieza(unsigned char **tablero, unsigned short pieza, int posFila, int posCol, int anchoTablero){

    for(int r=0; r<4; r++){ //recorremos la cuadricula 4*4 de la pieza
        for (int c=0; c<4;c++){
            int posicionBit=15-(r*4+c);//calculamos que bit estamos leyendo(del 15 hasta el 0)

            int bitActivo=(pieza>>posicionBit)&1; //extraemos el bit especifico usando un desplazamiento y la mascara AND 1

            if(bitActivo==1){//si el bit de la pieza es 1, se dibuja en el tablero
                setbit(tablero,posFila + r, posCol+c,anchoTablero);
            }


        }
    }
}
unsigned short rotarDerecha(unsigned short pieza){
    unsigned short piezaRotada=0; //iniciamos con 16bits en 0(0x0000)

    for (int r=0; r<4;r++){
        for (int c=0;c<4;c++){
            int posOriginal=15-(r*4+c);

            int posRotada=15-(c*4+(3-r));

            int bit =(pieza>>posOriginal)&1;

            if(bit==1){
                piezaRotada |=(1<<posRotada);
            }
        }
    }
    return piezaRotada;
}

void borrarPieza(unsigned char** tablero, unsigned short pieza, int posFila, int posCol, int anchoTablero){
    for(int r=0; r<4;r++){
        for(int c=0;c<4;c++){
            int posicionBit=15-(r*4+c);
            int bitActivo=(pieza>>posicionBit)&1;

            if(bitActivo==1){
                clearbit(tablero,posFila+r,posCol+c,anchoTablero);
            }
        }
    }
}
