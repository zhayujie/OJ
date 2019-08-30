#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
      if (str[i] == ' ') {
        count++;
      }
    }
    for (int j = length-1; j >= 0; j--) {
      if (str[j] != ' ') {
        str[j+ count*2] = str[j];
      } else {
        str[count*2+j] = '0';
        str[count*2+j-1] = '2';
        str[count*2+j-2] = '%';
        count--;
      }
    } 
	}
};

int main(void) {
  Solution soulution;
  char str[17] = "We Are Happy";

  cout << strlen(str) << endl;

  soulution.replaceSpace(str, 12);
  cout << str << endl; 

  return 0;
}
