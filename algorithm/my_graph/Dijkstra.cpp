/**
 * @brief 单源最短路径
 * @ref http://poj.org/problem?id=2387
 * */
#include <bits/stdc++.h>

/*****************************************
 * 
 * Template Below
 * 
 ****************************************/

template<typename T>
class Dijkstra {
public:
    std::vector<T> destination;
    T destinationInf;
    /**
     * @param maxPoint 结点的个数
     * @param destinationInf 默认为连接的最大值，如果是int范围内建议设置0x3f3f3f3f
     * */
    Dijkstra(int maxPoint, T destinationInf) : destination(maxPoint + 10, destinationInf), destinationInf(destinationInf) {}
    /**
     * @param beginPos 起始位置
     * @param distance 用二维动态数组实现的邻接表，std::pair<int, T>的值的意义是有向边的终点和边权。
     *
     * */
    void handle(int beginPos, std::vector<std::vector<std::pair<int, T>>>& distance) {
        destination[beginPos] = 0;
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> PQ;
        PQ.push({0, beginPos});
        while (!PQ.empty()) {
            auto cur = PQ.top().second;
            PQ.pop();
            for (auto& it : distance[cur]) {
                if (destination[cur] + it.second < destination[it.first]) {
                    destination[it.first] = destination[cur] + it.second;
                    PQ.push({destination[it.first], it.first});
                }
            }
        }
    }
};

/*****************************************
 * 
 * Template Above
 * 
 ****************************************/


int main() {
    int N;
#ifdef STDIN_CASES
    int T;
    std::cin >> T >> N;
#else
    N = 5;
#endif

    Dijkstra<int> solve(N, 0x3f3f3f3f);
    std::vector<std::vector<std::pair<int, int>>> distance(N + 10, std::vector<std::pair<int, int>>{});
#ifdef STDIN_CASES

    for (int i = 0; i < T; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        distance[a].push_back({b, c});
        distance[b].push_back({a, c});
    }
#else
    distance[1].push_back({2, 20});
    distance[2].push_back({1, 20});
    distance[2].push_back({3, 30});
    distance[3].push_back({2, 30});
    distance[3].push_back({4, 20});
    distance[4].push_back({3, 20});
    distance[4].push_back({5, 20});
    distance[5].push_back({4, 20});
    distance[1].push_back({5, 100});
    distance[5].push_back({1, 100});
#endif
    solve.handle(N, distance);
    std::cout << solve.destination[1] << std::endl;
#ifndef STDIN_CASES
    std::cout << (solve.destination[1] == 90 ? "Result match." : "Result mismatch.") << std::endl;
#endif
    return 0;
}

/*
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
*/