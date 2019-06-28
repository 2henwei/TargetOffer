#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool Find(vector<vector<int>> array, int target) {
        // Dimension of array
        size_t M = array.size();
        size_t N = array[0].size();

        // Current position
        size_t CurrentM = 0;
        size_t CurrentN = N - 1;

        while (CurrentM < M && CurrentN >= 0) {
            if (array[CurrentM][CurrentN] < target)
                ++CurrentM;
            else if (array[CurrentM][CurrentN] > target)
                --CurrentN;
            else
                return true;
        }
        return false;
    }
};

int main() {
    int a1[] = {
        1,
        2,
        8,
        9,
    };
    int a2[] = {
        2,
        4,
        9,
        12,
    };
    int a3[] = {
        4,
        7,
        10,
        13,
    };
    int a4[] = {
        6,
        8,
        11,
        15,
    };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout << solu.Find(array, 7) << endl;
    return 0;
}
