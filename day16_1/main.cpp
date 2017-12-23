#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


class dance {
public:
    vector<string> steps;
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
            steps.push_back(step);
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
            string operation=steps.at(i).substr(0,1);
            string element=steps.at(i).substr(1,steps.at(i).length()-1);
            if (operation=="s") {
                int sv=stoi(element);
                spining(sv);
                //kiir();
            } else if (operation=="x") {
                stringstream ss(element);
                string sv;
                int ix,jx;
                getline(ss, sv,'/');
                ix=stoi(sv);
                getline(ss, sv,'/');
                jx=stoi(sv);
                exchanging(ix,jx);
                //kiir();
            } else {
                stringstream ss(element);
                string sv;
                char a,b;
                getline(ss, sv,'/');
                a=sv[0];
                getline(ss, sv,'/');
                b=sv[0];
                partnering(a,b);
                //kiir();
            }
        }
        //return dancer;
    }
};

int main()
{
    dance d;
    d.dancing();
    d.kiir();
    return 0;
}
