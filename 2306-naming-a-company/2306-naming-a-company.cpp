class Solution {
public:
    long long distinctNames(vector<string>& ideas)
    {
        
        unordered_set<string> seen[26];
        
        for(auto idea : ideas)
        {
            seen[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        long long answer = 0;
        
        for(int i=0; i<25; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                
                int mutual = 0;
                
                for(auto idea : seen[i])
                {
                    if(seen[j].count(idea))
                    {
                        mutual++;
                    }
                }
                
                answer += 2LL * (seen[i].size() - mutual) * (seen[j].size() - mutual);
                
            }
        }
        
        return answer;
        
    }
};