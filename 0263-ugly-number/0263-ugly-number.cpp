class Solution {
public:
    bool isUgly(int n) {
       // int a[3]={2,3,5};
       //  if(n<=0)
       //      return false;
       //  for(int i=0;i<3;i++){
       //      while(n%a[i]==0){
       //          n = n/a[i];
       //      }
       //  }
       //  return n==1;
        
        if(n <= 0)
        {
            return false;
        }
        
        for(auto it : {2,3,5})
        {
            n = keepDividing(n, it);
        }
        
        return n == 1;
        
    }
    
    int keepDividing(int n, int it)
    {
        while(n % it == 0){
            n /= it;   
        }
        
        return n;
    }
};