#include <iostream>
#include <vector>

using namespace std;

// returns index
template <typename T>
int firstOccuranceOfK(const int k, const vector<T>& A){
    int found(-1);
    
    int left(0);
    int right(A.size() - 1);
    
    while(left <= right){  
        int mid = left + (right - left)/2;
        
        if (A[mid] < k){
            left = mid + 1;
        } else if (A[mid] == k){
            found = (found == -1 || mid < found) ? mid : found;
            right = mid - 1;
        } else {
            right = mid - 1;
        }    
    }
    
    return found;
} 

//###########################################################################
int main()
{
    vector<int> A = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    cout<< "first occurance of -14: \tA[" << firstOccuranceOfK(-14, A) << "]" << endl;
    cout<< "first occurance of 108: \tA[" << firstOccuranceOfK(108, A) << "]" << endl;
    cout<< "first occurance of 285: \tA[" << firstOccuranceOfK(285, A) << "]" << endl;
    cout<< "first occurance of 2: \t\tA[" << firstOccuranceOfK(2, A) << "]" << endl;
    cout<< "first occurance of 500: \tA[" << firstOccuranceOfK(500, A) << "]" << endl;

	return 0;
}
