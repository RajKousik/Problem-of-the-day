class Solution {
public:
    bool checkIfPangram(string sentence) {
  
//         unordered_set<char> st;
        
//         for(auto c : sentence)
//         {
//             st.insert(c);        
//         }
        
        //the below line do what exactly the above lines does
        
//         unordered_set<char> st(sentence.begin(), sentence.end());
        
//         return st.size() == 26;
        
        
        //SC - O(1)
        
        //using a variable for storing thier apperance of a alphabet
        // 11111111111111111111111111 - zyxw...edcba
        
        int bitHash = 0;
        
        for(auto c : sentence)
        {
            int bit = c - 'a';
            
            int num = 1 << bit;
            
            bitHash = bitHash | num;
            
        }
        
        //now we have to check that bitHash contains 26 ones or not
        // for that first left 1 by 26 and subtract one which gives 11111111111111111111111111
        //if equal it is true, else false
        
        return bitHash == (1<<26)-1;
        
    }
};