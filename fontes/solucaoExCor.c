#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    int vermelho;
    int verde;
    int azul;
} Cor;

void converterParaMaiusculas( char *str );
int compararCor( Cor *c1, Cor *c2 );

int main() {

    char strMai[] = "Avaliacao de CALC1";
    Cor c1 = { .vermelho = 200, .verde = 100, .azul = 150 };
    Cor c2 = { .vermelho = 200, .verde = 150, .azul = 100 };

    converterParaMaiusculas( strMai );

    printf( "Versao em maiusculas: %s\n", strMai );

    printf( "Cores em ordem crescente:\n" );
    if ( compararCor( &c1, &c2 ) < 0 ) {
        printf( "rgb{%d, %d, %d} <= rgb{%d, %d, %d}\n",
               c1.vermelho, c1.verde, c1.azul,
               c2.vermelho, c2.verde, c2.azul );
    } else {
        printf( "rgb{%d, %d, %d} <= rgb{%d, %d, %d}\n",
               c2.vermelho, c2.verde, c2.azul,
               c1.vermelho, c1.verde, c1.azul );
    }

    return 0;

}

void converterParaMaiusculas( char *str ) {

    int t = strlen( str );

    for ( int i = 0; i < t; i++ ) {
        str[i] = toupper( str[i] );
    }

}

int compararCor( Cor *c1, Cor *c2 ) {

    if ( c1->vermelho < c2->vermelho ) {
        return -1;
    } else if ( c1->vermelho > c2->vermelho ) {
        return 1;
    } else if ( c1->verde < c2->verde ) {
        return -1;
    } else if ( c1->verde > c2->verde ) {
        return 1;
    } else if ( c1->azul < c2->azul ) {
        return -1;
    } else if ( c1->azul > c2->azul ) {
        return 1;
    }

    return 0;

}
