#include<iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;
class NestedInteger{
    public:
        bool isInteger() const;
        int getInteger() const;
        const vector<NestedInteger> &getList() const;
};

class NestedIterator{
    public:
        NestedIterator(vector<NestedInteger> &nestedList){
            auto it = nestedList.begin();
            while(it != nestedList.end()){
                dfs(*it);
                it++;
            }
        }
        int next(){
            int e = flattened_list.back();
            flattened_list.pop();
            return e;
        }

        bool hasNext() {
            return flattened_list.empty();
        }

    private:
        void dfs(NestedInteger ni){
                if(ni.isInteger()){
                    flattened_list.push(ni.getInteger());
                    return;
                }
                else{
                    vector<NestedInteger> nl = it->getList();
                    for(auto ni : nl){
                        dfs(ni);
                    }
                }

        }
        queue<int> flattened_list;
        list<NestedInteger>::iterator it;
};
