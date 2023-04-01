#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    int difference = abs(arr[0]-arr[1]);
    sort(arr.begin() , arr.end());
    for (int i =1 ; i<arr.size()-1 ; i++){
        int d = (arr[i] -arr[i+1]);
        d = abs(d);
        if (d <= difference){
            difference = d;
        }
    }
    vector <int> newArr ;
    for (int i = 0 ; i < arr.size() ; i++){
        if (arr[i+1] - arr[i] ==difference){
            newArr.push_back(arr[i]);
            newArr.push_back(arr[i+1]);
        }
    }
    return newArr;
}

int main() {

    return 0;
}
