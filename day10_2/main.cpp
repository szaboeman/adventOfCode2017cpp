#include <iostream>
#include <vector>
#include <sstream>
#include  <iomanip>
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

    vector<int> revCommand;
    string row;
    getline(cin,row);

    for (int i=0; i<row.length(); i++) {
        revCommand.push_back((int)row[i]);
    }
    revCommand.push_back(17);
    revCommand.push_back(31);
    revCommand.push_back(73);
    revCommand.push_back(47);
    revCommand.push_back(23);
    int index=0;
    int skipSize=0;
    for (int k=0; k<64; k++) {
        for (int i=0; i<revCommand.size(); i++) {
            int revLength=revCommand[i];
            int firstInd=index;
            int lastInd=(index+revCommand[i]-1)%maxBlock;
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

            index=(index+revCommand[i]+skipSize)%maxBlock;
            skipSize++;
        }
    }
    kiir(list);


    for (int i=0; i<16; i++) {
        int sum=0;
        for (int j=i*16; j<(i+1)*16; j++) {
            sum=sum^list[j];
        }

        cout<<setfill('0') << setw(2) <<hex<<sum;
    }


    //4d b3 79 91 45 27 8d c9 f7 3d cd bc 68 0b d5 3d 32
    //4d b3 79 91 45 27 8d c9 f7 3d cd bc 68  b d5 3d
    //4d b3 79 91 45 27 8d c9 f7 3d cd bc 68 0b d5 3d
    //cout<<list[0]*list[1]<<endl;
    return 0;
}
