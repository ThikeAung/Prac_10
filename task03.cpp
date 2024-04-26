#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> findRightTriangles(int maxParameter);
void displayMaxSolutions(const vector<vector<int>> &triangles);

int main()
{
    int maxParameter = 1000;
    vector<vector<int>> triangles = findRightTriangles(maxParameter);

    displayMaxSolutions(triangles);

    return 0;
}

vector<vector<int>> findRightTriangles(int maxParameter)
{
    vector<vector<int>> triangles;

    for (int sideA = 1; sideA <= maxParameter / 2; ++sideA)
    {
        for (int sideB = sideA; sideB <= maxParameter / 2; ++sideB)
        {
            double sideHypotenuse = sqrt(sideA * sideA + sideB * sideB);
            int integerSideHypotenuse = static_cast<int>(sideHypotenuse);
            if (sideHypotenuse == integerSideHypotenuse)
            {
                int parameter = sideA + sideB + sideHypotenuse;
                if (parameter <= maxParameter)
                {
                    vector<int> newTriangle = {sideA, sideB, integerSideHypotenuse, parameter};
                    triangles.push_back(newTriangle);
                }
            }
        }
    }

    return triangles;
}

void displayMaxSolutions(const vector<vector<int>> &triangles)
{
    int maxCount = 0;
    vector<vector<int>> maxSolutions;

    for (size_t currentTriangleIndex = 0; currentTriangleIndex < triangles.size(); ++currentTriangleIndex)
    {
        int count = 0;
        for (size_t otherTriangleIndex = 0; otherTriangleIndex < triangles.size(); ++otherTriangleIndex)
        {
            if (triangles[currentTriangleIndex][3] == triangles[otherTriangleIndex][3])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            maxSolutions.clear();
            maxSolutions.push_back(triangles[currentTriangleIndex]);
        }
        else if (count == maxCount)
        {
            maxSolutions.push_back(triangles[currentTriangleIndex]);
        }
    }

    for (size_t index = 0; index < maxSolutions.size(); ++index)
    {
        cout << "(" << maxSolutions[index][0] << ", " << maxSolutions[index][1] << ", " << maxSolutions[index][2] << ", " << maxSolutions[index][3] << ")" << endl;
    }

    cout << maxCount << endl;
}
