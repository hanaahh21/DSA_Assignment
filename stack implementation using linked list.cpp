#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node* next;
};


struct Stack{
    Node* top;
    int sizeOfStack;
    int curSize;

    Stack(){
        top = nullptr;
        curSize = 0;
    }
    
    bool isEmpty(){
        return top ==nullptr;
    }
    
    bool isFull(){
        return curSize == sizeOfStack;
    }
    
    void push(int val){
        if (isFull()){
            cout<<"Stack overflow\n";
            return;
        }else{
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = top;
            top = newNode;
            curSize++;
        }
        
    }
    
    int pop(){
        if (isEmpty()){
            cout<<"Stack Underflow\n";
            return -1;
        }
       int val = top->data;
       Node* temp = top;
       top = top->next;
       delete temp;
       curSize--;
       return val;
    }
    
    int stacktop(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return -1;
        }else return top->data;
    }
    
    void display(){
        if (isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp != nullptr){
            cout<< temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
    
    
};

int main(){
    int size;
    cout<<"Enter the stack size: "<<endl;
    cin>> size;
    Stack S;
    S.sizeOfStack = size;
    
    auto start= steady_clock::now();
    S.push(8);
    S.push(10);
    S.push(5);
    S.push(11);
    S.push(15);
    S.push(23);
    S.push(6);
    S.push(18);
    S.push(20);
    S.push(17);
    S.display();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.display();
    S.push(4);
    S.push(30);
    S.push(3);
    S.push(1);
    S.display();
    auto end= steady_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken in nanoseconds: "<<duration.count();
    return 0;
    
    
}