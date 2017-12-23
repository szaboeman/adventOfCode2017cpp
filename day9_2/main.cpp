#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int main()
{
    string stream;

    int sum=0, score=0;

    ifstream f("input.txt");
    getline(f,stream);

    //getline(cin,stream);

    cout<<stream<<endl;
    string cleanFelkString="";

    int i=0;
    while (i<stream.length()) {
        if (stream[i]!='!') {
            cleanFelkString+=stream[i];
        } else {
            i++;
        }
        i++;
    }
    cout<<cleanFelkString<<endl;


    i=0;
    int count=0;
    string cleanRelString="";
    while (i<cleanFelkString.length()) {
        if (cleanFelkString[i]=='<') {
            while (i<cleanFelkString.length() && cleanFelkString[i]!='>') {
                i++;
                count++;
            }
            count-=1;
        } else {
            cleanRelString+=cleanFelkString[i];
        }
        i++;
    }
    cout<<count<<endl;

    cout<<"="<<sum<<" "<<score;
    return 0;
}
