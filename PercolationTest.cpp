#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <random>
#include <time.h>
#include "percolation.h"
#include "ProgressBar.h"
#include "pbPlots.hpp"
#include "supportLib.hpp"


using namespace std;


class PercolationTest
{
private:
    int n = 10;
    float prob;
    percolation p = percolation(n);
public:
    PercolationTest(float pr){
        prob = pr;
        random_device rd;
        default_random_engine generator(rd());
        bernoulli_distribution distribution(pr);
        for (size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                if(distribution(generator)) p.open(i, j);
            }   
        }
        
    }

    void printSys(){
        for (size_t i = 0; i < n; i++){
            for (size_t j = 0; j < n; j++){
                if(p.isOpen(i, j) && p.isFull(i, j)) printf("@ ");
                else if(p.isOpen(i, j)) printf("  ");
                else printf("# ");
            }
            printf("\n");
        }
    }

    bool chk(){
        return p.percolates();
    }
};

int main(){
    float p = 0.001;
    vector<vector<int>> res;
    ProgressBar progress{clog, 100u, "calculating"};

    for (auto i = 0.0;  i <= 1000;  i++) {
        progress.write(i/1000.0);
        vector<int> x;
        for (int j = 0; j < 100; j++)
        {
            PercolationTest pt(p*i);
            x.push_back(pt.chk());
        }
        res.push_back(x);
    }
    
    // for(vector <int> i : res){
    //     for(int j : i){
    //     cout << j << " ";
    //     }
    //     cout<< "\n";
    // }
    // cout << "" << endl;

    RGBABitmapImageReference *imageref = CreateRGBABitmapImageReference();

    vector<double>x;

    for (int i = 0; i < 1000; i++){
        x.push_back(i*p);
    }

    vector<double> y;

    for (int i = 0; i < 1000; i++){
        double sum = 0.0;
        for(int j: res[i]){
            sum+=j;
        }
        y.push_back(sum/100);
    }
    StringReference *errorMessage = new StringReference();
    DrawScatterPlot(imageref, 1920, 1080, &x, &y, errorMessage);

    vector<double> *pngdata = ConvertToPNG(imageref->image);
    WriteToFile(pngdata, "Montecarlo Simulation.png");
    DeleteImage(imageref->image);


    
    return 0;
}
