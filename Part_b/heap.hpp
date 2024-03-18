#include <vector>

#ifndef HEAP_HPP
#define HEAP_HPP

using namespace std;

template <typename T> class heap
{
    public:
        T getItem(int n);
        void initializeMaxHeap(vector<T>& inputDict);
        void maxHeapify(int location);
        void buildMaxHeap();
        void printHeap();
        vector<T> heapSort();

    private:
        vector<T> heapV;
        int parent(int location);
        int left(int location);
        int right(int location);
        void swap(int location, int otherLocation);
        int heapSize;
};

template <typename T>
T heap<T>::getItem(int n)
{
    return heapV[n];
}

template <typename T>
void heap<T>::swap(int location, int otherLocation)
{
    T temp = heapV[location];
    heapV[location] = heapV[otherLocation];
    heapV[otherLocation] = temp;
}

template <typename T>
int heap<T>::parent(int location)
{
    int parentLocation = location/2;
    return parentLocation;
}

template <typename T>
int heap<T>::left(int location)
{
    int leftChild = location*2;
    return leftChild;
}

template <typename T>
int heap<T>::right(int location)
{
    int rightChild = (location*2)+1;
    return rightChild;
}

template <typename T>
void heap<T>::initializeMaxHeap(vector<T>& inputDict)
{
    heapV = inputDict;
    heapSize = heapV.size();
}

template <typename T>
void heap<T>::maxHeapify(int location)
{
    int l = left(location);
    int r = right(location);
    int largest = location;
    
    if (l <= heapSize && heapV[l-1] > heapV[location-1])
    {
        largest = l;
    }
    if (r <= heapSize && heapV[r-1] > heapV[largest-1])
    {
        largest = r;
    }
    if (largest != location)
    {
        swap(largest-1, location-1);
        maxHeapify(largest);
    }
}

template <typename T>
void heap<T>::buildMaxHeap()
{
    for (int i = heapV.size()/2; i > 0; i--)
    {
        maxHeapify(i);
    }
}

template <typename T>
void heap<T>::printHeap()
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << heapV[i] << " ";
    }
    cout << endl;
}

template <typename T>
vector<T> heap<T>::heapSort()
{
    for (int i = heapSize; i > 1; i--)
    {
        swap(0, i-1);
        heapSize--;
        maxHeapify(1);
    }
    return heapV;
}

#endif