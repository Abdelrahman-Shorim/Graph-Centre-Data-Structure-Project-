//#include<bits/stdc++.h>
#include "floyd.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

#define INF 99999

floyd::floyd(llidatatype **x,llidatatype size, string *name)
{
    HANDLE std_output = GetStdHandle(STD_OUTPUT_HANDLE);

    int s=6;
    names=name;
    v=size;
    shortg=new llidatatype *[v];
    for(int i=0;i<v;i++)
    {
        shortg[i]=new llidatatype [v];
    }

    SetConsoleTextAttribute(std_output, 3);

    cout<<endl<<endl<<"The original graph is:\n\n";
    SetConsoleTextAttribute(std_output, 7);


    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            shortg[i][j] = x[i][j];
            Sleep(45);
            shortg[i][j] == INF ?
            cout<< setw(s) <<left<< "INF" << setw(s)<<left : cout << setw(s)<<left<<shortg[i][j]<< setw(s) << left;
        }
        cout<<endl;
    }
    floydWarshall();
}


void floyd::floydWarshall()
{
    HANDLE std_output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(std_output, 3);
    cout<<"\n\nSteps of floyd algorithm:\n\n";
    SetConsoleTextAttribute(std_output, 7);
    int s=6;
    for (int k = 0; k < v; k++) {
        // Pick all vertices as source one by one
        cout<<"Vertex '"<<names[k]<<"' as source: "<<endl;

        for (int i = 0; i < v; i++) {
            string o=names[i]+":";
            cout<< setw(13) <<left<<o<< setw(13) <<left;
            for (int j = 0; j < v; j++) {
                if (shortg[i][j] > (shortg[i][k] + shortg[k][j])
                    && (shortg[k][j] != INF
                        && shortg[i][k] != INF))
                {
                    shortg[i][j] = shortg[i][k] + shortg[k][j];
                    SetConsoleTextAttribute(std_output, FOREGROUND_GREEN);
                }
                Sleep(45);

                shortg[i][j] == INF ?
                cout<< setw(s) <<left<< "INF" << setw(s)<<left : cout << setw(s)<<left<<shortg[i][j]<< setw(s) << left;
                SetConsoleTextAttribute(std_output, 7);
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

}


void floyd::findcentre()
{
    llidatatype eccentricity[v];
    for(int i=0;i<v;i++)
    {
        eccentricity[i]=0;
        for(int j=0;j<v;j++)
        {
            if(shortg[i][j]==INF)
                continue;
            eccentricity[i]=(shortg[i][j]>eccentricity[i])?shortg[i][j]
                     :eccentricity[i];
        }
    }
    printshortestpathofcentre(eccentricity);
}
void floyd::printshortestpathofcentre(llidatatype e[])
{
    HANDLE std_output = GetStdHandle(STD_OUTPUT_HANDLE);
    llidatatype centre=INF,index=-1;
    for(int i=0;i<v;i++)
    {
        if(e[i]==0)
            continue;
        if(centre>=e[i])
        {
            centre=e[i];
            index=i;
        }
    }
    Sleep(45);
    cout<<"the centre vertex of this graph is: "<<names[index]<<endl<<endl;
    Sleep(45);
    cout<<"it's shortest path to other vertex are :\n";
    SetConsoleTextAttribute(std_output, 4);
    for(int i=0;i<v;i++)
    {
        Sleep(500);
        cout<<shortg[index][i]<<"   ";
    }
    SetConsoleTextAttribute(std_output, 7);

    cout<<endl<<endl<<endl<<endl;
}



void floyd::display()
{
        for(int i=0;i<v;i++)
        {

            for(int j=0;j<v;j++)
            {
                if(shortg[i][j]==INF)
                    cout<<0<<" ";
                else
                    cout<<shortg[i][j]<<" ";
            }
            cout<<endl;
        }
}
