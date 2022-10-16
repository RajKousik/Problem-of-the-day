class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int a = __builtin_popcount(num1);
        int b = __builtin_popcount(num2);
        // int a=0, b=0;
        int res = num1;
        
//         int n1 = num1;
//         int n2 = num2;
//         while(n1 != 0)
//         {
//             n1 = n1 & (n1-1);
//             a++;
//         }
        
//         while(n2 != 0)
//         {
//             n2 = n2 & (n2-1);
//             b++;
//         }
        
        // cout<<a<<a1<<b<<b1<<endl;
        
        for(int i=0; i<32; i++)
        {
            if(a > b and ((1<<i)&num1) > 0)
            {
                res ^= (1<<i);
                a--;
            }
            if(a < b and ((1<<i)&num1) == 0)
            {
                res ^= (1<<i);
                a++;
            }

        }
        
        return res;                
            
        
    }
};