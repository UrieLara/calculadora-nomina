/*
Proyecto Escolar.
Alumno: Uriel Lara Castro
13 de agosto del 2023
*/

//**Librerias**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphics.h>
#include <conio.h>

#include <iostream>
using namespace std;


//**Declaracion de funciones**
double CalculoNomina(double, int, double); //sueldo, diasT, horasE
void BasedeDatos(int, double); //noTrabajador, nomina
void CalculoGraficos(int, int, int); //promedioT
void Graficos(int, int, int);

//**Declaracion de variables globales**
int noTrabajador;
/*Esta matriz representa una base de datos que guarda el número de empleado y su sueldo. 
 {número de empleado, sueldo base}*/
double baseDatos[6][2] = {{5101,10000},{5102,10000},{6101,10000},{6102,10000},{7101,10000},{7102,10000}};

//Variables para el cálculo y graficación de los promedios
int promtecnicosA, promtecnicosB, promtecnicosC;


int main(int argc, char const *argv[])
{
   
   int diasTrabajados;
   double sueldo=0, horasExtras=0;
   char seleccion='y';

   //El primer dígito del número del trabajador representa su jerarquia
   enum Jerarquia{
      tecnicosA=5,
      tecnicosB=6,
      tecnicosC=7,
   };

   cout <<endl<< "-_-_-_-CALCULADOR DE NOMINA-_-_-_-" << endl;

while(seleccion=='y')
{
    //SOLICITAR DATOS
    //Se solicitan los datos necesarios para el cálculo de la nómina mensual del empleado
   cout <<endl<<"-> El numero de cada trabajador es de 4 digitos <-"<<endl
   <<endl<<"-> Primer digito: 5 = tecnico A, 6 = tecnico B, 7 = tecnico C <-"<<endl
   <<"Escriba el numero del trabajador: ";
   cin >> noTrabajador;
   cin.ignore();


    cout<<endl<<"Escriba el sueldo base del empleado sin comas ni puntos."
      <<endl<<"-> Ejemplo de sueldo base: $16000 <-"
    <<endl<<"Sueldo base: $";
    cin >> sueldo;
    cin.ignore();
        
    cout <<endl<<"Escriba el numero de dias trabajados al mes: ";
    cin >> diasTrabajados;

    cout <<endl<<"Trabajo horas extras? y=si, n=no"
    <<endl<<"Escriba y o n: ";
    cin >> seleccion;
    cin.ignore();

    if (seleccion=='y'){
      cout<<"Escriba cuantas horas extras: ";
      cin >> horasExtras;
      cin.ignore();

    }

   //CALCULO DE NOMINA
   int arreglo[3]={0};
   int aux=noTrabajador;
   
   for (int i=3; i>=0; i--){
      arreglo[i]=aux % 10;
      aux /= 10;
   }

   
   BasedeDatos(noTrabajador, CalculoNomina(sueldo, diasTrabajados, horasExtras));

   cout <<endl<<"Quiere calcular la nomina de otro trabajador? y=si, n=no."<<endl<<"Escriba y o n: ";
   cin >> seleccion;
   cin.ignore();

}

   CalculoGraficos(promtecnicosA,promtecnicosB,promtecnicosC);
   return 0;
}


double CalculoNomina(double sueldoB, int diasT, double horasE){
   double pagoxDia, pagoMes,pagohorasE,nominaFinal;

   pagoxDia=sueldoB/30;
   pagoMes=pagoxDia*diasT;
   //Las horas extras se pagan por 1.5 más
   pagohorasE=pagoxDia/8*1.5*horasE; 

   nominaFinal = pagoMes+pagohorasE;
   cout <<endl<< "*=== Pago de nomina correspondiente: $"<<nominaFinal<<" ===*"<<endl;

return nominaFinal;
}


void BasedeDatos(int noTrb, double nomina){

int filas = (sizeof(baseDatos)/sizeof(baseDatos[0]));
    int columnas = (sizeof(baseDatos[0])/sizeof(baseDatos[0][0]));
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         if(baseDatos[i][j]==noTrabajador) //encuentra el trabajador
            baseDatos[i][j+1]=nomina; //actualiza el salario
        }
    }

promtecnicosA=baseDatos[0][1]+baseDatos[1][1];
promtecnicosB=baseDatos[2][1]+baseDatos[3][1];
promtecnicosC=baseDatos[4][1]+baseDatos[5][1];

promtecnicosA=promtecnicosA/2;
promtecnicosB=promtecnicosB/2;
promtecnicosC=promtecnicosC/2;

//Se imprimen los resultados.
cout<<endl<<"Salario promedio de tecnicos A: $"<<promtecnicosA;
cout<<endl<<"Salario promedio de tecnicos B: $"<<promtecnicosB;
cout<<endl<<"Salario promedio de tecnicos C: $"<<promtecnicosC<<endl;
}


void CalculoGraficos(int p1, int p2, int p3){
int a,b,c, mayor;

//Se identifica el *promedio con mayor valor*
if(p1>p2 && p1>p3){
    mayor=p1;
    }
    if(p2>p3 && p2>p1){
    mayor=p2;        
    }
    if(p3>p2 && p3>p1){
    mayor=p3;        
    }
    

     a = mayor*100/p1;
     b = mayor*100/p2;
     c = mayor*100/p3;

/* Los pixeles se cuentan de arriba hacia abajo. 
Si el valor promedio mayor es más de 400, entonces defino que la gráfica mayor comenzará en el pixel 350, 
porque si el valor es mayor, se vería una gráfica muy pequeña o se dibujaría en el eje 'y' negativo.

Las otras 2 barras se dibujarán en proporción a la que tiene el valor mayor.*/

     if(a>400){a=350;}
     if(b>400){b=350;}
     if(c>400){c=350;}

Graficos(a,b,c);

}

void Graficos(int topA,int topB,int topC){
 
 //se inicializa la ventana de gráficos
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
//se personaliza 
   setcolor(YELLOW);
   rectangle(0,30,639,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(WHITE);
   outtextxy(205,0,"PROMEDIO DE SUELDOS");
//se dibuja un sistema de coordenadas
   setlinestyle(SOLID_LINE,0,2);

   line(100,420,100,60);
   line(100,420,600,420);
   line(90,70,100,60);
   line(110,70,100,60);
   line(590,410,600,420);
   line(590,430,600,420);
//Y se dibuja la gráfica de barras
/*Los primeros 2 números representan las coordenadas de una esquina del rectángulo y corresponden al eje X y Y. 
Los otros 2 números representan la esquina opuesta del rectángulo. */
   setfillstyle(LINE_FILL,BLUE);
   bar(150,topA,250,419);

   setfillstyle(XHATCH_FILL,RED);
   bar(300,topB,400,419);

   setfillstyle(WIDE_DOT_FILL,GREEN);
   bar(450,topC,550,419);

//Etiquetas
    outtextxy(95,35,"Sueldo");
    outtextxy(160,425,"tecnicos A");
    outtextxy(305,425,"tecnicos B");
    outtextxy(445,425,"tecnicos C");

   getch();
}

