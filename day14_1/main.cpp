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

int knuthash(string code) {
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
    int index=0;
    int skipSize=0;
    for (int k=0; k<64; k++) {
        for (int i=0; i<revCommand.size(); i++) {
            int revLength=revCommand[i];
            int firstInd=index;
            int lastInd=(index+revCommand[i]-1)%maxBlock;
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

            index=(index+revCommand[i]+skipSize)%maxBlock;
            skipSize++;
        }
    }

    int result=0;
    for (int i=0; i<16; i++) {
        int sum=0;
        for (int j=i*16; j<(i+1)*16; j++) {
            sum=sum^list[j];
        }
        result+=countDecBin1(sum);
        //cout<<setfill('0') << setw(2) <<hex<<sum;
    }
    return result;
}



int main()
{
    string code="amgozmfv";
    int c=0;
    for (int i=0; i<128 ; i++) {
        c+=knuthash("amgozmfv-"+to_string(i));
    }
    cout<<c<<endl;
    return 0;
}
