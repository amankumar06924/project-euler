/**
 * suppose triangle is
 *
 *        3
 *       7 4
 *      2 4 6
 *     8 5 9 3
 *
 * if we try to check all paths from top to bottom:
 *
 * 3->7->2->8
 * 3->7->2->5
 * 3->7->4->5
 * 3->7->4->9
 * ...
 *
 * number of paths grows exponentially → bad idea
 *
 * ------------------------------------------------
 * OBSERVATION
 * ------------------------------------------------
 *
 * look at second last row
 *
 *      2 4 6
 *     8 5 9 3
 *
 * from 2 we can go to
 * 8 or 5
 *
 * best choice = max(8,5) = 8
 *
 * so best path through 2 becomes
 *
 * 2 + 8 = 10
 *
 * ------------------------------------------------
 *
 * do same for entire row
 *
 *      2 4 6
 *     8 5 9 3
 *
 * 2 + max(8,5) = 10
 * 4 + max(5,9) = 13
 * 6 + max(9,3) = 15
 *
 * triangle becomes
 *
 *        3
 *       7 4
 *      10 13 15
 *
 * ------------------------------------------------
 *
 * repeat again
 *
 * 7 + max(10,13) = 20
 * 4 + max(13,15) = 19
 *
 * triangle becomes
 *
 *        3
 *       20 19
 *
 * ------------------------------------------------
 *
 * last step
 *
 * 3 + max(20,19) = 23
 *
 * answer = 23
 *
 * ------------------------------------------------
 *
 * IMPORTANT IDEA
 * each node = value + max(left_child , right_child)
 * we process from bottom to top
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int lvl;
    if (!(cin >> lvl)) return;
    vector<vector<int>> triangle(lvl);
    for (int i = 0; i < lvl; i++) {
        for (int j = 0; j <= i; j++) {
            int val; cin >> val;
            triangle[i].push_back(val);
        }
    }
    for (int i = lvl - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    cout << triangle[0][0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}