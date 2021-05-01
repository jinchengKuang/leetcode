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