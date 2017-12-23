#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

struct Coord {
    string name,x,y;
};

class Program {
public:
    map<char, long long int> reg;
    vector<Coord> steps;
    int count=0;
    int index=0;

    Program() {
        ifstream f("input.txt");
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
        for (int i=0; i<8; i++) {
            reg[(char)(i+97)]=0;
        }
    }
    int isdigit(char a) {
        return ((int)a>=48 && (int)a<=57);
    }

    void kiir() {
        for (auto& x: reg) {
            cout << x.first << ": " << x.second << '\n';
        }
        system("pause");
    }

    void lep() {
        if (steps[index].name=="set") {
            if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                reg[steps[index].x[0]]=stoi(steps[index].y);
            } else {
                reg[steps[index].x[0]]=reg[steps[index].y[0]];
            }
        } else if (steps[index].name=="mul") {
            if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                reg[steps[index].x[0]]*=stoi(steps[index].y);
            } else {
                reg[steps[index].x[0]]*=reg[steps[index].y[0]];
            }
            count++;
        } else if (steps[index].name=="sub") {
            if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                reg[steps[index].x[0]]-=stoi(steps[index].y);
            } else {
                reg[steps[index].x[0]]-=reg[steps[index].y[0]];
            }
        }

        if (steps[index].name=="jnz") {
            if (isdigit(steps[index].x[0])) {
                 index+=stoi(steps[index].y);
            } else {
                if (reg[steps[index].x[0]]!=0) {
                    if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                        index+=stoi(steps[index].y);
                    } else {
                        index+=reg[steps[index].y[0]];
                    }
                } else index++;
            }
        } else {
            index++;
        }

    }
};

class SolvedA {
public:
    void start() {
        Program program;
        while (program.index<program.steps.size() ){
            //program.kiir();
            program.lep();

        }
        cout<<program.count<<endl;
    }
};

int main() {
    SolvedA s;
    s.start();
    return 0;
}
