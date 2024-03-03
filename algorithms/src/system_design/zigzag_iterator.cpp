#include <iostream>
#include <vector>

/* Notes: 
 * Given two vectors 
 * a = 1, 2, 3, 4, 5, 
 * b = 10, 11, 12, 13, 14
 *
 * Approach 1: using indices (i for v1, and j for v2)
 *  state variable
 *  run loop (index = 0; iterate until index M + N - 1)\
 *  
 *  next()
 *  index
 *      condition 1: i < v1.size and j < v2.size
 *          ++i when index % 2 == 1
 *          ++j when index % 2 == 0
 *      condition 2: i < v1.size
 *          i++
 *      condition 3: j < v2.size
 *          j++
 *
 * hasNext 
 *      index < M + N -1
 * Special cases: 
 *  
 */


int main(){
}
