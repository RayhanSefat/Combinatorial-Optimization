#include <bits/stdc++.h>
using namespace std;

int const MAX = 1005;
int n;
int p[MAX];
int track[MAX];
int cut_lenth[MAX];

int dp(int n){
    if(n==0) return 0;
    if(track[n] != -1) return track[n];

    int ans = -100;

    for(int i=1; i<=n; i++){
        int profit = p[i] + dp(n-i);

        if(profit > ans){
            ans = profit;
            cut_lenth[n] = i;
        }
    }

    return track[n] = ans;
}

int main(){
    cout << "Enter the lenth of rod: ";
    int n; cin >> n;
    cout << "Enter the profts:\n";
    for(int i=1; i<=n; i++) cin >> p[i];

    memset(track, -1, sizeof track);

    cout << "The maximum profit is: " << dp(n) << endl;

    cout << "Cut lenths: ";
    int i = n;
    while(i>0){
        cout << cut_lenth[i] << " ";
        i -= cut_lenth[i];
    }
    cout << endl;

    return 0;
}
