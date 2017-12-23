#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> spinlock;
    spinlock.push_back(0);
    int skipSize=380;
    int index=0;
    for (int i=1; i<=2017; i++) {
        vector<int>::iterator it;
        index=(index+skipSize+1)%(spinlock.size());
        it=spinlock.end()-index;

        spinlock.insert(it,i);


        /*cout<<index<<endl;
        for (int j=0; j<spinlock.size(); j++) {
            cout<<spinlock[j]<<" ";
        }
        cout<<endl;
        system("pause");*/
    }
    /*cout<<index<<endl;
    for (int j=0; j<spinlock.size(); j++) {
        cout<<spinlock[j]<<" ";
    }
    cout<<endl;
    system("pause");*/
    cout<<spinlock[spinlock.size()-index-2];


    return 0;
}
