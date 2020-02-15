#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//**
//* Funcion menus .- muestra el menu principal
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void menus(){
	system("COLOR a0");
	system("cls");
	printf("\n			B-U-S-C-A-M-I-N-A-S 2-0-1-4 \n");
    printf("\n		( 1 ) Jugar\n");
    printf("		( 2 ) Configuracion\n");
    printf("		( 3 ) Registro de Jugadores \n");
    printf("		( 4 ) Ver Registro de Record \n");
    printf("		( 5 ) Acerca de... \n");
    printf("		( 0 ) Salir \n\n");
}
void mparametro(){
	system("cls");
	printf("\n			C-O-N-F-I-G-U-R-A-C-I-O-N \n");
    printf("\n\n\n		 1 :  PRINCIPIANTE\n");
    printf("		 2 :  INTERMEDIO\n");
    printf("		 3 :  EXPERTO \n");
    printf("		 0 :  Salir \n");
}

void menuRegistro(struct jugador ms[], int t){
	system("COLOR 6a");
	system("cls");
	printf("\n		R-E-G-I-S-T-R-O--D-E--J-U-G-A-D-O-R-E-S \n");
    imprimirJugadores(ms,t);
	printf("\n\n\n	 1 : NUEVO JUGADOR\n");
    printf("	 2 : MODIFICAR JUGADOR\n");
    printf("	 3 : ELIMINAR JUGADOR\n");
    printf("	 0 : Salir \n\n\n");
}
//**
//* Funcion getmenu .- pide al usuario una opcion con respecto al menu
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
int getmenu(){
	int opt=0;
    menus();
    do{
    	if(!(opt>=0 && opt<=4)){
    	system("cls");
    	menus();
		printf("  [x]ERROR, LA OPCION INGRESADA NO ES VALIDA");
		}
    	printf("\n  ELIJA UNA OPCION: ");scanf("%d",&opt);
    }while(!(opt>=0 && opt<=5));
    system("cls");
    return opt;
}

//**
//* Funcion iniciarArr .- permite crear las dos matrices del juego, la primera es el tablero campo y la segunda es jugadas
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void iniciaArr(int campo[][_TAM], int jugadas[][_TAM], int f, int c){
	int i=0,j=0;
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            campo[i][j]=_SINBOMBA;
            jugadas[i][j]=0;
        }
    }
}

//**
//* Funcion agregaBombas .- permite agregar las bombas al tablero campo dependiendo del numero de bombas
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void agregaBombas(int nbombas,int campo[][_TAM], int f, int c){
    int i=1,x=0,y=0;
    while (i<=nbombas){
        do{
		x=rand()%(f);
        y=rand()%(c);
    	}while(campo[x][y]==_BOMBA);
        campo[x][y]=_BOMBA;
        i=i+1;
    }
}

//**
//* Funcion contar2 .- permite contar el numero de bombas existentes en el tablero campo y lo devuelve en una variable nbombas
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
int contar2(int x,int y,int campo[][_TAM], int f, int c){
    int nbombas=0;
    int i=0,j=0;
    for(i=x-1;i<x+2;i++){
        for (j=y-1;j<y+2;j++){
            if (i>=0 && i<f && j>=0 && j<c){
                if (campo[i][j]==_BOMBA){
                    nbombas++;
                }
            }
        }
    }
    return nbombas;
}

//**
//* Funcion establecerNumeros .- junto con la funcion contar2,  añade un numero cercano al lugar donde se encuentra la bomba 
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void establecerNumeros(int campo[][_TAM], int f, int c){
    int i=0,j=0,numero=0;
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            if (campo[i][j]==_SINBOMBA){
            	numero=contar2(i,j,campo,f,c);
                campo[i][j]=numero;
           	}
        }
    }
}

//**
//* Funcion imprimirp1 .- permite imprimir el tablero campo del nivel principiante
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void imprimirp1(int jugadas[][_TAM], int campo[][_TAM], int f, int c, int *tipo){
    system("COLOR 47");
	int k=0,i=0,j=0;
	if(f==9){
		printf("\n*******************************PRINCIPIANTE************************************");
		*tipo=1;
	}else if(f==16){
		printf("\n******************************INTERMEDIO***************************************");
		*tipo=2;
	}else if(f==30){
		printf("\n********************************EXPERTO****************************************");
		*tipo=3;
	}else{
		*tipo=-1;
	}
    printf("\n[  x ]");
    for(k=1;k<=c;k++){
        if(k>9){
        	printf(" %d ",k);
		}else{
        	printf("  %d ",k);
    	}
	}
    printf("\n-------------------------------------------------------------------------------\n");
    for (i=0;i<f;i++){
    	if(i>8){
        	printf("[ %d ]",i+1);
    	}else{
        	printf("[  %d ]",i+1);
        }
        for (j=0;j<c;j++){
            if(jugadas[i][j]==1){
                if(campo[i][j]==_BOMBA){
                    printf("  * ");
                }else if(campo[i][j]==_MARCADO){
                    printf("  M ");
                }else{
                    printf("  %d ",campo[i][j]);
                }
            }else{
					if(campo[i][j]==_MARCADO){
                		printf("  M ");
                	}else{
                		printf("  - ");
                	}
            }
        }
        printf("\n");
    }
}

