#include <vector>
using namespace std;

class Solution {
public:
    // 只返回最大的收益
    int cut_rod(int p, vector<int>& B) {
        int max = -1;
        for (int i =0;i < p;i++) {
            int itr = B[i] + cut_rod(p - i, B);
            if (itr > max) {
                max = itr;
            }
        }
    }
    int memo_cut_rod(int p, vector<int>& B) {
        int max = -1;
        vector<int> r(p, 0);
        return inner_memo_cut_rod(p, B, r); 
    }

    int inner_memo_cut_rod(int p, vector<int>& B, vector<int>& mem) {
        if (mem[p] > 0) {
            return mem[p];
        }
        int max = -1;
        for (int i =0; i< p; i++) {
            int itr = B[i] + inner_memo_cut_rod(p - i, B);
            if (itr > max) {
                max = itr;
            } 
        }
        return max;   
    }

    int bottom_up_cut_rod(int p, vector<int>& B) {
        int max = -1;
        vector<int> mem(p, 0);
        for (int i =0; i< p; i++) {
            int max = -1;
            for (int j =0; j<i;j++) {
                if (max < B[j] + mem[i - j] ) {
                    max = B[j] + mem[i - j];
                }
            }
        }
    }


};