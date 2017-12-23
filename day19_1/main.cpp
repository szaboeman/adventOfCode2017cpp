#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Labirintus {
public:
    int x=0,y=0;
    int direction=1;
    vector<string> lab;
    int step=0;

    Labirintus() {
        ifstream f("input.txt");
        while (!f.eof()) {
            string row;
            getline(f,row);
            lab.push_back(row);
        }
    }

    void print() {
        for (int i=0; i<lab.size(); i++) {
            cout<<lab[i]<<endl;
        }
    }

    void setStart() {
        int i=0;
        while (lab[0][i]!='|') {
            i++;
        }
        x=0;
        y=i;
        //fel 1, jobbra 2, le 3, balra 4
        direction=3;
    }

    void bejar() {
        setStart();
        vector<string> sv=lab;
        bool stop=false;
        string answer="";
        while (!stop) {
            while (lab[x][y]!='+' && !stop) {
                //cout<<lab[x][y];
                if (lab[x][y]!=' '){
                    if ((int)lab[x][y]>=65 && (int)lab[x][y]<=90)
                        answer+=lab[x][y];
                    lab[x][y]=' ';
                    switch (direction) {
                        case 1: if (lab[x][y-1]=='-' || lab[x][y+1]=='-') lab[x][y]='-'; x--; break;
                        case 3: if (lab[x][y-1]=='-' || lab[x][y+1]=='-') lab[x][y]='-'; x++; break;
                        case 2: if (lab[x-1][y]=='|' || lab[x+1][y]=='|') lab[x][y]='|'; y++; break;
                        case 4: if (lab[x-1][y]=='|' || lab[x+1][y]=='|') lab[x][y]='|'; y--; break;
                    }
                    step++;
                } else {
                    stop=true;
                }
            }
            lab[x][y]='x';
            if (x<lab.size() && (lab[x+1][y]=='-' || lab[x+1][y]=='|')) {
                direction=3;
            } else if (x>=0 && (lab[x-1][y]=='-' || lab[x-1][y]=='|')) {
                direction=1;
            } else if (y<lab.size() && (lab[x][y+1]=='-' || lab[x][y+1]=='|')) {
                direction=2;
            } else {
                direction=4;
            }
            //cout<<answer;
        }
        cout<<answer<<endl<<step;
    }

};

int main() {
    Labirintus l;
    l.bejar();
    return 0;
}
