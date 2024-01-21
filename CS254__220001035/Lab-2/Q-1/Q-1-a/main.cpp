#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
    int m = a.size(), n = b.size();
    int i = 0, j = 0, k = 0;
    while(k < m + n) {
        if(j == n || a[i] <= b[j]) c[k] = a[i++];
        else if(i == m || b[j] <= a[i]) c[k] = b[j++];
        k++;
    }
}

int main() {
    int x; vector<int> a, b;

    ifstream array_a("../../array_a.txt");
    while(array_a >> x) a.push_back(x);
    sort(a.begin(), a.end());
    array_a.close();
   
    ifstream array_b("../../array_b.txt");
    while(array_b >> x) b.push_back(x);
    sort(b.begin(), b.end());
    array_b.close();

	int m = a.size(), n = b.size();
	vector<int> c(m + n);
	merge(a, b, c);

    ofstream outputFile("output.txt");
	for(int y : c) outputFile << y << " ";
    outputFile.close();
}