//**
//* Funcion jugadaEnGrupo .- tiene dos funciones, la primera es verificar si el usuario toco una mina devolviendo el estado perdedor, la segunda es abrir 
//camino hacia los ceros que el usuario halla tocado al momento de selecionar una posicion en especial asignandole a su paso un uno en la matris jugadas indicando que esa posicion ya fue 
///abierta
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void jugadaEnGrupo(int x, int y,int jugadas[][_TAM], int campo[][_TAM], int f, int c,int *estado){
    int i=0,j=0;
    char PREGUNTA[_TAM];
    char pregunta2[_TAM];
    char pregunta3[_TAM];
	if(x>=0 && x<f && y>=0 && y<c){
        jugadas[x][y]=1;
        if(campo[x][y]==_BOMBA){
        	printf("CUAL ES LA CAPITAL DEL ECUADOR: ");scanf("%s",PREGUNTA);
        	if(strcmp("QUITO",PREGUNTA)==0){
        		*estado=_ESTADOENJUEGO;
        	}else{
            	printf("\nCUANTO ES LA CAPITAL DE COLOMBIA: ");scanf("%s",pregunta2);
            	if(strcmp("BOGOTA",pregunta2)==0){
            		*estado=_ESTADOENJUEGO;
            	}else{
            		printf("\ncual es la capital de estados unidos: ");scanf("%s",pregunta3);
            		if(strcmp("WASHINGTON",pregunta3)==0){
            			*estado=_ESTADOENJUEGO;
            		}else{
            			*estado=_ESTADOPERDEDOR;
            		}
            	}
				
            }
        }else if(campo[x][y]==0){
                for(i=x-1;i<x+2;i++){
                    for(j=y-1;j<y+2;j++){
                        if(i>=0 && i<f && j>=0 && j<c){
                            if(campo[i][j]==0 && jugadas[i][j]!=1){
                                jugadaEnGrupo(i,j,jugadas,campo,f,c,estado);
                            }else{
                                jugadas[i][j]=1;
                        	}
                    	}
                	}
            	}
    	}
    
	}
}


//**
//* Funcion contarJugadas .- cuenta las jugadas realizadas por el usuario y la devuelve en la variable numero
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
int contarJugadas(int jugadas[][_TAM],int f, int c){
    int numero=0;
    int i=0,j=0;
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            if(jugadas[i][j]==1){
                numero=numero+1;
            }
        }
    }
    return numero;
}



//**
//* Funcion marcar .- permite marcar y desmarcar una posicion selecionada por el usuario
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void marcar(int x,int y,int campo[][_TAM],int aux2,int *aux){
   *aux=aux2;
   if(campo[x][y]==_MARCADO){
   		campo[x][y]=*aux;
   }else{
        campo[x][y]=_MARCADO;
   }
}

//**
//* Funcion printAll .- Imprime la resolucion completa del tablero para verificar en donde el usuario fallo al momento de jugar
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void printAll(int campo[][_TAM], int f, int c){
	int k=0,i=0,j=0;
    printf("\n----------------------------------RESULTADOS-----------------------------------");
    printf("\n[  x ]");
    for(k=1;k<=c;k++){
        if(k>9){
        	printf(" %d ",k);
		}else{
        	printf("  %d ",k);
    	}
	}
    printf("\n-------------------------------------------------------------------------------\n");
    for(i=1;i<=f;i++){
        if(i>9){
        	printf("[ %d ]",i);
    	}else{
        	printf("[  %d ]",i);
        }
        for(j=1;j<=c;j++){
            if(campo[i-1][j-1]==_BOMBA){
                printf("  * ");
            }else if(campo[i-1][j-1]==_MARCADO){
                printf("  M ");
            }else{
                printf("  %d ",campo[i-1][j-1]);
            }
        }
        printf("\n");
    }
}

//**
//* Funcion convMS .- permite convertir el tiempo en formato de minutos y segundos en un areglo
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void convMS(int segundos,int *vector){
	int x=0,k=0;
	x=(segundos/60);//minutos
	k=segundos-(60*x);//segundos
	vector[0]=x;
	vector[1]=k;
}
//


