// class comp
// {
//     public:
//     bool operator()(const string_view a, const string_view b) const 
//     {
//         return a.size() > b.size();

//     }
// };


class Solution 
{
public:
    
    
    
    string largestWordCount(vector<string>& messages, vector<string>& senders)
    {
        unordered_map<string, int> mp;
        
        int n = messages.size();
        
        string ans;
        int highFreq = 0;
        
        for(int i=0; i<n; i++)
        {
            string message = messages[i];
            
            int words = 0;
            for(auto it : message)
            {
                if(it == ' ')
                {
                    words++;
                }
            }
            words++;
            
            mp[senders[i]] += words;
            
            int total = mp[senders[i]];
            
            if(total > highFreq or (total == highFreq and senders[i] > ans))
            {
                highFreq = total;
                ans = senders[i];
            }
            
            
        }
        return ans;
        
        
//         for(auto it : mp)
//         {
//             cout<<it.first<<" "<<it.second<<endl;
//             if(it.second > highFreq)
//             {
                
//                 highFreq = it.second;
//                 ans = it.first;
                
//             }
//         }
        
        // return ans;
        
    }
};