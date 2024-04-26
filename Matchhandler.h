#ifndef MATCHERHANDLER_H
#define MATCHERHANDLER_H

#include <vector>
#include <functional>
#include <iostream>

template <typename Matcher, typename MatchHandler>
void searchForMatches(const std::vector<int> &dataset1,
                      const std::vector<int> &dataset2,
                      Matcher matchCondition, MatchHandler matchHandler);

void displayMatch(size_t position, int value1, int value2);

template <typename Matcher, typename MatchHandler>
void searchForMatches(const std::vector<int> &dataset1,
                      const std::vector<int> &dataset2,
                      Matcher matchCondition, MatchHandler matchHandler)
{
    if (dataset1.size() != dataset2.size())
    {
        return;
    }

    for (size_t i = 0; i < dataset1.size(); ++i)
    {
        if (matchCondition(dataset1[i], dataset2[i]))
        {
            matchHandler(i, dataset1[i], dataset2[i]);
        }
    }
}

void displayMatch(size_t position, int value1, int value2)
{
    std::cout << "Match found at position: " << position << std::endl;
    std::cout << "Value in dataset 1: " << value1 << std::endl;
    std::cout << "Value in dataset 2: " << value2 << std::endl;
}

#endif
