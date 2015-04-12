#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
class Solution{
	public:
		int minPathSum(vector<vector<int> > &grid) {
			// if (grid==null)
			// 	return 0;
			int m=grid.size();
			if (m==0)
				return 0;
			int n=grid[0].size();
			int value[n];
			for(int j=0;j<n;j++) {
			    value[j]=0;
			}
			int prevalue=0;
			for(int i=0;i<m;i++) {
				prevalue=value[0];
				for(int j=0;j<n;j++) {
					if (i==0) {  //first line
						value[j]=prevalue+grid[i][j];
					} else {
						value[j]=min(prevalue,value[j])+grid[i][j];
					}
					printf("%s\n","---------------------------" );
					prevalue=value[j];
					printf("location is %d:%d and the value is %d\n",i,j,value[j]);
				}
			}
			return value[n-1];
		}
};
int main() {
	vector<vector<int> > vector1;
	vector<int> vector2;
	vector<int> vector3;
	vector<int> vector4;
	vector2.push_back(1);
	vector2.push_back(3);
	vector2.push_back(1);
	vector3.push_back(1);
	vector3.push_back(5);
	vector3.push_back(1);
	vector4.push_back(4);
	vector4.push_back(2);
	vector4.push_back(1);		
	vector1.push_back(vector2);
	vector1.push_back(vector3);
	vector1.push_back(vector4);
	Solution Solution;
	int result=(Solution.minPathSum(vector1));
	printf("%d\n",result);
}