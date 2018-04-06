#pragma warning (disable: 4786)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct info {
    int id;				//申请者序号（防止因排序打乱）
    int ge, gi;
    int school[5];		//申请者志愿
} applicant;
applicant a[40000];
int quota[100];
bool comp(applicant v, applicant w);
bool comp_id(applicant v, applicant w);

int main(void) {
    int n, m, k, i, j;
    
    cin >> n >> m >> k;
    vector<vector<applicant> > vec(m);						//注意后面的> >之间的空格，没有空格vc6++会认为是>>号
    for (i = 0; i < m; i++)
        cin >> quota[i];
    for (i = 0; i < n; i++) {
        a[i].id = i;
        cin >> a[i].ge >> a[i].gi;
        for (j = 0; j < k; j++)
            cin >> a[i].school[j];
    }
    sort(a, a + n, comp);
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            int id = a[i].school[j];						//成绩排行第i的申请者的第j个志愿的学校
            if (quota[id] > 0) {
                vec[id].push_back(a[i]);
                quota[id]--;
                break;
            }
            else if (quota[id] == 0) {
                //这里有陷阱，因为数组a已经排序过，要进行比较的是id为t的人，而a[t]是排名为t的人
            // int t = vec[id].back();						//序号为id的学校录取的成绩最低的同学
                applicant t = vec[id].back();
                if (a[i].ge == t.ge && a[i].gi == t.gi) {	//成绩相同则完全相同
                    vec[id].push_back(a[i]);
                    break;
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (vec[i].size() == 0) {
            cout << "\n";
            continue;
        }
        sort(vec[i].begin(), vec[i].end(), comp_id);		//对容器中的学生序号进行排序
        cout << vec[i][0].id;
        for (j = 1; j < vec[i].size(); j++)
            cout << " " << vec[i][j].id;					//输出的是id
        cout << endl;
    }

    return 0;
}

bool comp(applicant v, applicant w) {
    if (v.ge + v.gi == w.ge + w.gi)
        return v.ge > w.ge;
    return (v.ge + v.gi) > (w.ge + w.gi);
}

bool comp_id(applicant v, applicant w) {
    return v.id < w.id;
}
