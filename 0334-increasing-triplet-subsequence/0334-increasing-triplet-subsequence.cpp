class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        //two candidates
        int x1 = INT_MAX;
        int x2 = INT_MAX;
        
        //iterate through the array
        for(auto it : nums)
        {
            if(it <= x1)    //first condidate
            {
                x1 = it;
            }                           
            else if(it <= x2 and it > x1)       //second candidate
            {
                x2 = it;
            }
            else        //third candidate so, return true
            {
                return true;
            }
        }
        //return false
        return false;
        
    }
};