#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    string row;
    int sum=0;
    do  {
        getline(cin,row);
        stringstream ss(row);
        if (row.length()>0) {
            vector<int> a;
            string data;
            while (getline(ss,data,' ')) {
                a.push_back(stoi(data));
            }
            sort(a.begin(),a.end());
            for (int i=0; i<a.size(); i++) {
                cout<<a[i]<<" ";
            }
            cout<<endl;

            int i=0,hight, low; bool isDiv=false;
            while (i<a.size()-1) {
                int j=i+1;
                while (j<a.size()) {
                    if (a[i]%a[j]==0) {
                        sum+=(a[i]/a[j]);
                        cout<<a[i]<<" "<<a[j]<<" "<<a[i]%a[j]<<endl;
                    } else if(a[j]%a[i]==0) {
                        cout<<a[i]<<" "<<a[j]<<" "<<a[j]%a[i]<<endl;
                        sum+=(a[j]/a[i]);
                    }
                    j++;
                }
                /*if (j<a.size()) {
                    isDiv=true;
                    if (a[i]%a[j]==0) {
                        hight=a[i];
                        low=a[j];
                    } else {
                        hight=a[j];
                        low=a[i];
                    }
                }*/
                i++;
            }
            /*cout<<hight<<" "<<low<<endl;
            sum+=(hight/low);*/
        }
    } while (row.length()>0);
    cout<<sum;
    return 0;
}
