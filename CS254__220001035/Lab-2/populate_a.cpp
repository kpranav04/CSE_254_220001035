#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);  // Change the range as needed
    const int numRandomNumbers = 100000;
    ofstream array_a("array_a.txt");

    if (!array_a.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        array_a << randomNum;

        if (i < numRandomNumbers - 1) {
            array_a << ' ';
        }
    }

    array_a.close();
    cout << "Random integers have been stored in array_a.txt." << endl;

    return 0;
}
