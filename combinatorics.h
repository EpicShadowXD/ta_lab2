#pragma once

namespace Permutations {
    void permute(std::vector<int>& arr, int l, int r) {
        if (l == r) {
            for (int num : arr)
                std::cout << num << " ";
            std::cout << std::endl;
        } else {
            for (int i = l; i <= r; i++) {
                std::swap(arr[l], arr[i]);
                permute(arr, l + 1, r);
                std::swap(arr[l], arr[i]);  // backtrack
            }
        }
    }

    void test() {
        std::vector<int> arr = {1, 2, 3};
        permute(arr, 0, arr.size() - 1);
    }
}

namespace Combinations {
    void combinations(std::vector<int>& arr, std::vector<int>& combo, int start, int n, int k) {
        if (k == 0) {
            for (int num : combo)
                std::cout << num << " ";
            std::cout << std::endl;
            return;
        }

        for (int i = start; i <= n - k; ++i) {
            combo.push_back(arr[i]);
            combinations(arr, combo, i + 1, n, k - 1);
            combo.pop_back();  // backtrack
        }
    }

    void test() {
        std::vector<int> arr = {1, 2, 3, 4};
        std::vector<int> combo;
        combinations(arr, combo, 0, arr.size(), 2);
    }
}


namespace Arrangements {
    void arrangements(std::vector<int>& arr, std::vector<int>& arng, std::vector<bool>& used, int k) {
        if (arng.size() == k) {
            for (int num : arng)
                std::cout << num << " ";
            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < arr.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                arng.push_back(arr[i]);
                arrangements(arr, arng, used, k);
                arng.pop_back();  // backtrack
                used[i] = false;
            }
        }
    }

    void test() {
        std::vector<int> arr = {1, 2, 3};
        std::vector<int> arng;
        std::vector<bool> used(arr.size(), false);
        arrangements(arr, arng, used, 2);
    }
}


