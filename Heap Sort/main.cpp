#include <iostream>
#include <vector>
#include <cmath>
using namespace  std;

struct heap{
    vector<int> arr;
    int heapsize ;
    bool maxHeap = false;
};

void printHeap (struct heap heap){
    for (int i =0 ; i<heap.heapsize ; i++){
        cout<<heap.arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> maxHeapify(struct heap A , int i ){
    int left = 2*i +1;
    int right = 2*i +2;
    int largest=0;
    if (left < A.heapsize and A.arr[left] > A.arr[i]){
        largest = left;
    }
    else{
        largest = i;
    }
    if (right <A.heapsize and A.arr[right] > A.arr[largest]){
        largest = right;
    }
    if (largest != i){
        int temp =A.arr[i];
        A.arr[i] = A.arr[largest];
        A.arr[largest]= temp;
        A.arr = maxHeapify(A, largest);
    }
    return A.arr;
}

vector<int> buildHeap (struct heap A, struct heap* B){
    for (int i = floor(A.arr.size()/2)-1 ; i>=0 ; i--){
        A.arr = maxHeapify(A,i);
    }
    B->maxHeap= true;
    return A.arr;
}

vector<int> heapSort (struct heap A, struct heap* B){
    A.arr = buildHeap(A,B);
    for (int i = A.arr.size()-1 ; i>=1 ; i--){
        int temp = A.arr[0];
        A.arr[0] = A.arr[i];
        A.arr[i] = temp;
        A.heapsize -=1;
        A.arr = maxHeapify(A,0);
    }
    B->maxHeap = false;
    return A.arr;
}

int heapMaximum(struct heap* A){
    if (!A->maxHeap){
        A->arr = buildHeap(*A ,A);
    }
    return A->arr[0];
}

int  heapExtractMax (struct heap*A){
    if (!A->maxHeap){
        A->arr = buildHeap(*A, A);
    }
    int max = A->arr[0];
    A->arr[0] = A->arr[A->arr.size()-1];
    A->arr[A->arr.size()-1] = max;
    A->heapsize -=1;
    A->arr.pop_back();
    A->arr = maxHeapify(*A ,0);
    return max;
}

void heapIncreaseKey (struct heap* A , int i , int key){
    if (key < A->arr[i]){
        cout<<"The key is lesser than the current value."<<endl;
        return;
    }
    else{
        int parent = floor((i-1)/2);
        A->arr[i]= key;
        while (parent >0 and A->arr[parent]< key){
            int temp = A->arr[parent];
            A->arr[parent]= A->arr[i];
            A->arr[i] = temp;
            parent = floor((parent-1)/2);
        }
    }
}

void maxHeapInsert(struct heap* A , int key){
    if (!A->maxHeap){
        A->arr =buildHeap(*A,A);
    }
    A->arr.push_back(key);
    A->heapsize++;
    A->maxHeap = false;
    int i = A->heapsize-1;
    int parent = floor((i-1)/2);
    while (parent >=0 and A->arr[parent]< key){
        int temp = A->arr[parent];
        A->arr[parent]= A->arr[i];
        A->arr[i] = temp;
        i = parent;
        parent = floor((parent-1)/2);
    }
}

int main(){
    heap heap;
    while (true){
        int y ;
        cin>>y;
        if (y ==-1){
            break;
        }
        else{
            heap.arr.push_back(y);
        }
    }

    heap.heapsize =heap.arr.size();
    heap.arr = heapSort(heap, &heap);
    printHeap(heap);


}