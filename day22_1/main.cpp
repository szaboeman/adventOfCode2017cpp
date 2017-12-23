#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Sporfica {
public:
    int x,y;
    int direction=0;
    Sporfica() {
        ifstream f("input.txt");
        while (!f.eof()) {
            string row;
            getline(f,row);
            computerGrid.push_back(row);
        }
        x=computerGrid.size()/2;
        y=computerGrid[0].length()/2;
    }

    void print() {
        for (int i=0; i<computerGrid.size(); i++) {
            for (int j=0; j<computerGrid[i].length(); j++) {
                if (x==i && y==j) {
                    if (computerGrid[i][j]=='#') cout<<"1";
                    else cout<<"0";
                } else {
                    cout<<computerGrid[i][j];
                }

            }
            cout<<endl;
        }
        cout<<x<<" "<<y<<endl;
        cout<<computerGrid.size()<<" "<<computerGrid[0].length()<<endl;
        system("pause");
    }

    /*
     * 0 - fel
     * 1 - jobbra
     * 2 - le
     * 3 - balra
     * */

    void solvedA() {
        int count=0;
        for (int i=0; i<10000000; i++) {
            //kezdetben egyenesen néz
            //print();
            if (computerGrid[x][y]=='.') {
                direction--;
                direction=(direction+4)%4;
                computerGrid[x][y]='W';
            } else if (computerGrid[x][y]=='#'){
                direction++;
                direction%=4;
                computerGrid[x][y]='F';
            } else if (computerGrid[x][y]=='F'){
                direction=(direction+2)%4;
                computerGrid[x][y]='.';
            } else if (computerGrid[x][y]=='W'){
                computerGrid[x][y]='#';
                count++;
            }
            move();
            pushNewRowOrCol();
            //print();
        }
        cout<<count<<endl;
    }
private:
    vector<string> computerGrid;
    void pushRowFirst() {
        string row="";
        x++;
        for (int i=0; i<computerGrid[0].length(); i++) {
            row+=".";
        }
        computerGrid.insert(computerGrid.begin(),row);
    }
    void pushRowLast() {
        string row="";
        for (int i=0; i<computerGrid[0].length(); i++) {
            row+=".";
        }
        computerGrid.push_back(row);
    }
    void pushColFirst() {
        y++;
        for (int i=0; i<computerGrid.size(); i++) {
            computerGrid[i]="."+computerGrid[i];
        }
    }
    void pushColLast() {
        for (int i=0; i<computerGrid.size(); i++) {
            computerGrid[i]=computerGrid[i]+".";
        }
    }
    void pushNewRowOrCol() {
        if (y==0) {pushColFirst();}
        if (y==computerGrid[0].length()-1) {pushColLast();}
        if (x==0) {pushRowFirst();}
        if (x==computerGrid.size()-1) {pushRowLast();}
    }
    void move() {
        switch (direction) {
            case 0: x--; break;
            case 1: y++; break;
            case 2: x++; break;
            case 3: y--; break;
        }
    }

};

int main() {
    Sporfica s;
    s.solvedA();
    return 0;
}
