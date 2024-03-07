#include <iostream>

// linked list to represent a sparse matrix
using namespace std;

class Node{
    public:
        int row;
        int col;
        int data;
        Node *next;
};

void create_new_node(Node **p, int row_index, int col_index, int x){
    Node *temp = *p;
    Node *r;

    if (temp == NULL){
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data  = x;
        *p = temp;
    }
    else{
        while(temp->next != NULL)
            temp = temp->next;
        r = new Node();
        r -> row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

void printList(Node *start){
    Node *ptr = start;
    cout << "row col data: " ;
    while(ptr != NULL){
        cout << ptr->row << " ";
        cout << ptr->col << " ";
        cout << ptr->data << " " << endl;
        ptr = ptr->next;
    }
}

int main(){
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0},
    };

    Node *first = NULL;
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            if(sparseMatrix[i][j] != 0)
                create_new_node(&first, i, j, sparseMatrix[i][j]);
        }
    }

    printList(first);
    return 0;
}
