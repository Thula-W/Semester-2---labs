#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance (vector<int> distance , vector<bool> visited){
    int minimum = 9999;
    int vertex=-1 ;
    for (int i = 0 ; i < distance.size(); i++){
        if (!visited[i] && distance[i] < minimum){
            minimum = distance[i];
            vertex = i;
        }
    }
    return vertex;
}

void printVector(vector<int> v){
    for (int i = 0 ; i< v.size() ;i++){
        cout<<"City "<<i<<" : "<< v[i]<<endl;
    }
}

vector<int> dijkstra (int n ,int start , vector<vector<int>> weightMatrix){
    vector<bool> visited (n , false);
    vector<int> distance (n, 9999);
    distance[start]= 0;

    for (int i = 0 ; i<n ; i++){
        int minimum = minDistance(distance , visited);
        visited[minimum]= true;
        for  (int i = 0 ; i<n ; i++) {
            if (weightMatrix[minimum][i] != 0 && distance[i] > distance[minimum] + weightMatrix[minimum][i]) {
                distance[i] = distance[minimum] + weightMatrix[minimum][i];
            }
        }
    }
    return distance;
}

int main() {
    vector< vector<int> > weight= {
            {0,10,0,0,15,5},
            {10,0,10,30,0,0},
            {0,10,0,12,5,0},
            {0,30,12,0,0,20},
            {15,0,5,0,0,0},
            {5,0,0,20,0,0}
    };
    for (int i =0 ; i<6 ; i++){
        vector<int> x = dijkstra(6,i , weight);
        cout<<"Time taken from city "<<i<<" to,"<<endl;
        printVector(x);
        cout<<"---------------------------------"<<endl;
    }
}
