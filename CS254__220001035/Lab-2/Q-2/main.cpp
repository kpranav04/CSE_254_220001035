#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) i++;
        else {
            int temp = a[j];
            for (int k = j; k > i; k--) a[k] = a[k - 1];
            a[i] = temp;
            i++, j++, m++;
        }
    }
}
int main() {
    int x; vector<int> a, b;

    ifstream array_a("../array_a.txt");
    while(array_a >> x) a.push_back(x);
    sort(a.begin(), a.end());
    array_a.close();
   
    ifstream array_b("../array_b.txt");
    while(array_b >> x) b.push_back(x);
    sort(b.begin(), b.end());
    array_b.close();

    vector<int> A;
    for(int y : a) A.push_back(y);
	for(int y : b) A.push_back(y);

	int n = A.size();
    int m = a.size();
	merge(A, 0, m-1, n-1);

    ofstream outputFile("output.txt");
	for(int y : A) outputFile << y << " ";
    outputFile.close();
	return 0;
}
