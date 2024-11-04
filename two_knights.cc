#include <iostream>
#include <cstdint>

using namespace std;
#define ul uint64_t

int main(void) {
    short int num_moves;
    cin >> num_moves;

    for (short int n = 1; n <= num_moves; ++n) {
        ul total_positions = ((ul)(n*n) * (n*n-1)) / 2; // cast from short to long to prevent integer overflow
        ul attack_positions = 4*(n-1)*(n-2);
        cout << total_positions-attack_positions << '\n';
    }

    return 0;
}
