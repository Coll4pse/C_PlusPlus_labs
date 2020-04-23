#include "ArrayUtil.h"
#include <iostream>
#include <tuple>
#include <stack>

using namespace std;

int ArrayUtil::search(const int* arrayStart, const int startId, const int endId, const int value) {
    arrayStart += startId;
    for (int i = startId; i < endId; i++, arrayStart++) {
        if (value == *arrayStart)
            return i;
    }
    return -1;
}

void ArrayUtil::swap(int* const first, int* const second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int ArrayUtil::partition(int* const arrayStart, int leftBorder, int rightBorder) {
    int suppElement = *(arrayStart + ((leftBorder + rightBorder) / 2));
    while (leftBorder <= rightBorder) {
        while (*(arrayStart + leftBorder) < suppElement)
            leftBorder++;
        while (*(arrayStart + rightBorder) > suppElement)
            rightBorder--;
        if (leftBorder <= rightBorder)
            swap(arrayStart + (leftBorder++), arrayStart + (rightBorder--));
    }
    return leftBorder;
}

void ArrayUtil::quickSort(int* arrayStart, const int startId, const int endId) {
    arrayStart += startId;

    stack<tuple<int, int>> stack;
    int leftBorder = startId, rightBorder = endId;
    stack.push(make_tuple(leftBorder, rightBorder));

    while (!stack.empty()) {
        tie(leftBorder, rightBorder) = stack.top();
        stack.pop();

        if (rightBorder <= leftBorder)
            continue;

        int suppElementId = partition(arrayStart, leftBorder, rightBorder);

        if (leftBorder < suppElementId - 1)
            stack.push(make_tuple(leftBorder, suppElementId - 1));
        if (suppElementId < endId)
            stack.push(make_tuple(suppElementId, rightBorder));
    }
}

void ArrayUtil::recursiveQuickSort(int *arrayStart, const int startId, const int endId) {
    int suppElementId = partition(arrayStart, startId, endId);
    if (startId < suppElementId - 1)
        recursiveQuickSort(arrayStart, startId, suppElementId - 1);
    if (suppElementId < endId)
        recursiveQuickSort(arrayStart, suppElementId, endId);
}

void ArrayUtil::generateArray(int *arrayStart, const int startId, const int endId) {
    arrayStart += startId;
    srand(time(nullptr));
    for (int i = startId; i < endId; i++, arrayStart++)
        *arrayStart = rand() % 21 - 10;
}

void ArrayUtil::printArray(const int *arrayStart, const int startId, const int endId) {
    arrayStart += startId;
    for (int i = startId; i < endId; i++, arrayStart++)
        cout << *arrayStart << "|";
    cout << endl << endl;
}

int ArrayUtil::pairSearch(const int *const arrayStart, const int left, const int right, const int value) {
    if (*(arrayStart + left) == value)
        return left;
    if (*(arrayStart + right) == value)
        return right;
    return -1;
}

int ArrayUtil::bSearch(const int* const arrayStart, int left, int right, const int value) {
    int middle;

    while (left + 1 < right) {
        middle = (right + left) / 2;

        if (*(arrayStart + middle) < value)
            left = middle;
        else
            right = middle;
    }
    return pairSearch(arrayStart, left, right, value);
}

int ArrayUtil::recursiveBSearch(const int* const arrayStart, int left, int right, const int value) {
    int middle = (right + left) / 2;

    if (left + 1 == right)
        return pairSearch(arrayStart, left, right, value);
    else if (*(arrayStart + middle) < value)
        recursiveBSearch(arrayStart, middle, right, value);
    else
        recursiveBSearch(arrayStart, left, middle, value);
}
