#include <iostream>
#include <vector>
using namespace std;

//Que es un grafo?
// Un grafo es como un mapa de relaciones 

//ejercicio 1: Tengo 4 personas: Ana, Bruno, Carla y David.
//y se quien es amigo de quien

//Ana es amiga de Bruno y Carla.
//Bruno es amigo de David.
//Carla es amiga de David.

//cada persona es un nodo (vertice)
//cada amistad es una conexion (arista)

//quiero: recordar quien es amigo de quien
//poder recorrer el grafo y decir : Quienes son los amigos de Carla?

//representacion sencilla: lista de adyacencia
//cada persona tiene su lista de amigos

//0: Ana     → 1 (Bruno), 2 (Carla)
//1: Bruno   → 0 (Ana), 3 (David)
//2: Carla   → 0 (Ana), 3 (David)
//3: David   → 1 (Bruno), 2 (Carla)

//voy a representarlo con un vector<int>

//creo el grafo

int main()
{

    int Numpersonas=4;
    vector<vector<int>> grafo(Numpersonas);//lista de adyacencia
    vector<string> nombres {"Ana","Bruno","Carla","David"};

    //aqui agrego las conexiones (amistades)
    grafo[0].push_back(1); //Ana -> bruno
    grafo[0].push_back(2); //Ana -> Carla
    grafo[1].push_back(0);//Bruno -> Ana
    grafo[1].push_back(3);//Bruno -> David
    grafo[2].push_back(0);//Carla -> Ana
    grafo[2].push_back(3);//Carla -> David
    grafo[3].push_back(1);//David -> Bruno
    grafo[3].push_back(2);//David -> Carla

    for(int i=0;i<Numpersonas;i++)
    {

        cout<<nombres[i]<<" es amigo de: ";
        for(int amigo:grafo[i])
        {

            cout<<nombres[amigo]<<" y ";

        }
        cout<<"\n";

    }

}