#include <cstdio>
#include <iostream>
#include <queue>

void floodFill(int *arr, int i, int j, int dstColor) {
  int C_MAX = 9;
  int R_MAX = 8;
  int currentColor = *(arr + (C_MAX-1)*i + j);
  std::queue<std::pair<int, int>> elementLoc;
  elementLoc.push(std::pair<int, int>(i, j));
  while (!elementLoc.empty()) {
    // change the color of current element
    *(arr+ (C_MAX - 1)*i + j) = dstColor;

    // Find neighbors with same color
    // check top
    if (*(arr + (C_MAX - 1)*(i - 1) + j) == currentColor)
      elementLoc.push(std::pair<int, int>(i - 1, j));
    // right
    if (*(arr + (C_MAX - 1)*i + j + 1) == currentColor)
      elementLoc.push(std::pair<int, int>(i, j + 1));

    // bottom
    if (*(arr + (C_MAX -1)*(i + 1) +  j) == currentColor)
      elementLoc.push(std::pair<int, int>(i + 1, j));

    // left
    if (*(arr + (C_MAX-1)* i + j-1) == currentColor)
      elementLoc.push(std::pair<int, int>(i, j - 1));
    // pop front
    elementLoc.pop();
    std::pair<int, int> location = elementLoc.front();
    // reassign i and j to update color.
    i = location.first;
    j = location.second;
  }
}

void floodFill1(int arr[][8], int i, int j, int dstColor) {
  int C_MAX = 9;
  int R_MAX = 8;
  int currentColor = arr[i][j];
  std::queue<std::pair<int, int>> elementLoc;
  elementLoc.push(std::pair<int, int>(i, j));
  while (!elementLoc.empty()) {
    // change the color of current element
    arr[i][j] = dstColor;

    // Find neighbors with same color
    // check top
    if (arr[i - 1][j] == currentColor)
      elementLoc.push(std::pair<int, int>(i - 1, j));
    // right
    if (arr[i][j + 1] == currentColor)
      elementLoc.push(std::pair<int, int>(i, j + 1));

    // bottom
    if (arr[i + 1][j] == currentColor)
      elementLoc.push(std::pair<int, int>(i + 1, j));

    // left
    if (arr[i][j-1] == currentColor)
      elementLoc.push(std::pair<int, int>(i, j - 1));
    // pop front
    elementLoc.pop();
    std::pair<int, int> location = elementLoc.front();
    // reassign i and j to update color.
    i = location.first;
    j = location.second;
  }
}

int main() {
  int arr[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0},
                   {1, 0, 0, 1, 1, 0, 1, 1}, {1, 2, 2, 2, 2, 0, 1, 0},
                   {1, 1, 1, 2, 2, 0, 1, 0}, {1, 1, 1, 2, 2, 2, 2, 0},
                   {1, 1, 1, 1, 1, 2, 1, 1}, {1, 1, 1, 1, 1, 2, 2, 1}};
  for (int i = 0; i < 8; i++){
      printf("\n");
      for(int j = 0; j < 8; j++){
          printf("%d,",arr[i][j]);
      }
  }
  int *b = (int*)arr;
  printf("pointer based value arr[i][j] = %d, %d %d\n ", arr[4][3], *(b+8*4+3), *(b+7*4+3));
  std::cout << " \nAfter flood fill" << std::endl;
  int X = 4, Y = 4, C = 3;
  floodFill1(arr, X, Y, C);
  for (int i = 0; i < 8; i++){
      printf("\n");
      for(int j = 0; j < 8; j++){
          printf("%d,",arr[i][j]);
      }
  }

}
