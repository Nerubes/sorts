#ifndef SORT_HEAD_H_2023_03_15
#define SORT_HEAD_H_2023_03_15

namespace templates {
/** Определение типа функции сравнения элементов
\return
\li > 0  - pElem1 меньше pElem2
\li 0   - элементы pElem1 и pElem2 равны
\li < 0 - pElem1 больше pElem2
*/
typedef int (CompareSortType)(const void *pElem1, const void *pElem2);

void mergeSort(void **ppArray, int length, CompareSortType pCompareFunc, void **tmp = nullptr);
void heapSort(void **ppArray, int length, CompareSortType pCompareFunc);

template<class T>
void mergeSort(T **ppArray,
               int length,
               int (pCompareFunc)(const T *pElem1, const T *pElem2),
               void **tmp = nullptr) {
  tmp = new void *[length];
  mergeSort(reinterpret_cast<void **>(ppArray), length, (CompareSortType *) pCompareFunc, tmp);
  delete[] tmp;
}
template<class T>
void heapSort(T **ppArray, int length, int (pCompareFunc)(const T *pElem1, const T *pElem2)) {
  heapSort(reinterpret_cast<void **>(ppArray), length, (CompareSortType *) pCompareFunc);
}
}; // namespace templates

#endif // #define SORT_HEAD_H_2023_03_15
