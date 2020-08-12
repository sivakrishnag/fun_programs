/* 
 * Convert the following functions into templates
 * 1. int Add(int x, int y); // Return the sum of two elements
 * 2. int ArraySum(int *pArr, int arrSize); //Returns the sum of array elements
 * 3. int Max(int *pArr, int arrSize); //Returns the largest element in the array
 * 4. std::pair<int, int> MinMax(int *pArr, int arrSize); //Return the smallest and largest element in a pair
 *
 * Take care to avoid copies of user-defined objects wherever applicable.
 */

#include <iostream>

template<typename T>
T Add (T x, T y)
{
    return (x + y);
}

template<typename T>
T ArraySum (T *pArr, int arrSize)
{
    T res = 0;

    for (int i = 0; i < arrSize; i++) {
        res += pArr[i];
    }

    return res;
}

template<typename T>
T Max (T *pArr, int arrSize)
{
    T max = pArr[0];

    for (int i = 1; i < arrSize; i++) {
        if (max < pArr[i])
            max = pArr[i];
    }

    return max;
}

template<typename T>
std::pair<T, T> MinMax (T *pArr, int arrSize)
{
    T max = pArr[0];
    T min = pArr[0];

    for (int i = 1; i < arrSize; i++) {
        if (max < pArr[i])
            max = pArr[i];

        if (min > pArr[i])
            min = pArr[i];
    }

    return std::pair<T, T>(min, max);
}

int main ()
{
    std::cout << "Add(5, 10) = " << Add<int>(6, 10) << std::endl;
    std::cout << "Add(5.5, 10.2) = " << Add<float>(5.5, 10.2) << std::endl;

    int int_pArr[] = {10, 20, 30, 40};
    std::cout << "ArraySum(int_pArr, sizeof(int_pArr) / sizeof(int)) = " << ArraySum(int_pArr, sizeof(int_pArr) / sizeof(int)) << std::endl;
    std::cout << "Max(int_pArr, sizeof(int_pArr) / sizeof(int)) = " << Max(int_pArr, sizeof(int_pArr) / sizeof(int)) << std::endl;

    auto int_min_max_pair = MinMax(int_pArr, sizeof(int_pArr) / sizeof(int));
    std::cout << "MinMax(int_pArr, sizeof(int_pArr) / sizeof(int)) = (" << int_min_max_pair.first << ", " << int_min_max_pair.second << ")" << std::endl;

    float float_pArr[] = {10.1, 20.2, 30.3, 40.4};
    std::cout << "ArraySum(float_pArr, sizeof(float_pArr) / sizeof(float)) = " << ArraySum(float_pArr, sizeof(float_pArr) / sizeof(float)) << std::endl;

    auto float_min_max_pair = MinMax(float_pArr, sizeof(float_pArr) / sizeof(float));
    std::cout << "Max(float_pArr, sizeof(float_pArr) / sizeof(float)) = (" << float_min_max_pair.first << ", " << float_min_max_pair.second << ")" << std::endl;

    return 0;
}
