#ifndef FLOYD_H
#define FLOYD_H
typedef long long int llidatatype;
#include <iostream>
using namespace std;

class floyd
{
private:
    llidatatype  **shortg;
    llidatatype v;
    string *names;

public:
    floyd(llidatatype **x,llidatatype size, string *name);
    void floydWarshall();
    void findcentre();
    void printshortestpathofcentre(llidatatype e[]);
    void display();

};

#endif // FLOYD_H
