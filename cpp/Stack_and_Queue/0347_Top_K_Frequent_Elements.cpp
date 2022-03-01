#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  class mycomparison {
  public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]]++;
    }

    priority_queue < pair < int, int >, vector < pair < int, int >>, mycomparison > pri_que;

    for (auto it = map.begin(); it != map.end(); it++) {
      pri_que.push(*it);
      if (pri_que.size() > k) {
        pri_que.pop();
      }
    }

    vector<int> res;
    while (!pri_que.empty()) {
      res.push_back((pri_que.top().first));
      pri_que.pop();
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
