/*

In the given range [L, R], print all numbers having unique digits. e.g. In range 10 to 20 should print all numbers except 11.

Example 1:

Input:
L = 10
R = 20

Output:
10 12 13 14 15 16 17 18 19 20

Explanation:
The number 11 has two 1 therefore
11 is not a unique number.

Example 2:

Input:
L = 1
R = 9

Output:
1 2 3 4 5 6 7 8 9

Explanation:
All the Numbers are unique.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function uniqueNumbers() which takes two integers L and R as an input parameter and returns the list/vector of all the unique numbers present between L to R.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= L <= R <= 10^4

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> uniqueNumbers(int l, int r)
{
    int m;
    vector<int> res;
    for (int i = l; i <= r; i++)
    {
        int num = i;
        bool visited[10] = {false};
        while (num)
        {
            if (visited[num % 10])
                break;

            visited[num % 10] = true;
            num = num / 10;
        }
        if (num == 0)
        {
            res.push_back(i);
        }
    }
    return res;
}
int main()
{
    vector<int> out;
    int l, r;
    cin >> l;
    cin >> r;
    out = uniqueNumbers(l, r);
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}