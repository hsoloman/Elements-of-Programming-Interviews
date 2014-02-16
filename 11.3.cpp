#include <iostream>
#include <vector>

using namespace std;

// returns index
template <typename T>
int indexEqualValue(const vector<T>& A){
    int found(-1);
    int left(0), right(A.size() -1);
    
    while (left <= right){
        int mid = left + (right - left)/2;
        
        if (A[mid]-mid < 0){
            left = mid + 1;
        } else if (A[mid] - mid == 0){
            return mid;
        } else {
            right = mid -1;
        }
    }

    return found;
} 

//###########################################################################
int main()
{
    vector<int> A = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    cout<< "first occurance k = A[k]: \tA[" << indexEqualValue(A) << "]" << endl; // 2
 
	return 0;
}
