#include <vector>
#include <string>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * use stack to simulate process
   * */
  int calPoints(vector <string>& ops) {
    stack<int> st;
    for (int i = 0; i < ops.size(); ++i) {
      if (ops[i] == "C") st.pop();
      else if (ops[i] == "D") st.push(st.top() * 2);
      else if (ops[i] == "+") {
        int temp1 = st.top();
        st.pop();
        int temp2 = st.top() + temp1;
        st.push(temp1);
        st.push(temp2);
      } else st.push(stoi(ops[i]));
    }
    // calculate sum
    int sum = 0;
    while (st.size()) {
      sum += st.top();
      st.pop();
    }

    return sum;
  }

  /*
   * use vector
   * */
  int calPoints(vector <string>& ops) {
    vector<int> res;
    for (int i = 0; i < ops.size(); ++i) {
      if (ops[i] == "C") res.pop_back();
      else if (ops[i] == "D") res.push_back(res.back() * 2);
      else if (ops[i] == "+") {
        int temp1 = res.back();
        res.pop_back();
        int temp2 = res.back() + temp1;
        res.push_back(temp1);
        res.push_back(temp2);
      } else res.push_back(stoi(ops[i]));
    }
    // calculate sum
    int sum = 0;
    for (int i = 0; i < res.size(); ++i) {
      sum += res[i];
    }

    return sum;
  }

  /*
   * use array
   * */
  int calPoints(vector <string>& ops) {
    int array[1000]{0};
    int arrSize = 0;
    for (int i = 0; i < ops.size(); ++i) {
      if (ops[i] == "C") --arrSize;
      else if (ops[i] == "D") {
        int temp = arr[arrSize++] * 2;
        array[arrSize] = temp;
      } else if (ops[i] == "+") {
        int temp1 = array[arrSize];
        int temp2 = array[arrSize - 1];
        ++arrSize;
        array[arrSize] = temp1 + temp2;
      } else {
        ++arrSize;
        array[arrSize] = ops[i];
      }
    }
    // calculate sum
    int sum = 0;
    for (int i = 0; i < array.size(); ++i) {
      sum += array[i];
    }

    return sum;
  }
};
//leetcode submit region end(Prohibit modification and deletion)