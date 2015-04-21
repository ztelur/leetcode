#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// all vector<int> is sorted!!! asumption
int findMax(vector<int> &);
int remove(vector<int> &,int);
int insert(vector<int> &,int);
bool contain(vector<int> &,int);
int binarySearch(vector<int> & ,int,int,int);
bool dfs(int x[] ,vector<int> & d,int n,int left,int right) {
	int dmax;
	bool found;

	if (d.empty()) return true;
	dmax=findMax(d);

	//check the x[right]=dmax is feasible
	bool isfeasible=true;
	for(int i=1;i<left;i++) {              //notice!!!!!!!!!!!!!! start from 1 !!!!!! x[0]=0 ????????
		if (!contain(d,abs(x[i]-dmax))) {
			isfeasible=false;
			break;
		}
	} 
	for(int i=right+1;i<=n;i++) {
		if (!contain(d,abs(x[i]-dmax))) {
			isfeasible=false;
			break;
		}
	}
	// if isFeasible do handle
	if (isfeasible) {
		x[right]=dmax;
		for(int i=1;i<left;i++) {
			remove(d,abs(x[i])-dmax);
		}
		for(int i=right+1;i<=n;i++) {
			remove(d,abs(x[i]-dmax));
		}
		found=dfs(x,d,n,left,right-1);
		if (!found) {   //backtracking
			for(int i=1;i<left;i++) {
				insert(d,abs(x[i])-dmax);
			}
			for(int i=right+1;i<=n;i++) {
				insert(d,abs(x[i]-dmax));
			}
		}
	}
	//check the x[left]=x[n]-dmax
	isfeasible=true;
	for(int j=1;j<left;j++) {
		if (!contain(d,abs(x[n]-dmax-x[j]))) {
			isfeasible=false;
		}
	}
	for(int j=right+1;j<n;j++) {
		if (!contain(d,abs(x[n]-dmax-x[j]))) {
			isfeasible=false;
		}
	}
	//do handle
	if (isfeasible) {
		x[left]=x[n]-dmax;
		for(int i=1;i<left;i++) {
			remove(d,abs(x[n]-dmax-x[i]));
		}
		for(int i=right+1;i<=n;i++) {
			remove(d,abs(x[n]-dmax-x[i]));
		}
		found=dfs(x,d,n,left+1,right);
		if (!found) {   //backtracking
			for(int i=1;i<left;i++) {
				insert(d,abs(x[n]-dmax-x[i]));
			}
			for(int i=right+1;i<=n;i++) {
				insert(d,abs(x[n]-dmax-x[i]));
			}
		}		
	}
	return found;
}
// binary search
int binarySearch(vector<int> & vec,int c,int left,int right) {
	if (left>right) {
		return -1; // not found;
	}
	int mid=(left+right)/2;
	if (vec[mid]>c) {
		return binarySearch(vec,c,left,mid-1);
	} else if (vec[mid]<c) {
		return binarySearch(vec,c,mid+1,right);
	} else {
		return mid;
	}
}
bool contain(vector<int> & vec,int c) {
	int location=binarySearch(vec,c,0,vec.size()-1);
	return location==-1?false:true;
}
int remove(vector<int> & vec,int c) {
	int location=binarySearch(vec,c,0,vec.size()-1);
	if (location!=-1) {
		vec.erase(vec.begin()+location);
	}
}
int insert(vector<int> & vec,int c) {
	int location=-1;
	for(int i=0;i<vec.size();i++) {
		if (c<=vec[i]) {
			location=i;
			break;
		}
	}
	vec.insert(vec.begin()+location,c);
}
int findMax(vector<int> & vec) {
	return vec[vec.size()-1];
}
int main() {

}