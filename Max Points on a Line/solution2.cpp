#include <vector>
#include <stdlib.h>
#include <map>
#include <limits.h>
#include <iostream>
using namespace std;

/**
 * 发现题目要求中对a line要求比较大，相当于有很多的规则，如果为了每个规则都要遍历一遍整个me
 * tric那么开销太大（这样空间消耗比较小），所以，只能是一次遍历，对于每个规则都进行判断，那么就需要额外
 * 的空间对数据进行存储，以便于算法分析。使用了离散化的概念啊，
 *
 * logic:其实这是最初的寻找同行，同列，同一个对角水平线问题的扩展。
 * 其实你可以发现，第一个同行，同列都是对于0,0这个点来说。
 * 而对于这道题，由于任何两个点之间都可以构成a line，那么就是说要以不同的点进行判断，那么就一定是两个嵌套循环的复杂度
 * 其实，对于问题的大致复杂度的了解是很重要的。
 *
 * 这次有忘记写了renturn，为什么呢？。。。。。。
 * hashmap在对于无法依次遍历的题目时的厉害之处啊。
 */
   struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
class Solution {
public:
    int maxPoints(vector<Point>& points) {
		int length=points.size();
		if(length<=2) return length;
		int max_count=0;

		for(int i=0;i<length;i++) {
			map<double,int> slope_map; //名字起的真好。。。
			int same_point=0; 
			int local_max=1; 
			for(int j=i+1;j<length;j++) {
				double m=0.0;
				if(points[j].x==points[i].x&&points[j].y==points[i].y) {
					same_point++;
					continue;
				} else if (points[j].x==points[i].x){
					m=INT_MAX;
					
				} else {
					m=(double(points[j].y-points[i].y))/(points[j].x-points[i].x);
				}
				if(slope_map.find(m)==slope_map.end()) {
					slope_map[m]=1;  //在这一条中便说明要进行排序，但是其实是可以进行优化的
				}
				cout << "the loca is "<< i<<" "<<j<<"the m is "<<m<<"  "<<slope_map[m]<<endl;
				slope_map[m]++;
				local_max=max(local_max,slope_map[m]);
				// cout<< "the local_max "<<local_max<<endl;
			}
			cout <<"same_point "<<same_point<<" local _max "<<local_max<<endl;
			max_count=max(local_max+same_point,max_count);
		}
		return max_count;
    }
};
int main() {
	Solution solution;
	vector<Point> input;
	input.push_back(Point(0,0));
	input.push_back(Point(1,-1));
	input.push_back(Point(1,1));
	int a=solution.maxPoints(input);
	cout<<a<<endl;
}
