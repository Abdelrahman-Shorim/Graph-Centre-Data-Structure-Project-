#include <iostream>
#include"graph.h"
#include "floyd.h"
using namespace std;
#define INF 99999
#include <windows.h>

void start()
{
    cout<<"*********************************************************\n";
    cout<<"**           Welcome to our project                    **\n";
    cout<<"**                Graph centre                         **\n";
    cout<<"*********************************************************\n";
}

int main()
{
    start();
    cout<<"Let's start our program by asking, do you want a directed graph?? enter y for yes \n";
    char c;
    bool typeisdirected;
    cin>>c;
    if(c=='y'||c=='Y')
        typeisdirected=true;
    else
        typeisdirected=false;
    llidatatype x=6,choice;
    string *names=new string[x];
    names[0]="Dr Ashraf";
    names[1]="Eng Hager";
    names[2]="Eng Mahmoud";
    names[3]="Nour";
    names[4]="Mohamed";
    names[5]="Youssef";

    Graph g(x,names);

    g.settypeisdirected(typeisdirected);
    cout<<"Enter the choice you want to do\n";

    do{
        cout<<"1: to add an edge manually\n2: use available edges \n";
       if(g.getnumberofedges()>0)
       {
           cout<<"4: jump to the Steps of floyd algo\n";
       }

        cin>>choice;

        if(!cin)
        {
            cout<<"you entered a wrong choice try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(choice==1)
        {
            if(g.getnumberofedges()==0)
                g.inputuser();
             g.addEdge();   //to add edges manually
        }
        if(choice==2) {
            if(g.getnumberofedges()>0)
            {
                cout<<"you already entered some data you can't use the available data\n";
                continue;
            }
            g.add();
            choice=4;
        }
        if(choice==4)
        {
            if(g.getnumberofedges()<=0)
                choice=0;
        }
    }while(choice!=4);

    floyd f(g.getoriginalg(),g.getsize(),g.getnames());
    f.findcentre();


}
