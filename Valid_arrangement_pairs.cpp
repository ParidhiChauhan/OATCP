#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>> ans;
        unordered_map<int, stack<int>> graph;
        unordered_map<int, int> outDegree;
        unordered_map<int, int> inDegrees;

        for (const vector<int>& pair : pairs) {
            const int start = pair[0];
            const int end = pair[1];
            graph[start].push(end);
            ++outDegree[start];
            ++inDegrees[end];
        }

        const int startNode = getStartNode(graph, outDegree, inDegrees, pairs);
        euler(graph, startNode, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    int getStartNode(const unordered_map<int, stack<int>>& graph,
                     unordered_map<int, int>& outDegree,
                     unordered_map<int, int>& inDegrees,
                     const vector<vector<int>>& pairs) {
        for (const auto& [u, _] : graph)
            if (outDegree[u] - inDegrees[u] == 1)
                return u;
        return pairs[0][0];  // Arbitrarily choose a node.
    }

    void euler(unordered_map<int, stack<int>>& graph, int u,
               vector<vector<int>>& ans) {
        auto& stack = graph[u];
        while (!stack.empty()) {
            const int v = stack.top();
            stack.pop();
            euler(graph, v, ans);
            ans.push_back({u, v});
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;
    
    vector<vector<int>> pairs(n);
    cout << "Enter the pairs in the format 'start end':\n";
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        pairs[i] = {start, end};
    }

    Solution solution;
    vector<vector<int>> arrangement = solution.validArrangement(pairs);

    cout << "Valid arrangement of pairs:\n";
    for (const auto& pair : arrangement) {
        cout << pair[0] << " " << pair[1] << "\n";
    }

    return 0;
}
