#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


class Stack{
private:
    int top;
    int *arr;
    int sizeOfStack;

public:
    Stack(int size){
        top = -1;
        sizeOfStack = size;
        arr = new int[sizeOfStack];
    }
    
    bool isEmpty(){
        return top ==-1;
    }
    
    bool isFull(){
        return top == sizeOfStack-1;
    }
    
    void push(int val){
        if (isFull()){
            cout<<"Stack overflow\n";
            return;
        }else{
            top++;
            arr[top]=val;
        } 
    }
    
    int pop(){
        if (isEmpty()){
            cout<<"Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    
    int stacktop(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return -1;
        }else return arr[top];
    }
    
    void display(){
        if (isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        for(int i =top; i>=0;i--){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    
    ~Stack(){
        delete[] arr;
    }
};

int main(){
    int size;
    cout<<"Enter the stack size: "<<endl;
    cin>> size;
    Stack S(size);
    
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