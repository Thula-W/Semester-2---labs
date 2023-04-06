#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

class Stack{
    public:
        int length;
        int top =-1;
        int arr[];
        Stack (int length){
            int arr [length] ;
        }

        void push(int data){
            if (!this->isFull()){
                arr[top +1] = data;
                top++;
            }
            else{
                cout<<"Stack overflow. "<< endl;
            }
        }

        void pop(){
            if (!this->isEmpty()){
                top--;
            }
            else{
                cout<<"stack under flow"<<endl;
            }
        }

        bool isEmpty (){
            if (top ==-1){
                return true;
            }
            else {
                return false;
            }
        }

        bool isFull(){
            if (top == length -1){
                return true;
            }
            else{
                return false;
            }
        }

        int stackTop(){
            if (this->isEmpty()){
                cout<<"the stack is empty. "<<endl;
            }
            return arr[top];
        }

        void Display(){
            for (int i =0 ; i<top+1 ; i++){
                cout<< arr[i]<< " ";
            }
            cout<<"\n";
        }


};

int main() {
    int length;
    cout<<"enter the length of the stack. "<<endl;

    auto start = high_resolution_clock ::now();
    cin>> length;
    Stack stack (length);

    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.Display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.Display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);
    stack.Display();

    auto stop = high_resolution_clock :: now();
    auto duration = duration_cast<seconds>(stop - start);
    cout<<"Time taken - "<< duration.count()<<" seconds"<<endl;
    return 0;
}
