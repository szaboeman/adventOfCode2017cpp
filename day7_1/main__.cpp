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

        element(string name, int value, vector<string> childs) {
            this->name=name;
            this->value=value;
            this->childs=childs;
        }

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

        void addNewElement(string row) {
            element e;
            string sv;
            stringstream ss(row);
            getline(ss,e.name);
            getline(ss,sv);
            e.value=stoi(sv.substr (1,sv.length()-1));
            getline(ss,sv);
            while (getline(ss,sv)){
                e.childs.push_back(sv);
            }
            t.push_back(e);
            //Darabolás
        }

        string getRoot() {
            int i=0;
            bool isRoot=false;
            while (i<this->t.size() && !isRoot) {
                int j=0;
                while (j<this->t.size() && !t[j].isParent(t[i].name)) {
                    j++;
                }
                isRoot=(j==this->t.size());
            }
            return t[i].name;
        }
};

int main() {
    tree t;
    string row;
    do {
        getline(cin,row);
        t.addNewElement(row);
    } while (row!="0");
    cout<<t.getRoot();
    return 0;
}