//**
//* Funcion jugando .- ejecuta el proceso de juego utilizando todas las funciones existentes en este fichero
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void jugando(int jugadas[][_TAM], int campo[][_TAM], int _FILAS, int _COLUMNAS, int nbombas,struct jugador cmp[],int tam, int jugador,struct record p[],struct record i[],struct record e[],int *tp, int *ti, int *te){
				int njugadas=0;
				int x=0,y=0;
    			int aux=0;
    			int aux2=0;
    			int modo=0;
    			int estado=0;
				int time_taken=0,time_taken1=0,time_taken2=0,tiempos[2],tiempo_actual=0;
				int control=0;
				int tamp=0,tami=0,tame=0;
				char prueba[_TAM];
				int puntos=0;
				int segundos=0;
				char modalidad[_TAM];
				//modo de juego facil, intermedio, experto
				int modoJuego=0;
				//
				njugadas=0;
        		x=0,y=0;
        		aux=0;
        		aux2=0;
        		modo=1;
        		modoJuego=0;
        		control=0;
        		tamp=0,tami=0,tame=0;
        		estado= _ESTADOENJUEGO;
				iniciaArr(campo, jugadas, _FILAS, _COLUMNAS);
        		agregaBombas(nbombas,campo, _FILAS, _COLUMNAS);
        		establecerNumeros(campo, _FILAS, _COLUMNAS);
        		time_t now=0;
				time_taken=clock();
				leerRecord("principiante.txt",p,tp);
				leerRecord("intermedio.txt",i,ti);
				leerRecord("experto.txt",e,te);
        		while(estado==_ESTADOENJUEGO){
        			system("cls");
        			time_taken2=clock();
					time_taken1=(time_taken2-time_taken);
					tiempo_actual=(time_taken1/1000);
					convMS(tiempo_actual,tiempos);
					if(jugador==-2){
						strcpy(prueba,"JUGADOR DE PRUEBA");
						printf(" JUGADOR: %s",prueba);
						control=1;
					}else{
						printf(" JUGADOR: %s",cmp[jugador].nombre);
						control=-1;
					}
        			printf("\n				TIEMPO: %d:%d\n",tiempos[0],tiempos[1]);
        			imprimirp1(jugadas,campo,_FILAS,_COLUMNAS,&modoJuego);
        			do{
        				if(!(x>=0 && x<_FILAS && y>=0 && y<_COLUMNAS)){
        					system("cls");
        					time_taken2=clock();
							time_taken1=(time_taken2-time_taken);
							tiempo_actual=(time_taken1/1000);
							convMS(tiempo_actual,tiempos);
							if(jugador==-2){
								strcpy(prueba,"JUGADOR DE PRUEBA");
								printf(" JUGADOR: %s",prueba);
								control=1;
							}else{
								printf(" JUGADOR: %s",cmp[jugador].nombre);
								control=-1;
							}
        					printf("\n				TIEMPO: %d:%d\n",tiempos[0],tiempos[1]);
        					imprimirp1(jugadas,campo,_FILAS,_COLUMNAS,&modoJuego);
        					printf("[x]ERROR, LAS FILAS Y COLUMNAS INGRESADAS ESTAN FUERA DEL RANGO ESTABLECIDO");
        				}
						printf("\nFILAS: ");scanf("%d",&x);
						printf("COLUMNAS: ");scanf("%d",&y);
						x=x-1;
						y=y-1;
					}while (!(x>=0 && x<_FILAS && y>=0 && y<_COLUMNAS));
            		printf("\nMODO DE SELECCION\n");
            		printf("1.- Descubrir\n");
            		printf("2.- Marcar / Desmarcar \n");
            		do{
            			if(!(modo>=1 && modo<=2)){
            				printf("\n[x]ERROR, EL MODO INGRESADO NO ES VALIDO\n");
            			}
            		printf("Elija el modo de seleccion: ");scanf("%d",&modo);
            		}while(!(modo>=1 && modo<=2));
            			if(modo==1){
                			while(campo[x][y]!=_MARCADO){
                				jugadaEnGrupo(x,y,jugadas,campo,_FILAS,_COLUMNAS,&estado);
                				system("cls");
                				njugadas=contarJugadas(jugadas,_FILAS,_COLUMNAS);
                				if(njugadas==((_FILAS*_COLUMNAS) - nbombas)){
                				
                					estado=_ESTADOGANADOR;
                				}
                				break;
                			}
                			system("cls");
                
            			}else if(modo==2){
                    		while(jugadas[x][y]!=1){
                        		system("cls");
                        		if(campo[x][y]!=_MARCADO){
                             		aux2=campo[x][y];
                        		}
                        		marcar(x,y,campo,aux2,&aux);
                        		break;
                    		}
                    		if(campo[x][y]==_MARCADO && jugadas[x][y]==1){
                        		campo[x][y]=aux2;
                        		jugadas[x][y]=0;
                    		}
							system("cls");
            			}
            
            	}
        		if(estado == _ESTADOPERDEDOR){
        			time_taken2=clock();
					time_taken1=(time_taken2-time_taken);
					tiempo_actual=(time_taken1/1000);
					convMS(tiempo_actual,tiempos);
					printf(" JUGADOR: %s",cmp[jugador].nombre);
					printf("\n				TIEMPO: %d:%d\n",tiempos[0],tiempos[1]);
            		imprimirp1(jugadas,campo,_FILAS,_COLUMNAS,&modoJuego);
            		printf("%s PERDISTE\n",cmp[jugador].nombre);
            		printf("SOLUCION: \n");
            		printAll(campo,_FILAS,_COLUMNAS);
            		printf("\n");
            		printf("EL tiempo transcurrido fue: \n");
            		printf("MINUTOS: %d SEGUNDOS: %d\n",tiempos[0],tiempos[1]);
            		if(modoJuego==1){
            			if(control==-1){
//						////////////principiante//////////////////////
							strcpy(cmp[jugador].modo,"PRINCIPIANTE");
							cmp[jugador].puntos=0;
							cmp[jugador].segundos=tiempo_actual;
							modificaJugador(cmp, tam, "jugadores.txt", 2, jugador,cmp[jugador].modo, cmp[jugador].puntos, cmp[jugador].segundos);
							leerJugadores("jugadores.txt",cmp,&tam);
							agregarRecord(p, *tp, "principiante.txt",cmp, jugador);
							leerRecord("principiante.txt",p,tp);
							printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",cmp[jugador].puntos,cmp[jugador].modo);
						}else if(control==1){
							////////////NIVEL PRUEBA//////////////////////
							strcpy(modalidad,"PRINCIPIANTE");
							puntos=0;
							segundos=tiempo_actual;
							printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",puntos,modalidad);
						}
					}else if(modoJuego==2){
						if(control==-1){
//						////////////intermedio//////////////////////
						strcpy(cmp[jugador].modo,"INTERMEDIO");
						cmp[jugador].puntos=0;
						cmp[jugador].segundos=tiempo_actual;
						modificaJugador(cmp, tam, "jugadores.txt", 2, jugador,cmp[jugador].modo, cmp[jugador].puntos, cmp[jugador].segundos);
						leerJugadores("jugadores.txt",cmp,&tam);
						agregarRecord(i, *ti, "intermedio.txt",cmp, jugador);
						leerRecord("intermedio.txt",i,ti);
						printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",cmp[jugador].puntos,cmp[jugador].modo);
						}else if(control==1){
							////////////NIVEL PRUEBA//////////////////////
							strcpy(modalidad,"INTERMEDIO");
							puntos=0;
							segundos=tiempo_actual;
							printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",puntos,modalidad);
						}
					}else if(modoJuego==3){
						if(control==-1){
//						////////////experto//////////////////////
						strcpy(cmp[jugador].modo,"EXPERTO");
						cmp[jugador].puntos=0;
						cmp[jugador].segundos=tiempo_actual;
						modificaJugador(cmp, tam, "jugadores.txt", 2, jugador,cmp[jugador].modo, cmp[jugador].puntos, cmp[jugador].segundos);
						leerJugadores("jugadores.txt",cmp,&tam);
						agregarRecord(e, *te, "experto.txt",cmp, jugador);
						leerRecord("experto.txt",e,te);
						printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",cmp[jugador].puntos,cmp[jugador].modo);
						}else if(control==1){
							////////////NIVEL PRUEBA//////////////////////
							strcpy(modalidad,"EXPERTO");
							puntos=0;
							segundos=tiempo_actual;
							printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",puntos,modalidad);
						}
					}
            		printf("PRESIONE UNA TECLA PARA CONTINUAR: ");
					getch();
        		}else{
            		//n=n+1;
            		time_taken2=clock();
					time_taken1=(time_taken2-time_taken);
					tiempo_actual=(time_taken1/1000);
					convMS(tiempo_actual,tiempos);
					printf(" JUGADOR: %s",cmp[jugador].nombre);
					printf("\n				TIEMPO: %d:%d\n",tiempos[0],tiempos[1]);
					imprimirp1(jugadas,campo,_FILAS,_COLUMNAS,&modoJuego);
            		printf("%s GANASTE !\n",cmp[jugador].nombre);
            		printAll(campo,_FILAS,_COLUMNAS);
            		printf("\n");
            		printf("EL tiempo transcurrido fue: \n");
            		printf("MINUTOS: %d SEGUNDOS: %d\n\n",tiempos[0],tiempos[1]);
            		if(modoJuego==1){
            			if(control==-1){
//							////////////principiante//////////////////////
							strcpy(cmp[jugador].modo,"PRINCIPIANTE");
							if(tiempo_actual<=60){
								cmp[jugador].puntos=100;
							}else if(tiempo_actual<=300){
								cmp[jugador].puntos=50;
							}else{
								cmp[jugador].puntos=10;
							}
							cmp[jugador].segundos=tiempo_actual;
							modificaJugador(cmp, tam, "jugadores.txt", 2, jugador,cmp[jugador].modo, cmp[jugador].puntos, cmp[jugador].segundos);
							leerJugadores("jugadores.txt",cmp,&tam);
							agregarRecord(p, *tp, "principiante.txt",cmp, jugador);
							leerRecord("principiante.txt",p,tp);
							printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",cmp[jugador].puntos,cmp[jugador].modo);
							}else if(control==1){
								////////////NIVEL PRUEBA//////////////////////
								strcpy(modalidad,"INTERMEDIO");
								if(tiempo_actual<=60){
									puntos=100;
								}else if(tiempo_actual<=300){
									puntos=50;
								}else{
									puntos=10;
								}
								segundos=tiempo_actual;
								printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",puntos,modalidad);
							}
					}else if(modoJuego==2){
						if(control==-1){
//						////////////intermedio//////////////////////
						strcpy(cmp[jugador].modo,"INTERMEDIO");
						if(tiempo_actual<=120){
							cmp[jugador].puntos=100;
						}else if(tiempo_actual<=600){
							cmp[jugador].puntos=50;
						}else{
							cmp[jugador].puntos=10;
						}
						cmp[jugador].segundos=tiempo_actual;
						modificaJugador(cmp, tam, "jugadores.txt", 2, jugador,cmp[jugador].modo, cmp[jugador].puntos, cmp[jugador].segundos);
						leerJugadores("jugadores.txt",cmp,&tam);
						agregarRecord(i, *ti, "intermedio.txt",cmp, jugador);
						leerRecord("intermedio.txt",i,ti);
						printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",cmp[jugador].puntos,cmp[jugador].modo);
						}else if(control==1){
								////////////NIVEL PRUEBA//////////////////////
								strcpy(modalidad,"INTERMEDIO");
								if(tiempo_actual<=120){
									puntos=100;
								}else if(tiempo_actual<=600){
									puntos=50;
								}else{
									puntos=10;
								}
								segundos=tiempo_actual;
								printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",puntos,modalidad);
							}
					}else if(modoJuego==3){
							if(control==-1){
//						////////////experto//////////////////////
						strcpy(cmp[jugador].modo,"EXPERTO");
						if(tiempo_actual<=300){
							cmp[jugador].puntos=100;
						}else if(tiempo_actual<=1200){
							cmp[jugador].puntos=50;
						}else{
							cmp[jugador].puntos=10;
						}
						cmp[jugador].segundos=tiempo_actual;
						modificaJugador(cmp, tam, "jugadores.txt", 2, jugador,cmp[jugador].modo, cmp[jugador].puntos, cmp[jugador].segundos);
						leerJugadores("jugadores.txt",cmp,&tam);
						agregarRecord(e, *te, "experto.txt",cmp, jugador);
						leerRecord("experto.txt",e,te);
						printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",cmp[jugador].puntos,cmp[jugador].modo);
						}else if(control==1){
								////////////NIVEL PRUEBA//////////////////////
								strcpy(modalidad,"INTERMEDIO");
								if(tiempo_actual<=300){
									puntos=100;
								}else if(tiempo_actual<=1200){
									puntos=50;
								}else{
									puntos=10;
								}
								segundos=tiempo_actual;
								printf("SU PUNTAJE FUE: %d EN EL NIVEL: %s\n\n",puntos,modalidad);
						}
					}
            		printf("PRESIONE UNA TECLA PARA CONTINUAR: ");
            		getch();
        			//
        		}
}
//**
//* Funcion leerConfiguracion .- lee los parametros de un archivo y obtiene el numero de columnas, filas y numero de bombas en el menu principal
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void leerConfiguracion(char path[], int *parametros){
	int i=0;
	FILE *archivo;
    archivo=fopen(path, "r");
    if(archivo!=NULL){
    	while(!feof(archivo)){
    		fscanf(archivo,"%d\n",&parametros[i]);
    		i++;
    	}
    }
    fclose(archivo);
}



