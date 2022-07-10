// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int mod = 1e9 + 7;
	    
        int prefZero[n];
        prefZero[0] = (arr[0] == 0);
        
        for(int i = 1; i < n; ++i)
            prefZero[i] = prefZero[i - 1] + (arr[i] == 0);
        
        int dp[n + 1][sum + 1];
        
        for(int idx = 0; idx <= n; ++idx){
            for(int wt = 0; wt <= sum; ++wt){
                if(wt == 0 && idx == 0)
                    dp[idx][wt] = 1;
                    
                else if(wt == 0)
                    dp[idx][wt] = pow(2, prefZero[idx - 1]);
                
                else if(idx == 0)
                    dp[idx][wt] = 0;
                    
                else if(wt - arr[idx - 1] >= 0)
                    dp[idx][wt] = (dp[idx - 1][wt - arr[idx - 1]]%mod + dp[idx - 1][wt]%mod)%mod;
                    
                else
                    dp[idx][wt] = dp[idx - 1][wt];
            }
        }
        
        return dp[n][sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends