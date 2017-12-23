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
    bool delay=false;
    queue<int> q;
    int count=0;
    int index=0;

    Program(char name, int start) {
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
        reg[name]=start;
    }
    int isdigit(char a) {
        return ((int)a>=48 && (int)a<=57);
    }
    void lep(queue<int> &q_other) {
        if (!delay) {
            if (steps[index].name=="snd") {
                q.push(reg[steps[index].x[0]]);
                count++;
            } else if (steps[index].name=="set") {
                if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                    reg[steps[index].x[0]]=stoi(steps[index].y);
                } else {
                    reg[steps[index].x[0]]=reg[steps[index].y[0]];
                }
            } else if (steps[index].name=="add") {
                if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                    reg[steps[index].x[0]]+=stoi(steps[index].y);
                } else {
                    reg[steps[index].x[0]]+=reg[steps[index].y[0]];
                }
            } else if (steps[index].name=="mul") {
                if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                    reg[steps[index].x[0]]*=stoi(steps[index].y);
                } else {
                    reg[steps[index].x[0]]*=reg[steps[index].y[0]];
                }
            } else if (steps[index].name=="mod") {
                if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                    reg[steps[index].x[0]]%=stoi(steps[index].y);
                } else {
                    reg[steps[index].x[0]]%=reg[steps[index].y[0]];
                }
            } else if (steps[index].name=="rcv") {
                if (q_other.size()>0) {
                    reg[steps[index].x[0]]=q_other.front();
                    q_other.pop();
                } else {
                    delay=true;
                }
            };

            if (steps[index].name=="jgz") {
                if (isdigit(steps[index].x[0])) {
                     index+=stoi(steps[index].y);
                } else {
                    if (reg[steps[index].x[0]]>0) {
                        if (isdigit(steps[index].y[0]) || steps[index].y[0]=='-') {
                            index+=stoi(steps[index].y);
                        } else {
                            index+=reg[steps[index].y[0]];
                        }
                    } else index++;
                }
            } else {
                if (!delay) index++;
            }
        } else {
            if (q_other.size()>0) {
                reg[steps[index].x[0]]=q_other.front();
                q_other.pop();
                delay=false;
                index++;
            }
        }
    }
};

class Duet {
public:
    void start() {
        Program program0('p',0);
        Program program1('p',1);
        while ((!program0.delay || !program1.delay) /*&&
               program0.index<program0.steps.size() &&
               program1.index<program1.steps.size()*/) {
            program0.lep(program1.q);
            program1.lep(program0.q);
            if (program0.delay && program1.delay)
                system("pause");
            //if (program0.index>20 && program1.index>20)
                //system("pause");
        }
        //7747 túl magas 3500 alacsony
        cout<<program1.count<<endl;
    }
};

int main() {
    Duet d;
    d.start();
    return 0;
}
