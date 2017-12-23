#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int indexOf(vector<int> vector, int value){
    int i=0;
    while (i<vector.size() && vector.at(i)!=value) i++;
    if (i<vector.size()) {
        return i;
    } else {
        return -1;
    }
}

long long int nextValue(int last, int modulus, int mult) {
    long long int sv;
    sv=((long long int)last*(long long int)mult)%modulus;
    return sv;
}

string decToBin(int numb) {
    string r="";
    for (int i=0; i<32;  i++) {
        r+="0";
    }
    int j=31;
    while (numb!=0) {
        int sv=numb%2;
        r[j]=(char)(sv+48);
        numb/=2;
        j--;
    }
    return r;
}

string last16(string s) {
    string a="";
    for (int i=16; i<32; i++) {
        a+=s[i];
    }
    return a;
}


int main()
{
    unsigned long long int multa=16807, multb=48271, mod=2147483647, a=116, b=299;
    //unsigned long long int multa=16807, multb=48271, mod=2147483647, a=65, b=8921;
    /*vector<int> va,vb;
    vector<string> var,vbr;
    while (indexOf(va,nextValue(a,mod,multa))==-1) {
        va.push_back(a);
        a=nextValue(a,mod,multa);
    }
    while (indexOf(vb,nextValue(b,mod,multb))==-1) {
        va.push_back(b);
        a=nextValue(b,mod,multb);
    }
    for (int i=0; i<va.size(); i++) {
        var.push_back(decToBin(va.at(i)));
    }
    for (int i=0; i<vb.size(); i++) {
        var.push_back(decToBin(vb.at(i)));
    }*/
    int db=0;
    int paircount=0;
    while (paircount<5000000) {
    //for (int i=0; i<40000000; i++) {
        do {
            a=nextValue(a,mod,multa);
        } while (a%4!=0);
        do {
            b=nextValue(b,mod,multb);
        }while (b%8!=0);
        //if (a%4==0 && b%8==0) {
            paircount++;
            bitset<16> bita(a);
            bitset<16> bitb(b);
            //cout<<bita<<endl<<bitb<<endl<<endl;
            if (bita==bitb) {
                db++;
                //cout<<paircount<<" "<<bita<<endl<<bitb<<endl<<endl;
            }
            /*if (paircount>1055) {
                cout<<a<<endl<<b<<endl<<endl;
                system("pause");
            }*/
        //}

    }
    cout<<db;
    return 0;
}
