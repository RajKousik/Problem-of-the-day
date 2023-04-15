/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    
    //kadane's algorithm
    
    let maximumSum = -Infinity;
    let currentSum = 0;
    
    for(let it of nums)
    {
        currentSum = Math.max(currentSum + it, it);
        maximumSum = Math.max(maximumSum, currentSum);
    }
    return maximumSum;
    
};