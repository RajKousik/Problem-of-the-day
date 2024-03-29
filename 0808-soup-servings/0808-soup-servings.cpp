// class Solution {
// public:
    
//     double calculateDP (int i, int j, unordered_map<int, unordered_map<int, double>> &dp)
//     {
//             return (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] +
//                     dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) /
//                    4;
//     }
    
//     double soupServings(int n) {
//         int m = ceil(n / 25.0);
//         unordered_map<int, unordered_map<int, double>> dp;
    
//         dp[0][0] = 0.5;
//         for (int k = 1; k <= m; k++) {
//             dp[0][k] = 1;
//             dp[k][0] = 0;
//             for (int j = 1; j <= k; j++) {
//                 dp[j][k] = calculateDP(j, k, dp);
//                 dp[k][j] = calculateDP(k, j, dp);
//             }
//             if (dp[k][k] > 1 - 1e-5) {
//                 return 1;
//             }
//         }
//         return dp[m][m];
//     }
// };

class Solution {
public:
    double calculateDP (int i, int j, unordered_map<int, unordered_map<int, double>> &dp) 
    {
            if (i <= 0 && j <= 0) {
                return 0.5;
            }
            if (i <= 0) {
                return 1;
            }
            if (j <= 0) {
                return 0;
            }
            if (dp[i].count(j)) {
                return dp[i][j];
            }
            return dp[i][j] = (calculateDP(i - 4, j, dp) + calculateDP(i - 3, j - 1, dp) +
                               calculateDP(i - 2, j - 2, dp) + calculateDP(i - 1, j - 3, dp)) / 4;
        };
    
    
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;
        for (int k = 1; k <= m; k++) {
            if (calculateDP(k, k, dp) > 1 - 1e-5) {
                return 1;
            }
        }
        return calculateDP(m, m, dp);
    }
};