#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
 
using namespace std; 
bool compare(const Interval & inter1,const Interval & inter2);
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        //先排序
        if (intervals.size()<2) {
            return intervals;
        }
        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),compare);
        Interval cur=intervals[0];
        bool isAddedAtLast=false;
        for (int i=1;i<intervals.size();i++) {
            Interval inter2=intervals[i];
            if (cur.end>=inter2.start) { //可以合并
                cur.end=max(cur.end,inter2.end);
                cout <<"i"<<inter2.start<<inter2.end<<endl;
                cout << cur.end <<cur.start<<endl;
                
            } else {
                result.push_back(cur);
                cout << "add cur"<<cur.start<<cur.end<<endl;
                cur=inter2;
                
            }
        }
        result.push_back(cur);
        
        return result;
    }

};
bool compare(const Interval &inter1,const Interval &inter2) {
        return inter1.start<inter2.start;
}
int main() {
	Solution* s=new Solution();
	vector<Interval> test;
	Interval in(1,4);
	Interval in2(5,6);
	test.push_back(in);
	test.push_back(in2);
	vector<Interval> result=s->merge(test);
               for (int i=0;i<result.size();i++) {
                    cout <<"[ " <<result[i].start <<" , "<<result[i].end <<" ]"<<endl;
               }
}
