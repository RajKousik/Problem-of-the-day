class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int times = 32;
        vector<int> store;
        
        while(times--)
        {
            int t = n & 1;
            store.push_back(t);
            n>>=1;
        }
        
        int res = 0;
        
        for(int i=0; i<32; i++)
        {
            res = res << 1;
            res = res | store[i];
        }
        
        return res;
        
    }
};