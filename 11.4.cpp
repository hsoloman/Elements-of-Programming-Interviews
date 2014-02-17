#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

namespace {
    typedef int value_t;
    typedef int index_t;    

    pair<index_t, index_t> findPairSumK(int k, const vector<int>& A){
        map<value_t, index_t> values;

        for (int index = 0 ; index < A.size() ; index++){
            values[A[index]] = index;
        }     
    
        for(int i = 0; i < A.size(); i++){
            int complement = k-A[i];
            if (values.count(complement)){
                return make_pair(i, values.find(complement)->second );
            }
        }
        
        return make_pair(-1, -1);
    }
}

//###########################################################################
int main()
{
    vector<int> A = {-49, 75, 103, -147, 164, -197, -238, 314, 348, -422};

    //  hash values to indices
    //  for each value, search for the corresponding value that sums to k 
    
    cout << "Pair that sums to 167: (" << findPairSumK(167, A).first << ", " 
        << findPairSumK(167, A).second << ")" << endl;
    
	return 0;
}
