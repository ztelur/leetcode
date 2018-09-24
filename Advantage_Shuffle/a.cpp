#include <utility>
#include <vector>
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result(B.size(), -1);

        vector<pair<int,int>> BB;
        for(int i=0; i < B.size(); i++) {
            BB.push_back(std::make_pair(B[i], i));
        }

        sort(BB.begin(), BB.end(), std::greater<pair<int,int>>());
        // 最大的
        priority_queue<int> pq;
        for (auto a : A) {
            pq.push(a);
        }

        for (int i=0; i< BB.size(); i++) {
            if (BB[i].first < pq.top()) {
                result[BB[i].second] = pq.top();
                pq.pop();
            }
        }

        if (!pq.empty()) {
            for (int i=0;i <result.size(); i++) {
                if (result[i] < 0) {
                    result[i] = pq.top();
                    pq.pop();
                }
            }
        }
        return result;
    }
};
