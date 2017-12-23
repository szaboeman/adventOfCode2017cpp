#include <iostream>
#include <vector>
#include <sstream>
#include  <iomanip>

using namespace std;

int countDecBin1(int numb) {
    int c=0;
    while(numb>0)
    {
        if(numb%2!=0)
        {
            c++;
        }
        numb=numb/2;
    }
    return c;
}

int knuthash(int matrix[128][128], string code, int index) {
    vector<int> list;
    int maxBlock=256;
    for (int i=0; i<maxBlock; i++) {
        list.push_back(i);
    }

    vector<int> revCommand;
    //string row;
    //getline(cin,row);

    for (int i=0; i<code.length(); i++) {
        revCommand.push_back((int)code[i]);
    }
    revCommand.push_back(17);
    revCommand.push_back(31);
    revCommand.push_back(73);
    revCommand.push_back(47);
    revCommand.push_back(23);
    int ind=0;
    int skipSize=0;
    for (int k=0; k<64; k++) {
        for (int i=0; i<revCommand.size(); i++) {
            int revLength=revCommand[i];
            int firstInd=ind;
            int lastInd=(ind+revCommand[i]-1)%maxBlock;
            for (int j=0; j<revLength/2; j++) {
                int sv=list[firstInd];
                list[firstInd]=list[lastInd];
                list[lastInd]=sv;
                firstInd=(firstInd+1)%maxBlock;
                if (lastInd-1<0) {
                    lastInd=lastInd-1+maxBlock;
                } else {
                    lastInd--;
                }
            }

            ind=(ind+revCommand[i]+skipSize)%maxBlock;
            skipSize++;
        }
    }
    for (int j=0; j<128; j++) matrix[index][j]=0;
    for (int i=0; i<16; i++) {
        int sum=0;
        for (int j=i*16; j<(i+1)*16; j++) {
            sum=sum^list[j];
        }

        int j=127-i*8;
        while(sum>0)
        {
            matrix[index][j]=sum%2;
            sum=sum/2;
            j--;
        }
        //cout<<setfill('0') << setw(2) <<hex<<sum;
    }
    //return result;
}

void nullaz(int matrix[128][128], int i, int j, int db) {
    if (i>=0 && i<128 && j>=0 && j<128 && matrix[i][j]==1) {
        matrix[i][j]=db+1;
        nullaz(matrix,  i+1, j,db);
        nullaz(matrix,  i, j+1,db);
        nullaz(matrix,  i-1, j,db);
        nullaz(matrix,  i, j-1,db);
    }
}

int groupCount(int matrix[128][128]) {
    int db=0;
    for (int i=0; i<128; i++) {
        for (int j=0; j<128; j++) {
            if (matrix[i][j]==1) {
                db++;
                nullaz(matrix,i,j,db);
            }
            cout<<"----------------------"<<endl;
            for (int k=0; k<20; k++) {
                for (int l=0; l<80; l++) {
                    if (k==i && l==j) {
                        cout<<"X"<<"";
                    } else {
                        cout<<matrix[k][l]<<" ";
                    }

                }
                cout<<endl;
            }
            system("pause");
        }
    }
    return db;
}

int main()
{
    //string code="amgozmfv";
    string code="flqrgnkx";
    int c=0;
    int matrix[128][128];
    for (int i=0; i<128 ; i++) {
        knuthash(matrix,code+"-"+to_string(i),i);
    }
    for (int i=0; i<50; i++) {
        for (int j=0; j<50; j++) {
            cout<<matrix[i][j]<<"";
        }
        cout<<endl;
    }
    cout<<groupCount(matrix);

    //cout<<c<<endl;
    return 0;
}
