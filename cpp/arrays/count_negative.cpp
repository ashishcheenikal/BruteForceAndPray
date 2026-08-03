#include <iostream>
#include <vector>
using namespace std;

int countNegative(const vector<int> &arr)
{
    int countNeg = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            countNeg++;
        }
    }

    return countNeg;
}
int main()
{
    vector<int> arr = {-1, 1, -2, 2, -3, 3 - 4, 4, -5, 5};
    cout << countNegative(arr) << endl;
}