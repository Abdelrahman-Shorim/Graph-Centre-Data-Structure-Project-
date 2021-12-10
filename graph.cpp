#include "graph.h"
#include<iostream>
//#include <string>

using namespace std;
#define INF 99999

void Graph::inputuser()
{
    this->~Graph();
    llidatatype x=0;
    cout<<"enter no of indices\n";
    while(x==0) {
        cin>>x;
        if(x==0)
        {
            cout<<"you entered an incorrect number of vertices, please try again\n";
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    string *name=new string[x];
    cout<<"enter each vertex names\n";
    for(int i=0;i<x;i++)
        cin>>name[i];
    this->names=name;
    this->v = x;
    l = new List[v];
    graph=new llidatatype *[v];
    for(int i=0;i<v;i++)
    {
        graph[i]=new llidatatype [v];
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }
}

Graph::Graph() :size(0)
{

}

Graph::Graph(llidatatype v, string *name) :size(0)
{

    names=name;
    this->v = v;
    l = new List[v];
    graph=new llidatatype *[v];
    for(int i=0;i<v;i++)
    {
        graph[i]=new llidatatype [v];
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }
}

void Graph::add()  // for auto adding edges
{
    addEdge(0, 1, 5);
    addEdge(0, 5, 2);
    addEdge(1, 2, 4);
    addEdge(2, 3, 9);
    addEdge(3, 4, 7);
    addEdge(3, 5, 3);
    addEdge(4, 0, 1);
    addEdge(5, 2, 1);
    addEdge(5, 4, 8);
}
void Graph::addEdge(llidatatype val1,llidatatype val2,llidatatype w)  // for auto adding edges
{
    l[val1].insert(val2,w);
    graph[val1][val2]=w;
    if(!typeisdirected)
    {
        l[val2].insert(val1,w);
        graph[val2][val1]=w;
    }
    size++;
}


void Graph::addEdge()
{
    string x="", y="";
    llidatatype w=0;
    int val1,val2;
    while(w<=0) {
    val1=-1,val2=-1;
    cout<<"enter the first vertex name then second vertex name and lastly their weight\n";
        cin>>x>>y>>w;
        for(int i=0;i<v;i++)
        {
            if(x==names[i])
                val1=i;
            if(y==names[i])
                val2=i;
        }
        if(val1==-1||val2==-1||w==0||!cin)
        {
            cout<<"you entered a wrong vertix name please try again or wrong weight, please try again\n";
            w=0;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        addEdge(val1,val2,w);
}
void Graph::display()
{
    for (int i = 0; i < v; i++)
    {
        l[i].display(i);
    }
}

llidatatype** Graph::getoriginalg()
{
    return graph;
}
llidatatype Graph::getsize()
{
    return v;
}


llidatatype Graph::getnumberofedges()
{
    return size;
}
void Graph::settypeisdirected(bool x)
{
    typeisdirected=x;
}
string* Graph::getnames()
{
    return names;
}



Graph::~Graph() {
    for(int i=0;i<v;i++)
        delete []graph[i];
    delete [] graph;
}
