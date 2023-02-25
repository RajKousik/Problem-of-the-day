class Solution {
public:
    int maxProfit(vector<int>& prices) {

        
//             int buyingPrice = INT_MAX;
//             int maxProfit = 0;
        
//             //First, we consider the buying prices as high as possible(INT_MAX)
//             //At each point we will check whether current price was lesser than our buyingPrice
//             //If it is lesser we will change our buying price to current price
            
//             //Then at each iteration, we try to sell the product, and find the profit at that stage
//             //If that profit was greater than the max profit, we will update our max profit
//             //atlast maxprofit gives the overall best profit
        
//             //iterate over the array and in each iteration check whether curr price is lesser than buying price. if yes, change, else carry on.
//             //check what is the profit, if we sell our product at this point, and compare with max profit, if greater than change max profit to profitNow
            
//             for(int i=0; i<prices.size(); i++)
//             {
//                 if(prices[i] < buyingPrice)
//                 {
//                     buyingPrice = prices[i];
//                 }
                
//                 int profitNow = prices[i] - buyingPrice;
                
//                 maxProfit = max(maxProfit, profitNow);
//             }
//         return maxProfit;
        
        int buyingPrice = INT_MAX;
        int maxP = 0;
        int n = prices.size();
        
        for(int i=0; i<n; i++)
        {
            
            buyingPrice = min(buyingPrice, prices[i]);
            maxP = max(maxP, prices[i] - buyingPrice);
            
        }   
        
        return maxP;
    }
};