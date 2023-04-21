#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> trees(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end()); // Sorting the trees in ascending order

    int left = 0;
    int right = trees[n - 1];
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            if (trees[i] > mid)
            {
                total += (trees[i] - mid);
            }
        }
        if (total >= m)
        {
            // If the total height of the cut trees is greater than or equal to m,
            // update the answer and move to the right part of the binary search
            answer = mid;
            left = mid + 1;
        }
        else
        {
            // Otherwise, move to the left part of the binary search
            right = mid - 1;
        }
    }
    cout << answer << "\n"; // Output the maximum height of the cut trees
    return 0;
}
