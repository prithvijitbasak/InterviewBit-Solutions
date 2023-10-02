//Editorial: In the solution.
int Solution::solve(vector<int> &arr, int k) {
    int ans = 0;
    map<int,int> mp;
    int xorVal = 0, n = arr.size();
    for(int i=0;i<n;i++)
    {
        // the main intuition behind this is 
        // we need to find the frequencies of (xorVal ^ k)
        // at every indexes 
        // and suppose at any index the sum becomes equal
        // to k then just directly update the ans by 1
        // because if the array is 4 2 2 6 4
        // and k is 6
        // what we are doing is that we are playing with the property of xor
        // because the 
        // a ^ b = c
        // then b ^ a = c
        // the a^c = b
        // so if we find any frequency of xorVal ^ K then increment by 1
        // this problem is same as subarray sum equals to k.
        
        xorVal ^= arr[i];
        if(xorVal == k)
            ans += 1;
        ans += mp[xorVal ^ k];
        mp[xorVal] += 1;
    }
    return ans;
}
