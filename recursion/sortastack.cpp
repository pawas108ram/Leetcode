// Sort a stack
// EasyAccuracy: 69.19%Submissions: 82K+Points: 2
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!  

// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

// Example 1:

// Input:
// Stack: 3 2 1
// Output: 3 2 1
// Example 2:

// Input:
// Stack: 11 2 32 3 41
// Output: 41 32 11 3 2
// Your Task: 
// You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

// Expected Time Complexity: O(N*N)
// Expected Auxilliary Space: O(N) recursive.

// Constraints:
// 1<=N<=100

void insert(stack<int>&s,int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return ;
    }
    int temp1=s.top();
    s.pop();
    insert(s,temp);
    s.push(temp1);
    return;
}
void SortedStack :: sort()
{
  //Your code here
  if(s.size()==0 || s.size()==1){
      return ;
  }
  int temp=s.top();
  s.pop();
  sort();
  insert(s,temp);
  return ;
  
}