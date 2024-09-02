#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    void findMaximumNumUtil(std::string& str, int k, int index, std::string& max_num) {
        // Base Case: If no swaps left or reached the end of the string
        if (k == 0 || index == str.length()) {
            return;
        }

        // Find the maximum digit in the remaining part of the string
        char max_digit = *max_element(str.begin() + index, str.end());

        // If the current digit is already the maximum, no need to decrement k
        if (max_digit != str[index]) {
            --k;
        }

        // Try swapping the current index with all positions that have the max digit
        for (int i = index; i < str.length(); ++i) {
            if (str[i] == max_digit) {
                // Swap the current digit with the digit at index i
                std::swap(str[index], str[i]);

                // Update the maximum number
                if (str.compare(max_num) > 0) {
                    max_num = str;
                }

                // Recur for the next index
                findMaximumNumUtil(str, k, index + 1, max_num);

                // Backtrack to restore the original string
                std::swap(str[index], str[i]);
            }
        }
    }

    std::string findMaximumNum(std::string str, int k) {
        std::string max_num = str;
        findMaximumNumUtil(str, k, 0, max_num);
        return max_num;
    }
};

// Example usage
int main() {
    Solution solution;
    std::string str = "1234567";
    int k = 4;
    std::cout << "Largest number after " << k << " swaps: " << solution.findMaximumNum(str, k) << std::endl;

    str = "3435335";
    k = 3;
    std::cout << "Largest number after " << k << " swaps: " << solution.findMaximumNum(str, k) << std::endl;

    return 0;
}
