#include <iostream>
#include <cstdlib>//nomas para usar rand(), xd
#include "tablero.h"
#include "piezas.h"
#include "juego.h"

using namespace std;


int main()
{
    int alto, ancho;
    cout<< ">>> Ingrese alto: ";
    cin>> alto;
    cout<<">>> Ingrese un ancho multiplo de 8: ";
    cin>> ancho;


    if(alto<8||ancho<8||ancho%8!=0){    //colocamos una validación para ingresar valores multiplos de 8
        cout<< "Error, dimensiones invalidas."<<endl;
        return 0;
    }
    unsigned char** tablero;    //creamos la memoria dinamica(matriz)
    tablero = new unsigned char*[alto];
    for(int i=0; i<alto;i++){
        tablero[i] = new unsigned char[ancho/8];

        for(int j=0;j<ancho/8;j++){
            tablero[i][j]=0;//la inicializamos en 0
        }
    }

    //damos inicio a la logica del juego
    int filaActual =0;
    int colActual =ancho /2 -2;
    unsigned short bancoPiezas[5]={pieza_O,pieza_I,pieza_T,pieza_S,pieza_L};//hacemos un banco de piezas

    int indiceAleatorio=rand()%5;       //elegimos la pieza al azar
    unsigned short piezaActual=bancoPiezas[indiceAleatorio];

    bool jugando = true;
    char accion;

    while(jugando){
        //dibujamos el tablero
        colocarPieza(tablero, piezaActual, filaActual, colActual,ancho);
        //system("cls");
        imprimirTablero(tablero,alto,ancho);

        borrarPieza(tablero,piezaActual,filaActual,colActual,ancho);


        cin>>accion;        //pedimos la acción y todo lo que registre, toupper lo vuelve mayuscula
        accion= toupper(accion);

        switch(accion){
        case 'A':    //mueve a la izda
            if(!hayColision(tablero,piezaActual,filaActual,colActual-1, alto, ancho)){
                colActual--;
            }
            break;
        case 'D':    //mueve a la derecha
            if(!hayColision(tablero,piezaActual,filaActual,colActual+1,alto,ancho)){
                colActual++;
            }
            break;

        case 'W':  //rota la pieza en sentido horario
        {
            unsigned short piezaRotada=rotarDerecha(piezaActual);
            if(!hayColision(tablero,piezaRotada,filaActual,colActual,alto,ancho)){
                piezaActual=piezaRotada;//si cabe, la rota, sino, pues nokass
            }
            break;
        }

        case 'S':   //baja o dejar fija
            if(!hayColision(tablero,piezaActual,filaActual+1,colActual,alto,ancho)){
                filaActual++;
            }else{
                colocarPieza(tablero,piezaActual,filaActual,colActual,ancho);

                limpiarFilas(tablero,alto,ancho);//revisamos si se llenó alguna fila y vamos borrando

                //presenciamos el nacimiento de una nueva pieza, jaja
                filaActual=0;
                colActual=ancho/2-2;
                int nuevoIndice=rand()%5;
                piezaActual=bancoPiezas[nuevoIndice];


                if(hayColision(tablero,piezaActual,filaActual,colActual,alto,ancho)){
                    jugando=false;
                    imprimirTablero(tablero,alto,ancho);
                    cout<<"*******************"<<endl;
                    cout<<">>>  Game Over  <<<"<<endl;
                    cout<<"*******************"<<endl;
                }
            }
            break;


        case 'Q':
            jugando=false;
            break;   //salimos del juego
        }

    }


    // setbit(tablero, fila, col, ancho);
    imprimirTablero(tablero, alto, ancho);



    for(int i=0;i<alto; i++){   //liberamos la memoria dinamica antes de salir
        delete[] tablero[i];
    }
    delete[]tablero;

    return 0;
}
