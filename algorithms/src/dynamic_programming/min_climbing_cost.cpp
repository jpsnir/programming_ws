#include <iostream>
#include <map>
#include <vector>

using namespace std;

int dp(std::vector<int> &cost, int state, std::map<int, int> &memo){
        if (state == 1 || state == 0){
            return 0;
        }
        if(state == 2){
            return std::min(cost[0], cost[1]);
        }

        if(memo.find(state) != memo.end()){
            return memo[state];
        }

        memo[state] = std::min(dp(cost, state - 1, memo) + cost[state - 1],
                         dp(cost, state - 2, memo) + cost[state - 2]);
        return memo[state];

    }
int dp_bottom_up(std::vector<int> &cost){
        int N = cost.size();
        int min_cost[N+1];
        min_cost[0] = 0;
        min_cost[1] = 0;
        min_cost[2] = std::min(cost[0], cost[1]);

        for (int i = 3; i < cost.size()  + 1; i++ ){
            min_cost[i] = std::min(min_cost[i-1] + cost[i-1],
                             min_cost[i-2] + cost[i-2]);
        }
        return min_cost[N];
    }
int minCostClimbingStairs(std::vector<int>& cost) {
        int state_final = cost.size();
        std::map<int, int> memo;
        return dp_bottom_up(cost);

}

int main(){
    std::vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    std::cout << " min cost of climbing stairs " << minCostClimbingStairs(cost) << std::endl;
}
