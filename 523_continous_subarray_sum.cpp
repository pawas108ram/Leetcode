// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:

// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.
// Note that:

// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

// Example 1:

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // curr_sum will keep track of sum from start till ith

        int curr_sum = 0;

        // declare a hashmap

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            // update curr_sum

            curr_sum += nums[i];

            // if multiple of k found 

            if(curr_sum % k == 0 && i > 0)
            {
                return true;
            }

            if(mp.count(curr_sum % k) && (i - mp[curr_sum % k] >= 2))
            {
                return true;
            }

            // if curr_sum % k is not present in map then insert it into map

            if(mp.count(curr_sum % k) == 0)
            {
                mp[curr_sum % k] = i;
            }
        }

        return false;
    }
};