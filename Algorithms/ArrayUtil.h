#ifndef ALGORITHMS_ARRAYUTIL_H
#define ALGORITHMS_ARRAYUTIL_H


class ArrayUtil {
public:
    static int search(const int* arrayStart, int startId, int endId, int value);
    static void quickSort(int* arrayStart, int left, int right);
    static void recursiveQuickSort(int* arrayStart, int startId, int endId);
    static void generateArray(int* arrayStart, int startId, int endId);
    static void printArray(const int* arrayStart, int startId, int endId);
    static int bSearch(const int* const arrayStart, int left, int right, int value);
    static int recursiveBSearch(const int* const arrayStart, int left, int right, int value);
private:
    ArrayUtil() = default;

    static void swap(int* const first, int* const second);
    static int partition(int* const arrayStart, int leftBorder, int rightBorder);
    static int pairSearch(const int* const arrayStart, int left, int right, int value);
};


#endif //ALGORITHMS_ARRAYUTIL_H
