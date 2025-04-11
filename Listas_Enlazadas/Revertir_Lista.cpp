#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo *siguiente;

};


void Insertar(Nodo *&lista, int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo*aux1=lista;
    Nodo*aux2;

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

void Eliminar(Nodo *&lista,int n)
{

    if(lista==nullptr)
    {

        cout<<"\nLista vacia"<<endl;
        return;

    }
    if(lista!=nullptr)
    {

        Nodo*aux1=lista;
        Nodo*aux2=nullptr;

        while((aux1!=nullptr)&&(aux1->dato!=n))
        {
            
            aux2=aux1;
            aux1=aux1->siguiente;

        }
        if(aux1==nullptr)
        {

            cout<<"\nEl elemento no existe";

        }else if(aux2==nullptr){

            lista=lista->siguiente;
            delete aux1;
            cout<<"\nElemento"<<n<<" eliminado exitsamente";

        }else{

            aux2->siguiente=aux1->siguiente;
            delete aux1;
            cout<<"\nElemento "<<n<<" elimianado exitosamente";

        }
        
    }

}

void BuscarElemento(Nodo *lista,int n)
{

    Nodo*actual=lista;
    bool encontrado=false;
    while((actual!=nullptr)&&(actual->dato<=n))
    {

        if(actual->dato==n)
        {

            encontrado=true;

        }
        actual=actual->siguiente;

    }
    if(encontrado==true)
    {

        cout<<"\nElemento "<<n<<" EXISTE en la lista";

    }else{

        cout<<"\nElemento "<<n<<" NO EXISTE en la lista";

    }

}

void Revertir(Nodo *&lista)
{

    Nodo *anterior=nullptr;
    Nodo*actual=lista;
    Nodo*siguiente=nullptr;

    while(actual!=nullptr)
    {

        siguiente=actual->siguiente;
        actual->siguiente=anterior;
        anterior=actual;
        actual=siguiente;

        //ejemplo grafico: anterior = null, actual = 5, siguiente = null
        //la lista esta asi lista y actual -> [5] -> [10] -> [15] -> null  

        //primer ciclo: 
        //siguiente = actual->siguiente -> [10]
        //actual->siguiente = anterior  lista y actual -> [5] -> null
        //anterior = actual ahora anterior apunta a [5]
        //actual=siguiente actual ahora a punta a [10]

        //segundo ciclo:
        //siguiente = actual->siguiente -> [15]
        //actual->siguiente=anterior lista y actual -> [10] -> [5] -> null
        //anterior=actual ahora anterior apunta a [10]
        //actual=siguiente actual ahora apunta a [15]

        //tercer ciclo:
        //siguiente = actual-> siguiente -> null
        //actual->siguiente=anterior lista y actual -> [15] -> [10]
        //anterior=actual anterioir apunta a [15]
        //actual = siguiente, actual ahora apunta a null

    }
    //salimos del bucle porque ahora es null
    lista=anterior;
    cout<<"\nLista revertirda!";
    

}

void MostrarLista(Nodo *lista)
{

    Nodo*actual=lista;
    while(actual!=nullptr)
    {
        
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    

}

int main()
{

    Nodo *lista=nullptr;
    int n=0;
    int opcion=0;
    do{

        cout<<"\n======MENU DE OPCIONES=======\n"<<endl;
        cout<<"1. Insertar elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista."<<endl;
        cout<<"3. Buscar elemento en la lista."<<endl;
        cout<<"4. Eliminar un elemento de la lista."<<endl;
        cout<<"5. Revertir Lista"<<endl;
        cout<<"6. Salir."<<endl;
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
            BuscarElemento(lista,n);

        }else if(opcion==4){

            cout<<"Ingrese el elemento a eliminar de la lista: "<<endl;
            cin>>n;
            Eliminar(lista,n);
            
        }else if(opcion==5){

            Revertir(lista);

        }else if(opcion==6){

            cout<<"Saliendo del programa.";
            break;

        }else{

            cout<<"Opcion no valida."<<endl;

        }

    }while(opcion!=6);

}