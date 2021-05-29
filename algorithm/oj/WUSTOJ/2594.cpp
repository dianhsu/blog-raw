#include <iostream>
#include <algorithm>

using namespace std;
int val[100];
int cmp[100];
int main(){
	int n;
	while(cin >> n){
		bool insertion_sort = true;
		for(int i = 0; i < n; ++i){
			cin >> val[i];
		}
		bool stage_1 = true;
		int sign = 0;
		for(int i = 0; i < n; ++i){
			cin >> cmp[i];
			if(stage_1){
				if(i == 0 || cmp[i] > cmp[i-1]){
					continue;
				}else if(cmp[i] == val[i]){
					stage_1 = false;
					sign = i;
				}else{
					insertion_sort = false;
				}
			}else{
				if(cmp[i] != val[i]){
					insertion_sort = false;
				}
			}
		}
		if(insertion_sort){
			cout << "Insertion Sort" << endl;
			for(int i = sign; i > 0; --i){
				if(cmp[i] < cmp[i-1]){
					swap(cmp[i],cmp[i-1]);
				}else{
					break;
				}
			}
			for(int i = 0; i < n; ++i){
				cout << cmp[i];
				if(i == n-1) cout << endl;
				else cout << ' ';
			}
		}else{
			cout << "Merge Sort" << endl;
			bool reach = false;
			int sep = 1;
			while(sep <= n){
				sep *= 2;
				for(int j = 0; j < n; j += sep){
					sort(val + j, val + min(j + sep, n));
				}
				if(!reach){
					bool same = true;
					for(int i = 0; i < n; ++i){
						if(val[i] != cmp[i]){
							same = false;
							break;
						}
					}
					if(same) reach = true;
				}else{
					for(int i = 0; i < n; ++i){
						cout << val[i];
						if(i == n-1) cout << endl;
						else cout << ' ';
					}
					break;
				}
			}

		}

	}
	return 0;
}
