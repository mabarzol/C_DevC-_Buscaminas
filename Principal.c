#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define _SINBOMBA -2
#define _BOMBA -1
#define _SINJUGAR -3
#define _ESTADOPERDEDOR 0
#define _ESTADOGANADOR 1
#define _ESTADOENJUEGO 2
#define _MARCADO -9
#define _TAM 100
#define SPA " "
struct jugador{
int cod;
char nombre[_TAM]; //campo “nombre”, estructura “jugador”.
char modo[_TAM]; //campo “modo”, estructura “jugador”.
int puntos; //campo “puntos”, estructura “jugador”.
int segundos; //campo “segundos”, estructura “jugador”.
};
struct record{
int cod;
char nombre[_TAM]; //campo “nombre”, estructura “jugador”.
int puntos; //campo “puntos”, estructura “jugador”.
int segundos; //campo “segundos”, estructura “jugador”.
};
#include "Funciones.h"
int main(void){
	int recuerdo[_TAM];
	int n=0;
	int _COLUMNAS=0;
    int _FILAS=0;
    int campo[_TAM][_TAM];
	int jugadas[_TAM][_TAM];
    int nbombas=0;
    int opt=-1;
    int conf[3];
    int njugadores;
    int codjugador;
    int salmenu1=0;
    int modalidad=0;
    int npric,ninte,nexp;
    struct jugador losquejuegan[_TAM];
    struct record principiante[_TAM];
    struct record intermedio[_TAM];
    struct record experto[_TAM];
    leerJugadores("jugadores.txt",losquejuegan,&njugadores);
    
	
	srand(time(NULL));
	while (opt!=0){
		opt=getmenu();
		switch(opt){
			case 1:
				leerConfiguracion("configuracion.txt", conf);
				_COLUMNAS=conf[0];
        		_FILAS=conf[1];
        		nbombas=conf[2];
        		opt=-1;
        		npric=0,ninte=0,nexp=0;
				menuJugadores(losquejuegan,&njugadores,&codjugador,&salmenu1);
        		if(salmenu1!=1){
       				jugando(jugadas,campo,_FILAS,_COLUMNAS,nbombas,losquejuegan,njugadores,codjugador,principiante,intermedio,experto,&npric,&ninte,&nexp);
       			}
		break;
			case 2:
				modoJuego(conf);
				opt=1;
		break;
			case 3:
				registrarJugador(losquejuegan,&njugadores);
				opt=1;
		break;
			case 4:
					leerRecord("principiante.txt",principiante,&npric);
					leerRecord("intermedio.txt",intermedio,&ninte);
					leerRecord("experto.txt",experto,&nexp);
					mostrarRecord(principiante, npric, intermedio, ninte, experto, nexp);
				opt=1;
		break;
			case 5:
				acercaDe();
				opt=1;
		break;
		}
	}
	getch();
	return 0;
}
