#include <iostream>
#include <vector>

using namespace std;


int indexOfLeastValue(const vector<int>& A){
    int left(0), right(A.size() -1);
    
    while(left < right){
        int mid = left = (right - left)/2;
        if (A[mid] < A[right]){
            right = mid;
        } else {
            left = mid + 1;
        }
    }    
    
    return left;
}


int main()
{
    // finding index of minimum element in a cyclically sorted array  
    vector<int> A = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
            // min is at A[4]
        
    int index = indexOfLeastValue(A);
    cout << "Least value " << A[index] << " at A[" << index << "]" << endl;
    return 0;
}
