#include <iostream>

using namespace std;

class Turing {
private:
    void stateA() {
        if (tape[cursor]=='0') {
            tape[cursor]='1';
            cursor++;
            state='B';
        } else {
            tape[cursor]='0';
            cursor--;
            state='B';
        }
    }

    void stateB() {
        if (tape[cursor]=='0') {
            tape[cursor]='0';
            cursor++;
            state='C';
        } else {
            tape[cursor]='1';
            cursor--;
            state='B';
        }
    }

    void stateC() {
        if (tape[cursor]=='0') {
            tape[cursor]='1';
            cursor++;
            state='D';
        } else {
            tape[cursor]='0';
            cursor--;
            state='A';
        }
    }

    void stateD() {
        if (tape[cursor]=='0') {
            tape[cursor]='1';
            cursor--;
            state='E';
        } else {
            tape[cursor]='1';
            cursor--;
            state='F';
        }
    }

    void stateE() {
        if (tape[cursor]=='0') {
            tape[cursor]='1';
            cursor--;
            state='A';
        } else {
            tape[cursor]='0';
            cursor--;
            state='D';
        }
    }

    void stateF() {
        if (tape[cursor]=='0') {
            tape[cursor]='1';
            cursor++;
            state='A';
        } else {
            tape[cursor]='1';
            cursor--;
            state='E';
        }
    }


    void expansion() {
        if (cursor<1) {
            tape="0"+tape;
            cursor++;
        } else if (cursor>tape.length()-1) {
            tape+="0";
        }
    }
public:
    string tape="000000000";
    int cursor=4;
    char state='A';

    Turing () {}

    void steping() {
        int sum=0;
        for (int i=0; i<12586542; i++) {
            switch (state) {
                case 'A': stateA(); break;
                case 'B': stateB(); break;
                case 'C': stateC(); break;
                case 'D': stateD(); break;
                case 'E': stateE(); break;
                case 'F': stateF(); break;
            }
            expansion();
        }

        for (int i=0; i<tape.length(); i++) {
            sum=sum+(tape[i])-48;
        }
        cout<<sum<<endl;
    }


};

int main()
{
    Turing t;
    t.steping();
    return 0;
}
