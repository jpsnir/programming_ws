#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<vector<char>> board = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'},
};

string word = "ABCCE";

class Solution{

    // board size
    int r, c;
    set<pair<char, char>> path;
    Solution();
    bool exist(const vector<vector<char>> &board, const string &word){
        this->r = board.size();
        this->c = board[0].size();
         
    }

};