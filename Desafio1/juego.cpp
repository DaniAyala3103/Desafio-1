#include "juego.h"
#include "tablero.h"

bool hayColision(unsigned char **tablero, unsigned short pieza, int posFila, int posCol, int altoTablero, int anchoTablero){
    //se recorren los 16 bits de la pieza
    for(int r=0;r<4;r++){
        for(int c=0;c<4;c++){
            int posicionBit=15-(r*4+c);
            int bitActivo =(pieza>>posicionBit)&1;

            if (bitActivo==1){//solo nos interesan los cudritos que forman la pieza
                int filaCalculada=posFila+r;
                int colCalculada=posCol+c;


                if(colCalculada<0||colCalculada>=anchoTablero){ //paredes izda y dere
                    return true;
                }

                if(filaCalculada>=altoTablero){     //piso del tablero
                    return true;
                }

                if (filaCalculada >=0){     //se encuentra con otra pieza, usamos getbit para leer la matriz a nivel de bits
                    if (getbit(tablero,filaCalculada,colCalculada,anchoTablero)==1){
                        return true;
                    }
                }

            }
        }
    }
    return false;       //una vez haya validado todo y ver que la ficha no tocó nada, el movimiento ta'legal jaja
}
void limpiarFilas(unsigned char** tablero, int alto, int ancho){
    int bytesporFila=ancho/8;

    for(int i=alto-1;i>=0;i--){
        bool filaLlena=true;

        for(int j=0; j<bytesporFila;j++){
            if(tablero[i][j]!=255){
                filaLlena=false;
                break;
            }
        }
        if(filaLlena){
            for(int k=i;k>0;k--){
                for(int j=0; j<bytesporFila;j++){
                    tablero[k][j]=tablero[k-1][j];
                }
            }

            for(int j=0;j<bytesporFila;j++){
                tablero[0][j]=0;
            }
            i++; //si bajó todo al piso, le toca volver a revisar la misma fila
        }
    }
}
