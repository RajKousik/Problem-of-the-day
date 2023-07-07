class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.size();
        int maxSize = k;
        unordered_map<char, int> umap;
        
        for(int i=0; i<k; i++)
        {
            umap[answerKey[i]]++;        
        }
        
        int leftPtr = 0, rightPtr = k;
        
        while(rightPtr < n)
        {
            umap[answerKey[rightPtr]]++;
            
            while(min(umap['T'], umap['F']) > k)
            {
                umap[answerKey[leftPtr]]--;
                leftPtr++;
            }
            
            maxSize = max(maxSize, rightPtr - leftPtr + 1);
            rightPtr++;
        }
        
        return maxSize;
        
    }
};