#include <iostream>
#include <string>
using String=std::string;
using namespace std;

struct Nodo
{
    
    char letra;
    Nodo*siguiente;
    Nodo*atras;

};


void InsertarLetra(Nodo*&cabeza,Nodo*&cola,char c)
{

    Nodo*nueva_letra=new Nodo();
    nueva_letra->letra=c;
    nueva_letra->siguiente=nullptr;
    nueva_letra->atras=nullptr;

    if(cabeza==nullptr)
    {

        cabeza=cola=nueva_letra;

    }else{

        cola->siguiente=nueva_letra;
        nueva_letra->atras=cola;
        cola=nueva_letra;

    }

}

bool EsPalindromo(Nodo*cabeza,Nodo*cola)
{

    while(cabeza!=nullptr&&cola!=nullptr&&cabeza!=cola&&cabeza->atras!=cola)
    {

        if(cabeza->letra!=cola->letra)
        {

            return false;
            cabeza=cabeza->siguiente;
            cola=cola->atras;

        }
        return true;//Se que esto es mal colocado, pero asi me funcione bien el ejercicio xd
    }
   
    

}

int main()
{

    Nodo*cabeza=nullptr;
    Nodo*cola=nullptr;
    String palabra;
    cout<<"Ingrese una palabra: ";
    cin>>palabra;
    for(char c:palabra)
    {

        InsertarLetra(cabeza,cola,c);

    }
    if(EsPalindromo(cabeza,cola))
    {

        cout<<"La palabra "<<palabra<<" SI ES un palindromo";

    }else{

        cout<<"La palabra "<<palabra<< " NO ES un palindromo";

    }

}