//**
//* Funcion guardarConfiguracion .- guarda los parametros de un archivo como el numero de columnas, filas y numero de bombas
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void guardarConfiguracion(char path[], int *parametros){
	int i=0;
	FILE *archivo;
    archivo=fopen(path, "w");
    if(archivo!=NULL){
    	while(i<3){
    		fprintf(archivo,"%d\n",parametros[i]);
    		i++;
    	}
    }
    fclose(archivo);
}

//**
//* Funcion modoJuego .- Muestra un menu con las configuraciones del tablero y del tipo de juego que desea el usuario
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void modoJuego(int *parametros){
	int opt=0;
	system("COLOR b6");
	mparametro();
	do{
		if(!(opt>=0 && opt<=3)){
			mparametro();
    		printf("  [x]ERROR, LA OPCION INGRESADA NO ES VALIDA");
		}
		printf("\n  ELIJA UNA OPCION: ");scanf("%d",&opt);
	}while(!(opt>=0 && opt<=3));
	if(opt==1){
		parametros[0]=9;
		parametros[1]=9;
		parametros[2]=10;
	}else if(opt==2){
		parametros[0]=16;
		parametros[1]=16;
		parametros[2]=40;
	}else if(opt==3){
		parametros[0]=16;
		parametros[1]=30;
		parametros[2]=99;
	}else{
		return;
	}
	guardarConfiguracion("configuracion.txt",parametros);
	printf("\n	Puff... Ingreso de configuracion Exitoso!!!");
	getch();
	return;
}

