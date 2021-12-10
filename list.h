#pragma once
typedef long long int llidatatype;
class List
{
private:
    class Node {
    public:

        llidatatype data;
        llidatatype weight;
        Node* next;

        Node()
            : next(0)
        {}

        Node(llidatatype dataValue, llidatatype w)
            : data(dataValue), weight(w), next(0)
        {}
    };

    typedef Node* NodePointer;
    NodePointer first;
    llidatatype mySize;
public:
    List();
    void insert(llidatatype data, llidatatype w);
    void display(llidatatype index)const;
};
