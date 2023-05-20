class Solution 
{

private:
    
    bool dfs(string start, string end, unordered_map<string, vector< pair<string, double> > > &graph, 
            unordered_map<string, double> &visited, double &ans, double runningProduct)
    {
        
        
        if(start == end and graph.find(start) != graph.end())
        {
            ans = runningProduct;
            return true;
        }
        
        
        bool tempPathFound = false;
        
        visited[start] = true;
        
        
        for(int i=0; i<graph[start].size(); i++)
        {
            
            if(visited[graph[start][i].first] == false)
            {
                
                tempPathFound = dfs(graph[start][i].first, end, graph, visited, 
                                    ans, runningProduct * graph[start][i].second);
                if(tempPathFound)
                {
                    break;
                }
                
            }
            
        }
        
        
        visited[start] = false;
        
        return tempPathFound;
        
        
        
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        
        int n = equations.size();
        int q = queries.size();
        
        unordered_map<string, vector< pair<string, double> > >graph;
        unordered_map<string, double> visited;
        
        for(int i=0; i<n; i++)
        {
            graph[equations[i][0]].push_back( { equations[i][1], values[i] } );
            graph[equations[i][1]].push_back( { equations[i][0], (1/values[i]) } );
            
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
            
        }
        
        vector<double> result(q);
        
        for(int i=0; i<q; i++)
        {
            
            double ans = 1;
            double runningProduct = 1;
            
            bool isPathFound = dfs(queries[i][0], queries[i][1], graph, visited, ans, runningProduct);
            
            if(isPathFound)
            {
                result[i] = ans;
            }
            else
            {
                result[i] = -1;
            }
                
        }
        return result;
    }
};