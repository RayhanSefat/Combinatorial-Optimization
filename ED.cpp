#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int m = s.size();
    int n = t.size();

    int table[m+2][n+2];

    table[0][0] = 0;

    for(int i=1; i<=n; i++) table[i][0] = i;
    for(int i=1; i<=m; i++) table[0][i] = i;

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

            cout << table[i][j] << " ";
        }

        cout << endl;
    }

    cout << "Edit distance: " << table[m][n] << endl;

    stack<string>st;

    cout << "Steps: " << endl;

    int i=m, j=n;
    while(i>0 and j>0){
        if(s[i-1] == t[j-1]){
            i--;
            j--;
        }else{
            if(table[i][j] == 1 + table[i-1][j]){
                i--;
                st.push("Insert");
            }
            if(table[i][j] == 1 + table[i][j-1]){
                j--;
                st.push("Delete");
            }
            else{
                i--;
                j--;
                st.push("Substitute");
            }
        }
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
