#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> a;

    ifstream array_a("../array_a.txt");
    while(array_a >> x) a.push_back(x);
    array_a.close();
    int n  = a.size();
    
    int first_minima = INT_MAX, second_minima = INT_MAX;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] < first_minima) {
            second_minima = first_minima;
            first_minima = a[i];
            continue;
        }
        if(a[i] < second_minima) second_minima = a[i];
    }

    ofstream outputFile("output.txt");
    outputFile << "First minima : " << first_minima << "\n";
    outputFile << "Second minima : " << second_minima << "\n";
}