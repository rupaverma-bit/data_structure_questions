//Write a program to finad a highest pivot element 

#include <iostream>
#include <vector>
using namespace std;

int findPivotElement(vector<int> arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(mid +1 >= arr.size() && arr[mid] > arr[mid + 1])
            return mid;
        if(mid - 1 >= arr[0] && arr[mid - 1] > arr[mid])
            return mid-1;
        if(arr[start] > arr[mid]){
            end = mid - 1;
        }    else{
            start = mid + 1;
        }
    mid = start + (end - start)/2;    
    }
   return -1; 
}

int main(){
    vector<int> arr{3, 4, 5, 6, 7, 1, 2};
    int ans = findPivotElement(arr);
    cout<<"pivot element is "<< arr[ans];
    return 0;
}