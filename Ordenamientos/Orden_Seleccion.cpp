#include<iostream>
using namespace std;

void OrdenamientoSeleccion(int arreglo[],int tamanio)
{

    int auxiliar,min;
    for (int i = 0; i < tamanio; i++)
    {
        min=i;
        for (int j = i+1; j < tamanio; j++)
        {
            
            if(arreglo[j]<arreglo[min])
            {

                min=j;

            }

        }
        auxiliar=arreglo[i];
        arreglo[i]=arreglo[min];
        arreglo[min]=auxiliar;
        
    }   
    

}

int main()
{

    int arreglo[]={5,3,2,4,1};
    int tamanio=5;
    cout<<"\nMostrando arreglo\n";
    for (int i = 0; i < tamanio; i++)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    
    OrdenamientoSeleccion(arreglo,tamanio);

    cout<<"\nMostrando arreglo ordenado\n";
    for (int j = 0; j<tamanio; j++)
    {
        
        cout<<arreglo[j]<<" ";

    }
    

}