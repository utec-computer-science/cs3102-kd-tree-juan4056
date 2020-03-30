#ifndef kdtree
#define kdtree

#include <bits/stdc++.h>

const int k = 2;

template <class Any>
class kdtre
{
private:
    struct Node {
        Any coor [k];
        Node * r;
        Node * l;
    }

    Node * root;

public:
    kdtre() = default;
    ~kdtre() = default;

    void insert (Any * coor)
    {

    }

    void search (Any * coor)
    {

    }

};



#endif