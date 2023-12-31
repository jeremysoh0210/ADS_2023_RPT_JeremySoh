#include <iostream>
//#include "OrderedArray.cpp"
#include "MySet.cpp"
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include <string>

using namespace std;

//read the csv file by using the filename and the leads (to store the unique phone number)
void readLeadsCSV(const string& filename, unordered_set<string>& leads) {
    //if the file has problem and cannot be open
    //it will print out the error message
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error !!! Input file cannot be open: " << filename << endl;
        return;
    }

    string line;
    //to skip the first line and to move the file pointer past it
    getline(inputFile, line);

    //while looping each line
    while (getline(inputFile, line)) {
        //divide the line into seperate attributes
        istringstream ss(line);
        string phoneNumber;

        //read the datas until a comma is encountered
        getline(ss, phoneNumber, ',');

        //store it in phoneNumber var
        leads.insert(phoneNumber);
    }

    //close the csv file
    inputFile.close();
}

void writeCSV(const string& filename, const vector<string>& leads) {
    //using output file stream to open the file by the filename
    ofstream outputFile(filename);

    //if the file has problem and cannot be open
    //it will print out the error message
    if (!outputFile.is_open()) {
        cout << "Error !!! Output file cannot be open: " << filename << endl;
        return;
    }

    outputFile << "Phone Number" << endl;

    //loop and write the phone number to the output file
    for (const string& phoneNumber : leads) {
        outputFile << phoneNumber << endl;
    }

    //close the output file
    outputFile.close();
}

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
    cout << endl;
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
    cout << endl;

    //clear all the elements in set2
    set2.clear();

    //print out the size of set2 after clearing all the elements
    cout << "Size of set 2 after using clear() : " << set2.size() << endl;
    cout << endl;
    /////////////////////////////////////////////////////////////////////////////////////////////
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
    cout << "Q3" << endl;
    
    //create two unordered_set<string> which are johnLeads and janeLeads, used to store phone numebr
    unordered_set<string> johnLeads, janeLeads;

    //read the file's name which are "johns_leads_20.csv" and store the phone numbers into unordered set which is named johnLeads
    readLeadsCSV("johns_leads_20.csv", johnLeads);
    readLeadsCSV("janes_leads_20.csv", janeLeads);

    //create 3 vectors which are commonLeads, johnUniqueLeads, janeUniqueLeads
    //these vectors are used to store the results of unique elements and duplicate elements
    vector<string> commonLeads, johnUniqueLeads, janeUniqueLeads;

    //loop and compare through every phone number from johnLeads set
    for (const string& phoneNumber : johnLeads) {
        //check if the phone number is found in janeLeads set, it is a common lead
        if (janeLeads.count(phoneNumber)) {
            //then the phone number will be added to commonLeads vector using push_back() function
            commonLeads.push_back(phoneNumber);
        }
        else {
            //else it is a unique lead submitted by john
            //use push_back() function to add the phone number to johnUniqueLeads
            johnUniqueLeads.push_back(phoneNumber);
        }
    }

    //loop through each phone number from janeLeads
    for (const string& phoneNumber : janeLeads) {
        //check if the phone number is not found in johnLeads set
        if (!johnLeads.count(phoneNumber)) {
            //then it is an unique lead by jane
            //use push_back() function to add the phone number to janeUniqueaLeads
            janeUniqueLeads.push_back(phoneNumber);
        }
    }

    //used writeCSV() function to write the common and unique leads into the csv files below
    writeCSV("common.csv", commonLeads);
    writeCSV("john_unique.csv", johnUniqueLeads);
    writeCSV("jane_unique.csv", janeUniqueLeads);

    cout << "The data are added to the CSV files." << endl;
    cout << "You can check the CSV files from the folder." << endl;

    cout << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    //To read the data from the csv files by the filename
    ifstream commonFile("common.csv");
    ifstream janeUniqueFile("jane_unique.csv");
    ifstream johnUniqueFile("john_unique.csv");

    cout << endl;
    cout << "Data from the common.csv file" << endl;

    //check if the commonFile is open
    if (commonFile.is_open()) {
        string line;
        int commonCount = 0;
        //loop through from commonFile and increase the commonCount by reading through each line using getline() function
        while (getline(commonFile, line)) {
            commonCount++;
        }
        //close annd release the commondFile after reading the file
        commonFile.close();
        //taking the header row out of the commonCount by subtracting 1 to show the counts
        cout << "Amount of data in common.csv: " << commonCount - 1 << " rows." << endl;
    }
    else {
        cerr << "Error opening common.csv" << endl;
    }

    //open the filename which is "common.csv"
    commonFile.open("common.csv");
    string line;

    //read the file's first line, then deletes it
    getline(commonFile, line);
    //reads the line from the file and stores it in "line" and print out in the while loop
    while (getline(commonFile, line)) {
        cout << line << endl;
    }

    //close annd release the commondFile after reading the file
    commonFile.close();
    cout << endl; 
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << endl;
    cout << "Data from the jane_unique.csv file" << endl;

    //check if janeUniqueFile is open
    if (janeUniqueFile.is_open()) {
        string line1;
        int janeUniqueCount = 0;
        //loop through from janeUniqueFile and increase the janeUniqueCount by reading through each line using getline() function
        while (getline(janeUniqueFile, line1)) {
            janeUniqueCount++;
        }
        //close annd release the janeUniqueFile after reading the file
        janeUniqueFile.close();
        cout << "Amount of data in jane_unique.csv: " << janeUniqueCount - 1 << " rows." << endl;
    }
    else {
        cerr << "Error opening jane_unique.csv" << endl;
    }

    //open the filename which is "jane_unique.csv"
    janeUniqueFile.open("jane_unique.csv");
    string line1;

    //read the file's first line1, then deletes it
    getline(janeUniqueFile, line1);

    //reads the lines from the file and stores it in "line1" and print out in the while loop
    while (getline(janeUniqueFile, line1)) {
        cout << line1 << endl;
    }
    //close annd release the janeUniqueFile after reading the file
    janeUniqueFile.close();
    cout << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << endl;
    cout << "Data from the john_unique.csv file" << endl;

    //check if johnUniqueFile is open
    if (johnUniqueFile.is_open()) {
        string line2;
        int johnUniqueCount = 0;
        //loop through from johnUniqueFile and increase the johnUniqueCount by reading through each line using getline() function
        while (getline(johnUniqueFile, line2)) {
            johnUniqueCount++;
        }
        //close annd release the johnUniqueFile after reading the file
        johnUniqueFile.close();
        cout << "Amount of data in john_unique.csv: " << johnUniqueCount - 1 << " rows." << endl;
    }
    else {
        cerr << "Error opening john_unique.csv" << endl;
    }

    //open the filename which is "john_unique.csv"
    johnUniqueFile.open("john_unique.csv");
    string line2;

    //read the file's first line, then deletes it
    getline(johnUniqueFile, line2);

    //reads the lines from the file and stores it in "line2" and print out in the while loop
    while (getline(johnUniqueFile, line2)) {
        cout << line2 << endl;
    }
    //close annd release the johnUniqueFile after reading the file
    johnUniqueFile.close();
    cout << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    return 0;
}