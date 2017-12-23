#include <iostream>
#include <vector>
using namespace std;

int maxn=10;
int matrix[10][10]={};

int osszeg(int x,int y){
    int sum=0;
    for (int i=-1; i<2; i++) {
        for (int j=-1; j<2; j++) {
            sum+=matrix[x+i][y+j];
        }
    }
    return sum;
}

int main()
{
    int key;
    cin>>key;

    vector<int> db;
    int hossz=1;
    for (int i=0; i<maxn*2; i+=2) {
        db.push_back(hossz);
        db.push_back(hossz);
        hossz++;
    }
    for (int i=0; i<maxn*2; i++) {
        cout<<db[i]<<" ";
    }

    int x=maxn/2, y=maxn/2;
    int i=1;
    matrix[x][y]=1;

    int k=0;
    for (int j=0; j<5; j++) {
        for (int i=0; i<db[k]; i++) {
            y++;
            matrix[x][y]=osszeg(x,y);
        }
        k++;
        for (int i=0; i<db[k]; i++) {
            x--;
            matrix[x][y]=osszeg(x,y);
        }
        k++;
        for (int i=0; i<db[k]; i++) {
            y--;
            matrix[x][y]=osszeg(x,y);
        }
        k++;
        for (int i=0; i<db[k]; i++) {
            x++;
            matrix[x][y]=osszeg(x,y);
        }
        k++;
    }
    for (int i=0; i<maxn; i++) {
        for (int j=0; j<maxn; j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }



    return 0;
}