int mostrarJugar(struct jugador cmp[],int tam){
	system("COLOR e4");
	system("cls");
	printf("\n************************************MENU JUGAR*********************************\n");
	
    if(cmp[tam-1].cod!=-1){//si esta lleno
		imprimirJugadores(cmp,tam);
		printf("\n\n	-2 : IR AL REGISTRO DE JUGADORES\n");
		printf("	-3 : SALIR \n\n");
    	return 1;
    }else{		//si esta vacio
    	printf("\n\n		( -1) JUGADOR DE PRUEBAS");
    	printf("\n		( -2) IR AL REGISTRO DE JUGADORES\n");
    	printf("		( -3) SALIR \n\n");
    	return 2;
    }

    return 3;
}

//**
//* Funcion modoJuego .- Muestra un menu con las configuraciones del tablero y del tipo de juego que desea el usuario
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void menuJugadores(struct jugador cmp[], int *tamanio, int *jdevuelto, int *salida){
	int opt=-3;
	int menu2=0;
	int escogido=-1;
	int x=-1;
	int control;
do{
	x=-1;
	control=mostrarJugar(cmp,*tamanio);
	do{
		if(!( (opt>=-3 && opt<0) || (opt>0 && opt<*tamanio) )){
			control=mostrarJugar(cmp,*tamanio);
    		printf("  [x]ERROR, LA OPCION INGRESADA NO ES VALIDA");
		}
		printf("\n  ELIJA UNA OPCION: ");scanf("%d",&opt);
	}while(!( (opt>=-3 && opt<0) || (opt>0 && opt<*tamanio) ));
	if(opt==-3){
		*jdevuelto=-1;
		*salida=1;
		return;
	}else if(opt==-2){
		//registro de jugadores
		registrarJugador(cmp,tamanio);
		x=1;
	}else if(opt==-1){
		if(control==1){
			system("cls");
			printf("	[x]ERROR, OPCION INVALIDA\n	PRESIONE UNA TECLA PARA CONTINUAR Y ELIJA UNA OPCION VALIDA\n	LA PROXIMA VEZ...!");
			getch();
			x=1;
		}else if(control==2){
			//jugador de pruebas
			*salida=-1,
			*jdevuelto=-2;
			return;
			
		}
	}else{
		*salida=-1;
		*jdevuelto=opt;
		return;
	}
}while(x==1);
}

void asignarCadena(int palabrasXBloque, char *ptr, char codigo[], char nombre[], char modo[], char puntos[], char segundos[]){
	switch(palabrasXBloque){
		case 1:
			strcpy(codigo,ptr);
			break;
		case 2:
			strcpy(nombre,ptr);
			break;
		case 3:
			strcpy(modo,ptr);
			break;
		case 4:
			strcpy(puntos,ptr);
			break;
		case 5:
			strcpy(segundos,ptr);
			break;
	}
}

int validarSeparadores(char codigo[], char nombre[], char modo[], char puntos[], char segundos[]){
	if(strstr(codigo,SPA)||strstr(nombre,SPA)||strstr(modo,SPA)||strstr(puntos,SPA)||strstr(segundos,SPA)){
		return 1;
	}
	return 0;
}

void leerJugadores(char path[],struct jugador cmp[],int *con){
	int i=0;
	FILE *archivo;
	char cadena[_TAM],codigo[_TAM],nombre[_TAM],modo[_TAM],puntos[_TAM],segundos[_TAM];
	char separadores[]=",";
	char *ptr;
	int palabrasXBloque=0;
	int cnt=0;
	memset(cadena,0,_TAM);
	memset(codigo,0,_TAM);
	memset(nombre,0,_TAM);
	memset(modo,0,_TAM);
	memset(puntos,0,_TAM);
	memset(segundos,0,_TAM);
    archivo=fopen(path, "r");
    if(archivo!=NULL){
    	while(!feof(archivo)){
    		fgets(cadena,_TAM,archivo);
    		ptr=strtok(cadena,separadores);
    		palabrasXBloque++;
    		asignarCadena(palabrasXBloque,ptr,codigo,nombre,modo,puntos,segundos);
    		while((ptr = strtok(NULL, separadores)) !=NULL){
    			palabrasXBloque++;
    			asignarCadena(palabrasXBloque,ptr,codigo,nombre,modo,puntos,segundos);
    			if(palabrasXBloque==5 || validarSeparadores(codigo,nombre,modo,puntos,segundos)==1){
    			
    				cmp[cnt].cod=atoi(codigo);
    				strcpy(cmp[cnt].nombre,nombre);
    				strcpy(cmp[cnt].modo,modo);
    				cmp[cnt].puntos=atoi(puntos);
    				cmp[cnt].segundos=atoi(segundos);
    				palabrasXBloque=0;
    				memset(codigo,0,_TAM);
					memset(nombre,0,_TAM);
					memset(modo,0,_TAM);
					memset(puntos,0,_TAM);
					memset(segundos,0,_TAM);
    			}
    		}
    		cnt++;
    	}
    }
    fclose(archivo);

    	*con=cnt-1;
}

