#include <iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*siguiente;

};


void Insertar(Nodo *&lista,int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo*aux1=lista;
    Nodo*aux2;

    //si la lista esta vacia
    if(lista==nullptr)
    {

        lista=nuevo_nodo;
        nuevo_nodo->siguiente=lista;//<- apunta a si mismo
        cout << "\nElemento " <<n<<" insertado correctamente a la lista simple circular\n"; 
        return;

    }

    while((aux1->siguiente!=lista)&&(aux1->dato<n))
    {

        aux2=aux1;
        aux1=aux1->siguiente;

    }
    if(lista==aux1&&n<aux1->dato)
    {
        
        //aqui se inserta al inicio
        nuevo_nodo->siguiente=lista;

        //aqui se buscara el ultimo nodo para cerrar el circulo
        Nodo*ultimo=lista;
        while(ultimo->siguiente!=lista)
        {
            
            ultimo=ultimo->siguiente;

        }
        ultimo->siguiente=nuevo_nodo;
        lista=nuevo_nodo;

    }else{

        //aqui se insertar al medio o al final
        aux2->siguiente=nuevo_nodo;
        nuevo_nodo->siguiente=aux1;

    }

    cout<<"\nElemento "<<n<<" insertado correctamente a la lista simple circular\n";
    
}

void MostrarLista(Nodo*lista)
{

    if(lista==nullptr)
    {

        cout<<"\nLista vacia";
        return;

    }

    Nodo*actual=lista;

    do
    {
        
        cout<<"["<<actual->dato<<"] -> ";
        actual=actual->siguiente;

    } while (actual!=lista);
    
    cout<<"(inicio)\n";
    

}

void EliminarElemento(Nodo*&lista,int n)
{

    if(lista==nullptr)
    {

        cout<<"\nLista vacia";

    }

    Nodo*actual=lista;
    Nodo*anterior=nullptr;
    //con este bucle recorrera la lista para buscar el nodo a eliminar, se detiene si da toda la vuelta
    do{

        if(actual->dato==n)
        break;

        anterior=actual;
        actual=actual->siguiente;

        

    }while(actual!=lista);

    //caso donde si no se encontra el nod
    if(actual->dato!=n)
    {

        cout<<"\nElemento "<<n<<" no encontrado en la lista circular\n";
        return;

    }

    //caso si solo hay un nodo
    if(actual==lista&&actual->siguiente==lista)
    {

        delete actual;
        lista=nullptr;
        cout<<"\nElemento "<<n<< " Eliminado de la lista circular\n";
        return;

    }

    //caso si es el primer nodo
    if(actual==lista)
    {

        //aqui buscamos el ultimo nodo
        Nodo*ultimo=lista;
        while(ultimo->siguiente!=lista)
        {
            
            ultimo=ultimo->siguiente;

        }
        lista=lista->siguiente;
        ultimo->siguiente=lista;
        delete actual;
        cout<<"\nElemento "<<n<< " Eliminado de la lista circular\n";
        return;
        
    }
    anterior->siguiente=actual->siguiente;
    delete actual;
    cout<<"\nElemento "<<n<< " Eliminado de la lista circular\n";
    return;

}

void BuscarElemento(Nodo*lista,int n)
{

    Nodo*actual=lista;
    bool encontrado=false;

    //porque siempre se usa do while en una lista circular?
    //porque en una lista circular, se debe revisar al menos una vez,
    //solo se detiene cuando da la vuelta completa, (actual==lista de nuevo)
    do{

        if(actual->dato==n)
        {

            encontrado=true;

        }
        actual=actual->siguiente;

    }while(actual!=lista);
    if(encontrado==true)
    {

        cout<<"\nEl elemento "<<n<<" se encuentra en la lista circular."<<endl;

    }else{

        cout<<"\nEl elemento "<<n<<" no se encuentra en la lista circular."<<endl;

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
          //  BuscarElementos(lista,n);

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