#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s) {
  	//first understand the question
  	//dynamic programming
    	// if (s==NULL) {
    	// 	// check
    	// }
    	vector<vector<string> > result;
    	vector<string> *curP;

    	for(int i=0;i<s.size();i++) {
    		if (i==0) {
    			curP=new vector<string>();
    			curP->push_back(s.substr(i,1));
    			result.push_back(*curP);
    			continue;
    		} 
    		for(int j=0;j<result.size();j++) {
    			curP=&result[j];
    			curP->push_back(s.substr(i,1));
    			result[j]=*curP;
    		}
    		int length=result.size();
    		for(int j=0;j<length;j++) {   // asumption that the first vector is a,b,c,d,e all alone
    		   	vector<string> temp=result[j];
    		   	// curP=&result[j];
    		   	//should compare the cuP value
    		   	int curPLen=temp.size();
			for(int c=curPLen-2;c>=0;c--) {   //all value in location of curP->size()-1 is s.at(i) !!!!!
				if (temp[c]==temp[curPLen-1]) {
					int temp1=c;
					int temp2=curPLen-1; // s.at(i) add into curP location
					bool isMath=true;
					while(temp1<temp2) {  // when equal, must satifiy palidrome
						if (temp[temp1]!=temp[temp2]) {
							isMath=false;
							break;
						} 
						temp1++;
						temp2--;
					}
					if (isMath) {
						vector<string> *newList=new vector<string>();
						for(int m=0;m<c;m++) {
							newList->push_back(temp[m]);
						}
						string str=temp[c];
						for(int n=c+1;n<curPLen;n++) {
							str+=temp[n];
						}
						newList->push_back(str);
						result.push_back(*newList);
					}
				}
			}	
			}
		}
		return result;
    }
};
int main() {
	Solution solution;
	vector<vector<string> > result=solution.partition("aaaa");
	cout <<"------------------------------------"<<endl;
	for(int i=0;i<result.size();i++) {
		for(int j=0;j<result[i].size();j++) {
			cout<< " "<<result[i][j];
		}
		cout<<endl;
	}
}
