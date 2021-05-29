#include <cstdio>

int main(){
		double st;
		int times;
		while(scanf("%lf%d", &st, &times)!=EOF) {
				double sum = st;
				double next = st/2.0;
				for(int i = 1; i < times; ++i) {
						sum += next*2;
						next/=2;
				}
                printf("%.8f %.8f\n",sum, next);
		}
		return 0;
}
