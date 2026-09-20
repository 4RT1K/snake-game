/*-------------------------------*librerias usadas *------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
/*--------------------------------*macros*----------------------------------------------------------*/
#define ancho 20
#define alto 20

/*--------------------------------structs ---------------------------------------------------------*/
struct serpiente {
	int longitut;
	int y[ancho*alto];
	int x[alto*ancho];
};
struct objeto {
	int y;
	int x;
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
/* generar la posicion de la manzana y añadirla al tablero */
void objetos(struct objeto *manzana){
		manzana->y = (rand() % (alto-2))+1;
		manzana->x = (rand()  % (ancho-2))+1;
}
void dibujar_manzana(struct objeto *manzana,char tablero[alto][ancho]){
	tablero[manzana->y][manzana->x] = '@';
}
/* movimiento de la cabesa de la serpiente  el cuerpo sigue a la cabesa*/
	void movimiento(struct serpiente *s){
		char tecla;
		scanf(" %c",&tecla);
		if(tecla == 'a'){s->x[0]--;}
		else if (tecla == 'd'){s->x[0]++;}
		else if (tecla == 'w'){s->y[0]--;}
		else if (tecla == 's'){s->y[0]++;}
}
/*verificar que toca la cabeza de la serpiente*/
int colision_serp(int y,int x,struct serpiente *serp){
	for(int i = 1;i<serp->longitut;i++){
		if (y == serp->y[i]&& x == serp->x[i]){
			return 1;}
	}
return 0;
}
int colision(int y,int x,struct serpiente *serp){
	for(int i = 0;i<serp->longitut;i++){
		if (y  == serp->y[i]&& x == serp->x[i]){return 1;}
	}
	return 0;
}
/* creacion de la cola de la serpiente y añadirla al tablero */
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
	srand((unsigned int)time(NULL));
	/*iniciamos la serpiente y la condicion de victorio o derrota*/
	int estado = 1;
	struct serpiente serp = {1,{1},{1}};
	/*inicialisamos la manzana*/
	struct objeto manzana = {alto/2,ancho/2};
	char tablero[alto][ancho];
	/* bucle que contiene el juego*/
		init_tablero(tablero);
		calcular_serpiente(&serp);
		añadir_serpiente(&serp,tablero);
		dibujar(tablero);
	while (estado){
		init_tablero(tablero);
		calcular_serpiente(&serp);
		añadir_serpiente(&serp,tablero);
		movimiento(&serp);	
	/* si la serpiente ocupa la misma casilla que cordenadas de la manzana creze y se genera una manzana que no coincida con la serpiente*/
		if (serp.y[0]==manzana.y && serp.x[0]==manzana.x){serp.longitut++;
			while(colision(manzana.y,manzana.x,&serp)){objetos(&manzana);}
		}
		dibujar_manzana(&manzana,tablero);
		
			if(colision_serp(serp.y[0],serp.x[0],&serp)){
				estado = 0;
				printf("game over");
			}
			else if(serp.y[0] == 0 ||serp.y[0] == alto-1||serp.x[0] == 0||serp.x[0] == ancho-1){
				printf("game over");
				estado = 0;
			}

		
		dibujar(tablero);	
	}
	return 0;
	}
