#include <iostream>
#include <chrono>
#include <fstream>
#include "array.h"

class oWlist
{
public:
    int info;
    oWlist* next;

    oWlist(int _info)
    {
        info = _info;
        next = nullptr;
    }
};

oWlist* insert(int value, oWlist* start);

oWlist* build_owlist(int* tab, int size, oWlist* start);

void display_owlist(oWlist* start);

void Owlist_test();

oWlist* search_OWlist(oWlist* start, int x);

oWlist* delete_OWlist(oWlist* start);