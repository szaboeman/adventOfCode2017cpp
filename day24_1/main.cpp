#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class vertex {
public:
    int value;
    map<vertex*, bool> v;
};

class graph {
private:
    bool isExist(int elementName) {
        int i=0;
        while (i<v.size() && v[i]->value!=elementName) {
            i++;
        }
        return (i<v.size());
    }
    int findOf(int elementName) {
        int i=0;
        while (i<v.size() && v[i]->value!=elementName) {
            i++;
        }
        return i;
    }
    bool isExistEdge(map<vertex*, bool> v, vertex* element) {
        /*int i=0;
        while (i<v.size() && (v.begin()+i)->first !=element) {
            i++;
        }
        return (i<v.size());*/
        map<vertex*, bool>::iterator it;
        it = v.find(element);
        return (it != v.end());
    }

public:
    vector<vertex*> v;

    graph() {
        string row;
        ifstream f("input.txt");

        while (getline(f,row)) {
            stringstream ss(row);
            string start, end;
            getline(ss,start,'/');
            getline(ss,end,'/');
            if (!isExist(stoi(start))) {
                vertex* elementName=new vertex();
                elementName->value=stoi(start);
                v.push_back(elementName);
            }
            if (!isExist(stoi(end))) {
                vertex* elementName=new vertex();
                elementName->value=stoi(end);
                v.push_back(elementName);
            }
            vertex *elementStart = new vertex();
            elementStart=v[findOf(stoi(start))];

            vertex *elementEnd= new vertex();
            elementEnd=v[findOf(stoi(end))];

            if (!isExistEdge(elementEnd->v,elementStart)) {
                map<vertex*,bool> sv;
                elementEnd->v[elementStart]=false;
            }

            if (!isExistEdge(elementStart->v,elementEnd)) {
                map<vertex*, bool> sv;
                elementStart->v[elementEnd]=false;
            }
        }

    }
    void kiir(vector<vertex*> v) {
        for (int i=0; i<v.size(); i++) {
            cout<<v[i]->value<<" -->";

            for (map<vertex*, bool>::iterator it=v[i]->v.begin(); it!=v[i]->v.end(); it++) {
                cout<<(it->first->value)<<" ("<<it->second<<") ";
            }
            cout<<endl;
        }
    }


    void solvedA() {
        //vector<vertex*> v;
        int i=0;
        while (i<v.size() && v[i]->value!=0) {
            i++;
        }
        //cout<<v[i]->value;
        int act=i;
        vector<pair<int,int>> elLista;
        //map<vertex*, bool>::iterator it=v[i]->v.begin();
        while (true) {
            int talalat=0;
            if (talalat>=0) {
                //cout<<"hihi";
                pair<int,int> edge;
                edge.first=v[act]->value;
                map<vertex*,bool>::iterator it;
                it=v[act]->v.begin();
                while (it->second) {
                    it++;
                }
                if (it!=v[act]->v.end()) {
                    it->second=true;
                    act=it->first->value;
                    edge.second=it->first->value;
                    elLista.push_back(edge);
                }

            }
            else break;
        }
    }

};

int main() {
    graph *g=new graph();
    g->kiir(g->v);
    g->solvedA();
    /*cout<<g->feladatA()<<endl;
    cout<<g->feladatB()<<endl;*/
    return 0;
}
