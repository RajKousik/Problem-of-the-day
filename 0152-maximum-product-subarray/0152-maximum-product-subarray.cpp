class Solution {
public:
    int maxProduct(vector<int>& A) {
      int n = A.size();
        
        int prefixProduct = 1;
        int suffixProduct = 1;
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            prefixProduct = (prefixProduct ? prefixProduct : 1) * A[i];
            suffixProduct = (suffixProduct ? suffixProduct : 1) * A[n-i-1];
            ans= max(ans, max(prefixProduct, suffixProduct));
        }
        return ans;
        
    }
};