#define INF 10000;
int V=100;
int T=10;
/**
 * 备忘录法，从上到下，而且是为了多次查找使用的啊。
 */

int [V+1][T+1] opt;
int cal(int v,int type) {
	if (type==T) {
		if (v==0) return 0;
		else return -INF;
	}
	if (v<0) {
		return -INF;
	} else if (v==0) {
		return 0;
	} else if (opt[v][type]!=-1) {
		return opt[v][type];
	}
	int ret=-INT;
	for(int i=0;i<=C[type],i++) {   //i标示数量的啊。
		int temp=cal(V-i*V[type],type+1);//找opt[v-vi][i+1];
		if (temp!=-INF) {
			temp+=H[type]+1;
			if (temp>ret) ret=temp;
		}
	}
	opt[v][type]=ret;
	return ret;
}