void imprimirJugadores(struct jugador ms[], int t){
	int i=0;
	for(i=1;i<t;i++){
		printf("\n		( %d ) %s",i,ms[i].nombre);
	}
}

///
void elejirJugador(struct jugador ms[], int tam, int *opt){
	int i=0;
	int op=-1;
	system("cls");
	printf("*****************************JUGADORES REGISTRADOS***************************\n\n");
	imprimirJugadores(ms,tam);
	printf("\n		( 0 ) IR AL REGISTRO DE JUGADORES \n");
	printf("\n");
	printf("\n\n	ELIJA CON QUE JUGADOR DESEA COMENZAR,\n	O ELIJA IR A LA OPCION DE REGISTROS: ");scanf("%d",&op);
	do{
		if(!(op>=0 && op<=tam)){
			system("cls");
			printf("*****************************JUGADORES REGISTRADOS***************************\n\n");
			imprimirJugadores(ms,tam);
			printf("\n		( 0 ) IR AL REGISTRO DE JUGADORES \n");
			printf("\n");
			printf("  [x]ERROR, EL JUGADOR SELECCIONADO NO ES VALIDO");
			printf("\n\n	ELIJA CON QUE JUGADOR DESEA COMENZAR,\n	O ELIJA IR A LA OPCION DE REGISTROS: ");scanf("%d",&op);
		}
	}while(!(op>=0 && op<=tam));
	
	*opt=op;//revisar esto.........
}
///

int buscarJugador(struct jugador ms[], int tam, int cod){
	int i=0;
	int op=0;
	int control=0;
	for(i=0;i<tam;i++){
		if(ms[i].cod==cod){
			control=1;
			break;
		}
	}
	if(control==1){
		return i;
	}else{
		return -1;
	}
}

int buscarJugadorNombre(struct jugador ms[], int tam, char nom[]){
	int i=0;
	int op=0;
	int control=0;
	for(i=0;i<tam;i++){
		if((strncmp(ms[i].nombre,nom,100)==0)){
			control=1;
			break;
		}
	}
	if(control==1){
		return i;
	}else{
		return -1;
	}
}

void registrarJugador(struct jugador ms[], int *tam){
	int modo=0;
	menuRegistro(ms,*tam);
	printf("\n\nELIJA UNA DE LAS SIGUIENTES OPCIONES: ");scanf("%d",&modo);
	do{
        if(!(modo>=0 && modo<=3)){
        	menuRegistro(ms,*tam);
            printf("[x]ERROR, EL MODO INGRESADO NO ES VALIDO");
            printf("\n\nELIJA UNA DE LAS SIGUIENTES OPCIONES: ");scanf("%d",&modo);
        }
    }while(!(modo>=0 && modo<=3));
    if(modo==1){
    	//agregarJugador();
    	agregarJugador(ms, *tam, "jugadores.txt");
    	leerJugadores("jugadores.txt",ms,tam);
		return;
	}else if(modo==2){
		//modificaJugador();
		modificaJugador(ms, *tam, "jugadores.txt", 1, 0,"N", 0, 0);
		leerJugadores("jugadores.txt",ms,tam);
		return;
	}else if(modo==3){
		//eliminaJugador();
		eliminarJugador(ms, *tam, "jugadores.txt");
		leerJugadores("jugadores.txt",ms,tam);
		return;
	}else{
		return;
	}
	
}

void agregarJugador(struct jugador ms[], int tam, char path[]){
	int i=1;
	int jk=0;
	int encontro=0;
	char nom[_TAM];
	FILE *archivo;
	////////////////////validando////////////////////
	system("cls");
	printf("**************************B-I-E-N-V-E-N-I-D-O************************\n\n");
    printf("\n\nINGRESA TU NOMBRE O NICK: ");scanf("%s",nom);
	encontro=buscarJugadorNombre(ms,tam,nom);
	do{
		if(encontro!=-1){
			system("cls");
			printf("**************************B-I-E-N-V-E-N-I-D-O************************\n\n");
			printf("[x]ERROR, EL MODO INGRESADO YA EXISTE");
            printf("\n\nINGRESA TU NOMBRE O NICK: ");scanf("%s",nom);
			encontro=buscarJugadorNombre(ms,tam,nom);
		}
	}while(encontro!=-1);
		if(ms[tam-1].cod==-1){
			ms[tam].cod=1;
		}else{
		ms[tam].cod=(ms[tam-1].cod)+1;
		}
		strcpy(	ms[tam].nombre,nom);
		strcpy(	ms[tam].modo,"N");
		ms[tam].puntos=0;
		ms[tam].segundos=0;
		tam=tam+1;
	
    archivo=fopen(path, "w");
    if(archivo!=NULL){
    	fprintf(archivo,"-1,top,N,0,0\n",ms[0].cod,ms[0].nombre,ms[0].modo,ms[0].puntos,ms[0].segundos);//CONO SEÑALADOR DEL TOPE DEL ARCHIVO
    	while(i<tam){
    		fprintf(archivo,"%d,%s,%s,%d,%d\n",ms[i].cod,ms[i].nombre,ms[i].modo,ms[i].puntos,ms[i].segundos);
    		i++;
    	}
    }
    fclose(archivo);
}


