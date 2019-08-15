#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int start = 0;
        int end = 0;
      
        for (int i = 1; i < s.length(); i++) {
          for (int j = start; j < i; j++) {
            if (s[i] == s[j]) {
              int currentCount = end - start + 1;
              if (currentCount > count) {
                count = currentCount;
              }
              start = j + 1;
              break;
            }
          }
          end = i;
        }
        int lastCount = s.length() - start;
        count = max(lastCount, count);
        return count;
    }
};

int main(void) {
  string s = "abcabcbb";
  Solution soulution;

  cout << soulution.lengthOfLongestSubstring(s) << endl; 

  return 0;
}
