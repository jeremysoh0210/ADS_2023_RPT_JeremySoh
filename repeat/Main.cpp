#include "OrderedArray.h"
#include <iostream>
using namespace std;

// display the OrderedArray's content
template <typename T>
void printOrderedArray(const OrderedArray<T>& arr) {
    cout << "OrderedArray: ";
    for (int i = 0; i < arr.length(); ++i) {
        cout << arr.getElement(i) << " ";
    }
    cout << endl;
}
 
int main() {
    OrderedArray<int> intArr(5);

    // push the elements into the array
    intArr.push(33);
    intArr.push(11);
    intArr.push(55);
    intArr.push(22);
    intArr.push(44);

    // print the array in order
    printOrderedArray(intArr);

    // search an elements that is not exist (result should be -1)
    int searchResult = intArr.search(99);
    cout << "Search result for 99: " << searchResult << endl;

    // search an elements that is exist (result should be the position in the ordered array which is 2)
    int searchResult2 = intArr.search(33);
    cout << "Search result for 33: " << searchResult2 << endl;

    // remove an element from the array
    bool removeResult = intArr.remove(1);
    if (removeResult) {
        cout << "Element removed successfully." << endl;
    }
    else {
        cout << "Failed" << endl;
    }

    // result --- OrderedArray: 11 33 44 55
    // 22 is removed
    printOrderedArray(intArr);


    // using OrderedArray of strings
    OrderedArray<string> strArr(4);

    strArr.push("jeremy");
    strArr.push("abigale");
    strArr.push("zoe");
    strArr.push("kacy");

    printOrderedArray(strArr); // Output: OrderedArray: apple banana grape orange

    // clearing the array and memory
    strArr.clear();
    printOrderedArray(strArr); // check if the array and memory is free

    return 0;
}