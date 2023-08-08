#include <iostream>
//#include "OrderedArray.cpp"
#include "MySet.cpp"

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

    /////////////////////////////////////////////////////////////////////////////////////////////
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << endl;

    //push the float elements to the array
    floatArray.push(7.89f);
    floatArray.push(1.234f);
    floatArray.push(5.678f);

    //print out the quantity of the elements from the array
    cout << "Quantity of the element: " << floatArray.length() << endl;
    cout << endl;

    //print out the elements from the array using loop
    for (int i = 0; i < floatArray.length(); ++i) {
        cout << "Float Element " << i << ": " << floatArray.getElement(i) << endl;
    }
    cout << endl;


    /////////////////////////////////////////////////////////////////////////////////////////////
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;

    //push double elements to the array
    doubleArray.push(1.11);
    doubleArray.push(2.22);
    doubleArray.push(3.33);
    doubleArray.push(4.44);

    //print out the quantity of the element from the array
    cout << "Double Array Length: " << doubleArray.length() << endl;
    cout << endl;
    
    //print out the elements from the array using loop
    for (int i = 0; i < doubleArray.length(); ++i) {
        cout << "Double Element " << i << ": " << doubleArray.getElement(i) << endl;
    }
    cout << endl;

    /////////////////////////////////////////////////////////////////////////////////////////////
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Q2" << endl;

    //add element 10,20,30 to set1
    MySet<int> set1;
    set1.insert(10);
    set1.insert(20);
    set1.insert(30);

    //add element 40,50,10 to set2
    MySet<int> set2;
    set2.insert(40);
    set2.insert(50);
    set2.insert(10);

    //create 2 instance which are unionSet and duplicateSet
    //unionSet to find all the unique elements from set1 and set2 by using operator |
    MySet<int> unionSet = set1 | set2;
    //duplicateSet to find the duplicate elements from set1 and set2 by using operator &
    MySet<int> duplicateSet = set1 & set2;

    //print out all the elements of set1 by using loop and getElement() function
    cout << "Element of Set 1: ";
    for (int i = 0; i < set1.size(); ++i) {
        cout << set1.getElement(i) << " ";
    }
    cout << endl;

    //print out all the elements of set2 by using loop and getElement() function
    cout << "Element of Set 2: ";
    for (int i = 0; i < set2.size(); ++i) {
        cout << set2.getElement(i) << " ";
    }
    cout << endl;

    cout << endl;

    //print out the unique elements from set1 and set2 in the unionSet
    cout << "Unique elements from two sets in Union Set: ";
    for (int i = 0;i < unionSet.size();++i)
    {
        cout << unionSet.getElement(i) << " ";
    }
    cout << endl;


    //print out the same elements from set1 and set2 in the duplicateSet
    cout << "Same elements from two sets in Duplicate Set: ";
    for (int i = 0;i < duplicateSet.size();++i)
    {
        cout << duplicateSet.getElement(i) << " ";
    }
    cout << endl;
    cout << endl;

    //test remove() function
    cout << "Remove 10 from set 2" << endl;
    set2.remove(10);

    //print out the elements of set 2
    cout << "Set 2 after remove 10: ";
    for (int i = 0; i < set2.size(); ++i) {
        cout << set2.getElement(i) << " ";
    }
    cout << endl;
    cout << endl;

    //check if 10 is still exist in set 2
    int CheckElement10 = 10;
    if (set2.contains(CheckElement10)) {
        cout << "Set 2 contains " << CheckElement10 << endl;
    }
    else {
        cout << CheckElement10 << " Not found !! " << endl;
    }

    //check if 20 is still exist in set 1
    int CheckElement20 = 20;
    if (set1.contains(CheckElement20)) {
        cout << "Set 1 contains " << CheckElement20 << endl;
    }
    else {
        cout << CheckElement20 << " Not found !! " << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    return 0;
}