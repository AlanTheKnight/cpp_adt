#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;

    vector<int> nums = {a, b, c};

    while (!((nums[0] == nums[1]) && (nums[2] == nums[0]))) {
        sort(nums.begin(), nums.end());
        int amount = nums[2] - max(nums[0], nums[1]);
        if (amount == 0) {
            amount = nums[2] - min(nums[0], nums[1]);
        }
        nums[0] += amount;
        nums[1] += amount;
        count += amount;
    }

    cout << count << endl;

    return 0;
}