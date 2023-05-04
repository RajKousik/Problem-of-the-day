class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        int n = senate.size();
        
        queue<int> rSenator;
        queue<int> dSenator;
        
        // vector<int> banned(n, false);
        
        for(int i=0; i<n; i++)
        {
            if(senate[i] == 'R')
            {
                rSenator.push(i);
            }
            else
            {
                dSenator.push(i);
            }
        }
        
        
        
        while(!rSenator.empty() and !dSenator.empty())
        {
            
            int rTurn = rSenator.front();
            rSenator.pop();
            
            int dTurn = dSenator.front();
            dSenator.pop();
            
            if(rTurn < dTurn)
            {
                rSenator.push(rTurn + n);
            }
            else
            {
                dSenator.push(dTurn + n);
            }
            
        }
        
        
        return rSenator.empty() ? "Dire" : "Radiant";
        
    }
};