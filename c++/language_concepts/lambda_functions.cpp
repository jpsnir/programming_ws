#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> // for_each expression
#include <numeric>

/* Functions that are not going to be reused;
 * short snippets of code and can be written
 * inline.
 * [ capture clause ] (parameters) -> return-type
 * {
 *  definition of method
 *  }
 */
void printVector(std::vector<int> v){
    for_each(v.begin(), v.end(), [](int i)
    {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

int main(){
    std::vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};
    printVector(v);


    // find a number greater than 5
    std::vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i)
            {
             return i > 4;
            });
    std::cout << " First number greater than 4 is :" << *p << std::endl;


    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
            {
             return a > b;
             });
    printVector(v);

    int cnt_5 = count_if(v.begin(), v.end(), [](int a)
        {
         return a >= 5;
        });

    std::cout << " The number of elements greater than or equal to 5 is:" << cnt_5 << std::endl;

    p = unique(v.begin(), v.end(), [](int a, int b){
            return a == b;
        });

    //std::cout << "Type of p: " << typeid(p).name() << "
    //and type of v.begin(): " << typeid(v.begin()).name() << "\n";

    std::cout << *p << std::endl;
    printVector(v);
    v.resize(distance(v.begin(), p));
    printVector(v);

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = std::accumulate(arr , arr + 10, 1, [](int i, int j)
            {
            return i*j;
            });
    std::cout << "Factorial of 10 is is : " << f << std::endl;

    auto square = [](int i){
        return i*i;
    };

    std::cout << " Square of 5 is : " << square(5) << std::endl;
}
