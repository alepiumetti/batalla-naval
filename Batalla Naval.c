#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tablerojugador[11][11];
char tablerooponente[11][11];
char tocb[11][11];
int hora;
int caj,cao; //CAJ=Contador ataques jugador CAO=Contador Ataques Oponentes 

int main(){
	
//Declaracion de funciones

void modo1();
void modo2();
void modo3();
void ataque(int y,int x,int cont,char tablero[][11],char tablero1[][11]);
void ataqueoponente();



//Declaracion de variables	
int j,i,h,k,modo,f,c,x,L;

char y;

caj=0;
cao=0;


//Ingreso de variable
//x,y son las coordenadas de entrada para indicar donde se quiere poner los barcos


//Impresion
//i=columna j,k,h=Filas
//f=filas para imprimir
//c=Columna para imprimir

//semilla random para el numero random;


//Guardo todas las pocisiones vacias
{
for (i=1;i<11;i++){
	for (j=1;j<11;j++){
		tablerojugador[i][j]='O';
	}
	for (h=1;h<11;h++){
		tablerooponente[i][h]='O';
	}
	
	for(k=1;k<11;k++){
		tocb[i][k]='O';
	}
}

	f=49;
	for (j=1;j<11;j++){
		tablerojugador[0][j]=f;
		f++;
	}
	f=49;
	for (h=1;h<11;h++){
		tablerooponente[0][h]=f;
		f++;
	}

	c=65;
	for (j=1;j<11;j++){
		tablerojugador[j][0]=c;
		c++;
	}
	c=65;
	for (h=1;h<11;h++){
		tablerooponente[h][0]=c;
		c++;
	}
	
	
}

//Bienvenida
{
printf("\tBatalla Naval\n\n\n\n\n\nCreado y diseñado por Alejandro Piumetti\n");
system("pause");
system("cls");
printf("Este juego seguramente tiene muchos errores, por lo tanto, seleccione solo lo que se le pida.\n");
system("pause");
system("cls");
printf("\tInstrucciones de juego\n");
printf("1-Los barcos se manejan como puntos, por lo tanto, podes poner todos seguidos uno al lado del otro y administrarlos como te guste.\n");
printf("2-Tener cuidado con las coordenadas de ataque ya que una equivocacion te puede llevar a perder, o a que el juego crashee que es basicamente lo mismo.\n");
printf("3-No reirse de la I.A. del ataque de la maquina.\n");
printf("4-Seguir las reglas de los tamaños de los barcos, se puede seguir la regla Nº1 pero sin romper las del juego.\n");
printf("5-La posicion : corresponde al numero 10.\n");
printf("6-Usar MAYUSCULAS.\n");
printf("7-Divertirse y a no enojarse si el juego tira error en plena guerra.\n");
printf("\n\tAVISO\n");
printf("Cuidado con los puntos de los barcos, ya que si se ponen dos en el mismo lugar se reemplazara y perderas un punto para distribuir dentro del agua\n");

system("pause");
system("cls");

}

//Eleccion de modo
{
printf("Elegir modo de juego\n");
printf("\tModo 1\n");
printf("\tModo 2\n");
printf("\tModo 3\n\n");
printf("Pulse un numero de modo y presione ENTER\n");
printf("Modo ");
scanf("%d",&modo);

switch(modo){
	case 1:
		modo1();
		break;
		
	case 2:
		modo2();
		break;
		
	case 3:
		modo3();
		break;

}


system("cls");
}

for (L=0;L<40;L=L+1){
	
	printf("\tTablero Jugador \t \t Tablero Oponente \n");

	for (i=0;i<11;i++){
		for (j=0;j<11;j++){
			printf(" %c ",tablerojugador[i][j]);
		}
		printf("\t");
	
		for (h=0;h<11;h++){
			printf(" %c ",tablerooponente[i][h]);
		}
		printf("\n");
	}
	printf("Tienes para poner 10 barcos:\n-uno de 4 lugares\n-dos de 3 lugares\n-tres de 2 lugares\n-cuatro de 1 lugar\n");
	printf("Seleccione en que coordenada poner cada punto de los barcos.\n");
	printf("Coordenadas Alto y Ancho YX:");
	scanf("%c",&y);
	scanf("%d",&x);
	tablerojugador[y-64][x]='X';
	
	system("cls");
}

printf("Comienza el juego\n");

while(cao<=19 || caj<=19){

	printf("Elegir una posicion para atacar\n");
	printf("Ingresar Coordenadas de ataque Alto y Ancho YX:");
	scanf("%c",&y);
	scanf("%d",&x);
	printf("\n");
	ataque(y,x,caj,tocb,tablerooponente);
	ataqueoponente();
	
		if (y=='p' && x==14){
			cao=20;
		}
		
		else {
		printf("\tTablero Jugador \t \t Tablero Oponente\n");

		for (i=0;i<11;i++){
			for (j=0;j<11;j++){
				printf(" %c ",tablerojugador[i][j]);
			}
			printf("\t");
	
			for (h=0;h<11;h++){
				printf(" %c ",tablerooponente[i][h]);
			}
			printf("\n");
		}
		
	}
}




if (cao==20){
	printf("\nPerdiste\n");
	system("pause");
}
else if (caj==20){
	printf("\nGanaste\n");
	system("pause");
}


return 0;
}

