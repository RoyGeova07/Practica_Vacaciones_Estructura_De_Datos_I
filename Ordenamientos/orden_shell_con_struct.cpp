#include<iostream>
#include<string>
using namespace std;

struct Estudiante
{
    
    string nombre;
    float nota;

};


void Shell(Estudiante arreglo[],int n)
{

    for (int gap=n/2; gap>0; gap/=2)
    {
        
        for (int i = gap; i < n; i++)
        {
            

            Estudiante aux=arreglo[i];
            int j;
            for (j = i; j>=gap&&arreglo[j-gap].nota >aux.nota; j-=gap)
            {
                
                arreglo[j]=arreglo[j-gap];

            }
            arreglo[j]=aux;
            

        }
        

    }
    

}

void MostrarEstudiante(Estudiante arreglo[],int n)
{

    for (int i = 0; i < n; i++)
    {
        
        cout<<"Nombre: "<<arreglo[i].nombre<<" Nota: "<<arreglo[i].nota<<endl;

    }
    

}

int main()
{

    int n;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;

    Estudiante* estu=new Estudiante[n];

    for (int i = 0; i < n; i++)
    {
        
        cout<<i+1<<"# Ingrese el nombre del estudiante: ";
        cin>>estu[i].nombre;
        cout<<i+1<<"# Ingrese la nota del estudiante: ";    
        cin>>estu[i].nota;

    }

    cout<<"\nMostrando estudiantes\n";
    MostrarEstudiante(estu,n);

    cout<<endl;

    Shell(estu,n);

    cout<<"\nMostrando estudiantes ordenados\n";
    MostrarEstudiante(estu,n);
    

}