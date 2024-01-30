'''
depth first traversal of 2D array,

@author: jagatpreet
@adapted : geekforgeeks

'''

ROW = 3
COL = 3

dRow = [0, 1, 0, -1]
dCol = [-1, 0, 1, 0]
vis = [[False for i in range(3)] for j in range(3)]
output = []


def is_valid(row, col):
    global ROW
    global COL
    global vis

    if (row < 0 or col < 0 or row >= ROW or col >= COL):
        return False

    if (vis[row][col]):
        return False

    return True


def DFS(row, col, grid):
    global dRow
    global dCol
    global vis

    # stack
    st = []
    st.append([row, col])
    while len(st) > 0:
        curr = st[len(st) - 1]
        st.remove(st[len(st) - 1])
        row = curr[0]
        col = curr[1]

        if (not is_valid(row, col)):
            print(f'[{row}, {col}] - invalid')
            continue

        print(f'[{row}, {col}] - valid')
        vis[row][col] = True
        output.append(grid[row][col])

        for i in range(4):
            adjx = row + dRow[i]
            adjy = col + dCol[i]
            st.append([adjx, adjy])
        print(st)


def print_output():
    global output
    for elem in output:
        print(elem, end=",")


if __name__ == "__main__":
    grid = [[-1, 2, 3],
            [0,  9, 8],
            [1, 0, 1]]
    DFS(0, 0, grid)
    print_output()
    print("\n")
