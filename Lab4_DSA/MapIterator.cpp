#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    //TODO - Implementation
    first();        //functia de first este implementata in constructor

}


void MapIterator::first() {
    //TODO - Implementation


    //se vor parcurge toate listele din curr_bucket

    for(int i=0;i<map.m;i++)
    {
        MapNode *aux=map.Array[i];
        if(aux!= nullptr)
        {

            curr_bucket=i;    //Primul element este cautat din toate listele
            curr_el=0;
            return;


        }

    }
    curr_bucket=-1;

}
//Complexitatea este de Theta(m)

void MapIterator::next() {
    //TODO - Implementation


    if(curr_bucket==-1)
    {
        throw exception();   //Daca nu mai sunt elemente in liste se va arunca exceptie

    }

    MapNode *aux=map.Array[curr_bucket];
    int copie=curr_el;

    while(copie>0)
    {
        copie--;
        aux=aux->next;    //se ajunge la pozitia curr-el in curr_bucket

    }


    //daca bucketul curent mai are elemente,doar creste curr_el
    if(aux->next!= nullptr)
    {
        curr_el++;
        return;
    }



    //altfel se cauta primul bucket cu elemente daca exista


    for(int i=curr_bucket+1;i<map.m;i++)
    {
        aux=map.Array[i];
        if(aux!=nullptr)
        {
            curr_bucket=i;
            curr_el=0;
            return;
        }

    }

    curr_bucket=-1;
//daca nu mai sunt elemente in nicio lista atunci curr_bucket=-1
}

//Complexitatea este de  O(m)

TElem MapIterator::getCurrent(){
    //TODO - Implementation
    if(curr_bucket==-1)
    {
        throw exception();       //daca in bucket ul de liste e minus 1 se arunca exceptie

    }

    MapNode *aux=map.Array[curr_bucket];
    int copie=curr_el;      //voi lua o copie pentru elementul curent

    while(copie>0)
    {
        aux=aux->next;
        copie--;
    }
    return aux->elem;
}
//Complexitatea de Theta(1)

bool MapIterator::valid() const {
    //TODO - Implementation

    return curr_bucket!=-1;        //se verifica daca curr_bucket este valid,
    //adica este element in lista
}

//Complexitatea este de Theta(1)



TElem MapIterator::delete_curr()
{


    MapNode *m1;
    int nr;
    int curr_el;
    int curr_bucket;
    int poz=0;
    MapNode *aux2=new MapNode;
    MapNode **Array;


    //Cat timp este diferit de 0
    if(m1!=0)
    {
        //MapNode *aux=this->Array[m1.curr_bucket]->Array[m1.curr_bucket]->next;
        aux2=aux2->next;


    }
    while(curr_el!=poz)
    {
        aux2=aux2->next;

    }



    //Stergerea va avea loc ca intr-o lista simpla inlantuita
    // avand nevoie de 2 pointeri


    MapNode *aux3=aux2->next;
    TValue v1=aux3->elem.second;

    aux2->next=aux3->next;

    delete aux3;

    nr--;



}



