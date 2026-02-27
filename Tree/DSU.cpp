#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
//并查集模板
/*
给你一个二维整数数组 properties，其维度为 n x m，以及一个整数 k。

定义一个函数 intersect(a, b)，它返回数组 a 和 b 中 共有的不同整数的数量 。

构造一个 无向图，其中每个索引 i 对应 properties[i]。如果且仅当 intersect(properties[i], properties[j]) >= k（其中 i 和 j 的范围为 [0, n - 1] 且 i != j），节点 i 和节点 j 之间有一条边。

返回结果图中 连通分量 的数量。
*/
using namespace std;
class Solution {
public:
    int intersect(vector<int>& a, vector<int>& b) {
        unordered_set<int> set_a(a.begin(), a.end());
        int count = 0;
        for (int& num : b) {
            if (set_a.count(num)) {
                count++;
                set_a.erase(num); // 避免重复计数
            }
        }
        return count;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        auto find = [&](this auto&& find, int i) -> int {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = find(parent[i]);
        };

        auto Union = [&](int i, int j) -> void { parent[find(i)] = find(j); };

        for (int i = 0; i < n; i++) {
            unordered_set<int> flag(properties[i].begin(), properties[i].end());
            for (int j = i + 1; j < n; j++) {
                if (intersect(properties[i],properties[j]) >= k) {
                    if (find(i) != find(j)) {
                        Union(i, j);
                    }
                }
            }
        }

        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[find(i)]++;
        }
        return cnt.size();
    }
};

int main() {

    return 0;
}