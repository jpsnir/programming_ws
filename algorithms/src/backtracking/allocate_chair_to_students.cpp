#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <list>
#include <stack>
/* Backtracking algorithms generates solution based on trying.
 * We generate a tree and assign each node of the tree with a solution.
 * The example we try here is assignment of chairs to students.
 * Some solutions, due to the constraints imposed by the problem,
 * turn out to be infeasible. That is where backtracking comes in. We stop the
 * generation of subtree from that node where the solution does not satisfy the
 * imposed condition. This way we are not constructing the whole solution like
 * we would have done in a brute force way and try all solutions.
 * The other nodes which remain feasible, we will keep growing them, until we
 * found the solution is infeasible.
 *
 */

/* Problem statement: Give we have n chairs (c1, c2, c3, .., cn) and n students (S1, S2, ..., SN),
 * we need to enumerate all the ways in which they can be seated.
 * The answer is n!.
 * To enumerate each combination, we use tree based approach.
 * The solution can be represented as a state space tree.
 */


int main(){
    size_t n = 3;
    std::vector<std::string> students{n,"s"};
    for (int i = 0; i < n; i++){
        std::stringstream str;
        str << "S" << i << std::endl;
        students[i] = str.str();
    }

    auto print_container = [](std::vector<std::string> &v){
        for (auto s: v){
            printf("student id: %s", s.c_str());
        }
    };

    print_container(students);

    // construct tree
    struct State{
        std::string student;
        std::list<State*> s_list;
        State(std::string student){
            this->student = student;
        }
    };

    int i = 0, j= 0;
    auto state_construction = [&students,&j](State* state){
        if (j==students.size()-1){
            // backtrack();
            State parent = find_parent(state);
            j--;
            return;
        }
        int i = j;
        auto st = new State(students[i]);
        state->s_list.push_back(st);
        j++;
    };

    auto root = new State("S");
    std::stack<std::string> st;
    for (auto s: students)
        st.push(s);

}
