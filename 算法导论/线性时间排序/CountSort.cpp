/** 计算排序,假设A[n],其中元素的范围都是在1~k之间,然后进行线性时间排序
 * 2015-5-10
 *
 *
 * 1 count_sort的注意点是计数数组中的数值转为为排序数组的loc时要-1的啊.
 * 你其实还是不是清楚了解算法,只是记得如此处理而已.
 **/
#include <iostream>
#include "sort.h"
using namespace std;

void count_sort(int *A,int *B,int len,int k) {
	//先初始化计数数组 最大值为5那么
	int C[k];
	int i;
	for(i=0;i<k;i++) {
		C[i]=0;
	}
	for(i=0;i<len;i++) {
		C[A[i]]++; //计数数组相应位置++
	}
	cout<<C[0]<<endl;
	for(i=1;i<k;i++) {
		C[i]+=C[i-1];
	}
	//值得注意的是,其中是从后往前进行的.
	cout<<"-----------------------"<<endl;
	for(i=len-1;i>=0;i--) {
		//error!!!!!!!    
		B[C[A[i]]]=A[i];
		C[A[i]]--; //去掉一个位置
	}
}
/**
   A=[2,5,3,0,2,3,0,3]
    C[  0,1,2,3,4,5 ]
   CV[ 2,0,2,3,0,1]
   CF[ 2,2,4,7,7,8]

**/
int main() {
	int A[]={2,5,3,0,2,3,0,3};
	int B[8];
	count_sort(A,B,8,6);
}
