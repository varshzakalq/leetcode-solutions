#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // 1. Build adjacency list for the invocation graph
        std::vector<std::vector<int>> graph(n);
        for (const auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
        }
        
        // 2. Identify all suspicious methods using BFS starting from k
        std::vector<bool> suspicious(n, false);
        std::queue<int> q;
        
        suspicious[k] = true;
        q.push(k);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : graph[curr]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // 3. Check if any non-suspicious method calls a suspicious method
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                // Removal invalid: return all original methods [0, 1, ..., n-1]
                std::vector<int> all_methods(n);
                std::iota(all_methods.begin(), all_methods.end(), 0);
                return all_methods;
            }
        }
        
        // 4. Return remaining non-suspicious methods
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
;
