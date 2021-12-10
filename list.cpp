#include "list.h"
#include<iostream>
using namespace std;

List::List()
{
    first = 0;
    mySize = 0;
}
void List::insert(long long int data,long long int w)
{
    NodePointer ptr = new Node(data,w);
    ptr->next = first;
    first = ptr;
    mySize++;
}
void List::display(long long int index)const
{
    NodePointer ptr = first;
    for (int i = 0; i < mySize; i++)
    {
        cout << index << "->" << ptr->data <<"   weight:" <<ptr->weight<<endl;
        ptr = ptr->next;
    }
}
