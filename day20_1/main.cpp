#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

struct Coord {
    int x,y,z;
};

struct Particle {
    Coord p,v,a;
};

class Swarm {
public:
    vector<Particle> particles;
    Swarm () {
        ifstream f("input.txt");
        while (!f.eof()) {
            string row;
            getline(f,row);
            regex reg("[pva= <>]");
            row = regex_replace(row, reg, "");
            reg="(,)";
            row = regex_replace(row, reg, " ");
            stringstream ss(row);
            Particle a;
            ss>>a.p.x>>a.p.y>>a.p.z;
            ss>>a.v.x>>a.v.y>>a.v.z;
            ss>>a.a.x>>a.a.y>>a.a.z;
            particles.push_back(a);
        }
    }
    void print() {
        for (int i=0; i<particles.size(); i++) {
            cout<<particles[i].p.x<<" "<<particles[i].p.y<<" "<<particles[i].p.z<<"    ;    ";
            cout<<particles[i].v.x<<" "<<particles[i].v.y<<" "<<particles[i].v.z<<"    ;    ";
            cout<<particles[i].a.x<<" "<<particles[i].a.y<<" "<<particles[i].a.z<<endl;
        }
        system("pause");
    }
    void print(int i) {
        cout<<particles[i].p.x<<" "<<particles[i].p.y<<" "<<particles[i].p.z<<"    ;    ";
        cout<<particles[i].v.x<<" "<<particles[i].v.y<<" "<<particles[i].v.z<<"    ;    ";
        cout<<particles[i].a.x<<" "<<particles[i].a.y<<" "<<particles[i].a.z<<endl;
        system("pause");
    }

    void solvedA() {
        double minDistance=99999999;
        int minIndex=-1;
        for (int i=0; i<1000; i++) {
            for (int j=0; j<particles.size(); j++) {
                particles[j].v.x+=particles[j].a.x;
                particles[j].v.y+=particles[j].a.y;
                particles[j].v.z+=particles[j].a.z;

                particles[j].p.x+=particles[j].v.x;
                particles[j].p.y+=particles[j].v.y;
                particles[j].p.z+=particles[j].v.z;

                double newDistance=abs(particles[j].a.x)+abs(particles[j].a.y)+abs(particles[j].a.z);

                if (minDistance>newDistance) {
                    //cout<<endl<<"-----------"<<minDistance<<" ----------------"<<newDistance<<endl;
                    minIndex=j;
                    minDistance=newDistance;
                    //cout<<endl<<"-----------"<<minIndex<<" ----------------"<<i<<endl;

                }
            }
            //print();
        }
        cout<<minDistance<<" "<<minIndex<<endl;
    }

    void torol(int index) {
        int db=0;
        Particle sv=particles[index];
        for (int i=0; i<particles.size(); i++) {
            if (particles[i].p.x==sv.p.x &&
                particles[i].p.y==sv.p.y &&
                particles[i].p.z==sv.p.z) {

                particles.erase(particles.begin()+i-db);
                db++;
                //system("pause");
            }
        }
        if (db==1) {
            particles.push_back(sv);
        }
    }

    void solvedB() {
        for (int i=0; i<1000; i++) {
            for (int j=0; j<particles.size(); j++) {
                particles[j].v.x+=particles[j].a.x;
                particles[j].v.y+=particles[j].a.y;
                particles[j].v.z+=particles[j].a.z;

                particles[j].p.x+=particles[j].v.x;
                particles[j].p.y+=particles[j].v.y;
                particles[j].p.z+=particles[j].v.z;
            }
            for (int j=0; j<particles.size(); j++) {
                torol(j);
            }

        }
        cout<<particles.size()<<endl;
    }
};

int main() {
    Swarm s;
    //s.solvedA();
    s.solvedB();
    return 0;
}
