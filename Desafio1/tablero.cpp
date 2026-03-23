#include "tablero.h"
#include <iostream>

using namespace std;

void imprimirTablero(unsigned char** tablero, int alto, int ancho){
    for(int i = 0; i < alto; i++){
        cout << "|";
        for(int j = 0; j < ancho / 8; j++){
            for(int k = 7; k >= 0; k--){
                int bit = (tablero[i][j] >> k) & 1;
                if (bit == 1)
                    cout << "#";
                else
                    cout << ".";
            }
        }
        cout << "|" << endl;
    }
    cout << "Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q] Salir: ";
}

void setbit(unsigned char** tablero, int fila, int col, int ancho){
    int byte = col / 8;
    int bit = 7 - (col % 8);
    tablero[fila][byte] |= (1 << bit);
}

void clearbit(unsigned char** tablero, int fila, int col, int ancho){
    int byte = col / 8;
    int bit = 7 - (col % 8);
    tablero[fila][byte] &= ~(1 << bit);
}

int getbit(unsigned char** tablero, int fila, int col, int ancho){
    int byte = col / 8;
    int bit = 7 - (col % 8);
    return (tablero[fila][byte] >> bit) & 1;
}
