class Solution {
public:
	string removeDuplicates(string S) {
		stack<char> st;
		for (char c : S) {
			if (!st.empty() && c == st.top()) {
				st.pop();
			}
			else {
				st.push(c);
			}
		}
		string ans = "";
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};