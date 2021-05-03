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

### Q26 Remove Duplicates from Sorted Array
Hint is "related topics" array and two pointers, immediately think of using left and right pointers to point at the current element

Process:
1. edge case: if size() is less than 1, then return size() directly
2. two pointers, left and right, left is the "non-duplicate element's index", right is the "current element's index"
3. loop every elements
   1. if `nums[left] == nums[right]`, means duplicate, then right pointer move forward
   2. if not, means non-duplicate, the left pointer move forward, and write the new value, then right pointer move forward
3. return `left + 1`

> One line solutions from the discussion forum: `return unique(nums.begin(),nums.end()) - nums.begin();` and `return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));`

### Q682 Baseball Game
Used **stack** and **vector** to solve this problem.

The problem's "related topics" gives "hint" to use stack, so I used stack as the first solution:
1. iterate each string in the ops
   1. match each string and push or pop in the stack
2. calculate the sum

However, stack is not easy to check the last second element, so I used vector as a second solution. Similar process as stack but easier to deal with last second element and calculating sum.

### Q1047 Remove All Adjacent Duplicates In String
Easilly think of using **stack**, but find better solution using string only fron the discussion board.

Process:
1. iterate each char in the string S
   1. if stack empty or matched top, then pop
   2. else, push
2. concat string
3. reverse string and return


> `while(!st.empty())` to iterate stack

> `reverse(char, char)` to reverse string 