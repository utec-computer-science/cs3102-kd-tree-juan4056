#include "kdtre.hpp"

int main(int argc, const char * argv[]){

    kdtre <int> kd;
    int points[][2] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, 
                       {9, 1}, {2, 7}, {10, 19}}; 

    int n = sizeof(points)/sizeof(points[0]); 
  
    for (int i=0; i<n; i++) 
       kd.insert(points[i]); 

    return 0;
}