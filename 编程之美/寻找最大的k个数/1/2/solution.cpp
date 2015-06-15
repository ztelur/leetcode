#include <stdio.h>
using namespace std;
class solution{
	public:
		int mid;
		int tempK;
		void sort(int array[],int left,int right,int k) {
			int tempK=quicksort(array,left,right);
			if (tempK == k) { //找到了k个
			
			} else if (tempK > k) {
				sort(array,mid+1,right,k);
			} else {
				//先保存大于mid的部分
				
				
				//继续遍历
				sort(array,left,mid-1,k-tempK);
			}
			
		}
		/**
		 * array:排序数组
		 * left:最左边的
		 * right:最右边的(无法达到
		 */
		void quicksort(int array[],int left,int right) {
			int pivot=maxThree(array,left,right);
			//三个位置的值,先比较啊.
			
			//预处理左侧
			int l=left+1,r=right-2;//    mid,max 分别为 right-1,right 
			//因为right是不可到达的.
			while (true) {
				while (l<=right && array[l]<=pivot) {
					l++;
				}
				while (r>=left && array[r]>pivot) {
					r--;
				}
				if (l<r) {
					swapArray(array,l,r);
				} else {
					break;
				}
				
			}

			//swap,l指向第一个大于pivo的值啊
			swapArray(array,l,right-2);
			//l是pivot,所以right-l就是多少个大于pivo的数
			mid=l;
			tempK=right-l;
			//**
			//quicksort(a,left,l-1);
			//quicksort(a,i+1,right);
				
		}
		/**
		 * 三值处理法
		 *
		 **/
		int maxThree(int array[],int left,int right) {
			int mid=(left+right)/2;
			//mid要为三者中中间大的值
			if (array[mid] > array[right]) {
				swapArray(array,mid,right);
			}
			if (array[left] < array[right]) {
				swapArray(array,left,right);
			}
			if (array[left] > array[mid]) {
				swapArray(array,left,mid);
			}
			//三者已经排好了,取中间的值,放在最右边
			swapArray(array,mid,right-1);
			return array[right-1];

		}
		void swapArray(int array[],int a,int b) {
			int temp=array[a];
			array[a]=array[b];
			array[b]=temp;
		}
		
		

}
