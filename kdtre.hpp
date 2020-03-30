#ifndef kdtree
#define kdtree

#include <bits/stdc++.h>
#include <iostream>

const int k = 2;

template <class Any>
class kdtre
{
private:
    struct Node {
        Any coor [k];
        Node * r;
        Node * l;
    };

    Node * root = nullptr;

public:
    kdtre() = default;
    ~kdtre() = default;

    void insert (Any * coor)
    {
        Node * newNode = new Node;
        newNode->r = nullptr;
        newNode->l = nullptr;

        for (int i = 0; i < k; i++){
            newNode->coor[i] = coor [i];
        }

        //std::cout <<"\nINSERT " << coor [0] << " " << coor [1] << "\n";

        if (root) {
            int t = 0;
            Node * temp = root;
            while(true){
                //std::cout << "paso por " << temp->coor [0] << " " << temp->coor [1];
                if (temp->coor [t % k] <= coor [t % k]){
                    //std :: cout << " right \n";
                    if (temp->r)
                        temp = temp->r;
                    else{
                        temp->r = newNode;
                        break;
                    }
                }
                else{
                    //std::cout << " left \n";
                    if (temp->l)
                        temp = temp->l;
                    else{
                        temp->l = newNode;
                        break;
                    }
                }          

                t++;    
            }

        }
        else
            root = newNode;
    }

    void search (Any * coor)
    {

    }

};



#endif