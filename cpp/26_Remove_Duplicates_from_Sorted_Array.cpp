class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) {
			return nums.size();
		}
		int left = 0;
		int right = 1;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[left] == nums[right]) {
				right += 1;
			}
			else {
				left += 1;
				nums[left] = nums[right];
				right += 1;
			}
		}
		return left + 1;
	}
};