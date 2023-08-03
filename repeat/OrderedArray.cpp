#include <iostream>

template <typename T>
class OrderedArray {
private:
    T* array;
    int capacity;
    int size;
    int grow_size;

public:
    // The Constructors and Destructor
    OrderedArray(int grow_size = 10) : capacity(grow_size), size(0), grow_size(grow_size) {
        array = new T[capacity];
    }

    OrderedArray(const OrderedArray& other) : capacity(other.capacity), size(other.size), grow_size(other.grow_size) {
        array = new T[capacity];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }

    //The delete[] deletes the dynamically allocated array, it releases the memory of the array
    //to prevent the memory leak
    ~OrderedArray() {
        delete[] array;
    }

    //to insert the elements to a ordered array
    void push(const T& newElement) {

        //to check if the size of the array is full
        if (size == capacity) {

            //if its full, the capacity will increase
            capacity += grow_size;

            //create a new array which name newArray and copy all the elements from the original array
            T* newArray = new T[capacity];

            //for loop
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }

            //delete the array to free the memory
            delete[] array;

            //set the pointer to point to the new array
            array = newArray;
        }

        int index = 0;

        //while loop to compare and to find the position to fit in to make the array in order
        while (index < size && array[index] < newElement) {
            index++;
        }

        //move elements to the right to make space fo the new elements
        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }

        //insert the new element at the right position
        array[index] = newElement;

        //increase the size
        size++;
    }

    //returns the quantity of the object
    int length() const {
        return size;
    }


    T getElement(int index) const {
        
        //check if the index is in the range
        if (index >= 0 && index < size) {
            //return the index of the element from the array
            return array[index];
        }
        return T();
    }

    //check if it's valid and remove the elements by its index
    bool remove(int index) {

        //check if the index is in the range
        if (index >= 0 && index < size) {

            //start a loop from the index to size - 2
            //move all the elements from the right of the index on position to the left
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }

            //decrease the size
            size--;

            //shows true if succeed
            return true;
        }
        //else return false
        return false;
    }

    //check if the target is in range and search the element and show its index
    int search(const T& target) const {
        
        //low is set for the beginning of the array
        int low = 0;

        //high is for the end of the array
        int high = size - 1;

        //using binary search to divided the range in half repeatedly to chek if the target match the middle element of the range
        while (low <= high) {
            int mid = (low + high) / 2;

            //if the mid elements match the target return index of mid
            if (array[mid] == target) {
                return mid;
            }

            //else if mid element is lesser than the target make low to mid + 1
            else if (array[mid] < target) {
                low = mid + 1;
            }

            //else the targer will be on the left side of the range, make high to mid - 1
            else {
                high = mid - 1;
            }
        }
        return -(low + 1);
    }

    //clear the data structure and remove all the elements
    void clear() {
        delete[] array;
        capacity = grow_size;
        size = 0;
        array = new T[capacity];
    }
};