class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		int idx1 = 0, idx2 = 0;
		vector<int> ret;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (nums[i] + nums[j] == target) {
					idx1 = i;
					idx2 = j;
					ret.push_back(idx1);
					ret.push_back(idx2);
					return ret;
				}
			}
		}
		return ret;
	}
};