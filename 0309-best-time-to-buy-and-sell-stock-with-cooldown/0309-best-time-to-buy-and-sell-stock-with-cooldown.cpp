class Solution {
public:
    
        // *****  SEE Best Time to Buy and Sell Stock II for better understanding ********
    
    
        /*
        
            same problem but after selling instead of going to next index(index+1), we should go to index+2
            
            *** the base vase should be greater than or equal to 
            
        */
    
    
//         int helper(int ind, int canWeBuyNow, vector<int> &prices)
//         {

//             if(ind >= prices.size())
//             {
//                 return 0;
//             }

//             if(canWeBuyNow)
//             {
//                 return max(-prices[ind] + helper(ind+1, 0, prices),
//                            0 + helper(ind+1, 1, prices));
//             }
//             else
//             {
//                 return max(prices[ind] + helper(ind+2, 1, prices),
//                             0 + helper(ind+1, 0, prices));
//             }

//         }

//         int maxProfit(vector<int>& prices) 
//         {
//             int canWeBuyNow = 1; 
//             return helper(0, canWeBuyNow, prices);    
//         }
    
    
    
    
    
    //jusy apply memoization
    
    // RECURSION + MEMOIZATION -> ACCEPTED -> TOPDOWN APPROACH
//     int helper(int ind, int canWeBuyNow, vector<int> &prices, vector<vector<int>> &dp)
//     {
        
//         if(ind >= prices.size())
//         {
//             return 0;
//         }
        
//         if(dp[ind][canWeBuyNow] != -1)
//         {
//             return dp[ind][canWeBuyNow];
//         }
        
//         if(canWeBuyNow)
//         {
//             return dp[ind][canWeBuyNow] = max(-prices[ind] + helper(ind+1, 0, prices, dp),
//                        0 + helper(ind+1, 1, prices, dp));
//         }
//         else
//         {
//             return dp[ind][canWeBuyNow] = max(prices[ind] + helper(ind+2, 1, prices, dp),
//                         0 + helper(ind+1, 0, prices, dp));
//         }
        
//     }
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return helper(0, 1, prices, dp);    
//     }
    
    
    
    
    
    
    
    
    
    //in else part (i.e) after selling, go to index + 2
    //during dp declaration use (n+2) 
    
    
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n+2, vector<int>(2, 0));
        
//             // base case of topdown is converted like this(NOTE: as default values are 0, no need of below line, only for understanding)
    
//         dp[n][0] = dp[n][1] = 0;
            
//             // topdown is from {0->n-1, 0->1}
//             // so here reverse order
    
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
//                     dp[ind][buy] = max(prices[ind] + dp[ind+2][1],
//                                 0 + dp[ind+1][0] );
//                 }
//             }
//         }
            
//         return dp[0][1];
        
//     }
    
    
    
    
    
    
    
    
    
    
    
    //instead of using 2d array, we can use 1d array 
    //but we need 3, 1d arrays
    //as we r using ind+2;
    //use front2, front1, curr
    
    //use prev2 only after selling the stock, 
    //and swap for next iteration
    
    //SPACE OPTIMZATION
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
        
//         vector<int> prev2(2, 0);
//         vector<int> prev1(2, 0);
//         vector<int> curr (2, 0);
        
//         for(int ind=n-1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy <= 1; buy++)
//             {

//                 if(buy)
//                 {
//                     curr[buy] = max(-prices[ind] + prev1[0],
//                                0 + prev1[1]) ;
//                 }
//                 else
//                 {
//                     curr[buy] = max(prices[ind] + prev2[1],
//                                 0 + prev1[0] );
//                 }
//             }
//              //swap for next operation
//             prev2 = prev1;
//             prev1 = curr;
//         }
        
//         return prev1[1];
// }
    
        int solve(int ind, bool canWeBuyNow, int n, vector<int> &prices, vector<vector<int>> &dp)
        {
            if(ind >= n)
            {
                return 0;
            }
            
            if(dp[ind][canWeBuyNow] != -1)
            {
                return dp[ind][canWeBuyNow];
            }
            
            if(canWeBuyNow)
            {
                return dp[ind][canWeBuyNow] = max(-prices[ind] + solve(ind+1, false, n, prices, dp),
                           solve(ind+1, true, n, prices, dp));
            }
            else
            {
                return dp[ind][canWeBuyNow] = max(prices[ind] + solve(ind+2, true, n, prices, dp),
                          solve(ind+1, false, n, prices, dp));
            }
            return 0;
        }
    
    
        int maxProfit(vector<int>& prices) 
        {
            int n = prices.size();
            
            vector<vector<int>> dp(n, vector<int>(2, -1));
            
            bool canWeBuyNow = true;
            return solve(0, canWeBuyNow, n, prices, dp);
            
        }
        
    
};