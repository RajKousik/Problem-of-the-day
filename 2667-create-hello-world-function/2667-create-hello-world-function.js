/**
 * @return {Function}
 */
// var createHelloWorld = function() {
//     return function(...args) {
//         return "Hello World"
//     }
// };

var createHelloWorld = () => {
    return () => "Hello World";
} 

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */