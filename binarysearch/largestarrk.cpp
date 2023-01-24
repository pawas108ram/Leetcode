// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)

class Solution {
public:
   int valid(vector<int>&nums,int k,int mid){
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count++;
                sum=nums[i];
            }
           
            else{
                sum+=nums[i];
            }
        }
        return count;

    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()){
            return -1;
        }
        int high=0;
        
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
            
            
        }
        int low=*max_element(nums.begin(),nums.end());
        
        
        if(k==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1 ){
            return high;
        }
        
        
        int ans=0;
        while(low<high){
            int mid=(low+high)>>1;
            int count=valid(nums,k,mid);
            
            if(count<=k){
                ans=mid;
             high=mid;
            }
          else if(count>k){
            low=mid+1;
          }
         
           

        }
        return ans;


    }
};