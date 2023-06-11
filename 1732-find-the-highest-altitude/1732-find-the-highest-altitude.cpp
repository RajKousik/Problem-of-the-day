class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int currentAltitude = 0;
        int highestAltitude = 0;
        
        for(int i=0; i<gain.size(); i++)
        {
            currentAltitude = currentAltitude + gain[i];
            highestAltitude = max(highestAltitude, currentAltitude);
        }
        
        return highestAltitude;
        
    }
};