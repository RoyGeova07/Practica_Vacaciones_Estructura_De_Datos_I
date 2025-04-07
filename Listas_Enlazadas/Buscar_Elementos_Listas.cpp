#include <iostream>
using namespace std;

struct Nodo{

    int dato;
    Nodo *siguiente;

};

void Insertar(Nodo *&lista,int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo *aux1=lista;
    Nodo *aux2;

    while((aux1!=nullptr)&&(aux1->dato<n))
    {

        aux2=aux1;
        aux1=aux1->siguiente;

    }
    if(lista==aux1)
    {

        lista=nuevo_nodo;
        
    }else{

        aux2->siguiente=nuevo_nodo;

    }
    nuevo_nodo->siguiente=aux1;//esto hace que el nuevo nodo apunte al siguiente nodo

    cout<<"Elemento "<<n<<" insertado a la lista correctamente."<<endl;
    


}

void MostrarLista(Nodo *lista)
{

    Nodo *actual=new Nodo();
    actual=lista;

    if(actual==nullptr)
    {

        cout<<"\nLa lista esta vacia."<<endl;
        return;

    }

    while(actual!=nullptr)
    {

        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }

}

//para buscar elementos en la lista hay q seguir 4 pasos
//1. crear un nuevo nodo (acutual)
//2. igualar ese nodo a actual a la lista
//3. recorrer la lista
//4. determinar si el elemento existe o no en la lista
void BuscarElementos(Nodo *lista, int n)
{

    Nodo *actual=new Nodo();
    actual=lista;
    bool encontrado=false;

    while ((actual!=nullptr)&&(actual->dato<=n))
    {
        
        if(actual->dato==n)
        {

            encontrado=true;

        }
        actual=actual->siguiente;//esto hace que pase al siguiente nodo

    }
    if(encontrado==true)
    {

        cout<<"\nEl elemento "<<n<<" se encuentra en la lista."<<endl;

    }else{

        cout<<"\nEl elemento "<<n<<" no se encuentra en la lista."<<endl;

    }
    

}

int main()
{

    Nodo *lista=nullptr;
    int n=0;
    int opcion=0;
    do{

        cout<<"\n======MENU DE OPCIONES======="<<endl;
        cout<<"1. Insertar elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista."<<endl;
        cout<<"3. Buscar elemento en la lista."<<endl;
        cout<<"4. Salir."<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        if(opcion==1)
        {

            cout<<"Ingrese un numero: ";
            cin>>n;
            Insertar(lista,n);

        }else if(opcion==2){

            MostrarLista(lista);
            cout<<endl;

        }else if(opcion==3){

                
            cout<<"Ingrese el numero buscar: ";
            cin>>n;
            BuscarElementos(lista,n);

        }else if(opcion==4){

            cout<<"Saliendo del programa."<<endl;
        }else{

            cout<<"Opcion no valida."<<endl;

        }

    }while(opcion!=4);

}