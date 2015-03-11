#include "../header.h"
/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

**/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m<1||n<1) {
        	return 0;
        }
        if (m==1||n==1) {
            return 1;
        }
        int cur;
        int pre;
        int upline[n];
        for(int i=1;i<=m;i++) {
            if (i==1) {
                pre=1;
            } else {
                pre=0;
            }
        	for (int j=1;j<=n;j++) {
        		if (i==1) {
        			upline[j]=0;
        		}
        		cur=pre+upline[j];
        		pre=cur;
        		upline[j]=cur;
        	}
        }
        return cur;
    }
};
int main() {

}