class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int minimumFlips = 0;
        
        while(a!=0 or b!=0 or c!=0)
        {
            if((c & 1) == 1)
            {
                minimumFlips += (((a & 1) == 0) and ((b & 1) == 0));
            }
            else
            {
                minimumFlips += (((a & 1) == 1) + ((b & 1) == 1));
            }
            
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        
        return minimumFlips;
        
    }
};