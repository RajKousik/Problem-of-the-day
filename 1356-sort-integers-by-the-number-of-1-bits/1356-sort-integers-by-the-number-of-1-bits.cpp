class Solution {
public:
    
    static int countBits(int a)
    {
        int count = 0;
        while(a)
        {
            a = a & (a-1);
            count++;
        }
        return count;
    }
    
    static bool compare(int a, int b)
    {
        int p = countBits(a);
        int q = countBits(b);
        
        if(p == q)
        {
            return a < b;
        }
        
        return p < q;
        
    }
    
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};