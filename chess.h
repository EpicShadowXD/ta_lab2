#pragma once

namespace Queens {
    bool isSafe(int row, int col, std::vector<std::string>& board, int n) {
        // Verificăm coloana
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Verificăm diagonala principală
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Verificăm diagonala secundară
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void solveNQueensUtil(int n, int row, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solveNQueensUtil(n, row + 1, board, solutions);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.'));
        solveNQueensUtil(n, 0, board, solutions);
        return solutions;
    }

    void test() {
        int n = 4;
        auto solutions = solveNQueens(n);
        for (const auto& solution : solutions) {
            for (const auto& line : solution) {
                std::cout << line << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

namespace Towers {
    bool isRowColSafe(int row, int col, std::vector<std::vector<char>>& board, int n) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'T')
                return false;

        for (int j = 0; j < col; j++)
            if (board[row][j] == 'T')
                return false;

        return true;
    }

    void solveTowersUtil(int n, int row, std::vector<std::vector<char>>& board, std::vector<std::vector<std::vector<char>>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isRowColSafe(row, col, board, n)) {
                board[row][col] = 'T';
                solveTowersUtil(n, row + 1, board, solutions);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    std::vector<std::vector<std::vector<char>>> solveTowers(int n) {
        std::vector<std::vector<std::vector<char>>> solutions;
        std::vector<std::vector<char>> board(n, std::vector<char>(n, ' '));
        solveTowersUtil(n, 0, board, solutions);
        return solutions;
    }

    void test() {
        int n = 4;
        auto solutions = solveTowers(n);
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                for (char c : row) {
                    std::cout << c << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "\n";
        }
    }
}

namespace Knights {
    // Verifică dacă un căluţ poate fi plasat la poziţia (row, col) fără să fie atacat de alţi căluţi
    bool isSafe(int row, int col, const std::vector<std::vector<bool>>& board, int n) {
        // Vectori pentru a verifica mişcările caracteristice unui cal
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < 8; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < n && board[x][y]) {
                return false;
            }
        }
        return true;
    }

    void placeKnights(int n, int k, int start, std::vector<std::vector<bool>>& board, std::vector<std::vector<std::vector<bool>>>& solutions) {
        if (k == 0) {
            solutions.push_back(board);
            return;
        }

        for (int index = start; index < n * n; index++) {
            int row = index / n;
            int col = index % n;

            if (isSafe(row, col, board, n)) {
                board[row][col] = true;
                placeKnights(n, k - 1, index + 1, board, solutions);
                board[row][col] = false; // backtrack
            }
        }
    }

    std::vector<std::vector<std::vector<bool>>> solveKnights(int n) {
        std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));
        std::vector<std::vector<std::vector<bool>>> solutions;
        placeKnights(n, n, 0, board, solutions);
        return solutions;
    }

    void test() {
        int n = 4;
        auto solutions = solveKnights(n);
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                for (bool placed : row)
                    std::cout << (placed ? 'K' : '.') << " ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
}