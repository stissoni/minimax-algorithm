#include <stdio.h>

const int JUGADOR = -1;
const int COMPUTADORA = 1;
const int NULO = 0;
const int TAMANO_TABLERO = 9;
const char CRUZ = 'X';
const char CERO = 'O';
const char CARACTER_VACIO = ' ';
const long int INFINITO = 999;

char imprimir_jugada(int i) {
    if (i == JUGADOR)  
        return CRUZ;
    if (i == COMPUTADORA)
        return CERO;
    else
        return CARACTER_VACIO;
    
}

void imprimir_tablero(int t[9], int i) {
    if (i == 0){
        printf(" %i | %i | %i\n",1,2,3);
        printf("---+---+---\n");
        printf(" %i | %i | %i\n",4,5,6);
        printf("---+---+---\n");
        printf(" %i | %i | %i\n",7,8,9);

    }
    else{
        printf(" %c | %c | %c\n",imprimir_jugada(t[0]),imprimir_jugada(t[1]),imprimir_jugada(t[2]));
        printf("---+---+---\n");
        printf(" %c | %c | %c\n",imprimir_jugada(t[3]),imprimir_jugada(t[4]),imprimir_jugada(t[5]));
        printf("---+---+---\n");
        printf(" %c | %c | %c\n",imprimir_jugada(t[6]),imprimir_jugada(t[7]),imprimir_jugada(t[8]));
    }
}

int verificar_ganador(int tablero[TAMANO_TABLERO]) {
    unsigned combinaciones_ganadoras[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(tablero[combinaciones_ganadoras[i][0]] != 0 &&
           tablero[combinaciones_ganadoras[i][0]] == tablero[combinaciones_ganadoras[i][1]] &&
           tablero[combinaciones_ganadoras[i][0]] == tablero[combinaciones_ganadoras[i][2]])
            return tablero[combinaciones_ganadoras[i][2]];
    }
    return NULO;
}

int minimax(int tablero[TAMANO_TABLERO], int jugador) {
    if(verificar_ganador(tablero) != 0) 
        return verificar_ganador(tablero) * jugador;
    int i;
    int movimiento = -1;
    int puntaje = -2;
    for(i = 0; i < 9; ++i) {
        if(tablero[i] == NULO) {
            tablero[i] = jugador;

            int minimax_puntaje = -minimax(tablero, jugador*-1);
            if(minimax_puntaje > puntaje) {
                puntaje = minimax_puntaje;
                movimiento = i;
            }
            tablero[i] = 0;
        }
    }
    if (movimiento == -1) 
        return 0;
    
    return puntaje;
}

void movimiento_computadora(int tablero[TAMANO_TABLERO]) {
    int movimiento;
    int mejor_puntaje = -INFINITO;
    int i;
    for(i = 0; i < TAMANO_TABLERO; ++i) {
        if (tablero[i] == 0){
            tablero[i] = 1;
            int puntaje = -minimax(tablero, -1);
            tablero[i] = 0;
            if (puntaje > mejor_puntaje){
                mejor_puntaje = puntaje;
                movimiento = i;
            }
        }
    }
    
    tablero[movimiento] = 1;
}

void movimiento_jugador(int tablero[TAMANO_TABLERO]) {
    int movimiento = 0;
    do {
        printf("\nIngrese su jugada (1-9): ");
        scanf("%d", &movimiento);
        printf("\n");
    } while (((movimiento - 1) >= TAMANO_TABLERO || (movimiento - 1) < 0) || (tablero[(movimiento -1)] != NULO));
    
    tablero[(movimiento - 1)] = JUGADOR;
}

int main() {
    int tablero[9] = {0,0,0,0,0,0,0,0,0};
    int jugador = 0;
    do {
        printf("Eres X, la computadora es O\nJuegas primero o segundo?: ");
        scanf("%d",&jugador);
        printf("\n");
    } while (jugador != 1 && jugador !=2);
    
    unsigned turno;
    for(turno = 0; turno < 9 && verificar_ganador(tablero) == 0; ++turno) {
        if((turno + jugador) % 2 == 0)
            movimiento_computadora(tablero);
        else {
            imprimir_tablero(tablero, turno);
            movimiento_jugador(tablero);
        }
    }

    if (verificar_ganador(tablero) == JUGADOR){
        imprimir_tablero(tablero, turno);
        printf("Has ganado\n");
    }
    if (verificar_ganador(tablero) == COMPUTADORA){
        imprimir_tablero(tablero, turno);
        printf("Has perdido\n");
    }

    if (verificar_ganador(tablero) == NULO){
        imprimir_tablero(tablero, turno);
        printf("Empate\n");
    }
}