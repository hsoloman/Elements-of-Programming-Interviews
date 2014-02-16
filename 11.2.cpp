#include <iostream>
#include <vector>

using namespace std;

// returns index
template <typename T>
int firstOccuranceLargerThanK(const int k, const vector<T>& A){
    int found(-1);
    int left(0), right(A.size() -1);
    
    while(left <= right){
        int mid = left + (right - left)/2;
        
        if (A[mid] <= k){
            left = mid + 1;
        } else {
            right = mid - 1;
            found = (found == -1 || mid < found) ? mid : found;
        }
        
    }

    return found;
} 

//###########################################################################
int main()
{
    vector<int> A = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    cout<< "first occurance larger than -14: \tA[" << firstOccuranceLargerThanK(-14, A) << "]" << endl;
    cout<< "first occurance larger than 108: \tA[" << firstOccuranceLargerThanK(108, A) << "]" << endl;
    cout<< "first occurance larger than 285: \tA[" << firstOccuranceLargerThanK(285, A) << "]" << endl;
    cout<< "first occurance larger than 2: \t\tA[" << firstOccuranceLargerThanK(2, A) << "]" << endl;
    cout<< "first occurance larger than 500: \tA[" << firstOccuranceLargerThanK(500, A) << "]" << endl;

    return 0;
}
