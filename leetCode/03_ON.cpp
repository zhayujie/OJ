#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int count = 0;
      int start = 0;

      vector<int> pos(128, -1);
      for (int i = 0; i < s.length(); i++) {
        if (pos[s[i]] >= start) {
          start = pos[s[i]] + 1;
        }
        count = max(count, i - start + 1);
        // 更新该字符最后一次出现的位置
        pos[s[i]] = i;
      }

      return count;
    }
};

int main(void) {
  string s = "cdd";
  Solution soulution;

  cout << soulution.lengthOfLongestSubstring(s) << endl; 

  return 0;
}
