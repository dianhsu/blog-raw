@import "/mystyle.less"

## 字典树

> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---


### 指针实现

```cpp
#include <bits/stdc++.h>

/**
 * @brief 字典树的节点
 * 
 * */
template<int MAX_WIDTH>
struct TrieTreeNode {
    int count;
    int endCount;
    TrieTreeNode *nex[MAX_WIDTH];

    TrieTreeNode() {
        for (int i = 0; i < MAX_WIDTH; ++i) {
            nex[i] = nullptr;
        }
        count = 0;
        endCount = 0;
    }

    ~TrieTreeNode() {
        for (int i = 0; i < MAX_WIDTH; ++i) {
            if (nex[i] != nullptr) {
                this->nex[i]->~TrieTreeNode();
                this->nex[i] = nullptr;
            }
        }
    }

    void buildChild(int k) {
        assert(k >= 0 and k < MAX_WIDTH);
        nex[k] = new TrieTreeNode();
    }
};

/**
 * @brief 字典树的整体结构
 * 
 * */
template<int MAX_WIDTH, char BASE_CHR>
class TrieTree {
public:
    TrieTree() {
        root = new TrieTreeNode<MAX_WIDTH>();
    }

    ~TrieTree() {
        this->root->~TrieTreeNode();
    }

    // 插入序列
    void insertSequence(const std::string &word) {
        auto ptr = root;
        for (auto it : word) {
            int pos = it - BASE_CHR;
            if (ptr->nex[pos] == nullptr) {
                ptr->buildChild(pos);
            }
            ptr->count++;
            ptr = ptr->nex[pos];

        }
        ptr->count++;
        ptr->endCount++;
    }

    // 计算前缀数量
    int countPre(const std::string &word) {
        auto ptr = root;
        for (auto it : word) {
            int pos = it - BASE_CHR;
            if (ptr->nex[pos] == nullptr) {
                return 0;
            }
            ptr = ptr->nex[pos];
        }
        return ptr->count;
    }

    // 判断是否有相同的串
    bool isWordExist(const std::string &word) {
        auto ptr = root;
        for (auto it : word) {
            int pos = it - BASE_CHR;
            if (ptr->nex[pos] == nullptr) {
                return false;
            }
            ptr = ptr->nex[pos];
        }
        return ptr->endCount > 0;
    }

private:
    TrieTreeNode<MAX_WIDTH> *root;
};

int main() {
    auto *trieTree = new TrieTree<26, 'a'>();
    std::vector<std::pair<std::string, std::string>> ops{
            {"insert",   "hello"},
            {"insert",   "word"},
            {"insert",   "nihao"},
            {"insert",   "google"},
            {"insert",   "microsoft"},
            {"insert",   "microsoft"},
            {"insert",   "microsoft"},
            {"insert",   "microsoft"},
            {"insert",   "micro"},
            {"insert",   "apache"},
            {"countPre", "h"},
            {"countPre", "micro"},
            {"isExist",  "hello"},
            {"isExist",  "micro"}
    };
    for (auto &it : ops) {
        std::cout << "[" << it.first << ", " << it.second << "]: ";
        std::cout.flush();
        if (it.first == "insert") {
            trieTree->insertSequence(it.second);
            std::cout << "success";
        } else if (it.first == "countPre") {
            std::cout << trieTree->countPre(it.second);
        } else if (it.first == "isExist") {
            std::cout << std::boolalpha << trieTree->isWordExist(it.second);
        }
        std::cout << std::endl;
    }
    delete trieTree;
    std::cout << "destruct" << std::endl;
    return 0;
}
```