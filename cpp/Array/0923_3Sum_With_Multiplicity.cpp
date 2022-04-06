#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  /*
   * two pointers
   * [1,1,2,2,3,3,4,4,5,5], target = 8
   * use hash table to store: key: element and value: count of element
   * skip duplicated element
   * find all the unique combinations
   * use math to calculate
   * */
  int threeSumMulti(vector<int>& arr, int target) {
    vector <vector<int>> path;
    // 1. use hash table to store: key: element and value: count of element
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); ++i) {
      int key = arr[i];
      if (map.find(key) != map.end()) ++map[key];
      else map[key] = 1;
    }
    // 2. sort the arr to prepare for two pointers
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    // 3. iterate the arr
    for (int i = 0; i < arr.size(); ++i) {
      // 3.2 now i is fixed, left and right is moving
      int left = i; // consider case [2,2,4]
      int right = arr.size() - 1;
      while (left <= right) { // consider case [2,3,3]
        if (arr[i] + arr[left] + arr[right] > target) right--;
        else if (arr[i] + arr[left] + arr[right] < target) left++;
        else {
          path.push_back({arr[i], arr[left], arr[right]});
          left++;
        }
      }
    }
    // 4. use math to calculate
    unsigned long result = 0;
    unsigned long mod = 1e9 + 7;
    for (int i = 0; i < path.size(); ++i) {
      unsigned long first = path[i][0], second = path[i][1], third = path[i][2];
      unsigned long count = map[second];
      // 4.1 in the path, first is equal to second element
      if (first == second && second == third) {
        if (count < 3) continue;
        else result += ((count * (count - 1) * (count - 2)) / 6) % mod;

      } else if (first == second) { // first == second
        if (count < 2) continue;
        else result += ((count * (count - 1)) / 2 * map[third]) % mod;
      } else if (second == third) { // second == third
        if (count < 2) continue;
        else result += ((count * (count - 1)) / 2 * map[first]) % mod;
      } else { // first != second != third
        result += (map[first] * map[second] * map[third]) % mod;
      }
    }

    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)