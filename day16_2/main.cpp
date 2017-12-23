#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class operations {
public:
    string op;
    string fist;
    string last;
    operations(string row) {
        this->op=row.substr(0,1);
        string other=row.substr(1,row.length()-1);
        if (this->op=="s") {
            this->fist=other;
        } else {
            stringstream ss(other);
            getline(ss, this->fist,'/');
            getline(ss, this->last,'/');
        }
    }
};


class dance {
public:
    vector<operations> steps;
    string dancer="";
    int length=16;

    dance() {
        for (int i=0; i<length; i++) {
            dancer+=(char)(i+97);
        }
        ifstream f("input.txt");
        string row,step;
        getline(f,row);
        stringstream ss(row);
        while (getline(ss,step,',')) {
            operations o(step);
            steps.push_back(o);
        }
    }
    void kiir() {
        cout<<dancer<<endl;
        /*for (int i=0; i<steps.size(); i++) {
            cout<<steps[i]<<"\t";
        }*/
        system("pause");
    }

    void spining(int i) {
        string end="";
        string front="";
        end=dancer.substr(dancer.length()-i,i);
        front=dancer.substr(0,dancer.length()-i);
        dancer=end+front;
    }

    void exchanging(int a, int b) {
        char sv=dancer[a];
        dancer[a]=dancer[b];
        dancer[b]=sv;

    }

    void partnering(char a, char b){
        int i=dancer.find(a);
        int j=dancer.find(b);
        exchanging(i,j);
    }

    void dancing() {
        for (int i=0; i<steps.size(); i++) {
            if (steps[i].op=="s") {
                spining(stoi(steps[i].fist));
            } else if (steps[i].op=="x") {
                exchanging(stoi(steps[i].fist),stoi(steps[i].last));
            } else {
                partnering(steps[i].fist[0],steps[i].last[0]);
            }
        }
        //return dancer;
    }
};

bool findOf(vector<string> l, string s) {
    int i=0;
    while (i<l.size() && l[i]!=s) i++;
    return (i<l.size());
}

int main()
{
    dance d;
    vector<string> lepesek;
    for (int i=0; i<1000000000; i++) {
        d.dancing();
        if (findOf(lepesek,d.dancer)) {
            break;
        }
        lepesek.push_back(d.dancer);
    }
    //cout<<lepesek.size();
    cout<<lepesek[1000000000%lepesek.size()-1];
    //d.kiir();
    return 0;
}
