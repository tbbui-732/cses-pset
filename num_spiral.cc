#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> coord_values;

void num_spiral(ll boundary, ll top_val, ll bottom_val, ll row, ll col) {
    ll res;

    if ((boundary & 1) == 0) {
        // starts with top_val and decreases
        if (row > col) { // bottom wall
            res = top_val - col + 1;
        } else { // right wall and bottom-right corner
            res = bottom_val + row - 1;
        }
    } else {
        // starts with bottom_val and increases
        if (row > col) { // bottom wall
            res = bottom_val + col - 1;
        } else { // right wall and bottom-right corner
            res = top_val - row + 1;
        }
    }
    
    coord_values.push_back(res);
}

int main(void) {
    int num_tests;
    cin >> num_tests;
    
    for (int test=0; test<num_tests; ++test) {
        // get row and col
        ll row, col;
        cin >> row >> col;

        // determine boundary 
        ll boundary = max(row, col);

        // determine start and end vals for current boundary
        ll top_val = boundary * boundary;
        ll bottom_val = top_val - ((boundary -1) * 2);

        // print coordinate value
        num_spiral(boundary, top_val, bottom_val, row, col);
    }

    for (ll i = 0; i < coord_values.size(); ++i) {
        cout << coord_values[i] << "\n";
    }

    return 0;
}
