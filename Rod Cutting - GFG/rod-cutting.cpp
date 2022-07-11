// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> dp;
  public:
    int solve(int price[], int idx, int n){
        if(idx == 0 || n == 0) return 0;
        
        if(dp[idx][n] != -1) return dp[idx][n];
        
        if(n - idx >= 0)
            return dp[idx][n] = max(price[idx - 1] + solve(price, idx, n - idx), solve(price, idx - 1, n));
        return dp[idx][n] = solve(price, idx - 1, n);
    }
    int cutRod(int price[], int n) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(price, n, n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends