#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> values = {2, 5};

    values.insert(values.begin() + 1, 3);
    values.insert(values.begin() + 2, 4);

    vector<int> additionalValues = {0, 1};
    values.insert(values.begin(), additionalValues.begin(), additionalValues.end());

    vector<int> reversedValues;
    for (auto it = values.rbegin(); it != values.rend(); ++it)
    {
        reversedValues.push_back(*it);
    }

    for (int reversedValue : reversedValues)
    {
        cout << reversedValue << " ";
    }
    cout << endl;

    return 0;
}
