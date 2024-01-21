#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);  // Change the range as needed
    const int numRandomNumbers = 100000;
    ofstream array_b("array_b.txt");

    if (!array_b.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        array_b << randomNum;

        if (i < numRandomNumbers - 1) {
            array_b << ' ';
        }
    }

    array_b.close();
    cout << "Random integers have been stored in array_b.txt." << endl;

    return 0;
}
