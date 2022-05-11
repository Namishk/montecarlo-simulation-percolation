#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using namespace std::chrono;


class UnionFind{

    private:
        vector<int> arr;   

    // int root(int r){
    //     if(arr[r] = r) return r;
    //     return root(arr[r]);
    // }

    public:
    
    void init(int n){
        for (size_t i = 0; i < n; i++)
        {
            arr.push_back(i);
        }
        
    }


    bool isConnected(int p, int q){
        return Find(p) == Find(q);
    }

    void Union(int p, int q){
        int rootA = Find(p);
        int rootB = Find(q);
        arr[rootA] = rootB;
    }

    int Find(int n){
        if(arr[n] == n) return n;
        return Find(arr[n]);
    }
};

// int main(){

//     UnionFind ds;
//     ds.init(5);
//     ds.Union(2,4);
//     cout << ds.isConnected(2, 4);
    
//     return 0;
// }