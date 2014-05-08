#include <iostream>
#include <vector>

using namespace std;

// returns index of value k in a cyclically sorted array
// returns -1 if not found
int indexOfK(const vector<int>& A, int k){
    int left(0), right(A.size() -1);
    
    while(left <= right) {
        int mid = left + (right-left)/2;
        
        cout << mid << endl;
        
        if (A[mid] == k) return mid;
        
        if (A[mid] < A[right]){ // right half contiguous
        
            if (k >= A[mid] && k <= A[right]){  // k in right half
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        } else {                // left half contiguous
            if (k >= A[left] && k <= A[mid]){
                right = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

int main()
{
    vector<int> A = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
    // min is at A[4]
        
    int k = 368;
    int index = indexOfK(A, k);
    cout << k << "  found at A[" << index << "]" << endl;
    return 0;
}
