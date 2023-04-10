#include<bits/stdc++.h>
using namespace std;

int const N = 1005;
int a[N];
int sol[N];

int rec(int n){
        if(sol[n] != -1) return sol[n];
        if(n==0) return 0;

        int q = -1;
        for(int i=1; i<=n; i++){
            q = max(q, a[i] + rec(n-i));
        }

        return sol[n] = q;
}

int main(){
    memset(sol, -1, sizeof sol);
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    cout << rec(n) << endl;

    return 0;
}
