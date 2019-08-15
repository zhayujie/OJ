#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int start = 0;
      
        for (int i = 0; i < s.length(); i++) {
          for (int j = start; j < i; j++) {
            if (s[i] == s[j]) {
              start = j + 1;
              break;
            }
          }
          count = max(i - start + 1, count);
        }
        return count;
    }
};

int main(void) {
  string s = "abcabcbb";
  Solution soulution;

  cout << soulution.lengthOfLongestSubstring(s) << endl; 

  return 0;
}
