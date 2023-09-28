/*
 * file: proj1-main.cpp
 * author: Michael Mathews
 * course: CSI 1440
 * assignment: Project 1
 * due date: 8/30/21
 *
 * date modified: 8/26/21
 *      - File Created
 *
 * date modified: 8/28/21
 *      - all files basic code written
 *
 * date modified: 8/29/21
 *      - all files completed
 *
 * Fills Person array and Person pointer array with people
 * Searches and sorts the arrays as requested
 * Displays first 5 people in array as requested
 */

#include <iostream>
#include <fstream>
#include "proj1-person.hpp"

using namespace std;

int main() {
    ifstream inputFile;
    const int MAX_PEOPLE = 25;
    int display = 5;
    Person thePeople[MAX_PEOPLE];
    Person *rThePeople[MAX_PEOPLE];
    int count = 0;
    string pName;

    //open file
    inputFile.open("people.dat");

    //test stream
    if (!inputFile) {
        cerr << "Bad" << endl;
        return 1;
    }

    getAPersonFromStream(inputFile, &thePeople[count]);
    //fill Person array and pointer array
    while ((!inputFile.eof()) and count < MAX_PEOPLE) {
        rThePeople[count] = &thePeople[count];
        count++;
        getAPersonFromStream(inputFile, &thePeople[count]);
    }

    //if less than 5 people exist set display to how many people there are
    if (count < display) {
        display = count;
    }

    //sort by age
    sortPersonArrayByAge(rThePeople, count);
    //display first 5 people (if 5 exist)
    for (int i = 0; i < display; i++) {
        displayAPerson(cout, rThePeople[i]);
    }


    //sort by name
    sortPersonArrayByName(rThePeople, count);
    //display first 5 people (if 5 exist)
    for (int i = 0; i < display; i++) {
        displayAPerson(cout, rThePeople[i]);
    }

    while (inputFile >> pName and pName != "no more") {
        displayAPerson(cout, findAPerson(rThePeople, count, pName));
    }

    inputFile.close();

    return 0;
}
