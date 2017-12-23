#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class vertex {
public:
    int value;
    vector<vertex*> v;
};

class graph {
public:
    vector<vertex*> v;

    int keres(int value) {
        int i=0;
        while (i<v.size() && v[i]->value!=value) {
            i++;
        }
        return i;
    }

    graph() {
        string row;
        ifstream f("input.txt");
        vector<string> rows;
        while (getline(f,row)) {
            rows.push_back(row);
            stringstream ss(row);
            string sv;
            getline(ss,sv,' ');
            vertex* elementName=new vertex();
            elementName->value=stoi(sv);
            v.push_back(elementName);
        }
        for (int i=0; i<rows.size(); i++) {
            string sv;
            stringstream ss(rows[i]);
            getline(ss,sv,' ');
            int hova=stoi(sv);
            getline(ss,sv,' ');
            //int db=0;
            while (getline(ss,sv,' ')) {
                /*vertex* element=new vertex();
                element=v[keres(stoi(sv))];*/
                if (sv[sv.length()-2]==',') {
                    sv=sv.substr(0,sv.length()-1);
                }
                int pos=keres(stoi(sv));
                v[hova]->v.push_back(v[pos]);
                //cout<<v[pos]<<endl;
                //cout<<pos<<" "<<v[pos]->v[db]->value<<endl;
                //db++;
            }
        }


    }
    void kiir() {
        for (int i=0; i<v.size(); i++) {
            cout<<v[i]->value<<" -->";
            for (int j=0; j<v[i]->v.size(); j++) {
                cout<<v[i]->v[j]->value<<" ";
            }
            cout<<endl;
        }
    }

    bool nemraktukle(vector<int> checked, int value) {
        int i=0;
        while (i<checked.size() && checked[i]!=value) {
            i++;
        }
        return (i<checked.size());
    }

    int feladatA() {
        vector<vertex*> values;
        vector<int> checked;
        values.push_back(v[0]);
        while (values.size()!=0) {
            vertex *sv=values[values.size()-1];
            values.pop_back();
            if (!nemraktukle(checked, sv->value)) {
                checked.push_back(sv->value);
            }
            for (int i=0; i<sv->v.size(); i++) {
                if (!nemraktukle(checked, sv->v[i]->value)) {
                    values.push_back(sv->v[i]);
                }
            }
        }
        return checked.size();
    }

    int torol(int value) {
        int i=0;
        while (i<v.size() && v[i]->value!=value) {
            i++;
        }
        if (i<v.size()) {
            v.erase(v.begin()+i);
        }
    }
    int feladatB() {
        int group=0;
        vector<vertex*> values;
        vector<int> checked;
        while (v.size()!=0) {
            values.push_back(v[0]);
            while (values.size()!=0) {
                vertex *sv=values[values.size()-1];
                torol(sv->value);
                values.pop_back();
                if (!nemraktukle(checked, sv->value)) {
                    checked.push_back(sv->value);
                }
                for (int i=0; i<sv->v.size(); i++) {
                    if (!nemraktukle(checked, sv->v[i]->value)) {
                        values.push_back(sv->v[i]);
                    }
                }
            }
            //v.erase(v.begin());
            group++;
        }
        return group;
    }

};

int main() {
    graph *g=new graph();
    g->kiir();
    cout<<g->feladatA()<<endl;
    cout<<g->feladatB()<<endl;
    return 0;
}
