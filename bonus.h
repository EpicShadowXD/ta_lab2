#pragma once

namespace TravelingSalesmanProblem {
    void TSPUtil(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int currPos, int n, int count, int cost, int& ans) {
        if (count == n && graph[currPos][0]) {
            ans = std::min(ans, cost + graph[currPos][0]);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[currPos][i]) {
                visited[i] = true;
                TSPUtil(graph, visited, i, n, count + 1, cost + graph[currPos][i], ans);
                visited[i] = false;
            }
        }
    }

    int TSP(const std::vector<std::vector<int>>& graph) {
        std::vector<bool> visited(graph.size(), false);
        visited[0] = true;
        int ans = INT_MAX;
        TSPUtil(graph, visited, 0, graph.size(), 1, 0, ans);
        return ans;
    }

    void test() {
        std::vector<std::vector<int>> graph = {
            { 0, 10, 15, 20 },
            { 10, 0, 35, 25 },
            { 15, 35, 0, 30 },
            { 20, 25, 30, 0 }
        };
        int result = TSP(graph);
        std::cout << "Minimum cost of traveling: " << result << std::endl;
    }
}

namespace Paranthesis {
    void generateParenthesisUtil(int open, int close, std::string s, std::vector<std::string>& result, int n) {
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            generateParenthesisUtil(open + 1, close, s + "(", result, n);
        }
        if (close < open) {
            generateParenthesisUtil(open, close + 1, s + ")", result, n);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateParenthesisUtil(0, 0, "", result, n);
        return result;
    }

    void test() {
        int n = 3;
        std::vector<std::string> result = generateParenthesis(n);
        for (const std::string& s : result) {
            std::cout << s << std::endl;
        }
    }
}