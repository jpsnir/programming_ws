#include<iostream>
#include<vector>
using namespace std;


class Solution {

public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &area){
        int M = grid.size();
        int N = grid[0].size();
        grid[i][j] = 0;
        area++;
        // left most
        if(i - 1 >= 0 && grid[i-1][j] == 1) dfs(grid, i - 1, j, area);
        if(i + 1 <= M - 1 && grid[i+1][j] == 1) dfs(grid, i + 1, j, area);
        if(j - 1 >= 0 && grid[i][j-1] == 1) dfs(grid, i, j - 1, area);
        if(j + 1 <= N - 1 && grid[i][j+1] == 1) dfs(grid, i, j + 1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i <grid.size(); i ++){
            for(int j =0 ; j < grid[0].size(); j ++){
                int area = 0;
                if(grid[i][j] == 1){

                    dfs(grid, i, j, area);
                }
                if (max_area <= area){
                    cout << "max area: " <<  max_area << endl;
                    max_area = area;
                }
            }
        }
        return max_area;
    }
};
