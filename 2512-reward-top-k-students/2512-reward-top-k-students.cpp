class compare
{
    public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        
        if(a.first == b.first)
        {
            return a.second > b.second;
        }
        
        return a.first < b.first; 
    }
};

class Solution 
{
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) 
    {
        
        unordered_set<string> pos, neg;
        
        for(auto it : positive_feedback)
        {
            pos.insert(it);
        }
        for(auto it : negative_feedback)
        {
            neg.insert(it);
        }
        
        int n = report.size();
        string word = "";
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        
        for(int i=0; i < n; i++)
        {
            int score = 0;
            for(int j=0; j<report[i].size(); j++)
            {
                
                while(j<report[i].size() and report[i][j] != ' ')
                {
                    word += report[i][j];
                    j++;
                }
                
                cout<<word<<" ";
                
                if(pos.find(word) != pos.end())
                {
                    score += 3;
                }
                if(neg.find(word) != neg.end())
                {
                    score -= 1;
                }
                word="";
            }
            pq.push({score, student_id[i]});
        }
        
        vector<int> ans;

        while(k--)
        {
            cout<<pq.top().first<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        
        return ans;
        
    }
};