#include <iostream>
using namespace std;



int main(void) {
  string s = "";
  int count = 1;
  int start = 0;
  int end = 0;

  if (s.length() == 0) {
    cout << 0 << endl; 
    return 0;
  }

  for (int i = 1; i < s.length(); i++) {
    for (int j = start; j < i; j++) {
      if (s[i] == s[j]) {
        int currentCount = end - start + 1;
        if (currentCount > count) {
          count = currentCount;
        }
        // cout << "start: " << start << " end: "<< end << " currentCount: " << currentCount << endl; 
        start = j + 1;
        break;
      }
    }
    end = i;
  }
  int lastCount = s.length() - start;
  if (lastCount > count) {
    count = lastCount;
  }

  cout << count << endl; 

  return 0;
}
