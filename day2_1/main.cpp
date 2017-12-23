#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string row;
    int sum=0;
    do  {
        getline(cin,row);
        stringstream ss(row);
        if (row.length()>0) {
            string data;
            int maxe=-1;
            int mine=9999999;
            while (getline(ss,data,' ')) {
                if (maxe<stoi(data)) maxe=stoi(data);
                if (mine>stoi(data)) mine=stoi(data);
            }
            sum+=(maxe-mine);
        }
    } while (row.length()>0);
    cout<<sum;
    return 0;
}
