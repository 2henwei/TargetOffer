#include <iostream>

using namespace std;

class Solution {
   public:
    void replaceSpace(char *str, int length) {
        if (!str || length <= 0) return;

        char *Ptr = str;

        size_t OriginalLength = 0;
        size_t SpaceLength = 0;
        while (*Ptr != '\0') {
            ++OriginalLength;
            if (*Ptr == ' ') ++SpaceLength;
            ++Ptr;
        }

        size_t UpdateLength = OriginalLength + SpaceLength * 2;
        if (length < UpdateLength || SpaceLength == 0) return;

        char *TailPtr = str + UpdateLength + 1;
        char *HeadPtr = str + OriginalLength + 1;
        while (HeadPtr != TailPtr) {
            if (*HeadPtr == ' ') {
                *TailPtr-- = '0';
                *TailPtr-- = '2';
                *TailPtr-- = '%';
            } else {
                *TailPtr-- = *HeadPtr;
            }
            HeadPtr -= 1;
        }
    }
};

int main() {
    char str[15 + 1] = "    ";

    Solution solu;
    solu.replaceSpace(str, 15);

    cout << str << endl;

    return 0;
}
