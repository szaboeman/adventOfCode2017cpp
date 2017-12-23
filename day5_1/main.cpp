#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    vector<int> arr;
    int sv;
    do {
        cin>>sv;
        arr.push_back(sv);
    } while (sv!=9999);
    arr.pop_back();
    int i=0, step=0;
    while (i>=0 && i<arr.size()) {
        int sv;
        int last=i;


        i+=(arr[i]);
        //if (i<)
        /*for (int j=0; j<arr.size(); j++) {
            cout<<arr[j]<<" ";
        }
        cout<<"---->"<<last<<"----->"<<i<<"----->"<<arr[i]<<endl;
*/
        if (abs(arr[last]>=3)) arr[last]--; else arr[last]++;



        step++;

  //      cin>>sv;
    }
    cout<<step-1;
    return 0;
}
