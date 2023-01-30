class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
            vector<int> mp(256, -1);
            int left = 0;
            int right = 0;
            int len = 0;
            int n = s.size();
        
            while(right < n)
            {
                
                if(mp[s[right]] != -1)
                {
                    left = max(left, mp[s[right]] + 1);  // to understand use testcase "abba"
                }
                mp[s[right]] = right;
                len = max(len, right - left + 1);
                right++;
            }
            
        return len;
        
        
        
//         unordered_map<char, int> mp;
//         int left = 0, right = 0;
//         int len = 0;
//         int n = s.size();
        
//         while(right < n){
            
//             if(mp.find(s[right]) != mp.end()) 
//             {
//                 left = max(mp[s[right]] + 1, left);
//             }
//             mp[s[right]] = right;
//             len = max(len, right - left + 1);
//             right++;
//         }
//         return len;
        
        //use first approach better time complexity :)
    }
};