// Write a program to find last occurence of given number
// note:- do not use linear search
// Time complexity:- O(logn)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lastOccurence(vector<int> arr, int target){
    int start = 0; 
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == target){
            ans = mid;
            start = mid + 1;
        }
        else if(target > arr[mid]){
            start = mid + 1;
        }
        else if(target < arr[mid]){
            end = mid -1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main(){
    vector<int> arr{1,7,7,7,7,7,7,9};
    int indexOfLastOccurence;
    int target = 7;
    indexOfLastOccurence = lastOccurence(arr, target);
    cout<<"Ans is: "<<indexOfLastOccurence<<endl;

    //using upper_bound method
    auto ans = upper_bound(arr.begin(), arr.end(), target);
    cout<<"upper bound ans: "<<(ans-arr.begin() - 1)<<endl;
}