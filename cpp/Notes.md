### Q20 Valid Parentheses
Easily think of using **stack** because the process is pushing to and poping from the top.
Process: 
1. if the size of the string is not even, then return false
2. for each char in the string
   1. if the char is left parentheses, then push into the stack
   2. if the char is right parentheses, then 
      1. if stack is empty, then return false
      2. if stack.top() and char is not paired, then return false
      3. else, stack.top() and char is paired, then the stack.top() is popped.
3. after finishing every char in the string, **return true if the stack is empty** 
> My first submission is wrong because of test case s="(("

> To improve, can use map for paired parentheses 

### Q682 Baseball Game
Used **stack** and **vector** to solve this problem.
The problem's "related topics" gives "hint" to use stack, so I used stack as the first solution:
1. iterate each string in the ops
2. match each string and push or pop in the stack
3. calculate the sum

However, stack is not easy to check the last second element, so I used vector as a second solution. Similar process as stack but easier to deal with last second element and calculating sum.