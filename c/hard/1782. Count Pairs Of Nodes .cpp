/*1782. Count Pairs Of Nodes
 * You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges,
 * the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
 * You are also given an integer array queries.
 * Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
 * The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
 * a < b
 * incident(a, b) > queries[j]
 * Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
 * Note that there can be multiple edges between the same two nodes.
 *
 * Example 1:
 * Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
 * Output: [6,5]
 * Explanation:
 * The answers for each of the queries are as follows:
 * - answers[0] = 6. All the pairs have an incident(a, b) value greater than 2.
 * - answers[1] = 5. All the pairs except (3, 4) have an incident(a, b) value greater than 3.
 *
 * Example 2:
 * Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
 * Output: [10,10,9,8,6]
 *
 * Constraints:
 * 2 <= n <= 2 * 104
 * 1 <= edges.length <= 105
 * 1 <= ui, vi <= n
 * ui != vi
 * 1<= queries.length <= 20
 * 0 <= queries[j] < edges.length
 */

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
                total += n - j;
            }
            for (auto &[val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};
/*
 * 时间984ms，击败21.88%
 * 内存190.4MB，击败46.88%
 */

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries) {
        map<int, int> countEdge;
        map<pair<int, int>, int> countRepeat;

        for (auto edge: edges) {
            countEdge[edge[0]]++;
            countEdge[edge[1]]++;

            if (edge[0] < edge[1]) {
                countRepeat[pair<int, int>(edge[0], edge[1])]++;
            } else {
                countRepeat[pair<int, int>(edge[1], edge[0])]++;
            }
        }
        map<int, int> sumCount;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int temp = countEdge[i] + countEdge[j] - countRepeat[pair<int, int>(i, j)];
                for (int it = 1; it < temp; ++it) {
                    sumCount[it]++;
                }
            }
        }

        vector<int> ans;
        for (auto query: queries) {
            ans.push_back(sumCount[query]);
        }
        return ans;
    }
};
/*
 * 超时
 */