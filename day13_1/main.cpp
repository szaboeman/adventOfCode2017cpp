#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

class wall {
public:
    int depht, act, direction;
    wall() {
        this->depht=0;
        this->act=0;
        this->direction=1;
    }
    wall(int hossz,int akt,int irany) {
        this->depht=hossz;
        this->act=akt;
        this->direction=irany;
    }
};

class firewall {
public:
    vector<wall> fw;
    firewall() {
        ifstream f("input.txt");
        string row;
        int i=0;
        while (getline(f,row)) {
            stringstream ss(row);
            string sv;
            int index;
            wall sw(0,0,1);
            getline(ss,sv,' ');
            index=stoi(sv.substr(0,sv.length()-1));
            for (int j=i; j<index; j++) {
                fw.push_back(sw); i++;
            }
            getline(ss,sv,' ');
            sw.depht=stoi(sv);
            i++;
            fw.push_back(sw);
        }
    }
    void kiir() {
        cout<<"-----------------------"<<endl;
        for (int i=0; i<fw.size(); i++) {
            cout<<i<<" ";
            for (int j=0; j<fw[i].depht;  j++) {
                if (j==fw[i].act) cout<<"X"; else cout<<"0";
            }
            cout<<endl;
        }
    }
    void mozog() {
        for (int i=0; i<fw.size(); i++) {
            if (fw[i].depht!=0) {
                fw[i].act+=fw[i].direction;
                if (fw[i].act==0) fw[i].direction=1;
                if (fw[i].act==fw[i].depht-1) fw[i].direction=-1;
            }
        }
    }
};

int main() {
        firewall fw;


        int severity=0;
        int i=0;
        for ( i=0; i<fw.fw.size(); i++) {
            //system("CLS");
            //fw.kiir();
            //cout<<"----"<<i<<endl;
            if (fw.fw[i].depht!=0 && fw.fw[i].act==0) {
                severity+=i*fw.fw[i].depht;
                //fw.kiir();
            }
            //fw.kiir();
            //sleep(1);
            fw.mozog();
        }
    cout<<severity;

    return 0;
}
