/*
class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack<int> st;
		for (string str : ops) {
			if (str == "+") {
				int first = st.top();
				st.pop();
				int second = st.top();
				int newTop = first + second;
				st.push(first);
				st.push(newTop);
			}
			else if (str == "D") {
				st.push(2 * st.top());
			}
			else if (str == "C") {
				st.pop();
			}
			else {
				st.push(atoi(str.c_str()));
			}
		}
		int sum = 0;
		int size = st.size();
		for (int i = 0; i < size; i++) {
			sum += st.top();
			st.pop();
		}
		return sum;
	}
};
*/

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> score;
		for (string str : ops) {
			if (str == "+") {
				score.push_back(score[score.size() - 1] + score[score.size() - 2]);
			}
			else if (str == "D") {
				score.push_back(2 * score[score.size() - 1]);
			}
			else if (str == "C") {
				score.pop_back();
			}
			else {
				score.push_back(atoi(str.c_str()));
			}
		}
		int sum = 0;
		for (int i : score) {
			sum += i;
		}
		return sum;
	}
};