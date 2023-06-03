#include <iostream>
#include "vector"
using namespace std;

vector<int> minimum(vector<bool> inMst , vector<vector<int>> weight){
    int min = 9999;
    int end ;
    int start;
    vector<int> details(3);
    for (int j =0 ; j<weight.size() ; j++) {
        if(weight[j][0] != -1) {
            for (int i = 0; i < 6; i++) { //since this is for this specific question with 6 vertices
                if (weight[j][i] < min && !inMst[i] && weight[j][i] != 0) {
                    min = weight[j][i];
                    end = i;
                    start = j;
                }
            }
        }
    }
    details[0]= start;
    details[1]=end;
    details[2]= min;
    return details;
}
void printMST (vector <vector<int>> v){
    for (vector<int> temp: v ){
        cout<<temp[0]<<" - "<<temp[1]<<" :    "<<temp[2]<<endl;
    }
}
void prim (vector <vector<int>> weight , int start , int n){
    vector<bool> inMst(n , false);
    vector <vector<int>> currentWeight(6,{-1});
    vector <vector<int>> q;
    currentWeight[start]= (weight[start]);
    inMst[start]= true;
    for (int i =0 ; i<n-1 ; i++) {
        vector<int> min = minimum(inMst, currentWeight);
        inMst[min[1]] = true;
        currentWeight[min[1]]= (weight[min[1]]);
        q.push_back(min);
    }
    cout<<"Edge  :  Weight"<<endl;
    printMST(q);
}
int main() {
    vector <vector<int>> weight = {
            {0,3,0,0,0,1},
            {3,0,2,1,10,0},
            {0,2,0,3,0,5},
            {0,1,3,0,5,0},
            {0,10,0,5,0,4},
            {1,0,5,0,4,0}
    };

    prim(weight , 0 , 6);
    return 0;
}
