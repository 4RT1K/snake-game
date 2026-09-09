#include <stdio.h>
#define ancho 20
#define alto 20
struct serpiente {
	int longitut;
	int y[ancho];
	int x[alto];
};
void init_tablero (char tablero[alto][ancho]){
	for(int columnas = 0;columnas<alto;columnas++){
		for(int filas = 0;filas<ancho;filas++){
			if(columnas == 0|| columnas == alto-1){tablero[columnas][filas]='#';}
			else if(filas ==0||filas == ancho-1){tablero[columnas][filas]='#';}
			else {tablero[columnas][filas] = ' ';}
		}
	}
}
void dibujar(char tablero[alto][ancho]){
	for(int columnas = 0;columnas<alto;columnas++){
		for (int filas = 0;filas<ancho;filas++){
			if(filas == ancho -1){printf("%c\n",tablero[columnas][filas]);}
			else{printf("%c",tablero[columnas][filas]);}
		}
	}
}		
int main(){
	
	/*struct serpiente serp = {1,{0},{0}};*/
	char tablero[alto][ancho];
	init_tablero(tablero);
	dibujar(tablero);
}
