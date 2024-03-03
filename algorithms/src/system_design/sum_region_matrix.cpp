#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

struct corner {
  int row;
  int col;
  // TODO: define the equal operator for map comparison
};
class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix) {
    this-> mat = matrix;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; i < matrix[0].size(); j++) {

        for (int k = 0; k < matrix.size(); k++) {
          for (int l = 0; l < matrix[0].size(); l++) {
            sum_map[tuple<int, int, int, int>(i, j, k, l)] = sum_block(i, j, k, l);
          }
        }
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    auto k = tuple<int,int,int,int>(row1, col1, row2, col2);
    if (sum_map.find(k) != sum_map.end()) {
      return sum_map[k];
    }
  }

private:
  vector<vector<int>> mat;
  int sum_block(int i, int j, int k, int l){
      int sum = 0;
      // rows >= i and rows <= k
      // cols >= j and col <= l
      for(auto row = i-1; row < k; row++){
          for(auto col = j-1; col < l; col++){
              sum += mat[row][col];
          }
      }
      return sum;
  };

  // r1, c1, r2, c2
  map<tuple<int, int, int, int>, int> sum_map;
};
