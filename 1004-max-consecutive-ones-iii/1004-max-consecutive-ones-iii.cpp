class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0;
        int right = 0;
        
        while(right < A.size())
        {
            if (A[right] == 0) 
                K--;
            if (K < 0 && A[left++] == 0) 
                K++;
            right++;
        }
        
        return right - left;
    }
};