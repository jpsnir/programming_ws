#include <iostream>
#include <array>

/* Recursion depends on dividing the problem upto a point that we can consider
 * only single problem and incremental step.
 * If we have max from an array of n-1 numbers and nth number, then we have to just compare
 * them to find the maximum number.
 *
 * Until we reach a single number, the max is itself
 *
 */
int max_using_recursion(int* array, int index){

    int max;
    if(index==0)
        return array[0];
    int max_subset = max_using_recursion(array, index -1);
    //array[index] is the last element of the array
    max = array[index] > max_subset ? array[index]: max_subset;
    return max;
}

int min_using_recursion(int* array, int index){

    int min;
    if(index==0)
        return array[0];
    int min_subset = min_using_recursion(array, index -1);
    //array[index] is the last element of the array
    min = array[index] < min_subset ? array[index]: min_subset;
    return min;
}

int find_max_iter(int array[],int  length){
    int maximum = 0;
    for (int i =0; i<length; i++){
        maximum = std::max(maximum, array[i]);
    }
    return maximum;
}
int main(){
    int numbers[]  = { 1,4,3,-5, -4, 8, 6,10,12,100};
    int length = sizeof(numbers)/sizeof(int);
    std::cout << " Length of numbers array = " << length << std::endl;
    int max = max_using_recursion(numbers, length-1);
    printf("Maximum number = %d \n", max);
    int min = min_using_recursion(numbers, length-1);
    printf("Minimum number = %d \n", min);
    max = find_max_iter(numbers, length);
    printf("Max number = %d \n", max);
    return 0;

}
