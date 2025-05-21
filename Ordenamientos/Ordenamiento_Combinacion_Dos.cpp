#include<iostream>
using namespace std;

void MostrarArreglo(int arreglo[],int inicio,int fin)
{

    for (int i = inicio; i <=fin ; i++)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    

}

void Combinar(int arreglo[],int inicio,int medio,int final)
{

    //tamanio de subarreglos
    int TamanioIzquierda=medio-final+1;
    int TamanioDerecha=final-medio;

    //aqui se crea los arreglo temporales para izquierda y derecha
    int*Izquierda=new int[TamanioIzquierda];
    int*Derecha=new int[TamanioDerecha];

    //aqui con un for copiamos los datos del arreglo temporal
    for (int i = 0; i < TamanioIzquierda; i++)
    {
        
        Izquierda[i]=arreglo[inicio+1];

    }
    for (int j = 0; j < TamanioDerecha; j++)
    {
        
        Derecha[j]=arreglo[medio+1+j];

    }
    //iteradores para combinar los arreglos ordenadamente
    int i=0,j=0,k=inicio;//indice para el arreglo original
    while (i<TamanioIzquierda&&j<TamanioDerecha)
    {
        
        if(Izquierda[i]<=Derecha[j])
        {

            arreglo[k]=Izquierda[i];
            i++;

        }else{

            arreglo[k]=Derecha[j];
            j++;

        }
        k++;

    }
    //ahora copiamos los elementos restantes de izquierda si hay
    while (i<TamanioIzquierda)
    {
        
        arreglo[k]=Izquierda[i];
        i++;
        k++;

    }
    while (i<TamanioDerecha)
    {
        
        arreglo[k]=Derecha[j];
        j++;
        k++;

    }

    cout<<"Despues de combinar:\n";
    MostrarArreglo(arreglo,inicio,final);

    //ahora liberamos memoria
    delete[] Izquierda;
    delete[] Derecha;

}

void MergeSort(int arreglo[],int inicio,int fin)
{

    if(inicio<fin)
    {

        //aqui encontramos el punto medio
        int medio=inicio+(fin-inicio)/2;

        //aqui dividimos la parte izquierda
        MergeSort(arreglo,inicio,medio);

        //aqui se divide la parte derecha
        MergeSort(arreglo,medio+1,fin);

        //aqui se combina las 2 mitades ordenadas
        Combinar(arreglo,inicio,medio,fin);


    }

}

int main()
{

    int arreglo[]={5,4,2,1,3};
    int tamanio=sizeof(arreglo)/sizeof(arreglo[0]);

    cout<<"Arreglo original\n";
    MostrarArreglo(arreglo,0,tamanio-1);

    MergeSort(arreglo,0,tamanio-1);

    cout<<"\nArreglo ordenado\n";
    MostrarArreglo(arreglo,0,tamanio-1);

}