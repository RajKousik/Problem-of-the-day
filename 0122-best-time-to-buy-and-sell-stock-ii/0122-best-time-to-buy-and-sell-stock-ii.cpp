class Solution {
public:
        
        /*
            O(N) approach
        */
    
        int maxProfit(vector<int>& prices) 
        {
            
            int i=0, n=prices.size();
            int buyingPrice, sellingPrice, netProfit = 0;
            
            for(int i=0; i<n; i++)
            {
                
                while(i+1 < n and prices[i+1] <= prices[i])
                {
                    i++;
                }
                
                buyingPrice = prices[i];
                
                while(i+1 < n and prices[i+1] > prices[i])
                {
                    i++;
                }
                
                sellingPrice = prices[i];
                
                netProfit += (sellingPrice - buyingPrice);
            }
            
            
            return netProfit;
        }
        
    
    
    
        /**/
    
    
    
    
    
    
        /*
        
        APPROACH:
            As we have to try all the possible options, it is definitely going to be recursion
            
            so we can buy as many stocks, but the only constraint is, we cannot by an stock, before selling the previous stock  
            so to buy the next stock, we should have sold the previously bought stock
            
            so we don't know when to buy the stock, as we don't know, whether we sold the previously bought stock
            for that purpose we take a variable, canWeBuyNow 
            canWeBuyNow -> 1 represents, yes we can buy now
                        -> 0 represents, we haven't sold previous stock, so we can't buy now
                        
            so we know our parameters now -> (index, canWeBuyNow)
            
            **BASE CASE**
            if we reach the n, then we can return 0
            
            **RECURSIVE CASE**
            ->  if canWeBuyNow is 1, then we have two option, whether we can buy now, or we can don't buy now, we will go to next index
                                    (similiar to pick and non-pick), we will take the max out of it
            
                so if we are buying something, then we are giving money and buying, so that is loss, so we subtract
                ->  if we bought that, then helper function goes to next index, 
                        (with canWeBuyNow as 0, as we have bought a stock, and haven't sold yet)
                        
                ->  if we haven't bought, then helper function goes to next index,
                        (with canWeBuyNow as 1, as we haven't bought a stock, so we can buy next stock)
                
            ->  if canWeBuyNow is 0, then we have two option, whether we can sell now, or we can don't sell now, we will go to next index
                                    (similiar to pick and non-pick), we will take the max out of it
            
                so if we are selling something, then we are getting money and selling, so that is profit, so we add
                ->  if we sell that, then helper function goes to next index, 
                    (with canWeBuyNow as 1, as we have sell a stock, and we can buy next stock)
                ->  if we haven't sell, then helper function goes to next index,
                        (with canWeBuyNow as 0, as we haven't sell a stock, so we cannot buy next stock)
        
        
        */
    
    
        //RECURSION -> GIVING TLE
    
//     int helper(int ind, int canWeBuyNow, vector<int> &prices)
//     {
        
//         if(ind == prices.size())
//         {
//             return 0;
//         }
        
//         if(canWeBuyNow)
//         {
//             return max(-prices[ind] + helper(ind+1, 0, prices),
//                        0 + helper(ind+1, 1, prices));
//         }
//         else
//         {
//             return max(prices[ind] + helper(ind+1, 1, prices),
//                         0 + helper(ind+1, 0, prices));
//         }
        
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int canWeBuyNow = 1; 
//         return helper(0, canWeBuyNow, prices);    
//     }
    
    
    
            
        /*
        
            as it is giving TLE, we should use DP, as there will be overlapping sub-problems
            
            the parameters that are changing are -> {index, canWeBuyNow}
            
            so we use 2d dp
            index is from 0 to n
            canWeBuyNow is from 0 to 1
            
            initiliaze as -1;
            
            store the ans, and if already found, use that one
            
            simple ;)
            
            
        
        */
    
    // RECURSION + MEMOIZATION -> ACCEPTED -> TOPDOWN APPROACH
//     int helper(int ind, int canWeBuyNow, vector<int> &prices, vector<vector<int>> &dp)
//     {
//         if(ind == prices.size())
//             return 0;
        
//         if(dp[ind][canWeBuyNow] != -1)
//             return dp[ind][canWeBuyNow];
        
//         if(canWeBuyNow)
//         {
//             return dp[ind][canWeBuyNow] = max(-prices[ind] + helper(ind+1, 0, prices, dp),
//                        0 + helper(ind+1, 1, prices, dp));
//         }
//         else
//         {
//             return dp[ind][canWeBuyNow] = max(prices[ind] + helper(ind+1, 1, prices, dp),
//                         0 + helper(ind+1, 0, prices, dp));
//         }
        
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return helper(0, 1, prices, dp);    
//     }
    
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
//     int maxProfit(vector<int>& prices) 
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
//                     dp[ind][buy] = max(prices[ind] + dp[ind+1][1],
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
    
    
    
    
    //SPACE OPTIMZATION
//     int maxProfit(vector<int>& prices) 
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
//                     curr[buy] = max(prices[ind] + prev[1],
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
    
//     int maxProfit(vector<int>& prices) 
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
//                     currNotBuy = max(prices[ind] + prevBuy,
//                                 0 + prevNotBuy );
//                 }
//             }
//             prevNotBuy = currNotBuy;
//             prevBuy = currBuy;
//         }
        
//         return prevBuy;
        
//     }
    
    
};