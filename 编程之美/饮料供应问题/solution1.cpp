#include <stdio.h>
/**
 * 饮料供应问题，动态编程，
 * 注意的是，使用编程之美中的思路，Opt(v,i)标示
 * 从第i，i+1,i+2到n的总满意度
 */
#define INF 1000000;
int V=100;
int T=10;
int V[V+1]
int opt[V+1][T+1]; //这是假设只提供100生，10种饮料,但是有初始化的000的。
//下边是动态编程的。
int cal(int V,int type) {
	//初始化条件啊
	for(int j=0;j<type;j++) {
		opt[0][T]=0;
	}
	for(int i=1;i<=V,i++) {
		opt[i][T]=-INF
	}
	//正在在计算啦
	for(int j=T-1;j>=0;j--) {
		for(int i=0;i<=V;i++) {
			opt[i][j]=-INF;
			for(int k=0;k<=C[j];k++) {  //k从0到这种饮料的可能的最大数量
				if (i<=K*V[j]) { // 比较容量啊
					break;
				}
				int x=opt[i-k*V[j]][j+1]; //j+1 标示j+1,j+2到n中饮料
				if (x != -INF) {
					x+=H[j]*k;
					if (x>opt[i][j]) {  //取最大值
						opt[i][j]=x;
					}
				}
			}
		
		}
	
	}
	return opt[V][0];
}



