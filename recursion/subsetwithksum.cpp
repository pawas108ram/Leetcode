// Perfect Sum Problem
// MediumAccuracy: 20.58%Submissions: 126K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!  

// Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10}
// Example 2:
// Input: N = 5, arr[] = {1, 2, 3, 4, 5}
//        sum = 10
// Output: 3
// Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
//              {2, 3, 5}

// Your Task:  
// You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

// Expected Time Complexity: O(N*sum)
// Expected Auxiliary Space: O(N*sum)

// Constraints:
// 1 ≤ N*sum ≤ 106
// 0<=arr[I]<=106

class Solution{

	public:
	const int mod=1e9+7;
	int solve(int arr[],int idx,int n,int sum,int s,vector<vector<int>>&dp){
	    if(s>sum)return 0;
	    if(idx==n){
	        if(sum==s)return 1;
	        else return 0;
	    }
	    if(dp[idx][s]!=-1)return dp[idx][s];
	    //take
	    s+=arr[idx];
	    int take=solve(arr,idx+1,n,sum,s,dp);
	    s-=arr[idx];
	    
	    //not take
	    int not_take=solve(arr,idx+1,n,sum,s,dp);
	    return dp[idx][s]=(take+not_take)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int s=0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,0,n,sum,s,dp);
	}
	  
};