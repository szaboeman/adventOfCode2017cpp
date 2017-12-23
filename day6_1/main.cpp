#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool egyenlo(vector<int> mb1, vector<int> mb2) {
    int i=0;
    while (i<mb1.size() && mb1[i]==mb2[i]) {
        i++;
    }
    return (i==mb1.size());
}

int volte(vector<vector<int>> memomyblocks, vector<int> mb) {
    int i=0;
    while (i<memomyblocks.size()-1 && !egyenlo(memomyblocks[i],mb)) {
        i++;
    }

    return i;
}

int max(vector<int> mb) {
    int maxi=0;
    for (int i=1; i<mb.size(); i++) {
        if (mb[i]>mb[maxi]) {
            maxi=i;
        }
    }
    return maxi;
}
void kiir(vector<vector<int>> mb) {
    for (int j=0; j<mb.size(); j++) {
        vector<int> sv=mb[j];
        for (int i=0; i<sv.size(); i++) {
            cout<<sv[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main() {
    vector<vector<int>> memoryblocks;
    vector<int> mb;
    string row;
    getline(cin,row);
    stringstream ss(row);
    string data;
    while (ss>>data) {
        mb.push_back(stoi(data));
    }
    memoryblocks.push_back(mb);

    do {
        int maxind=max(mb);
        int value=mb[maxind];

        int resz=(int)value/(mb.size()-1);
        if (resz==0) {
            mb[maxind]=0;
            resz++;
        } else {
            mb[maxind]=mb[maxind]-resz*(mb.size()-1);
        }

        int kiosztott=0,j=maxind;
        //kiir(memoryblocks);
        //cout<<"rész: "<<resz<<"maxért: "<<value<<endl;
        while (kiosztott<value-mb[maxind]) {
            if (maxind!=j) {
                kiosztott+=resz;
                mb[j%mb.size()]+=resz;
            }
            j++;
        }
        memoryblocks.push_back(mb);


    } while (volte(memoryblocks, mb)>=memoryblocks.size()-1);
    cout<<"---------------------------"<<endl<<memoryblocks.size()-1<<endl;
    cout<<"---------------------------"<<endl<<memoryblocks.size()-1-volte(memoryblocks, mb);


    return 0;
}
