class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int, int> umap;
        
        //freq of each tasks
        for(auto it : tasks)
        {
            umap[it]++;
        }
        
        int count = 0;
        for(auto it : umap)
        {
            //if only one remaining, it can't be done, so return -1
            if(it.second == 1)
            {
                return -1;
            }
            
            //if multiple of 3, include the ans, as 3 tasks can be done in, at a same time
            if(it.second % 3 == 0)
            {
                count += (it.second/3);
            }
            else
            {
                // if tasks % 3 == 1
                // for example for 4, it can be done by pair of 2 tasks at a time
                // for example for 7, it can be done by pair of 2 tasks and 3 tasks at a time
                
                // if tasks % 3 == 2
                // for example for 5, it can be done by pair of 2 tasks and 3 tasks at a time
                // for example for 8, it can be done by pair of 3 tasks and 3 tasks at a time
                
                // so the formula is ((taskscount/3) + 1)
                count += (it.second/3 + 1);
            }
            
        }
        
        return count;
    }
};