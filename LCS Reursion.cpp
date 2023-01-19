#include <bits/stdc++.h>
using namespace std;

int const MAX = 1000;
int table[MAX][MAX];
string s, t;

int dp(int m, int n){
    if(m==0 or n==0) return 0;
    if(table[m][n] != -1) return table[m][n];

    if(s[m]==t[n]) return table[m][n] = dp(m-1, n-1);

    return table[m][n] = 1 + min(dp(m-1, n), dp(m, n-1));
}

int main(){
    memset(table, -1, sizeof table);

    cin >> s >> t;

    int m = s.size();
    int n = t.size();

    cout << "LCS: ";
    cout << dp(m, n) << endl;

    return 0;
}
