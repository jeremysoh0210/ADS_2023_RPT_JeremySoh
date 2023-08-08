#include <iostream>
#include "OrderedArray.cpp"

template<typename T>
class MySet {
public:
    //the constructors and destructor
    MySet();
    MySet(const MySet& other);
    ~MySet();

    //insert element in order
    void insert(const T& value);
    //return quantity of the elements from the set
    int size() const;
    //return the index of the element from the set
    T getElement(int index) const;
    //check if the element is valid and remove it from the set
    bool remove(const T& value);
    //check if the element is in the set
    bool contains(const T& value) const;
    //clears the element from the set
    void clear();

    MySet<T> operator|(const MySet& other) const; // Union operator
    MySet<T> operator&(const MySet& other) const; // Intersection operator

private:
    OrderedArray<T> data;
};

template<typename T>
MySet<T>::MySet() {}

template<typename T>
MySet<T>::MySet(const MySet& other) : data(other.data) {}

template<typename T>
MySet<T>::~MySet() {}

//add the new elemens if if the elements is not contain in the elements
template<typename T>
void MySet<T>::insert(const T& value) {
    if (!contains(value)) {
        data.push(value);
    }
}

//return the number that is contained in the set
template<typename T>
int MySet<T>::size() const {
    return data.length();
}

//return the index number of the element that is search from the set
template<typename T>
T MySet<T>::getElement(int index) const {
    return data.getElement(index);
}

//remove the element that is set for
template<typename T>
bool MySet<T>::remove(const T& value) {
    //set the index as -1
    int index = -1;

    //loop through the set to see if the elements is match to the value
    for (int i = 0; i < data.length(); ++i) {
        if (data.getElement(i) == value) {
            index = i;
            break;
        }
    }

    //check if the valid index is greater or equal to 0
    if (index >= 0) {
        //remove the specify index of the elements
        return data.remove(index);
    }
    //return false if it's not found 
    return false;
}

//check if the elements is exist in the set
template<typename T>
bool MySet<T>::contains(const T& value) const {
    
}

//reset and remove all the elements from the set
template<typename T>
void MySet<T>::clear() {
    data.clear();
}

//create a new set by combining the union elements from the two sets
template<typename T>
MySet<T> MySet<T>::operator|(const MySet& other) const {
    
}

//create a new set by the duplicate, repeat elements from the two sets
template<typename T>
MySet<T> MySet<T>::operator&(const MySet& other) const {
    
}