void eliminarJugador(struct jugador ms[], int tam, char path[]){
	int i=0;
	int jk=0;
	int cod=0;
	int usu=-1;
	int orden=0;
	struct jugador tem[_TAM];
	FILE *archivo;
	system("cls");
	printf("***************************H-A-S-T-A--P-R-O-N-T-O**************************\n\n");
	imprimirJugadores(ms,tam);
	printf("\n\n");
	printf("\n ELIJE EL NOMBRE O NICK QUE DESEAS BORRAR: ");scanf("%d",&cod);
	usu=buscarJugador(ms,tam,cod);
	if(ms[tam-1].cod==-1){
			return;
	}
	do{
		if(!(cod>0 && cod<tam)){
			system("cls");
			printf("***************************H-A-S-T-A--P-R-O-N-T-O**************************\n\n");
			imprimirJugadores(ms,tam);
			printf("\n\n");
			printf("[x]ERROR, EL USUARIO INGRESADO NO EXISTE");
			printf("\n ELIJE EL NOMBRE O NICK QUE DESEAS BORRAR: ");scanf("%d",&cod);
			usu=buscarJugador(ms,tam,cod);
		}
		
	}while(!(cod>0 && cod<tam));
	for(i=0;i<usu;i++){
		tem[i].cod=ms[i].cod;
		strcpy(	tem[i].nombre,ms[i].nombre);
		strcpy(	tem[i].modo,ms[i].modo);
		tem[i].puntos=ms[i].puntos;
		tem[i].segundos=ms[i].segundos;
	}
	for(i=usu+1;i<tam;i++){
		tem[i-1].cod=ms[i].cod;
		strcpy(	tem[i-1].nombre,ms[i].nombre);
		strcpy(	tem[i-1].modo,ms[i].modo);
		tem[i-1].puntos=ms[i].puntos;
		tem[i-1].segundos=ms[i].segundos;
	}
	tam=tam-1;
	for(i=0;i<tam;i++){
		ms[i].cod=tem[i].cod;
		strcpy(ms[i].nombre,tem[i].nombre);
		strcpy(ms[i].modo,tem[i].modo);
		ms[i].puntos=tem[i].puntos;
		ms[i].segundos=tem[i].segundos;
	}
	ms[0].cod=-1;
	for(i=1;i<tam;i++){
		ms[i].cod=i;
	}
	i=0;
    archivo=fopen(path, "w");
    if(archivo!=NULL){
    	while(i<tam){
    		fprintf(archivo,"%d,%s,%s,%d,%d\n",ms[i].cod,ms[i].nombre,ms[i].modo,ms[i].puntos,ms[i].segundos);
    		i++;
    	}
    }
    fclose(archivo);
}

void modificaJugador(struct jugador ms[], int tam, char path[], int modo, int usur, char modos[], int puntos, int segundos){
	int i=0;
	int jk=0;
	int cod=0;
	int usu=-1;
	int orden=0;
	char nom[_TAM];
	struct jugador tem[_TAM];
	FILE *archivo;
if(modo!=2){
	system("cls");
	printf("***************************M-O-D-I-F-I-C-A-R**************************\n\n");
	imprimirJugadores(ms,tam);
	printf("\n\n");
	printf("\n ELIJE EL NOMBRE O NICK QUE DESEAS MODIFICAR: ");scanf("%d",&cod);
	usu=buscarJugador(ms,tam,cod);
	if(ms[tam-1].cod==-1){
			return;
	}
	do{
		if(!(cod>0 && cod<tam)){
			system("cls");
			system("cls");
			printf("***************************M-O-D-I-F-I-C-A-R**************************\n\n");
			imprimirJugadores(ms,tam);
			printf("\n\n");
			printf("\n ELIJE EL NOMBRE O NICK QUE DESEAS MODIFICAR: ");scanf("%d",&cod);
			usu=buscarJugador(ms,tam,cod);
		}
		
	}while(!(cod>0 && cod<tam));
}else{
	usu=buscarJugador(ms,tam,usur);
}
	if(modo==1){
		printf("INGRESA TU NUEVO NOMBRE O NICK: ");scanf("%s",nom);
		strcpy(ms[usu].nombre,nom);
	}else if(modo==2){
		strcpy(ms[usu].modo,modos);
		ms[usu].puntos=puntos;
		ms[usu].segundos=segundos;
	}else{
		printf("	[X]ERROR MODO INVALIDO: ");
		return;
	}
	i=0;
    archivo=fopen(path, "w");
    if(archivo!=NULL){
    	while(i<tam){
    		fprintf(archivo,"%d,%s,%s,%d,%d\n",ms[i].cod,ms[i].nombre,ms[i].modo,ms[i].puntos,ms[i].segundos);
    		i++;
    	}
    }
    fclose(archivo);
}


//**
//* Funcion acercaDe .- muestra la descripcion del juego y autores
//* Creada en 6 de junio del 2014
//* Autor Ricardo Becerra - Israel Molina
//* Versión 1
//*/
void acercaDe(){	
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y	HORA: %H:%M:%S",tlocal);
    system("cls");
    printf("\n");
    printf("Autores: \n");
    printf("   *RICARDO BECERRA\n");
    printf("   *ISRAEL MOLINA\n");
    printf("\nDescripcion: \n");
    printf("El objetivo de Buscaminas es encontrar todas las minas lo antes posible,\nsin descubrir ninguna. Si descubre una mina, perdera la partida.\n");
    printf("\nFECHA: ");
    printf("%s\n",output);
    printf("\n\n");
    printf("PRESIONE UNA TECLA PARA CONTINUAR: ");
    getch();
    system("cls");
}

///SISTEMA DE RECORD
void asignarCadena2(int palabrasXBloque, char *ptr, char codigo[], char nombre[], char puntos[], char segundos[]){
	switch(palabrasXBloque){
		case 1:
			strcpy(codigo,ptr);
			break;
		case 2:
			strcpy(nombre,ptr);
			break;
		case 3:
			strcpy(puntos,ptr);
			break;
		case 4:
			strcpy(segundos,ptr);
			break;
	}
}

int validarSeparadores2(char codigo[], char nombre[], char puntos[], char segundos[]){
	if(strstr(codigo,SPA)||strstr(nombre,SPA)||strstr(puntos,SPA)||strstr(segundos,SPA)){
		return 1;
	}
	return 0;
}

