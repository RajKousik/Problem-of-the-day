class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<int> indexes;

        for(int i=0; i<plantTime.size(); i++)
        {
            indexes.push_back(i);
        }

        
        sort(indexes.begin(), indexes.end(), [&](int i, int j){return growTime[i] > growTime[j];});
        
        int currTime = 0,maxTime=0; 
        
        
        
        for(auto it : indexes)
        {
            currTime += plantTime[it];
            maxTime = max(maxTime, currTime + growTime[it]);
        }

        return maxTime;
    }
};