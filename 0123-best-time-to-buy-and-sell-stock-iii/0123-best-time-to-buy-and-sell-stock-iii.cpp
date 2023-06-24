class Solution {
public:
        
        int maxProfit(vector<int>& prices) 
        {
            int firstBuy = INT_MAX;
            int profit1 = INT_MIN;
            int secondBuy = INT_MAX;
            int profit2 = INT_MIN;
            
            for(int price : prices)
            {
                firstBuy = min(firstBuy, price);
                profit1 = max(profit1, price - firstBuy);
                secondBuy = min(secondBuy, price - profit1);
                profit2 = max(profit2, price - secondBuy);
            }
            return profit2;
        }
    
    
    
        //   ************* please see BEST TIME TO BUY AND SELL II ****************************    //
        // (link in similar topics section)
    
        /*
        
            same approach as previous qn(BEST TIME TO BUY AND SELL II),
            we will another variable to maintain the capacity
            
            **BASE CASE**
            extra base case will be, when capacity is 0, return 0
            
            if we sell a particulat stock, then we subtract the capacity by 1, and call the recusrve funciton
            
            other things are same as previous
            
        */
    
        //RECURSION -> GIVING TLE
//     int helper(int ind, int canWeBuyNow, int capacity, vector<int> &prices)
//     {
        
//         if(ind == prices.size() or capacity == 0)
//         {
//             return 0;
//         }
        
//         if(canWeBuyNow)
//         {
//             return max(-prices[ind] + helper(ind+1, 0, capacity, prices),
//                    0 + helper(ind+1, 1, capacity, prices) );
//         }
//         else
//         {
//             return max(prices[ind] + helper(ind+1, 1, capacity-1, prices),
//                       0 + helper(ind+1, 0, capacity, prices));
//         }
        
        
//     }
    
    
//     int maxProfit(vector<int>& prices) 
//     {
//         return helper(0, 1, 2, prices);    
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    // RECURSION + MEMOIZATION -> ACCEPTED -> TOPDOWN APPROACH
//     int helper(int ind, int canWeBuyNow, int capacity, vector<int> &prices, vector<vector<vector<int>>> &dp)
//     {
//         if(ind == prices.size() or capacity == 0)
//         {
//             return 0;
//         }
//         if(dp[ind][canWeBuyNow][capacity] != -1)
//         {
//             return dp[ind][canWeBuyNow][capacity];
//         }
//         if(canWeBuyNow)
//         {
//             return dp[ind][canWeBuyNow][capacity] = max(-prices[ind] + helper(ind+1, 0, capacity, prices, dp),
//                                                          0 + helper(ind+1, 1, capacity, prices, dp) );
//         }
//         else
//         {
//             return dp[ind][canWeBuyNow][capacity] = max(prices[ind] + helper(ind+1, 1, capacity-1, prices, dp),
//                                                          0 + helper(ind+1, 0, capacity, prices, dp) );
//         }
//     }
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return helper(0, 1, 2, prices, dp);    
//     }
    
    
    
    
    
    
    
    
    
    
        // TABULATION -> BOTTOM UP APPROACH 
//         int maxProfit(vector<int>& prices) 
//         {
//             int n = prices.size();
//             vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
            
// //             for(int i=0; i<=1; i++)
// //             {
// //                 for(int j=0; j<=2; j++)
// //                 {
// //                     dp[n][i][j] = 0;
// //                 }
// //             }
            
// //             for(int i=0; i<n; i++)
// //             {
// //                 for(int j=0; j<=1; j++)
// //                 {
// //                     dp[i][j][0] = 0;
// //                 }
// //             }
            
            
            
//             for(int ind = n-1; ind>=0; ind--)
//             {
//                 for(int canWeBuyNow = 0; canWeBuyNow<=1; canWeBuyNow++)
//                 {
//                     for(int capacity = 1; capacity <= 2; capacity++)
//                     {
//                         if(canWeBuyNow == 1)
//                         {
//                             dp[ind][canWeBuyNow][capacity] = max(-prices[ind] + dp[ind+1][0][capacity],
//                                                                 0 + dp[ind+1][1][capacity]);
//                         }
//                         else
//                         {
//                             dp[ind][canWeBuyNow][capacity] = max(prices[ind] + dp[ind+1][1][capacity-1],
//                                                                 0 + dp[ind+1][0][capacity] );
//                         }
//                     }
//                 }
//             }

//             return dp[0][1][2];
//         }
    
    
    
    
    
    
    
    
    //SPACE-OPTIMIZATION
//     int maxProfit(vector<int>& prices) 
//         {
//             int n = prices.size();
        
//             vector<vector<int>> prev(2, vector<int>(3, 0));
//             vector<vector<int>> curr(2, vector<int>(3, 0));
            
            
//             for(int ind = n-1; ind>=0; ind--)
//             {
//                 for(int canWeBuyNow = 0; canWeBuyNow<=1; canWeBuyNow++)
//                 {
//                     for(int capacity = 1; capacity <= 2; capacity++)
//                     {
//                         if(canWeBuyNow == 1)
//                         {
//                             curr[canWeBuyNow][capacity] = max(-prices[ind] + prev[0][capacity],
//                                                                 0 + prev[1][capacity]);
//                         }
//                         else
//                         {
//                             curr[canWeBuyNow][capacity] = max(prices[ind] + prev[1][capacity-1],
//                                                                 0 + prev[0][capacity] );
//                         }
//                     }
//                 }
//                 prev = curr;
//             }

//             return prev[1][2];
//         }
    
    
    
    
        /*
        
        
            we used three parameters 
            index, canweBuyNow, capacity
            
            instead of using 3 parameters, we can use 2 paramters
            
            one is for index
            second one will be transaction (instead of canWeBuyNow and capacity)
            
            transaction will take the values in the range of 0 -> 3
            
            transaction ->  0    1     2    3        4
                           buy  sell  buy  sell  that's it return
                           
            if transaction is even number, then we have to buy
            if it is odd, then we have to sell
            
            if we reached 4, then we finished two transactions, we can return from here
            
            **BASE CASE**
            
            extra base will be if transaction will be 4, return 0
        
        
        */    
    
    
    
    
    
    
    //ANOTHER APPROACH:
//     int helper(int ind, int transaction, vector<int> &prices,vector<vector<int>> &dp)
//     {
        
//         if(ind == prices.size() or transaction == 4)
//         {
//             return 0;
//         }
        
//         if(dp[ind][transaction] != -1)
//         {
//             return dp[ind][transaction];
//         }
        
        
//         if(transaction%2 == 0)
//         {
//             return dp[ind][transaction] = max(-prices[ind] + helper(ind+1, transaction+1, prices, dp),
//                    0 + helper(ind+1, transaction, prices, dp) );
//         }
//         else
//         {
//             return dp[ind][transaction] = max(prices[ind] + helper(ind+1, transaction+1, prices, dp),
//                       0 + helper(ind+1, transaction, prices, dp));
//         }
        
        
//     }
    
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(4, -1));
//         return helper(0, 0, prices, dp);    
//     }
    
    
    
    
    
    
    /*
    
        base case have to be converted, but all are initially 0, so need of explicitly, defined
        
        copy the paste recurrence relation, from the topdown, and change according to need

    
    */

        //TABULATION -> BOTTOM UP APPROACH 
    
