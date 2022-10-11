#include "Map.h"
#include "MapIterator.h"
#include<stdio.h>
#include<iostream>


using namespace std;


Map::Map()
{

    //TODO - Implementation
    m=23;                                //initializarea variabilelor
    Array=new MapNode*[m];         //alocarea dinamica a array ului de pointeri
    nr=0;
    for(int i=0;i<m;i++)
    {
        Array[i]= nullptr;
    }
}

//Complexitatea este de Theta(m) pentru constructor


Map::~Map()
{
    //TODO - Implementation
    delete []Array;            //aici este destructorul pentru Array ul de pointeri

}
//Complexitatea este de Theta(1) pentru destructor


TValue Map::add(TKey c, TValue v){
    //TODO - Implementation



    int h=hashFunction(c);  //se va aplica functia de hash pe cheia din Map
    MapNode *aux=Array[h];
    int found=0;


    //Se cauta elementul daca mai exista deja,
    // elementul cu cheia respectiva,se inlocuieste valoarea
    while(aux!= nullptr)
    {

        if(aux->elem.first==c)
        {
            int oldv=aux->elem.second;

            aux->elem.second=v;
            //Aici va avea loc resize ul si rehash ul in sus
            return oldv;

        }
        aux=aux->next;
    }


    MapNode *nou=new MapNode;
    nou->elem= std::make_pair(c,v);   //perechea cu cheie si valoare va fi egal cu nou
    nr++;

    nou->next=Array[h];
    Array[h]=nou;



    return NULL_TVALUE;
}


//Best Case este de Theta(1)
//Worst Case O(n)
//Average Case Theta(n)


TValue Map::search(TKey c) const{
    //TODO - Implementation
    int h=hashFunction(c);
    MapNode *aux=Array[h];


    //se va parcurge lista
    while(aux!= nullptr)
    {
        if (aux->elem.first == c)                //se va parcurge toata lista si se va cauta in dictionar dupa cheie si se va retuna valoarea
        {
            return aux->elem.second;
        }
        aux = aux->next;     //trec la urmatorul nod din hash-map
    }
    return NULL_TVALUE;
}

//Best Case Theta(1)
//Worst Case O(n)
//Average Case Theta(1)


TValue Map::remove(TKey c){
    //TODO - Implementation

    int h=hashFunction(c);//Functia de hash-ing se va aplica pe cheie
    MapNode *aux=Array[h];

    MapNode *prev;   //Se va lua un nou pointer pentru previous node ul din hash map


    if(aux== nullptr)
        return NULL_TVALUE;   //nu exista elemente in lista

    if(aux->elem.first==c)                      //se cauta elementul dupa cheia lui
    {
        int v=aux->elem.second;
        Array[h]=aux->next;              //cazul in care stergem primul element din lista
        delete aux;
        nr--;
        //resize si rehas ul in jos,pentru care trebuia un nou Array de pointeri
        return v;
    }
    prev=aux;                      //nodul anterior o sa fie aux
    aux=aux->next;


    //se tin doi pointeri pentru stergerea de la mijloc sau de la final ca sa se stie cum
    //se fac legaturile in lista

    while(aux!= nullptr)
    {
        if(aux->elem.first==c)
        {
            int v=aux->elem.second;
            prev->next=aux->next;
            delete aux;
            nr--;
            //resize si rehash ul in jos
            return v;
        }

        prev=aux;
        aux=aux->next;
    }
    return NULL_TVALUE;
}


//Best Case este de Theta(1)
//Worst Case este O(n)
//Average Case este de Theta(1)

int Map::size() const {
    //TODO - Implementation
    return nr;     //se returneaza size hash mapului
}
//Complexitatea de Theta(1)

bool Map::isEmpty() const{
    //TODO - Implementation
    return nr==0;       //functie booleana care verifica daca hash mapul este gol
}
//Complexitatea de Theta(1)


MapIterator Map::iterator() const {
    return MapIterator(*this);
}

//Complexitatea de Theta(1)



int Map::hashFunction(TKey c) const
{
    int x=c%m;
    if(x<0)
        x=-x;          //Functie de hash
    return x;

}



//Complexitatea de Theta(1)

