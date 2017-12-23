#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <string>
#include <fstream>
using namespace std;

typedef vector<vector<int>> matrix;

struct Imaging {
    vector<matrix> base;
    matrix image;
    int db;
};

class Pattern {
private:
    int sumMatrix(matrix a) {
        int sum=0;
        for (int i=0; i<a.size(); i++) {
            for (int j=0; j<a.size(); j++) {
                sum+=a[i][j];
            }
        }
        return sum;
    }
    vector<int> stringToVector(string s) {
        vector<int> sv;
        for (int i=0; i<s.length(); i++) {
            sv.push_back((s[i]=='.')?0:1);
        }
        return sv;
    }
    matrix stringToMatrix(string s) {
        string data;
        matrix m;
        stringstream ss(s);
        while (getline(ss,data,'/')) {
            m.push_back(stringToVector(data));
        }
        return m;
    }
    matrix cuttingM(int row, int col, int n) {
        matrix newMatrix;
        for (int i=row; i<row+n; i++) {
            vector<int> newRow;
            for (int j=col; j<col+n; j++) {
                newRow.push_back(p[i][j]);
            }
            newMatrix.push_back(newRow);
        }
        return newMatrix;
    }
    vector<vector<matrix>> cuttingMatrix() {
        vector<vector<matrix>> cutM;
        int size=(p.size()%2==0)?2:3;
        for (int i=0; i<p.size(); i+=size) {
            vector<matrix> newRowCutM;
            for (int j=0; j<p.size(); j+=size) {
                newRowCutM.push_back(cuttingM(i,j,size));
            }
            cutM.push_back(newRowCutM);
        }
        return cutM;
    }
    bool equalVectors(vector<int> v1, vector<int> v2) {
        if (v1.size()==v2.size()) {
            int i=0;
            while (i<v1.size() && v1[i]==v2[i]) i++;
            return (i==v1.size());
        } else {
            return false;
        }
    }
    bool equalMatrices(matrix a, matrix b) {
        if (a.size()==b.size()) {
            int i=0;
            while (i<a.size() && equalVectors(a[i],b[i])) {
                i++;
            }
            return i==a.size();
        } else {
            return false;
        }
    }
    matrix rotateMatrix(matrix a) {
        matrix rotateM;
        for (int i=0; i<a.size(); i++) {
            vector<int> sv;
            for (int j=0; j<a[i].size(); j++) {
                sv.push_back(a[j][a.size()-1-i]);
            }
            rotateM.push_back(sv);
        }
        return rotateM;
    }
    matrix flipXMatrix(matrix a) {
        for (int i=0; i<a.size()/2; i++) {
            vector<int> sv;
            sv=a[i];
            a[i]=a[a.size()-1-i];
            a[a.size()-1-i]=sv;
        }
        return a;
    }
    matrix flipYMatrix(matrix a) {
        return rotateMatrix(rotateMatrix(flipXMatrix(a)));
    }
    matrix rotate2Matrix(matrix a) {
        return rotateMatrix(rotateMatrix(a));
    }
    matrix rotate3Matrix(matrix a) {
        return rotateMatrix(rotateMatrix(rotateMatrix(a)));
    }
    matrix concatPieces(vector<vector<matrix>> pieces) {
        matrix m;
        int size=pieces[0][0].size();
        for (int i=0; i<pieces.size()*size; i++) {
            vector<int> sv;
            for (int j=0; j<pieces.size()*size; j++) {
                sv.push_back(pieces[i/size][j/size][i%size][j%size]);
            }
            m.push_back(sv);
        }
        return m;
    }
    matrix swapImagingMatrix(matrix a) {
        bool isFound=false;
        int i=-1;
        int db=sumMatrix(a);
        while (!isFound) {
            i++;
            if (db==v[i].db) {
                int j=0;
                while (j<v[i].base.size() &&
                       !equalMatrices(v[i].base[j],a)) j++;
                isFound=(j<v[i].base.size());
            }
        }
        return v[i].image;

    }

public:
    vector<Imaging> v;
    matrix p;


    Pattern() {
        ifstream f("input.txt");
        string row;
        while (getline(f,row)) {
            stringstream ss(row);
            matrix svm;
            string base, image;
            getline(ss,base,' ');
            getline(ss,image,' ');
            getline(ss,image,' ');
            Imaging sv;
            svm=stringToMatrix(base);
            sv.base.push_back(svm);
            sv.base.push_back(rotateMatrix(svm));
            sv.base.push_back(rotate2Matrix(svm));
            sv.base.push_back(rotate3Matrix(svm));
            sv.base.push_back(flipXMatrix(svm));
            sv.base.push_back(flipYMatrix(svm));
            sv.base.push_back(rotateMatrix(flipXMatrix(svm)));
            sv.base.push_back(rotateMatrix(flipYMatrix(svm)));
            sv.db=sumMatrix(svm);
            sv.image=stringToMatrix(image);
            v.push_back(sv);
        }
        f.close();
        f.open("start.txt");
        while (getline(f,row)) {
            p.push_back(stringToVector(row));
        }
    }

    void printVector(vector<int> v) {
        for (int j=0; j<v.size(); j++) {
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
    void printMatrix(matrix m) {
        for (int i=0; i<m.size(); i++) {
            printVector(m[i]);
        }
    }
    void print() {
        printMatrix(p);
        /*cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        for (int i=0; i<v.size(); i++) {
            printMatrix(v[i].base);
            cout<<"--------------||---------------"<<endl;
            cout<<"--------------\\/---------------"<<endl;
            printMatrix(v[i].image);
            cout<<"--------------------------------"<<endl;
        }*/
    }

    void solvedA() {
        int length=18;
        vector<vector<matrix>> pieces;
        for (int i=0; i<length; i++) {
            //printMatrix(p);
            pieces=cuttingMatrix();
            for (int j=0; j<pieces.size(); j++) {
                for (int k=0; k<pieces.size(); k++) {
                    pieces[j][k]=swapImagingMatrix(pieces[j][k]);
                }
            }
            p=concatPieces(pieces);

            //printMatrix(p);

            //cout<<p.size()<<endl;



        }
        cout<<sumMatrix(p)<<endl;

    }

};

int main(int argc, char *argv[]) {
    Pattern p;
    p.solvedA();
    return 0;
}
