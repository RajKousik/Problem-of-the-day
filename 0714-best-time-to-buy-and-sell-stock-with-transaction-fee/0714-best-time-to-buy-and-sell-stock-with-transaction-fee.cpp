class Solution {
public:
    
        //  ******* SEE  Best Time to Buy and Sell Stock II for better understanding ****
    
    
        /*
            the difference is:
            here the fee should be deducted for every transaction
            
            so same code
            
            just after selling the product, subtract the fees
            that's it, so simple
            
            
            **NOTE: we can also subtract the fees from the buying time, which is also correct
            so we can either subtract the fees during buying, or selling
    
        */
    
    
        //RECURSION -> GIVING TLE
    
//     int helper(int ind, int canWeBuyNow, vector<int> &prices, int fee)
//     {
        
//         if(ind == prices.size())
//         {
//             return 0;
//         }
        
//         if(canWeBuyNow)
//         {
//             return max(-prices[ind] + helper(ind+1, 0, prices, fee),
//                        0 + helper(ind+1, 1, prices, fee));
//         }
//         else
//         {
//             return max(prices[ind] - fee + helper(ind+1, 1, prices, fee),
//                         0 + helper(ind+1, 0, prices, fee));
//         }
        
//     }
    
//     int maxProfit(vector<int>& prices, int fee) 
//     {
//         int canWeBuyNow = 1; 
//         return helper(0, canWeBuyNow, prices, fee);    
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // RECURSION + MEMOIZATION -> ACCEPTED -> TOPDOWN APPROACH
    int helper(int ind, int canWeBuyNow, vector<int> &prices, vector<vector<int>> &dp, int fee)
    {
        if(ind == prices.size())
        {
            return 0;
        }
        if(dp[ind][canWeBuyNow] != -1)
        {
            return dp[ind][canWeBuyNow];
        }
        if(canWeBuyNow)
        {
            return dp[ind][canWeBuyNow] = max(-prices[ind] + helper(ind+1, 0, prices, dp, fee),
                       0 + helper(ind+1, 1, prices, dp, fee));
        }
        else
        {
            return dp[ind][canWeBuyNow] = max(prices[ind]-fee + helper(ind+1, 1, prices, dp,fee),
                        0 + helper(ind+1, 0, prices, dp, fee));
        }   
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp, fee);    
    }
    
    
    
    
    
    
        /*
            so we use 2d dp
            index is from 0 to n
            canWeBuyNow is from 0 to 1
            
            initiliaze as 0
            
            BOTTOM-UP APPROACH
                1. convert the base case
                2. use nested loops in reverse order of topdown
                3. copy the recurive call from the topdown
    
    
        */
    
    
    
    
    // TABULATION -> BOTTOM UP APPROACH 
//     int maxProfit(vector<int>& prices, int fee) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
//           // base case of topdown is converted like this(NOTE: as default values are 0, no need of below line, only for understanding)
    
//         dp[n][0] = dp[n][1] = 0;
            
//            // topdown is from {0->n-1, 0->1}
//            // so here reverse order
    
//         for(int ind=n-1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy <= 1; buy++)
//             {

//                 if(buy)
//                 {
//                     dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
//                                0 + dp[ind+1][1]) ;
//                 }
//                 else
//                 {
//                     dp[ind][buy] = max(prices[ind]-fee + dp[ind+1][1],
//                                 0 + dp[ind+1][0] );
//                 }
//             }
//         }
            
//         return dp[0][1];
        
//     }
    
    
    
    
    
    
    
        
     /*
    
        we need only previous row, not entire dp
        so we can use two rows
        
        and modified it as need
    
    */
    
    
    // SPACE OPTIMZATION
//     int maxProfit(vector<int>& prices, int fee) 
//     {
//         int n = prices.size();
        
//         vector<int> prev (2, 0);
//         vector<int> curr (2, 0);
        
//         for(int ind=n-1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy <= 1; buy++)
//             {

//                 if(buy)
//                 {
//                     curr[buy] = max(-prices[ind] + prev[0],
//                                0 + prev[1]) ;
//                 }
//                 else
//                 {
//                     curr[buy] = max(prices[ind]-fee + prev[1],
//                                 0 + prev[0] );
//                 }
//             }
//              //swap for next operation
//             prev = curr;
//         }
        
//         return prev[1];
        
//     }
    

    

    
    
    
    
    //IN SPACE OPTIMZATION, we used two vectors of size 2, 
    //so that can be implemented using 4 variables
    //prev[0] -> prevNotBuy
    //prev[1] -> prevBuy
    //curr[0] -> currNotBuy
    //curr[1] -> currBuy 
    
//     int maxProfit(vector<int>& prices, int fee) 
//     {
//         int n = prices.size();
        
//         int prevNotBuy, prevBuy, currNotBuy, currBuy;
        
//         prevNotBuy = 0;
//         prevBuy = 0;
        
//         for(int ind=n-1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy <= 1; buy++)
//             {

//                 if(buy)
//                 {
//                     currBuy = max(-prices[ind] + prevNotBuy,
//                                0 + prevBuy) ;
//                 }
//                 else
//                 {
//                     currNotBuy = max(prices[ind]-fee + prevBuy,
//                                 0 + prevNotBuy );
//                 }
//             }
//             prevNotBuy = currNotBuy;
//             prevBuy = currBuy;
//         }
        
//         return prevBuy;
        
//     }
    
    
};