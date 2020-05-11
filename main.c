#include <stdio.h>

const int JUGADOR = -1;
const int COMPUTADORA = 1;
const int CASILLERO_VACIO = 0;
const int EMPATE = 0;
const int TAMANIO_TABLERO = 9;
const char CRUZ = 'X';
const char CERO = 'O';
const char CARACTER_VACIO = ' ';
const int INFINITO = 999;

void imprimir_tablero(int tablero[TAMANIO_TABLERO]);
void jugar_partida(int tablero[TAMANIO_TABLERO]);

int main() {
    int tablero[9] = {0,0,0,0,0,0,0,0,0};

    printf("\nLa computadora es X, tu eres O.\n\n");
    imprimir_tablero(tablero);
    printf("\nLA COMPUTADORA EMPIEZA.\n\n");
    
    jugar_partida(tablero);
    return 0;
}