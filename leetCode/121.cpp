#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)      return 0;
        int minVal = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < size; i++) {
            maxProfit = max(maxProfit, prices[i]-minVal);
            minVal = min(minVal, prices[i]);
        }
        return maxProfit;
    }
};

int main(void) {

}