#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Coord {
public:
    string x,y;
};

class Reg {
public:
    vector<map<char, int>> reg;
    vector<map<string, Coord>> steps;
    Reg() {
        ifstream f("input.txt");
        string sName, sX, sY;
        while (!f.eof()) {
            f>>sName;
            if (sName=="snd" || sName=="rcv") {
                f>>sX;
                sY="0";
            } else {
                f>>sX>>sY;
            }
            Coord sv;
            sv.x=sX;
            sv.y=sY;
            map<string, Coord> step;
            step[sName]=sv;
            //step.insert(sName,sv);
            steps.push_back(step);
        }
    }
    void kiir() {
        cout<<endl<<"---------Regiszter--------------"<<endl;
        for (int i=0; i<reg.size(); i++) {
            map<char,int>::iterator it = reg[i].begin();
            cout<<it->first<<" "<<it->second<<"\t";
        }
        cout<<endl<<"-----------Steps-----------------"<<endl;
        for (int i=0; i<steps.size(); i++) {
            map<string, Coord>::iterator it = steps[i].begin();
            cout<<it->first<<" "<<it->second.x<<" "<<it->second.y<<"\n";
        }
    }
};

int main() {
    Reg r;
    r.kiir();
    return 0;
}
