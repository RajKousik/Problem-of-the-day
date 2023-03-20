class Solution {
public:
//     int findMaxForm(vector<string>& strs, int m, int n) 
//     {
//         int s = strs.size();
//         vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(s, -1)));
//         return helper(strs, m, n, 0, dp);
        
//     }
    
//     int helper(vector<string> str, int zeros, int ones, int ind, vector<vector<vector<int>>> &dp)
//     {
//         if(ind == str.size() or (zeros == 0 and ones == 0))
//         {
//             return 0;
//         }
        
//         if(dp[zeros][ones][ind] != -1)
//         {
//             return dp[zeros][ones][ind];
//         }
        
//         string temp = str[ind];
//         int zerosInString = 0, onesInString = 0;
        
//         for(auto it : temp)
//         {
//             if(it == '0')
//             {
//                 zerosInString++;
//             }
//             else
//             {
//                 onesInString++;
//             }
//         }
        
//         int pick = 0;
        
//         if(zerosInString <= zeros and onesInString <= ones)
//         {
//             pick = 1 + helper(str, zeros - zerosInString, ones - onesInString, ind + 1, dp);
//         }
        
//         int notPick = helper(str, zeros, ones, ind + 1, dp);
        
//         return dp[zeros][ones][ind] = max(pick, notPick);
        
//     }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int s = strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(string temp : strs)
        {
            int zerosInString = 0, onesInString = 0;
            for(auto it : temp)
            {
                if(it == '0')
                {
                    zerosInString++;
                }
                else
                {
                    onesInString++;
                }
            }

            for(int zeros = m; zeros >= zerosInString; zeros--)
            {
                for(int ones = n; ones >= onesInString; ones--)
                {
                    dp[zeros][ones] = max(dp[zeros][ones], 1 + dp[zeros - zerosInString][ones - onesInString] );
                }
            }
        }
        
        
        return dp[m][n];
        
    }
    
};