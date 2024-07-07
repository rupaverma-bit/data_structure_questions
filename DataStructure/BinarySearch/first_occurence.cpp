// Write a program to finad a first occurence of given number in the array
//note:-don't use linear search
// Time complexity :- O(logn)

#include<iostream>
//for using vector
#include <vector>
//for using lower bound or upper bound
#include <algorithm>
using namespace std;

int firstOccurence(vector<int> v, int target){
    int first = 0;
    int last = v.size() - 1;
    int mid = (first + last)/2;
    int ans = -1;
    while(first <= last){
        if(v[mid] == target){
            ans = mid;
            last = mid - 1;
        }
        else if(target > v[mid]){
            first = mid + 1;
        }
        else if(target < v[mid]){
            last = mid - 1;
        }
        mid = (first + last)/2;
    }
    return ans;
}

int main(){
    vector<int> v{1,3,4,5,5,5,6,7};
    int target = 8;
    int indexOfFirstOccurence = firstOccurence(v, target);
    cout<<"ans is: "<<indexOfFirstOccurence<<endl;

    // using lower bound method to find first occurence of given number
    auto ans = lower_bound(v.begin(), v.end(), target);
    cout<<"lower bound answer: "<<(ans-v.begin())<<endl;
}