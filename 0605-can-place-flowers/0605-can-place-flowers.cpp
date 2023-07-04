class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        
//         if(n == 0) return true;
        
//         int len = arr.size(), flowersPlaced=0;

//         if(arr[0] == 0 and len == 1)
//             return true;
//         else if(arr[0] == 1 and len==1)
//             return false;
        
//         if(arr[0] == 0 and arr[1] != 1)
//         {
//             arr[0] = 1;
//             flowersPlaced++;
//         }
        
//         if(arr[len-1] == 0 and arr[len-2] != 1)
//         {
//             arr[len-1] = 1;
//             flowersPlaced++;
//         }
        
//         for(int i=1; i<len-1; i++)
//         {
//             if(arr[i] == 0 and arr[i-1] != 1 and arr[i+1] != 1)
//             {
//                 flowersPlaced++;
//                 arr[i] = 1;
//             }
//         }
        int len = arr.size(), flowersPlaced=0;
        for(int i=0; i<len; i++)
        {
            if(arr[i] == 0)
            {
                bool isLeftSafe = (i==0) or (arr[i-1] == 0);
                bool isRightSafe = (i==len-1) or (arr[i+1] == 0);
                
                
                if(isLeftSafe and isRightSafe)
                {
                    flowersPlaced++;
                    arr[i] = 1;
                    if(flowersPlaced >= n)
                    {
                        return true;
                    }
                }
                
            }
        }
        
        return flowersPlaced >= n;
    }
};