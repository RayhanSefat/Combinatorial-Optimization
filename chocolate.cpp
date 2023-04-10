#include<bits/stdc++.h>
using namespace std;

int const N = 1005;
int a[N][N];
int sol[N][N];

int rec(int n, int m){
        if(sol[n][m] != -1) return sol[n][m];
        if(n==0 || m==0) return 0;

        int q = -1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int op = max(rec(n -i, j) + rec(n, m-j), rec(i, m-j) + rec(n-i, m));
                q = max(q, a[i][j] + op);
            }
        }

        return sol[n][m] = q;
}

int main(){
    memset(sol, -1, sizeof sol);
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    cout << rec(n, m) << endl;

    return 0;
}
