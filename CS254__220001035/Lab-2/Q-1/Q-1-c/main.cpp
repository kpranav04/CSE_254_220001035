#include <bits/stdc++.h>
using namespace std;
 
void intersection(vector<int>& a, vector<int>& b, int m, int n, vector<int>& ans) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) i++;
		else if (b[j] < a[i]) j++;
		else {
			ans.push_back(b[j]);
			i++, j++;
			while(i < m && a[i] == a[i-1]) i++;
			while(j < n && b[j] == b[j-1]) j++;
		}
	}
}

int main() {
 int x; vector<int> a, b;

    ifstream array_a("../../array_a.txt");
    while(array_a >> x) a.push_back(x);
    sort(a.begin(), a.end());
	unique(a.begin(), a.end());
    array_a.close();
   
    ifstream array_b("../../array_b.txt");
    while(array_b >> x) b.push_back(x);
    sort(b.begin(), b.end());
	unique(b.begin(), b.end());
    array_b.close();
	
	int m = a.size();
	int n = b.size();

    vector<int> ans;
 	intersection(a, b, m, n, ans);
    ofstream outputFile("output.txt");
	for(int y : ans) outputFile << y << ' ';
    outputFile.close();
}
