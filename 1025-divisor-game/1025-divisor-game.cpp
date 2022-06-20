/*
TC: O(n root(n))
SC: O(N)
*/
class Solution {
public:
    vector<int> getDiv(int n){
        vector<int> div;
        
        for(int i = 1; i * i <= n; ++i){
            if(n % i == 0){
                if(n / i != i && n / i != n)
                    div.push_back(n/i);
                div.push_back(i);
            }
        }
        return div;
    }
    
    bool divisorGame(int n) {
        // dp[i] represents losing/winning state for whichever player with i coins
        // and if the game starts with i coins
        int dp[n + 1];
        // If there are no coins left at the table, whoever's turn it is loses
        dp[1] = 0;
        
        for(int i = 2; i <= n; ++i){
            dp[i] = 0;
            vector<int> divs = getDiv(i);
            for(int div: divs){
                if(i - div >= 1 && dp[i - div] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        for(int i: dp) cout<<i<<endl;
        return dp[n];    
    }
};

// bool divisorGame(int n) {
//     int dp[n+1];
//     memset(dp,0,sizeof(dp));
//     for(int i=2;i<n+1;i++){
//         for(int j=1;j<i;j++){
//             if(i%j==0)dp[i] = dp[i] | !dp[i-j];  //(!dp[i-j] checks if i-j is a losing position)
//         }
//     }return dp[n];
// }