class Solution {
    int getScore(vector<int> &player, int n)
    {
        int sum = 0;
        for(int i=0; i<player.size(); i++)
        {
            if(i == 0)
                sum += player[i];
            else if(i == 1)
            {
                if(player[0] == 10)
                    sum += (player[i] * 2);
                else
                    sum += player[i];
            }
            else
            {
                sum += (player[i-1] == 10 or player[i-2] == 10) ? 2 * player[i] : player[i];
            }
        }
        return sum;
    }
    
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        // int sum1 = 0, sum2 = 0;
        
        int p1Score =  getScore(player1, player1.size());
        int p2Score =  getScore(player2, player2.size());
        
        return p1Score > p2Score ? 1 : (p1Score < p2Score) ? 2 : 0;
        
    }
};