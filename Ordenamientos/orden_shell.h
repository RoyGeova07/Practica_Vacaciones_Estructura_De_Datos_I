#ifndef SHELL_H
#define SHELL_H
#include<iostream>
using namespace std;


template <typename T>
void Shell(T arreglo[],int n)
{
    //                     partir
    for(int gap=n/2;gap>0;gap/=2)//sirve para dividir el arreglo en partes
    {
        for(int i=gap;i<n;i++)          //recorre desde el gap, porque es el resultado, necesitamos que llega al tope
        {

            T tem=arreglo[i];//temporal para guardar el valor de la posicion i
            int j;//variable para recorrer el arreglo, la posicion j es la que se va a desplazar hacia la derecha,se declara aqui para que no se inicialice en cada iteracion del for
            //aqui se hace el recorrido del arreglo, y se compara si el valor de la posicion j es mayor al valor de la posicion i
            //el for servira paa desplazar el valor de la posicion j hacia la derecha, para que el valor de la posicion i pueda entrar en su lugar
            for(j=i;j>=gap&&arreglo[j-gap]>tem;j-=gap)//aqui se hace la comparacion de los valores, y si el valor de la posicion j es mayor al valor de la posicion i, se desplaza el valor de la posicion j hacia la derecha
            {  

                arreglo[j]=arreglo[j-gap];//se desplaza el valor de la posicion j hacia la derecha, para que el valor de la posicion i pueda entrar en su lugar

            }
            arreglo[j]=tem;//aqui se coloca el valor de la posicion i en su lugar correspondiente, que es la posicion j

        }


    }

}

template<typename T>
void printshell(const T arreglo[],int n)
{
    for (int i = 0; i < n; ++i)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    
}

#endif // SHELL_H