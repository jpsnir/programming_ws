#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    // O(1) operation to add a numbers
    numbers.push_back(num);
    N++;
  }

  double findMedian() {
    // sort only when median is asked for
    // n logn
    sort_list();
    double median;
    auto it = find_element(N / 2);
    if (N % 2 == 0) {
      // access N/2 and N/2 + 1 since zero indexed
      median = 0.5 * (*it + *(it + 1));
    } else {
      median = *it;
    }

    return median;
  }

private:
  void sort_list() { sort(numbers.begin(), numbers.end()); }

  list<int>::iterator find_element(int id) {
    int counter = 0;
    list<int>::iterator it;
    for (it = numbers.begin(); it != numbers.end(); it++, counter++) {
      if (counter == id)
        break;
    }

    return it;
  }

  list<int> numbers;
  int N = 0;
};
