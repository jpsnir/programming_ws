#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;



class Solution{

    // board size
    int r, c;
    vector<vector<char>> board;
    set<pair<int,int>> path;
    string word="";
public:
    Solution(const vector<vector<char>> board){
        this->r = board.size();
        this->c = board[0].size();
        //cout <<"memory ok" << endl;
        this->board.reserve(r);
        for (int i = 0; i < r; i++){
            //cout << " reserve\n";
            this->board[i].reserve(c);
            //cout << "assign\n";
            this->board[i] = board[i];
            //cout << "assigned\n";
        }
    }
    bool exist(const string &word){
        bool is_exist;
        this->word = word;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                //cout << "\n First letter search:" << board[i][j] << endl;
                is_exist = dfs(0, i, j);
                if (is_exist)
                    break;
            }
        }
        return is_exist;
    }

    bool dfs(int k, int i, int j){
        //cout <<"in dfs \n";
        // reached the end
        if (k == word.length()-1)
            return true;
        
        // out of bounds, non matching character and repeat position
        if(i<0 || j < 0 || i > r-1 || j > c-1 || 
           word[k] != board[i][j] || 
           path.find(pair<int, int>(i, j))!=path.end())
            return false;
        
        cout <<" Word character = " << word[k] << " board character = " << board[i][j] <<endl;
        path.insert(pair<int,int>(i, j));
        bool result = (dfs(k+1, i+1, j) || 
                       dfs(k+1, i-1, j) ||
                       dfs(k+1, i, j-1) || 
                       dfs(k+1, i, j+1));
        path.erase(pair<int,int>(i, j));

        return result;
    }

};

int main(){
    vector<vector<char>> board = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'},
    };

    string word = "ABCCE";
    Solution s(board);
    string result = s.exist(word)? " yes\n": " no\n";
    cout << "The word exists: " << result ;
}