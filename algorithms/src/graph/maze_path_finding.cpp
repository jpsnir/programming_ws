#include <vector>
using namespace std;
#include <limits.h>

class Solution {
public:

    int dp(vector<vector<int>>& maze, vector<int> &start, vector<int>& destination, map<pair<vector<int, int> , vector<int,int>>, int > &memo ){
        return 0;
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

       vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));

       distance[start[0]][start[1]] = 0;
       dfs(maze, start, distance);
       return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];


    }

    void dfs(vector<vector<int>>& maze, vector<int> start, vector<vector<int>> &distance){
        vector<vector<int>> dirs = {
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0},
        };

        for (vector<int> dir : dirs){
            int x = start[0] + dir[0];
            int y = start[1] + dir[1];
            int count = 0;
            while(x>=0 && y >= 0 && x < maze.size() &&
            y < maze[0].size() && maze[x][y] == 0){
                x += dir[0];
                y += dir[1];
                count ++;
            }
            if (distance[start[0]][start[1]] + count  <  distance[x-dir[0]][y-dir[1]]){
                distance[x - dir[0]][y -dir[1]] = distance[start[0]][start[1]] + count;
                vector<int> new_start = {x -dir[0], y - dir[1]};
                dfs(maze, new_start, distance);
            }
        }
    }
};
