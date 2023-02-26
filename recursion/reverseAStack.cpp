// Reverse a Stack
// MediumAccuracy: 80.5%Submissions: 18K+Points: 4
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!  

// You are given a stack St. You have to reverse the stack using recursion.

// Example 1:

// Input:
// St = {3,2,1,7,6}
// Output:
// {6,7,1,2,3}
// Example 2:

// Input:
// St = {4,3,9,6}
// Output:
// {6,9,3,4}
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and returns the reversed stack.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= size of the stack <= 104
// -109 <= Each element of the stack <= 109
// Sum of N over all test cases doesn't exceeds 106
// Array may contain duplicate elements. 

class Solution{
public:
    void insert(stack<int>&St,int temp){
  if(St.empty()){
      St.push(temp);
      return ;
  }
     int temp1=St.top();
     St.pop();
     insert(St,temp);
     St.push(temp1);
     return ;
        
        
        
    }
    void Reverse(stack<int> &St){
        if(St.size()==1 || St.size()==0){
            return ;
        }
        int temp=St.top();
        St.pop();
        Reverse(St);
        insert(St,temp);
        
        return;
    }
};