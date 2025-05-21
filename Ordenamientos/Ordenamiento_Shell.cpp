#include<iostream>
using namespace std;

template<typename T>

void OrdenamientoShell(T arreglo[],int tamanio)
{

    for (int gap = tamanio/2; gap > 0; gap/=2)
    {
        
        for (int i = gap; i < tamanio; i++)
        {
            
            T aux=arreglo[i];
            int j;
            for(j=i; j>=gap&&arreglo[j-gap]>aux;j-=gap)
            {

                arreglo[j]=arreglo[j-gap];

            }
            arreglo[j]=aux;

        }
        

    }
    

}
template<typename T>

void print(T arreglo[],int n)
{

    for (int i = 0; i < n; i++)
    {
        
        cout<<arreglo[i]<<" ";

    }
    cout<<endl;
    

}



int main()
{

    int tamanio;

    cout<<"Ingrese el tamanio del arreglo\n";
    cin>>tamanio;

    int* arreglo=new int[tamanio];

    for (int i = 0; i < tamanio; i++)
    {
        
        cout<<"["<<i<<"] Ingrese un numero: \n";
        cin>>arreglo[i];

    }

    cout<<"\nOrden normal\n";
    print(arreglo,tamanio);
    cout<<endl;
    
    OrdenamientoShell(arreglo,tamanio);

    cout<<"\nOrden ascendente\n";
    print(arreglo,tamanio);
    
    


}