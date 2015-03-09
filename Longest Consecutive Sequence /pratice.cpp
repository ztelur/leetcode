#include "../header.h"
#include <vector>
#include <map>
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.
bool debug=false;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int size=num.size();
        map<int,int> result;
        int longest=1;
        if (size<2) {
        	return size;
        }
        for (int i=0;i<size;i++) {
        	// assumption no duplicate
        	int cur=num[i];
        	if (result.find(cur)!=result.end()) {
        		continue;
        	}

        	int before=0;
        	if (result.find(cur-1)!=result.end()) {
        		before=result[cur-1];
        	}
        	int after=0;
        	if (result.find(cur+1)!=result.end()) {
        		after=result[cur+1];
        	}
        	//change the valu
        	int curLength=before+after+1;
        
        	if (before!=0) {
        		result[cur-before]=curLength;
        	}
        	if (after!=0) {
        		result[cur+after]=curLength;
        	}

        	result[cur]=curLength;

        	longest=max(longest,curLength);
        }
        return longest;
    }
};
int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	Solution * solution=new Solution();
	int a=solution->longestConsecutive(v);
	cout <<a <<endl;
}