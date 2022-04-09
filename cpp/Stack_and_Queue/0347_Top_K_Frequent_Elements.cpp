#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * use hash map to count the elements
   * use min heap to keep the top Kth element in the heap
   * */
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // map: key->element's value; value->element's count
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      map[nums[i]]++;
    }

    // customize min heap comparator (> is min heap)
    struct myComparison {
      bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
      }
    };

    // heap
    priority_queue < pair < int, int >, vector < pair < int, int >>, myComparison > pq;

    // push into pq, if size of pq is larger than k, pop the top i.e. min
    for (auto& p: map) {
      pq.push(p);
      if (pq.size() > k) pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top().first);
      pq.pop();
    }
    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
