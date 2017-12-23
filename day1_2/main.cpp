#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int sum=0;
    getline(cin,a);
    int lepeskoz=a.length()/2;
    for (int i=0; i<a.length(); i++) {
        if (a[i]==a[(i+lepeskoz>=a.length())?i+lepeskoz-a.length():i+lepeskoz]) {
            sum+=(a[i]-48);
        }
    }
    cout<<sum;
    return 0;
}
