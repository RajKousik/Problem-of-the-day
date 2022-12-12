int climbStairs(int n){

        if(n <= 3) return n;
    
        int secondPrev = 2;
        int prev = 3;
        int ans;
        for(int i=4; i<=n; i++)
        {
            ans = prev + secondPrev;
            secondPrev = prev;
            prev = ans;
        }
    
        return ans;
}