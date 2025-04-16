#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Ejemplo practico: armar un ejemplo practico como si fuera un nombres de nombres por rutas

//5 nombres
//0: Ciudad A  
//1: Ciudad B  
//2: Ciudad C  
//3: Ciudad D  
//4: Ciudad E

//y las rutas de las nombres son:
//A conecta con B y C
//B conecta con D
//C conecta con D y E
//D conecta con E

//Objetivo
//representa las conexiones 
//mostrar que cciudades estan conectadas con cual

//aprender como ver si se puede llegar de una ciudad a otra, usando un algoritmo de recorrido llamado
// Busqueda de anchura (BFS)

//que es un BFS?
//este recorre el grafo por niveles
//para ver que ciudades estan conectadas una por una

//objetivo: queremos saber si se puede ir de ciudad A(0) a Ciudad E(4)

bool ExisteCaminoBFS(vector<vector<int>>& grafo,int inicio,int destino)
{

    vector<bool> visitado(grafo.size(),false);
    queue<int> cola;

    visitado[inicio]=false;
    cola.push(inicio);

    while(!cola.empty())
    {
        
        int actual=cola.front();
        cola.pop();

        if(actual==destino)
        {

            return true;

        }
        for(int vecino:grafo[actual])
        {

            if(!visitado[vecino])
            {

                visitado[vecino]=true;
                cola.push(vecino);

            }

        }

    }
    
    return false;//no se encontro el caminoooooo

}

int main()
{

    int NumCiudades=5; // grafo
    vector<vector<int>> mapa(NumCiudades);
    vector<string> nombres {"Ciudad A","Ciudad B","Ciudad C","Ciudad D","Ciudad E"};

    mapa[0].push_back(1);//A -> B
    mapa[0].push_back(2);//A -> C
    mapa[1].push_back(3);//B -> D
    mapa[1].push_back(0);//B -> A
    mapa[2].push_back(3);//C -> D
    mapa[2].push_back(4);//C -> E
    mapa[2].push_back(0);//C -> A
    mapa[3].push_back(1);//D -> B
    mapa[3].push_back(2);//D -> C
    mapa[3].push_back(4);//D -> E
    mapa[4].push_back(3);//E -> D
    mapa[4].push_back(2);//E -> C

    for(int i=0;i<NumCiudades;i++)
    {

        cout<<nombres[i]<<" esta conectada con: ";
        for(int destino:mapa[i])
        {

            cout<<nombres[destino]<<", ";

        }
        cout<<"\n";

    }

    int origen=0;//CIUDAD A
    int destino=4;//CIUDAD E

    if(ExisteCaminoBFS(mapa,origen,destino))
    {

        cout<<"Si existe un camino entre "<<nombres[origen]<<" y "<<nombres[destino]<<"."<<endl;

    }else{

        cout<<"No existe un camino entre "<<nombres[origen]<<" y "<<nombres[destino]<<"."<<endl;

    }

}

