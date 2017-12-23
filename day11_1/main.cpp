#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string row,sv;
    ifstream f("input.txt");
    getline(f,row);
    //row="se,sw,se,sw,sw";
    stringstream ss(row);
    vector<string> steps;
    while (getline(ss,sv,',')) {
        steps.push_back(sv);
    }
    double y=0, x=0;
    int maxe=-0;
    for (int i=0; i<steps.size();i++) {
        if (steps[i]=="n") {x++;}
        else if (steps[i]=="s") {x--;}
        else if (steps[i]=="ne") {x+=0.5; y+=0.5;}
        else if (steps[i]=="nw") {x+=0.5; y-=0.5;}
        else if (steps[i]=="se") {x-=0.5; y+=0.5;}
        else if (steps[i]=="sw") {x-=0.5; y-=0.5;}
        //cout<<steps[i]<<" ";
        if (maxe<round(abs(y)+abs(x))) {
            maxe=round(abs(y)+abs(x));
        }
    }
    cout<<x<<" "<<y<<endl;
    cout<<round(abs(y)+abs(x))<<endl;
    cout<<maxe<<endl;
    return 0;
}