void leerRecord(char path[],struct record cmp[],int *con){
	int i=0;
	FILE *archivo;
	char cadena[_TAM],codigo[_TAM],nombre[_TAM],puntos[_TAM],segundos[_TAM];
	char separadores[]=",";
	char *ptr;
	int palabrasXBloque=0;
	int cnt=0;
	memset(cadena,0,_TAM);
	memset(codigo,0,_TAM);
	memset(nombre,0,_TAM);
	memset(puntos,0,_TAM);
	memset(segundos,0,_TAM);
    archivo=fopen(path, "r");
    if(archivo!=NULL){
    	while(!feof(archivo)){
    		fgets(cadena,_TAM,archivo);
    		ptr=strtok(cadena,separadores);
    		palabrasXBloque++;
    		asignarCadena2(palabrasXBloque,ptr,codigo,nombre,puntos,segundos);
    		while((ptr = strtok(NULL, separadores)) !=NULL){
    			palabrasXBloque++;
    			asignarCadena2(palabrasXBloque,ptr,codigo,nombre,puntos,segundos);
    			if(palabrasXBloque==4 || validarSeparadores2(codigo,nombre,puntos,segundos)==1){
    			
    				cmp[cnt].cod=atoi(codigo);
    				strcpy(cmp[cnt].nombre,nombre);
    				cmp[cnt].puntos=atoi(puntos);
    				cmp[cnt].segundos=atoi(segundos);
    				palabrasXBloque=0;
    				memset(codigo,0,_TAM);
					memset(nombre,0,_TAM);
					memset(puntos,0,_TAM);
					memset(segundos,0,_TAM);
    			}
    		}
    		cnt++;
    	}
    }
    fclose(archivo);

    	*con=cnt-1;
}
////////////////////////////////////////////////////
void agregarRecord(struct record ms[], int tam, char path[],struct jugador ms2[], int pos){
	int i=1;
	int jk=0;
	int encontro=0;
	char nom[_TAM];
	FILE *archivo;
		if(ms[tam-1].cod==-1){
			ms[tam].cod=1;
		}else{
		ms[tam].cod=(ms[tam-1].cod)+1;
		}
		strcpy(	ms[tam].nombre, ms2[pos].nombre);
		ms[tam].puntos=ms2[pos].puntos;
		ms[tam].segundos=ms2[pos].segundos;
		tam=tam+1;
	
    archivo=fopen(path, "w");
    if(archivo!=NULL){
    	fprintf(archivo,"-1,top,0,0\n");//CONO SEÑALADOR DEL TOPE DEL ARCHIVO
    	while(i<tam){
    		fprintf(archivo,"%d,%s,%d,%d\n",ms[i].cod,ms[i].nombre,ms[i].puntos,ms[i].segundos);
    		i++;
    	}
    }
    fclose(archivo);
}

void mostrarRecord(struct record p[], int tp, struct record i[], int ti, struct record e[], int te){
	int f=0,c=0;
	int k=0;
	int cod1=0,cod2=0,cod3=0;
	char nom1[_TAM],nom2[_TAM],nom3[_TAM];
	int aux1=0,aux2=0,aux3=0;
	int seg1=0,seg2=0,seg3=0;
	int tiempo1[2];
	for(f=1;f<=tp-1;f++){ 
		for(c=1;c<=tp-1;c++){ 
			if(p[c].puntos<p[c+1].puntos){
				cod1=p[c].cod;
				strcpy(nom1,p[c].nombre);
				aux1=p[c].puntos; 
				seg1=p[c].segundos;
				//
				p[c].cod=p[c+1].cod;
				strcpy(p[c].nombre,p[c+1].nombre);
				p[c].puntos=p[c+1].puntos;
				p[c].segundos=p[c+1].segundos;
				//
				p[c+1].cod=cod1;
				strcpy(p[c].nombre,nom1);
				p[c+1].puntos=aux1; 
				p[c+1].segundos=seg1; 
			} 
		} 
	} 
	printf("********PRINCIPIANTE**********\n");
	for(k=1;k<tp;k++){
		convMS(p[k].segundos,tiempo1);
		printf("%d	%s	%d	%d:%d\n",k,p[k].nombre,p[k].puntos,tiempo1[0],tiempo1[1]);
	}
	
	for(f=1;f<=ti-1;f++){ 
		for(c=1;c<=ti-1;c++){ 
			if(i[c].puntos<i[c+1].puntos){
				cod1=i[c].cod;
				strcpy(nom1,i[c].nombre);
				aux1=i[c].puntos; 
				seg1=i[c].segundos;
				//
				i[c].cod=i[c+1].cod;
				strcpy(i[c].nombre,i[c+1].nombre);
				i[c].puntos=i[c+1].puntos;
				i[c].segundos=i[c+1].segundos;
				//
				i[c+1].cod=cod1;
				strcpy(i[c].nombre,nom1);
				i[c+1].puntos=aux1; 
				i[c+1].segundos=seg1; 
			} 
		} 
	} 
	printf("\n********INTERMEDIO**********\n");
	for(k=1;k<ti;k++){
		convMS(i[k].segundos,tiempo1);
		printf("%d	%s	%d	%d:%d\n",k,i[k].nombre,i[k].puntos,tiempo1[0],tiempo1[1]);
	}
	
	
	
	for(f=1;f<=te-1;f++){ 
		for(c=1;c<=te-1;c++){ 
			if(e[c].puntos<e[c+1].puntos){
				cod1=e[c].cod;
				strcpy(nom1,e[c].nombre);
				aux1=e[c].puntos; 
				seg1=e[c].segundos;
				//
				e[c].cod=e[c+1].cod;
				strcpy(e[c].nombre,e[c+1].nombre);
				e[c].puntos=e[c+1].puntos;
				e[c].segundos=e[c+1].segundos;
				//
				e[c+1].cod=cod1;
				strcpy(e[c].nombre,nom1);
				e[c+1].puntos=aux1; 
				e[c+1].segundos=seg1; 
			} 
		} 
	} 
	printf("\n********EXPERTO**********\n");
	for(k=1;k<te;k++){
		convMS(e[k].segundos,tiempo1);
		printf("%d	%s	%d	%d:%d\n",k,e[k].nombre,e[k].puntos,tiempo1[0],tiempo1[1]);
	}
	getch();

}
#endif
