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
    typedef std::vector <Node *>  VectorNodes;
    typedef std::vector <VectorNodes> MatrixNodes;
    typedef std::stack <Node *> StackNodes;

    Node * root = nullptr;

    void nodeToStack (Node * & n, StackNodes & s, MatrixNodes & v){
        s.push (n);
        if (s.size () > v.size()){
            VectorNodes temp;
            v.push_back (temp);
        }
        if (n->l)
            nodeToStack (n->l, s, v);
        if (n->r)
            nodeToStack (n->r, s, v);

        v[s.size() - 1].push_back(n);
        s.pop ();
    }

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

    bool search (Any * coor)
    {
        if (root) {
            int t = 0;
            Node * temp = root;
            while(true){
                int eq_coors = 0;
                for (; eq_coors < k; eq_coors++){
                    if (temp->coor [eq_coors] != coor [eq_coors])
                        break;
                }

                if (eq_coors == k)
                    return true;

                if (temp->coor [t % k] <= coor [t % k]){
                    if (temp->r)
                        temp = temp->r;
                    else
                        break;
                }
                else{
                    if (temp->l)
                        temp = temp->l;
                    else
                        break;
                }          

                t++;    
            }
        }

        return false;
    }

    void print (){
        if (root){
            StackNodes stacknodes;
            MatrixNodes vec;
            nodeToStack (root, stacknodes, vec);
            for (int i = 0; i < vec.size(); i++){
                if (i%2)
                    std::cout << "y:  ";
                else
                    std::cout << "x:  ";
                for(int j = 0; j < vec [i].size(); j++)
                    std::cout << vec [i] [j]->coor[0] << "," << vec [i][j]->coor [1] << " ";
                std::cout << "\n";
            }
        }
        else
        {
            std::cout << "Not nodes\n";
        }
        
    }

};



#endif