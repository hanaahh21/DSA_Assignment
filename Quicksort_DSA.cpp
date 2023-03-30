#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


// finding the partition function
int partition(int arr[], int begin, int end){
    int pivot = arr[end];
    int i = begin - 1;

    for(int j=begin; j<end; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[j];
            arr[j]= pivot;
            pivot = temp ;
        }
    }

    int temp = arr[i+1];
    arr[i+1]= arr[end];
    arr[end] = temp ;
    return i+1;
}

// recursive  QuickSort function
void quickSort(int arr[], int begin, int end){
    if(begin < end){
        int pivot = partition(arr, begin, end);

        quickSort(arr, begin, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

void quickSortIterative(int arr[], int low, int high){
    // Creating an auxiliary stack
    int stack[high - low + 1];
  
    // initializing the  top of stack
    int top = -1;
  
    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array find the partition point
        int p = partition(arr, low, high);
  
        // If there are elements on left side of pivot, then push left side to stack
        
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}
int main(){
    int arr[100]; // Initialize the array 
    
    //add random elements
    for(int i=0; i<100; i++){
        arr[i] = rand()%1000;
    }
    
	  //calculate the size of an array
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //find the time taken to recursive quicksort
    auto start = high_resolution_clock::now(); // Start the clock
    quickSort(arr, 0,n-1);
    auto stop = high_resolution_clock::now(); // Stop the clock

    auto duration = duration_cast<microseconds>(stop - start); // Calculate the duration in microseconds
    cout << "Time taken by quickSort function: " << duration.count() << " microseconds" << endl;
    
    
    //find the time taken to iterative quicksort
    auto start1= high_resolution_clock::now(); // Start the clock
    quickSortIterative(arr,0,n-1);
    auto stop1= high_resolution_clock::now(); // Stop the clock
    auto duration1= duration_cast<microseconds>(stop1- start1);// Calculate the duration in microseconds
    cout << "Time taken by quickSortIterative: " <<duration1.count() << " microseconds" << endl;
    return 0;
}
