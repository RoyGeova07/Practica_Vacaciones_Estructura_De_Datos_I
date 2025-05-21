#include<iostream>
using namespace std;

void Cambio(int& a,int& b)
{

    int aux=a;
    a=b;
    b=aux;

}

void Ordenamiento(int lista[],int numero)
{

    for (int i = 0; i < numero-1; i++)
    {
        
        for (int j = i+1; j < numero; j++)
        {
            
            if(lista[i]>lista[j])
            {

                Cambio(lista[i],lista[j]);

            }

        }
        

    }
    

}



int main(){

    int arreglo[30];
    int tamanio;
    

    cout<<"Ingrese el tamanio del arreglo: ";
    cin>>tamanio;

    for (int i = 0; i < tamanio; i++)
    {
        
        cout<<"Numero["<<i<<"]: \n";
        cin>>arreglo[i];

    }
    
    

    for (int i= 0; i < tamanio; i++)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    
    Ordenamiento(arreglo,tamanio);

    for (int i= 0; i < tamanio; i++)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;


}