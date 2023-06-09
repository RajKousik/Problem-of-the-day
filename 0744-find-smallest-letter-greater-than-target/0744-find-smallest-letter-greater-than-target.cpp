class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
//         int index = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        
//         return index == letters.size() ? letters[0] : letters[index];
        
        int low = 0, high = letters.size() - 1;
        int ans = -1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(letters[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                // cout<<ans<<" ";
                high = mid - 1;
            }
            
        }
        
        return ans == -1 ? letters[0] : letters[ans];
        
    }
};