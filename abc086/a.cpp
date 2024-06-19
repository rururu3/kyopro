#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t A, B;
    cin >> A >> B;

    cout << ((A * B) % 2 ? "Odd": "Even") << endl;

    return(0);
}