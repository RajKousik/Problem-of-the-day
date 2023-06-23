class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int, int> reminderFrequency;
        
        for(int num : arr)
        {
            //to handle negative numbers
            reminderFrequency[((num % k) + k) % k]++;
        }
        
        for(int num : arr)
        {
            
            int reminder = ((num % k) + k) % k; 
            
            if(reminder == 0)
            {
                if(reminderFrequency[0] % 2 == 1)
                {
                    return false;
                }
            }
            else
            {
                if(reminderFrequency[reminder] != reminderFrequency[k - reminder])
                {
                    return false;
                }
            }
        
        }
        
        return true;
        
    }
};