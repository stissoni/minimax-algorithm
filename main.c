#include <stdio.h>
#include <stdbool.h>
#include "funciones_y_constantes.h"

int main() {
    int tablero[9] = {0,0,0,0,0,0,0,0,0};

    printf("\nLa computadora es X, tu eres O.\n\n");
    imprimir_tablero(tablero);
    printf("\nLA COMPUTADORA EMPIEZA.\n\n");
    
    int turno;
    for(turno = 0; turno < 9 && verificar_ganador(tablero) == EMPATE; turno++) {
        if (turno% 2 == 0){
            movimiento_computadora(tablero);
        }
        else {
            imprimir_tablero(tablero);
            movimiento_jugador(tablero);
            printf("\n");
        }
    }
    if (verificar_ganador(tablero) == COMPUTADORA){
        imprimir_tablero(tablero);
        printf("\nHas perdido!\n\n");
    }
    if (verificar_ganador(tablero) == CASILLERO_VACIO){
        imprimir_tablero(tablero);
        printf("\nHan empatado\n\n");
    }
}