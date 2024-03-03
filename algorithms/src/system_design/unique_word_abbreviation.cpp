#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
/* NOTE:
 *
 */

class ValidWordAbbr {
public:
  ValidWordAbbr(vector<string> &dictionary) {
    build_abbreviation_map(dictionary);
  }

  bool isUnique(string word) {i
    auto ab = word_abbreviation(word);
    // find ab in abbreviations
    // n string comparisons at most.
    // break if found

  }

private:
  string word_abbreviation(string word) {
    // dog - > d1g
    // f = 0, l = 2
    // it , f = 0, l = 1
    string abbr;
    int first = 0, last = word.size();
    if (last - first - 1 == 0)
      abbr = to_string(word[first]) + to_string(word[last]);
    else
      abbr = to_string(word[first]) + to_string(last - first - 1) +
             to_string(word[last]);

    return abbr;
  }

  void build_abbreviation_map(vector<string> &dictionary) {
    for (auto word : dictionary) {
      string abbr = word_abbreviation(word);
      abbreviations.push_back(abbr);
    }
  }

  // map of abbreviated to word index
  vector<string> abbreviations;
  //can store abbreviations in a trie to search faster and with less space. 
  vector<string> dictionary;
};

int main() {}
