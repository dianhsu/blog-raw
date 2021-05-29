#include <iostream>
#include <algorithm>

int main(){
    int val[3];
    while(std::cin >> val[0] >> val[1] >> val[2]){
        std::sort(val,val+3);
        if(val[0] == val[2]){
            std::cout << "等边三角形\n";
        }else if(val[0]*val[0]+val[1]*val[1] == val[2]*val[2]){
            std::cout << "直角三角形\n";
        }else if(val[0] == val[1] or val[1] == val[2]){
            std::cout << "等腰三角形\n";
        }else{
            std::cout << "普通三角形\n";
        }
    }

}
