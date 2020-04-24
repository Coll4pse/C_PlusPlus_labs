#include "ArrayUtil.h"
#include "IntStack.h"
#include <iostream>

using namespace std;

int ArrayUtil::search(const int* arrayStart, int startId, int endId, int value) {
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
    int pivot = *(arrayStart + ((leftBorder + rightBorder) / 2));
    while (leftBorder <= rightBorder) {
        while (*(arrayStart + leftBorder) < pivot)
            leftBorder++;
        while (*(arrayStart + rightBorder) > pivot)
            rightBorder--;
        if (leftBorder <= rightBorder)
            swap(arrayStart + (leftBorder++), arrayStart + (rightBorder--));
    }
    return leftBorder;
}

void ArrayUtil::quickSort(int* arrayStart, int left, int right) {
    arrayStart += left;

    IntStack leftBorders, rightBorders;

    leftBorders.push(left);
    rightBorders.push(right);

    while (!leftBorders.isEmpty() || !rightBorders.isEmpty()) {
        left = leftBorders.pop();
        right = rightBorders.pop();

        if (right <= left)
            continue;

        int pivot = partition(arrayStart, left, right);

        if (left < pivot - 1) {
            leftBorders.push(left);
            rightBorders.push(pivot - 1);
        }
        if (pivot < right) {
            leftBorders.push(pivot);
            rightBorders.push(right);
        }
    }
}

void ArrayUtil::recursiveQuickSort(int *arrayStart, int startId, int endId) {
    int suppElementId = partition(arrayStart, startId, endId);
    if (startId < suppElementId - 1)
        recursiveQuickSort(arrayStart, startId, suppElementId - 1);
    if (suppElementId < endId)
        recursiveQuickSort(arrayStart, suppElementId, endId);
}

void ArrayUtil::generateArray(int *arrayStart, int startId, int endId) {
    arrayStart += startId;
    srand(time(nullptr));
    for (int i = startId; i < endId; i++, arrayStart++)
        *arrayStart = rand() % 21 - 10;
}

void ArrayUtil::printArray(const int *arrayStart, int startId, int endId) {
    arrayStart += startId;
    for (int i = startId; i < endId; i++, arrayStart++)
        cout << *arrayStart << "|";
    cout << endl << endl;
}

int ArrayUtil::pairSearch(const int *const arrayStart, int left, int right, int value) {
    if (*(arrayStart + left) == value)
        return left;
    if (*(arrayStart + right) == value)
        return right;
    return -1;
}

int ArrayUtil::bSearch(const int* const arrayStart, int left, int right, int value) {
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

int ArrayUtil::recursiveBSearch(const int* const arrayStart, int left, int right, int value) {
    int middle = (right + left) / 2;

    if (left + 1 == right)
        return pairSearch(arrayStart, left, right, value);
    else if (*(arrayStart + middle) < value)
        recursiveBSearch(arrayStart, middle, right, value);
    else
        recursiveBSearch(arrayStart, left, middle, value);
}
