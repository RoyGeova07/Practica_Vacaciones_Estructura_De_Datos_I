#include"orden_shell.h"
#include<iostream>
using namespace std;

int main()
{

    //un ejemplo de parte enteros haz 
    int numeros[]={23, 12, 1, 8, 34, 54, 2, 3};
    int n=sizeof(numeros)/sizeof(numeros[0]);//aqui se obtiene el tamaño del arreglo, dividiendo el tamaño total entre el tamaño de un elemento del arreglo

    cout<<"Arreglo Original\n";
    printshell(numeros,n);

    Shell(numeros,n);

    cout<<"Orden Ascendente\n";
    printshell(numeros,n);


    //ahora con cararacteres
    char letras[]={'d','a','c','b','e'};

    int m=sizeof(letras)/sizeof(letras[0]);//aqui se obtiene el tamaño del arreglo, dividiendo el tamaño total entre el tamaño de un elemento del arreglo
    cout<<"Arreglo Original\n";
    printshell(letras,m);

    Shell(letras,m);

    printshell(letras,m);

}

