class Solution {
public:
    
    //not using INT_MAX as we r doing INT_MAX + some value, which will give Runtime Error
    //max value
    const int MAX = 101;   
    
    //finding the length of the x
    // for example a12, here 12 is the x
    inline int find_len(int x)
    {
        if(x == 1)
        {
            return 0;
        }
        else if(x < 10)
        {
            return 1;
        }
        else if(x < 100)
        {
            return 2;
        }
        else if(x < 1000)
        {
            return 3;
        }
        return 4;
    }
    
    int solve(int index, int k, string &s, int n, vector<vector<int>> &dp)
    {
        //if no more characters can be deleted, return MAX
        if(k < 0)
        {
            return MAX;
        }
        
        //if we crossed the index, or 
        //n - index <= k, meaning -> we have 7 characters left, but our k is 8, so we can delete all the 7 characters, to get the minimum string length as possible, so return 0
        if(index >= n or n - index <= k)
        {
            return 0;
        }
        
        //memoization
        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }
        
        //holds the freqs of alphabets
        vector<int> freq(26, 0);
        int most_freq = 0;
        int ans = MAX;
        
        for(int j=index; j<n; j++)
        {
            //most freq character
            most_freq = max(most_freq, ++freq[s[j] - 'a']);
            
            // 1 -> a12 -> here that single characters occupies one space, 12 will carry will two spaces which will be calculated by find_len, 
            //then we pass the remaining string to recursion
            //j + 1->next index
            // k - (j-index+1-most) -> atmost we can k characters to delete, from that k we have deleted j - index + 1 - most
            //j - index + 1 -> gives the current length of the string 
            //from that we have used 'most' alphabets, so remaning characters is deleted.
            ans = min(ans, 1 + find_len(most_freq) + solve(j+1, k-(j-index+1-most_freq), s, n, dp) );
        }
        
        //store it in dp, and return
        return dp[index][k] = ans;
        
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        vector<vector<int>> dp(101, vector<int>(101, -1));
        
        int n = s.size();
        
        return solve(0, k, s, n, dp);
        
    }
};