#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

void printarr (vector <int> arr ){
    for ( int i = 0 ; i < arr.size() ; i++ ){
        cout << arr[i]<<" ";
    }
    cout<< "\n";
}
double findMedian(vector<int> arr) {
    int n = arr.size();
    if (arr.size()%2 ==1){
        int mid = ::floor(arr.size()/2);
        return arr[mid];
    }
    else{
        int mid1 = arr.size() /2;
        int mid2 = arr.size()/2 -1;
        return ((arr[mid1]+ arr[mid2])/2.0);
    }
}

int main() {
    vector<int > arr;
    while (true){
        cout<<"Enter the numbers of the array-";
        int x;
        cin>> x;
        arr.push_back(x);
        sort(arr.begin() , arr.end());
        cout<<"The sorted array is ";
        printarr(arr);
        cout<<"The median is ";
        double answer = findMedian(arr);
        cout<<fixed<<setprecision(1)<<answer<<endl;
    }
}