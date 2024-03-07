#include <iostream>

using namespace std;

struct value_list{
    int col;
    int val;
    struct value_list *next;
};


struct row_list{
    int row;
    struct value_list *first;
    struct row_list *next;
};

void create_value_node(int data, int j, struct row_list **z){
    struct value_list *temp, *d;

    temp = new value_list();
    temp->col = j+1;
    temp->val = data;
    temp->next = NULL;

    if((*z)->first == NULL){
        (*z)->first = temp;
    }
    else{
        d = (*z)->first;
        while(d->next != NULL){
            d = d->next;
        d->next = temp;
        }
    }

}

void create_row_list(struct row_list **start, int row, int col, int sparseMatrix[4][5]){
    for (int i = 0; i < row; i++){
        struct row_list *z, *r;
        z = new row_list();
        z->row = i+1;
        z->next = NULL;
        z->first = NULL;
        if (i==0)
            *start = z;
        else{
            r = *start;
            while(r->next != NULL)
                r = r->next;
            r->next = z;
        }

        for (int j = 0; j < 5; j++){
            if (sparseMatrix[i][j] != 0){
                create_value_node(sparseMatrix[i][j], j, &z);
            }
        }
    }
}
void print_LIL(struct row_list *start){
    struct row_list *r;
    struct value_list *z;
    r = start;
    while(r != NULL){
        if(r->first != NULL){
            cout << " row =" << r->row << endl;
            z = r->first;
            while(z != NULL){
                cout << " column = " << z->col << " value=" << z->val <<endl;
                z = z->next;
            }
        }
        r = r->next;
    }
}


int main(){
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    struct row_list* start = NULL;
    create_row_list(&start, 4, 5, sparseMatrix);

    print_LIL(start);
    return 0;
}
