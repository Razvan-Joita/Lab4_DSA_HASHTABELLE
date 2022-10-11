#pragma once
#include "Map.h"


class MapIterator
{
    //DO NOT CHANGE THIS PART
    friend class Map;
private:
    const Map& map;
    //TODO - Representation

    int curr_bucket;      //multimea de liste din hash-map
    int curr_el;       //elementul curent din hash-map
    //int Array;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
    MapIterator(const Map& m);

    TElem delete_curr();


    TElem delete_curr() const;


};


