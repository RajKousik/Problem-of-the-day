class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        //O(N) approach
        
        // vector<int> ans(2*n);
        // int i=0;
        // int j=n; 
        // int k=0;
        // while(k < 2 *n)
        // {
        //     ans[k++] = (nums[i++]);
        //     ans[k++] = (nums[j++]);
        // }
        // return ans;
        
        
        
        
        // O(1) approach
        
        //the maximum number given in constraint is 10^3
        //so only 10 bits are used, remaining 22 bits are unused
        //so we are going to use that unused 22 bits to store annther number
        //so in one varibale two numbers are stored
        
        //last 10 bits -> one number
        //the previous 10 bits -> another number
        
        // 0....0 0000000000 0000000000 (totally 32 bits)
        //rem bits second no first number
        
        for(int i=n; i<2*n; i++)
        {
            int secondNumber = nums[i] << 10;
            nums[i-n] |= secondNumber;
        }
        
        int allOnes = pow(2, 10) - 1; //(1111111111)
        
        for(int i=n-1; i>=0; i--)
        {
            int secondNumber = nums[i] >> 10;
            int firstNumber = nums[i] & allOnes;
            
            nums[2*i] = firstNumber;
            nums[2*i+1] = secondNumber;
        }
        
        return nums;
        
    }
};