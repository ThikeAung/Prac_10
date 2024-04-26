#include "Matchhandler.h"

int main()
{
    std::vector<int> dataset1{2, 500, 6, 9, 10, 101, 1};
    std::vector<int> dataset2{4, 4, 2, 9, 0, 300, 1};

    std::function<bool(int, int)> isGreaterThan100 = [](int value1, int value2)
    {
        return value1 > 100 && value2 > 100;
    };

    int threshold = 100;
    std::function<bool(int, int)> isGreaterThanThreshold = [threshold](int value1, int value2)
    {
        return value1 > threshold && value2 > threshold;
    };

    std::cout << "Searching with stateless lambda:" << std::endl;
    searchForMatches(dataset1, dataset2, isGreaterThan100, displayMatch);

    std::cout << "\nSearching with stateful lambda:" << std::endl;
    searchForMatches(dataset1, dataset2, isGreaterThanThreshold, displayMatch);

    return 0;
}
