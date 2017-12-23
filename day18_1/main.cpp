#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

class Coord {
public:
    string name,x,y;
};

class Reg {
public:
    map<char, long long int> reg;
    vector<Coord> steps;
    Reg() {
        ifstream f("input.txt");
        string sName, sX, sY;
        while (!f.eof()) {
            Coord step;
            f>>step.name;
            if (step.name=="snd" || step.name=="rcv") {
                f>>step.x;
                step.y="0";
            } else {
                f>>step.x>>step.y;
            }
            steps.push_back(step);
        }
    }
    void kiir() {
        //cout<<endl<<"---------Regiszter--------------"<<endl;
        for (auto& x: reg) {
            cout << x.first << ": " << x.second << '\n';
        }
        system("pause");
        /*cout<<endl<<"-----------Steps-----------------"<<endl;
        for (int i=0; i<steps.size(); i++) {
            cout<<steps[i].name<<" "<<steps[i].x<<" "<<steps[i].y<<"\n";
        }*/
    }
    void solvedA() {
        int i=0;
        int lejatszott=0;
        while (i<steps.size()) {
            if (steps[i].name=="snd") {
                lejatszott=reg[steps[i].x[0]];
                //cout<<"lejátszás: "<<steps[i].name<<"="<<reg[steps[i].name[0]];
            } else if (steps[i].name=="set") {
                if (isdigit(steps[i].y[0]) || steps[i].y[0]=='-') {
                    reg[steps[i].x[0]]=stoi(steps[i].y);
                } else {
                    reg[steps[i].x[0]]=reg[steps[i].y[0]];
                }
            } else if (steps[i].name=="add") {
                if (isdigit(steps[i].y[0]) || steps[i].y[0]=='-') {
                    reg[steps[i].x[0]]+=stoi(steps[i].y);
                } else {
                    reg[steps[i].x[0]]+=reg[steps[i].y[0]];
                }
            } else if (steps[i].name=="mul") {
                if (isdigit(steps[i].y[0]) || steps[i].y[0]=='-') {
                    reg[steps[i].x[0]]*=stoi(steps[i].y);
                } else {
                    reg[steps[i].x[0]]*=reg[steps[i].y[0]];
                }
            } else if (steps[i].name=="mod") {
                if (isdigit(steps[i].y[0]) || steps[i].y[0]=='-') {
                    reg[steps[i].x[0]]%=stoi(steps[i].y);
                } else {
                    reg[steps[i].x[0]]%=reg[steps[i].y[0]];
                }
            } else if (steps[i].name=="rcv") {
                if (reg[steps[i].x[0]]!=0) {
                    cout<<lejatszott;
                    system("pause");
                }
                //cout<<"Lejátsz előző<<endl";
            }
            if (steps[i].name=="jgz") { //jgz
                if (reg[steps[i].x[0]]>0) {
                    if (isdigit(steps[i].y[0]) || steps[i].y[0]=='-') {
                        i+=stoi(steps[i].y);
                    } else {
                        i+=reg[steps[i].y[0]];
                    }
                } else i++;
            } else {
                i++;
            }

           // kiir();

        }

    }
};

int main() {
    Reg r;
    r.solvedA();
    return 0;
}