//         int maxProfit(vector<int>& prices) 
//         {
//             int n = prices.size();
//             vector<vector<int>> dp(n+1, vector<int>(5, 0)) ;
            
//             for(int ind = n-1; ind>=0; ind--)
//             {
//                 for(int transaction = 3; transaction >= 0; transaction--)
//                 {
//                     if(transaction%2 == 0)
//                     {
//                          dp[ind][transaction] = max(-prices[ind] + dp[ind+1][transaction+1],
//                                                     0 + dp[ind+1][transaction] );
//                     }
//                     else
//                     {
//                          dp[ind][transaction] = max(prices[ind] + dp[ind+1][transaction+1],
//                                                     0 + dp[ind+1][transaction]);
//                     }
//                 }
//             }
            
//             return dp[0][0];
//         }
    
        
    
    
    
    
    
        /*
        
            instead of using 2d array, we can use 1d array        
            and change according to the need
        
        */
    
    
        //SPACE-OPTIMZATION
    
//         int maxProfit(vector<int>& prices) 
//         {
//             int n = prices.size();
//             vector<int> prev(5, 0);
//             vector<int> curr(5, 0);
            
//             for(int ind = n-1; ind>=0; ind--)
//             {
//                 for(int transaction = 3; transaction >= 0; transaction--)
//                 {
//                     if(transaction%2 == 0)
//                     {
//                          curr[transaction] = max(-prices[ind] + prev[transaction+1],
//                                                     0 + prev[transaction] );
//                     }
//                     else
//                     {
//                          curr[transaction] = max(prices[ind] + prev[transaction+1],
//                                                     0 + prev[transaction]);
//                     }
//                 }
//                 prev = curr;
//             }
            
//             return prev[0];
//         }
    
};