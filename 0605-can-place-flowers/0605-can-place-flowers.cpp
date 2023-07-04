class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        
        if(n == 0) return true;
        
        int len = arr.size(), flowersPlaced=0;

        if(arr[0] == 0 and len == 1)
            return true;
        else if(arr[0] == 0 and len==1)
            return false;

        
        
        if(arr[0] == 0 and arr[1] != 1)
        {
            arr[0] = 1;
            flowersPlaced++;
        }
        
        if(arr[len-1] == 0 and arr[len-2] != 1)
        {
            arr[len-1] = 1;
            flowersPlaced++;
        }
        
        for(int i=1; i<len-1; i++)
        {
            if(arr[i] == 0 and arr[i-1] != 1 and arr[i+1] != 1)
            {
                flowersPlaced++;
                arr[i] = 1;
            }
        }
        return flowersPlaced >= n;
    }
};