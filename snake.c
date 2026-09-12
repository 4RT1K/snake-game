/*-------------------------------*librerias usadas *------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
/*--------------------------------*macros*----------------------------------------------------------*/
#define ancho 20
#define alto 20

/*--------------------------------structs ---------------------------------------------------------*/
struct serpiente {
	int longitut;
	int y[ancho*alto];
	int x[alto*ancho];
};
/*------------------ funciona para limpiar y crear el tablero --------------------------------------*/
void init_tablero (char tablero[alto][ancho]){
	for(int columnas = 0;columnas<alto;columnas++){
		for(int filas = 0;filas<ancho;filas++){
			if(columnas == 0|| columnas == alto-1){tablero[columnas][filas]='#';}
			else if(filas ==0||filas == ancho-1){tablero[columnas][filas]='#';}
			else {tablero[columnas][filas] = ' ';}
		}
	}
}
/* creacion de la cola de la serpiente y añadirla al tablero */
/*	void movimiento(struct serpiente *s){
	char entrada = 'd';
	scanf(&entrada);
	if 
}
*/
void calcular_serpiente(struct serpiente *s){
	for(int i = s->longitut-1;i>0;i--){
		s->y[i] =s->y[i-1];
	}
	for(int i = s->longitut-1;i>0;i--){
		s->x[i] =s->x[i-1];
	}
}
void añadir_serpiente(struct serpiente *s,char tablero[alto][ancho]){
	for(int cuerpo = 0;cuerpo<s->longitut;cuerpo++){
			tablero[s->y[cuerpo]][s->x[cuerpo]] = '0';
	}
}
/* dibujar el tablero y todo lo que este contenga serpiente manzanas*/
void dibujar(char tablero[alto][ancho]){
	system("clear");
	for(int columnas = 0;columnas<alto;columnas++){
		for (int filas = 0;filas<ancho;filas++){
			if(filas == ancho -1){printf("%c\n",tablero[columnas][filas]);}
			else{printf("%c",tablero[columnas][filas]);}
		}
	}
}		
int main(void){
	/*iniciamos la serpiente y la condicion de victorio o derrota*/
	int estado = 1;
	struct serpiente serp = {1,{1},{1}};
	char tablero[alto][ancho];
	/* bucle que contiene el juego*/
	while (estado){
		init_tablero(tablero);
		calcular_serpiente(&serp);
		añadir_serpiente(&serp,tablero);
	/*	movimiento(&serp);	*/
		dibujar(tablero);	
		
	}
	return 0;
}
