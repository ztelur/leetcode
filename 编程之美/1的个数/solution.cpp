#include <stdio.h>
using namespace std;
int sum1s(int);
int main(){
	int a=123;
	printf("%d\n",sum1s(a));


}
int sum1s(int num) {
	int  iCount=0;
	int iFactor=1;
	int mSmallNum=0;
	int mCurrentNum=0;
	int mLargerNum=0;
	while (num/iFactor!=0) {    //
		mSmallNum=num-(num/iFactor)*iFactor;
		mCurrentNum=(num/iFactor)%10;
		mLargerNum=num/(iFactor*10);
		printf("small:%dcurrent:%dlarger:%d\n",mSmallNum,mCurrentNum,mLargerNum );
		switch (mCurrentNum) {
			case 0:      //200   104
				iCount+=mLargerNum*iFactor;  //这个时候只于高位数有关的.
				break;
			case 1:     //   213,124 ,这个时候和高位数和低位数都有关
				iCount+=mLargerNum*iFactor+mSmallNum+1;
				break;
			default:    //220   , 224  这个时候其实
				iCount+=(mLargerNum+1)*iFactor;
		}
		iFactor *= 10;
	}
	return iCount;
}
int binSum1s(string num) {
	
}
