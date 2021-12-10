#pragma once
#include"list.h"
#include <iostream>
using namespace std;

class Graph
{
private:
    llidatatype v;
    List* l;
    string *names;
    bool typeisdirected;
    llidatatype  **graph;
    llidatatype size;
public:
    Graph();
    Graph(llidatatype v, string *name);
    void addEdge();
    void addEdge(llidatatype val1,llidatatype val2,llidatatype w);
    void display();
    void add();
    llidatatype** getoriginalg();
    llidatatype getsize();
    llidatatype getnumberofedges();
    void inputuser();
    void settypeisdirected(bool x);
    void handle_errors(llidatatype x,llidatatype y,llidatatype w);
    string* getnames();

    ~Graph();
};
