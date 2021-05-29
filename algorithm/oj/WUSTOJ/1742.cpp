#include <iostream>
#include <vector>
int main(){
    int n;
    while(std::cin >> n){
        int tmp = n;
        std::vector<int> vec;
        int key = 2;
        while(tmp > 1){
            while(tmp%key==0){
                tmp/= key;
                vec.push_back(key);
            }
            ++key;
        }
        std::cout << n;
        bool flag = false;
        for(auto item: vec){
            if(!flag){
                std::cout << "=";
                flag = true;
            }else{
                std::cout << "*";
            }
            std::cout << item;
        }
        std::cout << std::endl;
    }
    return 0;
}
