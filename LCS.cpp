#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int m = s.size();
    int n = t.size();

    int table[m+2][n+2];
    memset(table, 0, sizeof table);

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    cout << "Longest common subsequence lenth: " << table[m][n] << endl;

    int i=m, j=n;

    string ans;

    char x[ table[m][n] ];
    int idx = table[m][n] - 1;

    while(i>0 and j>0){
        if(s[i-1] == t[j-1]){
           x[idx] = s[i-1];
           idx--;
           i--;
           j--;
        }else if(table[i-1][j] > table[i][j-1]) i--;
        else j--;
    }

    cout << "The sequence is ";
    for(int i=0; i<table[m][n]; i++){
        cout << x[i];
    }
    cout << endl;

    return 0;
}
