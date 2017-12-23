#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int key=325489;
    //cin>>key;
    int i=1,k=1;
    while (pow(i+2,2)<=key) {
        i+=2;
        k++;
    }
    //cout<<pow(i,2)<<" "<<k;
    i=pow(i,2)+1;
    int tav=k*2-1, diff=-1;
    cout<<i<<" "<<tav<<" "<<diff<<endl;
    while (i!=key) {
        i++;
        tav+=diff;
        if (tav==k) diff=1;
        if (tav==2*k) diff=-1;
    }
    cout<<tav;
    //while ()
    return 0;
}
