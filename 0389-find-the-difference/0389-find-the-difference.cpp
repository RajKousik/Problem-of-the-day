class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        
        for(char cs:s){
            ans^=cs;
        }
        for(char ct:t){
            ans^=ct;
        }
        return ans;
    }
};