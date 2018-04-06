#pragma warning (disable: 4786)
#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> vec;
 
int main(void) {
    int num;
     
    cin>>num;
    int sum = 2, x = 2, count = 0, maxn = 0, start = 0;
    while (sum <= num) {
        if (num % sum == 0) {
            vec.push_back(x++);
            count++;
            sum *= x;
        }
        else {
            vec.push_back(x++);
            sum = sum / vec[start] * x;
            start++;
        }
        if (maxn < count) {
            maxn = count;
            //vec.erase(i, j);   delete the elements [i, j-1]
            if (start > 0)
                vec.erase(vec.begin(), vec.begin()+start);
            start = 0;
        }
        if (maxn == 0 && sum * sum > num) {
            printf("0\n");
            return 0;
        }
    }
    cout<<maxn<<endl;
    for (int i = 0; i < maxn-1; i++)
        cout<<vec[i]<<"*";
    cout<<vec[maxn-1]<<endl;
     
    return 0;
}
