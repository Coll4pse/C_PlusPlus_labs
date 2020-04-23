#ifndef ALGORITHMS_ARRAYUTIL_H
#define ALGORITHMS_ARRAYUTIL_H


class ArrayUtil {
public:
    static int search(const int* arrayStart, const int startId, const int endId, const int value);
    static void quickSort(int* arrayStart, const int startId, const int endId);
    static void recursiveQuickSort(int* arrayStart, const int startId, const int endId);
    static void generateArray(int* arrayStart, const int startId, const int endId);
    static void printArray(const int* arrayStart, const int startId, const int endId);
    static int bSearch(const int* const arrayStart, int left, int right, const int value);
    static int recursiveBSearch(const int* const arrayStart, int left, int right, const int value);
private:
    ArrayUtil() = default;

    static void swap(int* const first, int* const second);
    static int partition(int* const arrayStart, int leftBorder, int rightBorder);
    static int pairSearch(const int* const arrayStart, const int left, const int right, const int value);
};


#endif //ALGORITHMS_ARRAYUTIL_H
