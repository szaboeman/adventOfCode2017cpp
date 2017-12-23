#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int sum=0;
    getline(cin,a);
    //cout<<a;
    int i=0;
    for (i=0; i<a.length()-1; i++) {
        if (a[i]==a[i+1]) {
            sum+=(a[i]-48);
        }
    }
    if (a[i]==a[0]) {
        sum+=(a[i]-48);
    }
    cout<<sum;
    return 0;
}
