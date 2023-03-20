class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        
        int cnt = 0;
        int s = flowerbed.size();
        
        if(s == 1)
        {
            return flowerbed[0] == 0 ? cnt+1 >= n : cnt>=n;
        }
        
        if(flowerbed[0] == 0 and flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            cnt++;
        }
        if(flowerbed[s-1] == 0 and flowerbed[s-2] == 0)
        {
            flowerbed[s-1] = 1;
            cnt++;
        }
        
        for(int i=1; i<s-1; i++)
        {
            if(flowerbed[i] == 0 and flowerbed[i-1] != 1 and flowerbed[i+1] != 1)
            {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        return cnt >= n;
    }
};