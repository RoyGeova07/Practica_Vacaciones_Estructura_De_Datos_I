#include <iostream>
using namespace std;

struct Nodo
{
    
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
    nuevo_nodo->siguiente=aux1;

}

void MostrarLista(Nodo *lista)
{

    Nodo *actual=new Nodo();
    actual=lista;

    if(actual==nullptr)
    {

        cout<<"\n La lista esa vacia"<<endl;
        return;

    }

    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    

}

void BuscarElementos(Nodo *lista,int n)
{

    Nodo *actual=new Nodo();
    actual=lista;
    bool Banderita=false;

    while((actual!=nullptr)&&(actual->dato<=n))
    {

        if(actual->dato==n)
        {

            Banderita=true;

        }
        actual=actual->siguiente;

    }
    if(Banderita==true)
    {

        cout<<"\nEl elemento "<<n<<" se encuentra en la lista."<<endl;

    }else{

        cout<<"\nEl elemento "<<n<<" no se encuentra en la lista."<<endl;

    }
    

}

//para eliminar un elemento de la lista hay q seguir 5 pasos
//1,preguntar si la lista esta vacia
//2. crear un nodo auxiliar y anterior=null
//3. igualar auxiliar al inicio de la lista
//4. recorre la lista
//5. eliminar el elemento de la lista

void EliminarElemento(Nodo *&lista,int n)
{

    if(lista==nullptr)
    {

        cout<<"\nLa lista esta vacia."<<endl;
        return;

    }

    if(lista!=nullptr)
    {

        Nodo *auxiliar_borrar=new Nodo();
        Nodo *anterior=nullptr;
        auxiliar_borrar=lista;

        while ((auxiliar_borrar!=nullptr)&&(auxiliar_borrar->dato!=n))
        {
            
            anterior=auxiliar_borrar;
            auxiliar_borrar=auxiliar_borrar->siguiente;//esto hace que pase al siguiente nodo

        }
        if(auxiliar_borrar==nullptr)
        {

            cout<<"\nEl elemento no existe";

        //si esta condicional se cumple es porque no se cumplio el while
        }else if(anterior==nullptr){//si el elemento es el primero que queremos eliminar de la lista esta condicional se cumplira

            lista=lista->siguiente;
            delete auxiliar_borrar;
            cout<<"\nElemento "<<n<<" eliminado exitosamente";

        }else{
            
            anterior->siguiente=auxiliar_borrar->siguiente;//esto hara que anterior pase al siguiente nodo, ya se si es un elemento o en null
            delete auxiliar_borrar;
            cout<<"\nElemento "<<n<<" eliminado exitosamente";

        }
        

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
        cout<<"4. Eliminar un elemento de la lista."<<endl;
        cout<<"5. Salir."<<endl;
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

            cout<<"Ingrese el elemento a eliminar de la lista: "<<endl;
            cin>>n;
            EliminarElemento(lista,n);
            
        }else if(opcion==5){

            cout<<"Saliendo del programa.";
            break;

        }else{

            cout<<"Opcion no valida."<<endl;

        }

    }while(opcion!=5);

}