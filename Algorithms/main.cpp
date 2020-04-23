#include <iostream>
#include <string>
#include <chrono>
#include "ArrayUtil.h"

/// Степанов М. О. РИ-280017 ///

using namespace std;

constexpr int N = 100;

string whichMessage(const int index) {
    if (index == -1)
        return "такого значения нет в массиве.";
    else
        return "первое вхождение значения найдено по индексу " + to_string(index) + ".";
}

void sortsTesting(void sortFunc(int*, const int, const int)) {
    int array[N];
    ArrayUtil::generateArray(array, 0, N - 1);
    ArrayUtil::printArray(array, 0, N / 2 -1);
    sortFunc(array, 0, N - 1);
    ArrayUtil::printArray(array, 0, N / 2 - 1);
}

void searchesTesting(const int value) {
    int array[N * N];

    ArrayUtil::generateArray(array, 0, N * N - 1);
    cout << "Линейный поиск: " << whichMessage(ArrayUtil::search(array, 0, N * N - 1, value))
        << "Значение: " << value << endl << endl;

    ArrayUtil::recursiveQuickSort(array, 0, N * N - 1);

    cout << "Бинарный итеративный поиск: "
    << whichMessage(ArrayUtil::bSearch(array, 0, N * N - 1, value))
         << "Значение: " << value << endl << endl;

    cout << "Бинарный рекурсивный поиск: "
    << whichMessage(ArrayUtil::recursiveBSearch(array, 0, N * N - 1, value))
         << "Значение: " << value << endl << endl;
}

int getRuntime(int searchFunc(const int* const, int, int, const int), const bool isBSearch, const int value) {
    int array[N * N];
    ArrayUtil::generateArray(array, 0, N * N - 1);

    if (isBSearch)
        ArrayUtil::recursiveQuickSort(array, 0, N * N - 1);

    auto begin = chrono::system_clock::now();
    searchFunc(array, 0, N * N - 1, value);
    auto end = chrono::system_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
}

int main() {
    /// Сортировка ///
    sortsTesting(ArrayUtil::quickSort);
    sortsTesting(ArrayUtil::recursiveQuickSort);
    /// Поиск ///
    searchesTesting(10);
    searchesTesting(20);
    searchesTesting(-8);
    /// Быстродействие ///
    cout << "Время работы линейного поиска: "
        << getRuntime(ArrayUtil::search, false, 7) << " нс" << endl << endl;
    cout << "Время работы бинарного итеративного поиска: "
        << getRuntime(ArrayUtil::bSearch, true, 7) << " нс" << endl << endl;
    cout << "Время работы бинарного рекурсивного поиска: "
        << getRuntime(ArrayUtil::recursiveBSearch, true, 7) << " нс" << endl << endl;
}
