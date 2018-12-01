#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <fstream>
#include <string.h>
#include <string>
#include "Funciones.h"

#include <cmath>

using namespace std;

double aNumero(string linea){
    double numero;
    int largo = linea.length();
    if(largo >= 1){
        linea[1]='.';
        numero = stof(linea);
    }   
    return numero;
}

double media(double cant, double sumaTotal){
    double mediaArit=sumaTotal/cant;
    
    //para redondear el numero a 2 decimales
    double aux;
    aux = mediaArit*100;  
    aux = trunc(aux);
    aux= aux/100;
   
    return aux;
}

/*
float mediana(float cant){
    float medianaFinal;
    float aux = cant/2;
    aux = ceil(aux);   
    
    return medianaFinal;
}
*/

double desviacionEstandar(double promedio,double cantidad){
    double sumatoria = 0.0;
    double desviacionFinal;
    
    string linea;
    double numeroLinea;
    int largo;
    
    ifstream archivo;
    archivo.open("Ejemplo.txt",ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo.---"<<endl;
    }
    
    while(!archivo.eof()){
        getline(archivo, linea);
        largo = linea.length();
        if(largo>=1){
            numeroLinea = aNumero(linea);
            
            sumatoria = sumatoria + pow((numeroLinea - promedio),2);
        }
    }
    archivo.close();
    
    desviacionFinal = sqrt( sumatoria/cantidad );
    
    
    return desviacionFinal;
}



void modaInicio(int modaNumeros[][10],double numero){
    int auxUno = int(trunc(numero)); //numero entero
    int auxDos = int((numero*10))%10; //numero decimal
    
    modaNumeros[auxUno][auxDos] = modaNumeros[auxUno][auxDos] + 1;   
}

void iniciar(int modaNumeros[][10]){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            
            modaNumeros[i][j]=0;
        
        }
    }
}


void imprimir(int modaNumeros[][10]){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            
            cout<< modaNumeros[i][j]<<endl;
        
        }
    }
}



double modaFin(int modaNumeros[][10]){
    int mayor = 0;
    int columna,fila;
    
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(modaNumeros[i][j]>mayor){
                columna = i;
                fila = j;
                mayor = modaNumeros[i][j];
            }
        }
    }
    
    double aux = columna*10 + fila;
    aux = aux/10;
    
    return aux;
}

