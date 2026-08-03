#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int largestNumber(const vector<int> &arr)
{
    int largest = INT_MIN; //Initialize the answer with the smallest possible integer.
    for (auto val : arr)
    {
        if (largest < val)
        {
            largest = val;
        }
    }
    return largest;
}

int main()
{
    vector<int> arr = {-3,-4,-5};
    cout << largestNumber(arr) << endl;
}