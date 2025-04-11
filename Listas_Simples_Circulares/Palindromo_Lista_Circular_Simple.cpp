#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo
{
    
    char caracter;
    Nodo*siguiente;

};


void Insertar(Nodo*&lista,char c)
{

    Nodo*nuevo_caracter=new Nodo();
    nuevo_caracter->caracter=c;

    if(lista==nullptr)
    {

      lista=nuevo_caracter;
      nuevo_caracter->siguiente=lista;  //apunta a si mismo bro

    }else{

        Nodo*aux1=lista;
        while(aux1->siguiente!=lista)
        {
            
            aux1=aux1->siguiente;

        }
        aux1->siguiente=nuevo_caracter;
        nuevo_caracter->siguiente=lista;
        

    }

}

bool EsPalindromo(Nodo*lista)
{

    if(lista==nullptr)return false;

    string palabra="";
    Nodo*actual=lista;
    string invertido;

    do{

        palabra+=actual->caracter;
        actual=actual->siguiente;

    }while(actual!=lista);
    invertido=palabra;
    reverse(invertido.begin(),invertido.end());

    return palabra==invertido;

}

int main()
{

    Nodo*lista=nullptr;
    string palabra;

    cout<<"Ingrese una palabra: ";
    cin>>palabra;

    for(char c:palabra)
    {

        Insertar(lista,c);

    }

    if(EsPalindromo(lista))
    {

        cout<<"\nLa palabra "<<palabra<<" ES UN PALINDROMO\n";

    }else{

        cout<<"\nLa palabra "<<palabra<<" NO ES UN PALINDROMO\n";

    }


}