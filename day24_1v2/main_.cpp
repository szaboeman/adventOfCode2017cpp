#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Graph {
public:
    vector<pair<int, int>> edgeList;
    Graph() {
        ifstream f("input.txt");
        string row,first,second;
        while (getline(f,row)) {
            stringstream ss(row);
            getline(ss,first,'/');
            getline(ss,second,'/');
            pair<int,int> sv(stoi(first),stoi(second));
            edgeList.push_back(sv);
        }
    }

    void print() {
        for (int i=0; i<edgeList.size(); i++) {
            cout<<edgeList[i].first<<" "<<edgeList[i].second<<endl;
        }
    }


    bool isSaved(vector<pair<int,int>> result, pair<int,int> edge) {
        int i=0;
        while (i<result.size() && result[i]!=edge) {
            i++;
        }
        return (i<result.size());
    }

    bool isGoodHit(pair<int,int> edge, bool &isGood, int second) {
        if ((second==-1 && edge.first==0) || edge.first==second || edge.second==second ) {
            isGood=true;
            return true;
        } else {
            isGood=false;
            return false;
        }
    }

    int lastPos(vector<pair<int,int>> result ,pair<int,int> edge) {
        int i=0;
        while (result[i]!=edge) {
            i++;
        }
        return i;
    }

    void backTrack() {
        vector<pair<int,int>> result;
        int i=0, act=0;
        int first=0, second=-1;
        while (i<edgeList.size() && i>=0) {
            int j=act;
            bool isGood=false;
            while (j<edgeList.size() &&
                   (!isGoodHit(edgeList[j], isGood, second) ||
                    isSaved(result, edgeList[j]))) {
                j++;
            }
            //jovalasztkeres();
            if (j<edgeList.size() && isGood) {
                result.push_back(edgeList[j]);

                if (second==-1 || edgeList[j].first==second) {
                    second=edgeList[j].second;
                    first=edgeList[j].first;
                } else {
                    second=edgeList[j].first;
                    first=edgeList[j].second;
                }
                act=0;
            } else {

                for (int k=0; k<result.size(); k++) {
                    cout<<result[k].first<<" "<<result[k].second<<" --> ";
                }
                act=lastPos(edgeList, result[result.size()-1])+1;
                second=first;
                result.erase(result.begin()+result.size()-1);
                if (result.size()!=0) {
                    if (result[result.size()-1].first==second) {
                        first=result[result.size()-1].second;
                    }else {
                        first=result[result.size()-1].first;
                    }
                } else {
                    i++;
                    act=i;
                    first=edgeList[act].first;
                    second=edgeList[act].first;
                }
                cout<<"Elozo: "<<first<<" "<<second<<endl;

                system("pause");
            }
        }
    }


};

int main_() {
    Graph g;
    g.print();
    g.backTrack();
    return 0;
}
