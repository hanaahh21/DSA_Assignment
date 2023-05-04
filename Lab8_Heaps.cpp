#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root){
   // build heapify
  int max = root;               //initialize the max as root
  int left = 2*root + 1;        //left child index
  int right = 2*root + 2;       //right child index

  //if left child is larger than root
  if (left<n && arr[left] > arr[max]) max = left;
  
  //if right child is larger than root
  if(right <n && arr[right] > arr[max]) max = right; 
  
  //if max is not root swap root and max and recursively heapify the subtree
  if (max != root){
   swap(arr[root],arr[max]);
   heapify(arr, n, max);
  }
}
 
 
  
// implementing heap sort
void heapSort(int arr[], int n){
   // build heap
   for (int i = n/2 - 1; i>=0 ; i--){
      heapify (arr, n, i);
   }
   
  
   // extracting elements from heap one by one
   for (int i = n-1; i>=0; i--){
      swap(arr[0],arr[i]);
      heapify(arr, i, 0);
   }
}
 
 
  
/* print contents of array */
void displayArray(int arr[], int n){
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
  
  
// main program
int main(){
    string input;
    int heap_arr[100];
    int n = 0;

    getline(cin, input); // read the input line from user
    
    // convert input line to stream and read integers one by one
    stringstream ss(input);
    int num;
    while(ss >> num){
        heap_arr[n++] = num;
    }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
