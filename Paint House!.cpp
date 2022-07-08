//Editorial: https://youtu.be/kh48JLieeW8 , https://www.geeksforgeeks.org/minimize-cost-of-painting-n-houses-such-that-adjacent-houses-have-different-colors/
int Solution::solve(vector<vector<int> > &arr) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (3,0));
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }
    return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}
