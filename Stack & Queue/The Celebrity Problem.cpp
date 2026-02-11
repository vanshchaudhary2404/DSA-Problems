/* Author : Vansh Kumar
  Date : 2025-12-02
  Description: The Celebrity Problem
*/
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

//Approach 1: Brute Force
//t.c = O(n^2) and s.c = O(1)
int findCelebrity(vector<vector<int>>& M, int n) {
    for (int i = 0; i < n; i++) {

        bool isCelebrity = true;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                // If i knows j OR j does not know i
                if (M[i][j] == 1 || M[j][i] == 0) {
                    isCelebrity = false;
                    break;
                }
            }
        }

        if (isCelebrity)
            return i;
    }

    return -1;
}

int main() {

    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();

    int result = findCelebrity(M, n);

    if (result == -1)
        cout << "No Celebrity Found" << endl;
    else
        cout << "Celebrity is person: " << result << endl;

    return 0;
}



//Approach 2: Using Stack
//t.c = O(n) and s.c = O(n)
int findCelebrity(vector<vector<int>>& M, int n) {

    stack<int> st;

    // Step 1: Push all persons into stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (st.size() > 1) {

        int i = st.top();
        st.pop();

        int j = st.top();
        st.pop();

        if (M[i][j] == 1) {
            // i knows j → i cannot be celebrity
            st.push(j);
        } else {
            // i does NOT know j → j cannot be celebrity
            st.push(i);
        }
    }

    // Step 3: Potential candidate
    int celeb = st.top();

    // Step 4: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            if (M[celeb][i] == 1 || M[i][celeb] == 0)// If celeb knows someone i OR i does not know celeb
                return -1;
        }
    }

    return celeb;
}

int main() {

    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();

    int result = findCelebrity(M, n);

    if (result == -1)
        cout << "No Celebrity Found" << endl;
    else
        cout << "Celebrity is person: " << result << endl;

    return 0;
}




//Approach 3: Two Pointer
//t.c = O(n) and s.c = O(1)
int findCelebrity(vector<vector<int>>& M, int n) {
    int a = 0;
    int b = n - 1;
    // Step 1: Elimination
    while (a < b) {

        if (M[a][b] == 1) {
            // a knows b → a cannot be celebrity
            a++;
        } else {
            // a does NOT know b → b cannot be celebrity
            b--;
        }
    }

    // Step 2: Candidate
    int candidate = a;

    // Step 3: Verification
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[candidate][i] == 1 || M[i][candidate] == 0)
                return -1;
        }
    }

    return candidate;
}

int main() {

    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();

    int result = findCelebrity(M, n);

    if (result == -1)
        cout << "No Celebrity Found" << endl;
    else
        cout << "Celebrity is person: " << result << endl;

    return 0;
}
