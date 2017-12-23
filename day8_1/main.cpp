#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    map<string, int> reg;
    string row;
    do {
        getline(cin,row);
        if (row!="0") {
            stringstream ss(row);
            string data;
            getline(ss,data, ' ');
            if (reg.find(data)==reg.end()) {
                reg[data]=0;
            }
            int szorzo=1;
            getline(ss,data,' ');
            if (data=="dec") szorzo=-1;

            getline(ss,data,' ');
            int value=stoi(data);
            getline(ss,data,' ');

            string mit, rel;
            int valuefelt;
            getline(ss,mit,' ');
            getline(ss,rel,' ');
            getline(ss,data,' ');
            valuefelt=stoi(data);

            if (reg.find(mit)==reg.end()) reg[data]=0;

            switch (rel) {
                case "==": break;
                case "!=": break;
                case "<=": break;
                case ">=": break;
                case "<": break;
                case ">": break;
            }


        }
    } while (row!="0");



    return 0;
}
