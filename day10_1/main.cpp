#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void kiir(vector<int> list) {
    for (int i=0; i<list.size(); i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> list;
    int maxBlock=256;
    for (int i=0; i<maxBlock; i++) {
        list.push_back(i);
    }
    kiir(list);

    vector<int> revSize;
    string row;
    getline(cin,row);

    stringstream ss(row);
    string sv;
    while (getline(ss,sv,',')) {
        revSize.push_back(stoi(sv));
    }
    int index=0;
    int skipSize=0;
    for (int i=0; i<revSize.size(); i++) {
        int revLength=revSize[i];
        int firstInd=index;
        int lastInd=(index+revSize[i]-1)%maxBlock;
        for (int j=0; j<revLength/2; j++) {
            int sv=list[firstInd];
            list[firstInd]=list[lastInd];
            list[lastInd]=sv;
            firstInd=(firstInd+1)%maxBlock;
            if (lastInd-1<0) {
                lastInd=lastInd-1+maxBlock;
            } else {
                lastInd--;
            }
        }
        kiir(list);
        index=(index+revSize[i]+skipSize)%maxBlock;
        skipSize++;
    }
    cout<<list[0]*list[1]<<endl;
    return 0;
}
