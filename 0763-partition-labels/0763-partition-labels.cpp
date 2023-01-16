class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int lastOccurence[26] = {0};
        
        for(int i=0; i<s.size(); i++)
        {
            lastOccurence[s[i] - 'a'] = i;
        }
        
        int startPos = 0;
        int endPos = 0;
        vector<int> ans;
        
        for(int i=0; i<s.size(); i++)
        {
            endPos = max(endPos, lastOccurence[s[i] - 'a']);
            
            if(i == endPos)
            {
                ans.push_back(i - startPos + 1);
                startPos = i + 1;
            }
            
        }
        
        return ans;
        
    }
};