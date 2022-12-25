// You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure time of the ith bus. You are also given a 0-indexed integer array passengers of length m, where passengers[j] represents the arrival time of the jth passenger. All bus departure times are unique. All passenger arrival times are unique.

// You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.

// When a passenger arrives, they will wait in line for the next available bus. You can get on a bus that departs at x minutes if you arrive at y minutes where y <= x, and the bus is not full. Passengers with the earliest arrival times get on the bus first.

// More formally when a bus arrives, either:

// If capacity or fewer passengers are waiting for a bus, they will all get on the bus, or
// The capacity passengers with the earliest arrival times will get on the bus.
// Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same time as another passenger.

// Note: The arrays buses and passengers are not necessarily sorted.

 

// Example 1:

// Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
// Output: 16
// Explanation: Suppose you arrive at time 16.
// At time 10, the first bus departs with the 0th passenger. 
// At time 20, the second bus departs with you and the 1st passenger.
// Note that you may not arrive at the same time as another passenger, which is why you must arrive before the 1st passenger to catch the bus.


class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
     int bs=b.size();
     int ps=p.size();
     sort(begin(b),end(b));
     sort(begin(p),end(p));
     int prev=0;
     int j=0;int ans=0;
     for(int i=0;i<bs;i++){
         int count=0;
         while(j<ps && p[j]<=b[i] && count<c ){
             if(p[j]-prev > 1) ans = p[j]-1;
                prev=p[j] , j++ ,count++;
         }
         if(count< c && b[i]-prev>=1){
             ans=b[i];
         }

     }
     return ans;
       
    }
};