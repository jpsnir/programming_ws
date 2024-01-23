#include <iostream>
#include <map>
#include <ctime>
#include <chrono>
#include <string>

/* number of ways to climb stairs, given we can climb either 2 or 1 step.
 * formulated as a dp problem
 *
 */
int topdown_dp(int i, std::map<int, long> &memo){
    if (memo.find(i) != memo.end()){
        return memo[i];
    }
    if(i<=2) return i;
    int result = topdown_dp(i-1, memo) + topdown_dp(i-2, memo);
    memo[i] = result;
    return result;
}
int bottomup_dp(int i){
    int steps[i+1];
    steps[0] = 0; // same step
    steps[1] = 1; // one step
    steps[2] = 2; // 2 stairs

    for (int k = 3; k < i + 1; k++){
        steps[k] = steps[k-1] + steps[k-2];
    }

    return steps[i];
}
int main(){
    std::map<int, long> memo;
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    int result = topdown_dp(250, memo);
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::cout << " Number of stairs = " << result << std::endl;
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << " Time taken in top down approach = " << time_span.count() << std::endl;

    t1 = std::chrono::steady_clock::now();
    result = bottomup_dp(250);
    t2 = std::chrono::steady_clock::now();
    std::cout << " Number of stairs = " << result << std::endl;
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << " Time taken in bottom up approach = " << time_span.count() << std::endl;


}
