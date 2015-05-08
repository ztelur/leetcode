#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 * 题目:
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 * 找出在一行中的最大的值啊,应该是横竖都包括的,比较害怕还有斜的
 *
 * 1 思路: 先按照x排序,计算最大的值
 * 			在按照y排序,计算最大值,然后返回就行啦
 * 			妈了个喵的,竟然所有的斜的都可以
 * 			连 1,1 1,1 2,3这样的都算3个.....
 */
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
typedef bool (*Eq)(const Point&,const Point&);
bool compareByX(const Point& p1,const Point& p2) {
	if(p1.x>p2.x) {
		return true;
	} else if(p1.x<p2.x){
		return false;
	} else {
		if (p1.y>p2.y) {
			return true;
		} else {
			return false;
		}
	}
}

bool compareByY(const Point& p1,const Point& p2) {
	if (p1.y>p2.y) {
		return true;
	} else if (p1.y<p2.y){
		return false;
	} else {
		if (p1.x>p2.x) {
			return true;
		} else {
			return false;
		} //p1==p2 return false;
	}
}
bool compareByYPlusX(const Point& p1,const Point& p2) {
	return p1.x+p1.y>p2.x+p2.y;
}
bool eqFromCol(const Point& p1,const Point& p2) {
	return p1.x==p2.x;
}
bool eqFromRow(const Point& p1,const Point& p2) {
	return p1.y==p2.y;
}
bool eqFromSlant(const Point& p1,const Point& p2) {
	return (p1.x-p1.y)==(p2.x-p2.y);
}

class Solution {
public:
    int maxPoints(vector<Point>& points) {
		if (points.size()==1) return 1;
		sort(points.begin(),points.end(),compareByX); //按照x排序了
		for(int i=0;i<points.size();i++) {
			printf("the node is %d %d\n",points[i].x,points[i].y);
		}

		int max1=maxFrom(points,&eqFromCol);
		sort(points.begin(),points.end(),compareByY);

		for(int i=0;i<points.size();i++) {
			printf("the node is %d %d\n",points[i].x,points[i].y);
		}
		int max2=maxFrom(points,&eqFromRow);

		sort(points.begin(),points.end(),compareByYPlusX);
		int max3=maxFrom(points,&eqFromSlant);
		return max(max1,max(max2,max3));
    }
	//查看x相同的个数的最大值
	int maxFrom(const vector<Point>& points,Eq eq) {
		int tmax=-1;
		int len=points.size();
		for(int i=0;i<len;i++) {
			printf("the loc is %d\n", i);
			int num=1;
			while(i+1<len&&eq(points[i],points[i+1])) {
				num++;
				i++;
			}
			printf("the num is %d\n",num);
			if(num>tmax) {
				tmax=num;
			}
		}
		return tmax;
	}
};
int main() {
	vector<Point> rec;
	rec.push_back(Point(0,0));
	rec.push_back(Point(-1,-1));
	rec.push_back(Point(2,2));
	Solution solution;
	int t=solution.maxPoints(rec);
	printf("%d\n",t );
}
