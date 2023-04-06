#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

class node{
public:
    int data;
    node* next;
    node (int data){
        this->data = data;
    }
};

class stack{
    public:
        node* top;
        int length;
        int current = 0;
        stack(int length){
            this->length = length;
            top = nullptr;
        }

        bool isEmpty(){
            return current == 0;
        }

        bool isFull(){
            return current >= length;
        }

        void pop(){
            if (this->isEmpty()){
                cout<<"Stack underflow. "<< endl;
            }
            else{
                top = top->next;
                current --;
            }
        }
        void push(int data){
            if(this->isFull()){
                cout<<"Stack overflow."<<endl;
            }
            else{
               node* newnode =new node(data);
               newnode->next = top;
               top = newnode;
               current ++;
            }
        }

        void Display(){
            node* temp = top;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }

        int stackTop(){
            return top->data;
        }


};
int main() {
    int length;
    cout<<"enter the length of the stack. "<<endl;

    auto start = high_resolution_clock ::now();
    cin>> length;
    stack stack (length);

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