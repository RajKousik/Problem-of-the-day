class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<double, int>> adj[n];
        
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back( {succProb[i], edges[i][1]} );
            adj[edges[i][1]].push_back( {succProb[i], edges[i][0]} );
        }
        
        vector<double> maxProbabilty(n, 0.0);
        maxProbabilty[start] = 1.0;
        
        priority_queue< pair<double, int> > pq;
        pq.push({1.0, start});
        
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            
            int currNode = node.second;
            double currProbability = node.first;
            
            // cout<<currNode<<endl;
            
            if(currNode == end)
            {
                return currProbability;
            }
            
            for(auto neighbors : adj[currNode])
            {
                int nextNode = neighbors.second;
                double nextProbability = neighbors.first;
                // cout<<nextNode << " "<<nextProbability << endl;
                if(currProbability * nextProbability > maxProbabilty[nextNode])
                {
                    maxProbabilty[nextNode] = currProbability * nextProbability;
                    pq.push( {maxProbabilty[nextNode] , nextNode} );
                }
                
            }
            
        }
        return 0.0;
    }
};