#include <iostream>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <time.h>
#include "UnionFind.h"


using namespace std;

class percolation{
private:
    int n;
    vector<vector<int>> perc;
    UnionFind full;
    UnionFind uf;
    int openSites;

    int encode(int i,int j){
        return n*i + j + 1;
    }

public:
    percolation(int k){
        n = k;
        uf.init(k * k +2);
        full.init(k*k +1);
        for (size_t i = 0; i < k; i++){
            perc.push_back(vector<int>(k, -1));
        } 
        uf.Union(1, 0);
        openSites = 0;

    }

    bool isOpen(int i, int j){
        return (perc[i][j] == 1);
    }

    void open(int i, int j){
        if(!isOpen(i, j)){
            perc[i][j] = 1;
            openSites++;

            if(i >0 && isOpen(i-1, j)){
                uf.Union(encode(i-1, j), encode(i, j));
                full.Union(encode(i-1, j), encode(i, j));
            }
            else if(i-1 == -1){
                uf.Union(0, encode(i, j));
                full.Union(0, encode(i, j));
            }
            if(j >0 && isOpen(i, j-1) ){
                uf.Union(encode(i, j-1), encode(i, j));
                full.Union(encode(i, j-1), encode(i, j));
                
            }
            if(i+1 < n && isOpen(i+1, j) ){
                uf.Union(encode(i+1, j), encode(i, j));
                full.Union(encode(i+1, j), encode(i, j));
            }
            else if(i +1 == n){
                uf.Union(encode(i, j), n*n +1);
            }
            if(j+1 < n && isOpen(i, j+1)){
                uf.Union(encode(i, j+1), encode(i, j));
                full.Union(encode(i, j+1), encode(i, j));
                
            }
        }
    }

    bool isFull(int i, int j){
        return(uf.isConnected(encode(i, j), 0) && isOpen(i, j));
    }

    bool percolates(){
        return uf.isConnected(0, (n*n) +1);
    }

    
};

// int main(){
//     percolation p(3);
//     // p.open(0,0);
//     p.open(0,1);
//     p.open(1, 0);
//     p.open(1,1);
//     p.open(2,1);
//     cout << p.percolates() << endl;
//     return 0;
// }