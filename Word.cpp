#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t){
    int m = s.size();
    int n = t.size();

    int table[m+n][m+n];

    for(int i=1; i<m+n; i++){
        for(int j=1; j<m+n; j++){
            table[i][j] = 1000;
        }
    }

    table[0][0] = 0;

    for(int i=1; i<=m; i++) table[i][0] = i;
    for(int i=1; i<=n; i++) table[0][i] = i;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                table[i][j] = table[i-1][j-1];
            }else{
                if(table[i-1][j-1]<table[i][j-1] && table[i-1][j-1]<table[i-1][j]){
                    table[i][j] = 1 + table[i-1][j-1];
                }else if(table[i][j-1] < table[i-1][j]){
                    table[i][j] = 1 + table[i][j-1];
                }else{
                    table[i][j] = 1 + table[i-1][j];
                }
            }

            //cout << table[i][j] << " ";

        }
        //cout << endl;

    }

    return table[m][n];
}

int main(){
    //
    freopen("intput.txt", "r", stdin);

    cout << "Enter the number of known words: ";
    int n;
    cin >> n;
    cout << "Enter the known words:" << endl;
    string known[n+1];
    for(int i=1; i<=n; i++){
        cin >> known[i];
    }

    cout << "Enter the given word: ";
    string given;
    cin >> given;

    int mn = INT_MAX;
    string ans = "";

    for(int i=1; i<=n; i++){
        int ed = editDistance(given, known[i]);

        //cout << ed << endl;

        if(ed < mn){
            mn = ed;
            ans = known[i];
        }
    }

    cout << "Result: " << ans << endl;

    return 0;
}
