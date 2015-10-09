/**
 * 解法五，使用基数排序的思想啊，其实就是改变其中，可以在线性时间内完成
 */

/**
 * 假设n个数中都在0到m之间
 *
 */
/**
 *
 * 由于假设n个数是在0到m之间，所以计数数组要为m+1
 * 参数m就是m+1啦
 */
void countFindK(int N[],int n,int k,int m) {
	int *hole=new int[m]; //hole
	int i=0;
	for(;i<m,i++) {
		hole[i]=0;
	}
	//遍历N
	for(i=0;i<n;i++) {
		hole[N[i]]++;
	}
	//处理计数数组
	int all=0;
	int j=m-1;
	int *res=new int[k];
	for(i=m-1;i>=0;i--) {
		all+=hole[i];
		j--;
		if (all>=k) {
			break;
		} else {
			
		
		}
	}
	//获得all和j
	//对j进行操作啊，获得所有的数啊。！！！
	int *res=new int[k];

}

