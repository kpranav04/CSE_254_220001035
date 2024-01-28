#include <bits/stdc++.h>
using namespace std;
//Kande's algorithm

int maxSubarraySum(vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        max_current =max(arr[i], max_current + arr[i]);
        max_global =max(max_global, max_current);
    }

    return max_global;
}

int main() {
    ifstream arrFile("input.txt");
    vector<int> arr;
    if (!arrFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    int x;
    while (arrFile >> x) arr.push_back(x);
    arrFile.close();
    int result = maxSubarraySum(arr);

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    outputFile <<"Maximum subarray sum: "<< result << endl;
    outputFile.close();
    cout << "Data has been written to output.txt." << endl;

    return 0;
}