void ataque(int y,int x,int cont,char tablero[][11],char tablero1[][11]){
	if (tablero[y-64][x]=='O' || tablero[y-64][x]=='-') {
		tablero1[y-64][x]='-';
	}
	else if(tablero[y-64][x]=='X'){
		tablero1[y-64][x]=178;
		cont=cont+1;
	}
}


void ataqueoponente(){
int y,x;
hora=time(NULL);
srand(hora);

	y=rand() % 11 + 65;
	x=rand() % 11;
	ataque(y,x,cao,tablerojugador,tablerojugador);



}
void modo1(){
	
	tocb[1][1]='X';
	tocb[1][10]='X';
	tocb[10][1]='X';
	tocb[10][10]='X';
	tocb[1][3]='X';
	tocb[1][4]='X';
	tocb[1][5]='X';
	tocb[4][2]='X';
	tocb[4][3]='X';
	tocb[4][4]='X';
	tocb[4][5]='X';
	tocb[4][7]='X';
	tocb[5][7]='X';
	tocb[6][2]='X';
	tocb[7][2]='X';
	tocb[7][4]='X';
	tocb[7][5]='X';
	tocb[8][2]='X';
	tocb[9][6]='X';
	tocb[9][7]='X';
	
}

void modo2(){
	
	tocb[2][2]='X';
	tocb[2][5]='X';
	tocb[3][8]='X';
	tocb[4][4]='X';
	tocb[4][8]='X';
	tocb[6][2]='X';
	tocb[6][5]='X';
	tocb[6][6]='X';
	tocb[8][2]='X';
	tocb[8][5]='X';
	tocb[8][6]='X';
	tocb[8][7]='X';
	tocb[8][8]='X';
	tocb[8][10]='X';
	tocb[9][2]='X';
	tocb[9][10]='X';
	tocb[10][4]='X';
	tocb[10][5]='X';
	tocb[10][6]='X';
	tocb[10][10]='X';
	
}

void modo3(){
	
	tocb[1][1]='X';
	tocb[1][8]='X';
	tocb[1][9]='X';
	tocb[1][10]='X';
	tocb[2][5]='X';
	tocb[3][3]='X';
	tocb[3][8]='X';
	tocb[3][9]='X';
	tocb[4][3]='X';
	tocb[6][6]='X';
	tocb[6][7]='X';
	tocb[6][8]='X';
	tocb[6][9]='X';
	tocb[7][3]='X';
	tocb[8][1]='X';
	tocb[8][6]='X';
	tocb[9][1]='X';
	tocb[9][6]='X';
	tocb[9][9]='X';
	tocb[10][1]='X';

	
}

