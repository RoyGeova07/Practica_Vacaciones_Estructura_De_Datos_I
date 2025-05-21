#include<iostream>
#include<string>
using namespace std;

void Shell(string cadenas[],int n)
{

    for (int gap = n/2; gap>0; gap/=2)
    {
        
        for (int i = gap; i < n; i++)
        {
            
            string aux=cadenas[i];
            int j;
            for (j = i; j>=gap&&cadenas[j-gap].length()>aux.length(); j-=gap)
            {
                
                cadenas[j]=cadenas[j-gap];

            }
            cadenas[j]=aux;
            
        }
        

    }
    

}

int main()
{

    int n;
    cout<<"Ingrese el numero de cadenas: ";
    cin>>n;
    cin.ignore();//para ignorar el salto de linea que queda en el buffer
    string *cadenas=new string[n];
    for (int i = 0; i < n; i++)
    {
        
        cout<<"Ingrese la cadena "<<i+1<<": ";  
        getline(cin,cadenas[i]);



    }
    Shell(cadenas,n);

    cout<<"\nMostrando cadenas ordenadas\n";
    cout<<"--------------------------\n";
    for (int i = 0; i < n; i++)
    {
        
        cout<<cadenas[i]<<" - "<<cadenas[i].length()<<" caracteres"<<endl;

    }
    
    delete[]cadenas;

}