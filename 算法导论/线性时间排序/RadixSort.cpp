/** 基数排序啊.
 * 基本思想:1 利用计数排序
 * 			2 将多位的数字按照一组位来排序啊.比若说都是二进制数组,按照3位,3未
 * 		进行排序,这里有一个最优的比例.
 *
 
**/
void radix_sort(int A[],int d,int len) {
	int bits=figure(d,10);
	for(int i=len-1;i>=0;i++) {
		int B[len];
		radix_count_sort(A,B,10,i);
		A=B;
	}
}
/**
 * int d:默认是二进制下的位数,来判断按照多少个位来进行判断最优
 * int k:代表进制,如果是2进制 k=2;如果是10进制,k=10
 *//
int figure(int d,int k) {
	return 1; //默认返回
}
void radix_count_sort(int *A,int *B,int k,int bit) {
	

}
int bitOfInt(int num,int bit) {
}
