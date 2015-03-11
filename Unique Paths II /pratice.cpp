#include "../header.h"
#include <vector>
/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
**/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid.at(0).size();
        int preline[m];
        int pre=0;
        int cur;    
        for (int i=0;i<n;i++) {
        	vector<int> curLine=obstacleGrid.at(i);
        	if (i==0) {
        	    pre=1;
        	} else {
        	    pre=0;
        	}
        	for (int j=0;j<m;j++) {
        		if (i==0) {
        			preline[j]=0;
        		}
        		if (curLine.at(j)==1) {
        			cur=0;
        		} else {
        			cur=pre+preline[j];
        		}
        		preline[j]=cur;
        		pre=cur;
        	}
        }
        return cur;
    }
};