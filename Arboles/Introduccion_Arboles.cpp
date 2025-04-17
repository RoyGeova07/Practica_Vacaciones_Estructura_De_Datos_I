//Un arbol binario es un arbol de orden 2. Se conoce el nodo de la izquierda como hijo izquierdo, y el 
//nodo de la izquierda como hijo izquierdo y el nodo de la derecha como hijo izquierdo y el nodo de la
//derecha como hijo derecho.

//Un arbol binario es una estructura recursiva. Un arbol binariose divide en tres subconjuntos disjuntos:

//Nodo raiz
//Subarbol izquierdo
//Subarbol derecho

//Es una estrucutura recursiva porque podria volver a llarmar asi misma, si quitamos la raiz 
//podriamos volver a llamar los subarboles izquierdo y derecho, ya que en cada nivel se vuelve a repetir
//lo del nivel anterior

//Tipos de arboles binarios

//Arbol lleno:
//Es aquel en el que todos sus nodos excepto los del ultimo nivel, todos sus nodos tienen 2 hijos, 
//excepto el ultimo nivel y ademas el ultimo nivel, todos estan exactos  

//Arbol completo: 
//La pequeña diferencia que tiene un arbol lleno con un arbol completo es que los nodos hojas del ultimo
//nivel no estan todos, al mismo nivel 

//Arbol degenerado
//Solos arboles que solo tiene un hijo, al extenderlo puede ser una lista enzlzadaa

//Representacion en codigo
struct Nodo
{
    
    int dato;
    Nodo*derecha;
    Nodo*izquierda;

};

//Arbol binario de busqueda 
//Es aquel que dado un nodo, todos los datos del subarbol izquierdo son menores, mientras que todos los
//datos del subarbol derecho son mayores

//Operaciones en arboles binarios de busqueda:
//Insertar un nodo en el arbol
//Mostrar el arbol completo
//Buscar un nodo especifico
//Recorrer el arbol -> PreOrden, Orden y Posorden 3, recorridos del arbol
//Borrar un nodo del arbol