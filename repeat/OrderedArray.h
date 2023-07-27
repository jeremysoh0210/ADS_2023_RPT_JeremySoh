#pragma once
template <typename T>
class OrderedArray {
private:
    T* data;         // the dynamic array's pointer
    int size;        // the array's current element count
    int capacity;    // array's current capacity
    int grow_size;   // How much the array will expand if it is resized

public:
    // the constructors and destructor
    OrderedArray(int grow_size = 10);
    OrderedArray();
    ~OrderedArray();

    void push(const T& newElement);
    int length() const;
    T getElement(int index) const;
    bool remove(int index);
    int search(const T& target) const;
    void clear();
};

// constructor that is using (grow_size) parameter
template <typename T>
OrderedArray<T>::OrderedArray(int grow_size) : size(0), capacity(grow_size), grow_size(grow_size) {
    data = new T[capacity];
}

template <typename T>
OrderedArray<T>::OrderedArray() : size(0), capacity(10), grow_size(10) {
    data = new T[capacity];
}

template <typename T>
OrderedArray<T>::~OrderedArray() {
    delete[] data;
}

// add new element in order to the array
template <typename T>
void OrderedArray<T>::push(const T& newElement) {
    if (size >= capacity) {
        // resize the array by grow_size if it is full.
        capacity += grow_size;
        T* new_data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    // find the location in the ordered array where to insert the new element.
    int position = 0;
    while (position < size && data[position] < newElement) {
        ++position;
    }

    // move the elements around to make space for the new element
    for (int i = size; i > position; --i) {
        data[i] = data[i - 1];
    }

    // add the new element at the correct position
    data[position] = newElement;
    ++size;
}

// get the number of the elements in the array
template <typename T>
int OrderedArray<T>::length() const {
    return size;
}

// get the index of the elements
template <typename T>
T OrderedArray<T>::getElement(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return T();
}

// remove the element at the index that is given
template <typename T>
bool OrderedArray<T>::remove(int index) {
    if (index >= 0 && index < size) {
        // shift elements to remove the specified element
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
        return true;
    }
    return false;
}

// using binary search to search for a specific target value in the array
template <typename T>
int OrderedArray<T>::search(const T& target) const {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            return mid;
        }
        else if (data[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    // if the element is not found, shows -1
    return -1;
}

// clear the array and free the memory
template <typename T>
void OrderedArray<T>::clear() {
    delete[] data;
    size = 0;
    capacity = grow_size;
    data = new T[capacity];
}