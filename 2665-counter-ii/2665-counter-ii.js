/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
// var createCounter = function(init) {
//     let currentCount = init;
//     return {

//         increment : function()
//         {
//             currentCount++;
//             return currentCount;
//         },
//         decrement : function()
//         {
//             currentCount--;
//             return currentCount;
//         },
//         reset : function()
//         {
//             currentCount = init;
//             return currentCount;
//         },
//     }
        
// };

var createCounter = function(init){
    
    let currentValue = init;
    
    return {
        increment : () => ++currentValue,
        decrement : () => --currentValue,
        reset : () => (currentValue = init),
    }
    
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */