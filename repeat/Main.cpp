#include <iostream>
#include "OrderedArray.cpp"
#include <string>

using namespace std;


int main() {    
    cout << "Q1" << endl;
    cout << endl;

    OrderedArray<int> intArray(5);
    OrderedArray<float> floatArray;
    OrderedArray<double> doubleArray;

    //push elements to intArray
    intArray.push(10);
    intArray.push(5);
    intArray.push(15);
    intArray.push(2);
    intArray.push(8);

    //print out the length of the array
    cout << "Length of the array: " << intArray.length() << endl;
    cout << endl;

    //loop to print out the elements from the array
    cout << "Elements of the array: ";

    for (int i = 0; i < intArray.length(); i++) {
        cout << intArray.getElement(i) << " ";
    }
    cout << endl;
    cout << endl;
    //search element 15 from the intArray (valid element)
    int searchElement = 15;
    int index = intArray.search(searchElement);
    string MessageError = "not found!";

    //check if the index is valid
    if (index >= 0) {
        cout << "Found " << searchElement << " at index " << index << endl;
    }

    //else shows error msg
    else {
        cout << searchElement << " " << MessageError << endl;
    }
    cout << endl;
    //search element 115 from the intArray (invalid element)
    int searchElement1 = 115;
    int index1 = intArray.search(searchElement1);

    //check if the index is valid
    if (index1 >= 0) {
        cout << "Found " << searchElement1 << " at index " << index1 << endl;
    }

    //else shows error msg
    else {
        cout << searchElement1 << " " << MessageError << endl;
    }
    cout << endl;

    //remove the element from position 1
    intArray.remove(1);

    //print the length after remove element
    cout << "Length after element got removed: " << intArray.length() << endl;
    cout << endl;

    //print the element of the array after the element got removed to check
    cout << "Elements of the array after element got removed: ";
    for (int i = 0; i < intArray.length(); i++) {
        cout << intArray.getElement(i) << " ";
    }
    cout << endl;
    cout << endl;

    //clear the data structure and remove all the elements
    intArray.clear();

    //check if the array is cleared
    cout << "Length after clearing: " << intArray.length() << endl;
    cout << endl;

    return 0;
}