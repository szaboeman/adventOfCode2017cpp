#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

    struct node{
        string name;
        vector<node*> next;
        node* prev;
    };

    struct H{
        string name;
        vector<string> next;
    };

    int keres(vector<node*> sv, string a){
        for(int i=0; i<sv.size(); i++){
            if(a==sv[i]->name){
                return i;
            }
        }
    }



int main(){
    vector<string> be;
    for(int i=0; i<13; i++){
        string sv;
        getline(cin, sv);
        be.push_back(sv);
    }
    vector<H> t;
    for(int i=0; i<be.size(); i++){
        string sv=be[i];
        int j=0;
        string ki="";
        while(sv[j]!=' '){
            ki+=sv[j];
            j++;
        }
        string ki2="";
        while(sv[j]!=')'){
            j++;
        }
        if(sv.length()==j+1){

        }else{
            j+=4;
            while(j<sv.length()){
                if(sv[j]!=' '){
                    ki2+=sv[j];
                }
                j++;
            }
        }
        istringstream ss(ki2);
        string token;
        vector<string> next;
        while(getline(ss, token, ',')) {
            next.push_back(token);
        }
        H a;
        a.name=ki;
        a.next=next;
        t.push_back(a);
    }

    vector<node*> sv;

    for(int i=0; i<t.size(); i++){
        node* n;
        n = new node;
        n->name=t[i].name;
        n->prev=NULL;
        sv.push_back(n);
    }

    for(int i=0; i<t.size(); i++){
        if(t[i].next.size()>0){
            for(int j=0; j<t[i].next.size(); j++){
                int hely=keres(sv, t[i].next[j]);
                sv[i]->next.push_back(sv[hely]);
                sv[hely]->prev=sv[i];
            }
        }
    }
    node* elso;
    elso=sv[0];
    while(elso->prev!=NULL){
        elso=elso->prev;
    }
    cout<<elso->name<<endl;
    cout<<elso->next[0]->next[0]->name;




    return 0;
}



