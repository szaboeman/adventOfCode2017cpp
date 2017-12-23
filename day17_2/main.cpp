#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> spinlock;
    spinlock.push_back(0);
    int skipSize=380;
    int index=0;
    vector<int> indexes;
    int last=0, value=0;
    for (int i=1; i<=50000000; i++) {
        vector<int>::iterator it;
        index=(index+skipSize+1)%i;
        if (index==0) {
            last=index;
            value=i;
            //cout<<index<<" "<<i<<" "<<value<<endl;
            //system("pause");
        }
        /*indexes.push_back(index);
        it=spinlock.end()-index;

        spinlock.insert(it,i);*/



/*        for (int j=0; j<indexes.size(); j++) {
            cout<<indexes[j]<<" ";
        }
        cout<<endl;
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
    cout<<value;


    return 0;
}
