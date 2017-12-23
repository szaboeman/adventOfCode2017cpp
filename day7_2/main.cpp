#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class element {
    public:
        string name;
        int value;
        vector<string> childs;
        int rank;

        bool isNode() {
            return (this->childs.size()==0);
        }

        bool isParent(string name) {
            int i=0;
            while (i<this->childs.size() && this->childs[i]!=name) {
                i++;
            }
            return (i<this->childs.size());
        }
};

class tree {
    public:
        vector<element> t;
        tree () {
            string row="";
            do {
                getline(cin,row);
                if (row!="0") {
                    this->addNewElement(row);
                }
            } while (row!="0");
        }
        void addNewElement(string row) {
            element e;
            string sv;
            stringstream ss(row);
            getline(ss,e.name,' ');
            getline(ss,sv,' ');
            e.value=stoi(sv.substr (1,sv.length()-1));
            getline(ss,sv,' ');
            while (getline(ss,sv,' ')){
                if (sv[sv.length()-1]==',') {
                    sv=sv.substr(0,sv.length()-1);
                }
                e.childs.push_back(sv);
            }
            t.push_back(e);
        }

        int getRoot() {
            int i=0;
            bool isRoot=false;
            while (i<this->t.size() && !isRoot) {
                int j=0;
                while (j<this->t.size() &&
                       !t[j].isParent(t[i].name)) {
                    j++;
                }
                isRoot=(j>=this->t.size());
                i++;
            }
            return i-1;
        }

        int findElement(string name) {
            int k=0;
            while (k<t.size() && name!=t[k].name) k++;
            return k;
        }

        void setRank(int i) {
            if (t[i].isNode()) {
                t[i].rank=t[i].value;
            } else {
                t[i].rank=t[i].value;
                for (int j=0; j<t[i].childs.size(); j++) {
                    int k=findElement(t[i].childs[j]);
                    setRank(k);
                    t[i].rank+=t[k].rank;
                }
            }
        }

        void kiir(int elemind, string tav) {
            for (int i=0; i<t[elemind].childs.size(); i++) {
                int elem=findElement(t[elemind].childs[i]);
                cout<<tav<<t[elem].name<<" "<<t[elem].rank<<endl;
                kiir(elem,tav+"--");
            }
            /*for (int i=0; i<t.size(); i++) {
                cout<<this->t[i].name<<" "<<this->t[i].value<<" "<<this->t[i].rank<<"    ";
                for (int j=0; j<this->t[i].childs.size(); j++) {
                    cout<<this->t[i].childs[j]<<" ";
                }
                cout<<endl;
            }*/
        }

        bool kiegyensulyozva(int elemind) {
            int rank=t[findElement(t[elemind].childs[0])].rank;
            int i=1;
            while (i<t[elemind].childs.size() && t[findElement(t[elemind].childs[i])].rank==rank) i++;
            return (i==t[elemind].childs.size());
        }

        void findError(int elemind, int &hiba) {
            if (kiegyensulyozva(elemind)) {

                for (int j=0; j<t[elemind].childs.size(); j++) {
                    if (!t[findElement(t[elemind].childs[j])].isNode())
                    findError(findElement(t[elemind].childs[j]),hiba);
                }
            } else {
                int minind=0, mindb=1;
                int maxind=0, maxdb=1;
                for (int i=1; i<t[elemind].childs.size(); i++) {
                    if (t[findElement(t[elemind].childs[i])].rank<t[findElement(t[elemind].childs[minind])].rank) {
                        minind=i;
                    }
                    if (t[findElement(t[elemind].childs[i])].rank>t[findElement(t[elemind].childs[maxind])].rank) {
                        maxind=i;
                    }
                }
                cout<<endl;
                for (int i=0; i<t[elemind].childs.size(); i++) {
                    cout<<t[findElement(t[elemind].childs[i])].rank<<"("<<t[findElement(t[elemind].childs[i])].value<<")";
                }
                cout<<endl;
                cout<<elemind<<" "<<maxind<<" "<<minind<<endl;

                for (int j=0; j<t[elemind].childs.size(); j++) {
                    if (!t[findElement(t[elemind].childs[j])].isNode())
                    findError(findElement(t[elemind].childs[j]),hiba);
                }
            }
        }
};

int main() {
    tree t;
    cout<<t.t[t.getRoot()].name<<endl;
    t.setRank(t.getRoot());
    t.kiir(t.getRoot(),"|--");
    int hiba=0;
    t.findError(t.getRoot(),hiba);
    cout<<hiba<<endl;
    cout<<t.t[t.getRoot()].rank;
    return 0;
}
