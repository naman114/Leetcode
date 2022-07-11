// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[M + 1][V + 1];
	    
	    for(int idx = 0; idx <= M; ++idx){
	        for(int sum = 0; sum <= V; ++sum){
	            if(sum == 0) dp[idx][sum] = 0;
	            
	            else if(idx == 0) dp[idx][sum] = INT_MAX - 1;
	            
	            else if(sum - coins[idx - 1] >= 0)
	                dp[idx][sum] = min(dp[idx][sum - coins[idx - 1]] + 1, dp[idx - 1][sum]);
	            
	            else 
	                dp[idx][sum] = dp[idx - 1][sum];
	        }
	    }
	    
	    return (dp[M][V] >= INT_MAX - 1 ? -1 : dp[M][V]);
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends