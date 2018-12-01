#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <fstream>
#include <string.h>
#include <string>

#include "Funciones.h"
using namespace std; 

int main(int argc, char** argv) {
    
    /*
    //--------------------------------------------
    
    fseek(archivo, 0, SEEK_END);
    largoArchivo = ftell(archivo);
    
    fclose(archivo);
    
    cout<<"El archivo txt pesa: "<<largoArchivo<< " bytes..."<<endl;
    */ //---------------------------------------------
    
    ifstream archivo;
    archivo.open("Ejemplo.txt",ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo.---"<<endl;
    }
    
    string linea;
    
    double numeroLinea; //numero que esta en esa linea
    double sumaTotal; //suma total de todos los numeros
    double cant; //cantidad de numeros en total
    double promedio; //variable para guardar la media
    //float medianaB; //variable para guardar la mediana
    
    double desviacion;//variable para guardar la desviacion estandar
    double modaDef; // variable para guardar la moda
    
    int modaNumeros[10][10]; // matriz que guarda cuantas veces se repiten los numeros
    iniciar(modaNumeros);
    
    
    int largo;//largo de la linea 
    
    while(!archivo.eof()){
        getline(archivo, linea);
        largo = linea.length();
        if(largo>=1){
            numeroLinea = aNumero(linea);
            cant = cant + 1.0;
            sumaTotal= sumaTotal + numeroLinea;
            modaInicio(modaNumeros,numeroLinea);
        }
       
    }
    archivo.close();
    
    promedio = media(cant,sumaTotal);
    //medianaB = mediana(cant);
    desviacion = desviacionEstandar(promedio,cant);
    
    modaDef = modaFin(modaNumeros);
    
    cout<<"La suma total es: "<< sumaTotal <<endl;
    cout<<"La cantidad de numeros es: "<< cant <<endl;
    cout<<"La media(promedio) es: "<< promedio <<endl;
    //cout<<"La mediana es: "<< medianaB <<endl;
    cout<<"La moda es: " << modaDef <<endl;
    cout<<"La desviacion estandar es: "<< desviacion <<endl;
    
    
    return 0;
}

