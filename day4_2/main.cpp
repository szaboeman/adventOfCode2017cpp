#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool findof(vector<string> psw, string data) {
    int i=0;
    while (i<psw.size()-1 && psw[i]!=data) i++;
    return (i<psw.size()-1);
}

int main() {
    string row;
    int db=0;
    do {
        vector<string> psw;
        getline(cin,row);
        stringstream ss(row);
        string data;
        bool isvalid=true;
        while (getline(ss,data,' ') && isvalid) {
            sort(data.begin(), data.end());
            cout<<data<<" ";
            psw.push_back(data);
            if (findof(psw,data)) {
                isvalid=false;
            }
        }

        if (isvalid) { db++; cout<<"<---------"<<db;};
        cout<<endl;
    } while (row.length()>1);
    cout<<db-1;
    return 0;
}
