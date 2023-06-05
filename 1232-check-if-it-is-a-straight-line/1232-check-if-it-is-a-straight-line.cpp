class Solution 
{
private: 
    int getDeltaX(vector<int> &a, vector<int> &b)
    {
        return a[0] - b[0];
    }
    
    int getDeltaY(vector<int> &a, vector<int> &b)
    {
        return a[1] - b[1];
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        
        int deltaX = getDeltaX(coordinates[1], coordinates[0]);
        int deltaY = getDeltaY(coordinates[1], coordinates[0]);
        
        for(int i=2; i<coordinates.size(); i++)
        {
            if((deltaY * getDeltaX(coordinates[i], coordinates[0]))
               != (deltaX * getDeltaY(coordinates[i], coordinates[0]) ))
            {
                return false;
            }
        }
        return true;
    }
};