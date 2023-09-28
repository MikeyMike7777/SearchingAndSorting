/*
 * file: proj1-person.cpp
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
 * Functions to use on Person array
 */

#include "proj1-person.h"

/**
-  getAPersonFromStream
-
-  This function reads a single Person from the stream
-
-  Parameters:
-    input: istream
-    ppl: Person
-
-  Output:
-    return: input
*/

istream &getAPersonFromStream(istream &input, Person *ppl) {
    getline(input, ppl->name, ',');
    input >> ppl->age;
    input.ignore(1, '\n');
    return input;
}

/**
-  sortPersonArrayByAge
-
-  implements selection sort to sort array of People by age in ascending order
-
-  Parameters:
-    rPeople: Person**
-    n: int - amount of people
-
-  Output:
-    return: none
*/

void sortPersonArrayByAge(Person **rPeople, int n) {
    //selection sort
    int min_age;

    //move unsorted array starting point
    for (int i = 0; i < n-1; i++) {
        //find smallest element
        min_age = i;
        for (int j = i+1; j < n; j++) {
            if (rPeople[j]->age < rPeople[min_age]->age) {
                min_age = j;
            }
        }
        //swap first element with smallest element
        swap(rPeople[min_age], rPeople[i]);
    }
}

/**
-  sortPersonArrayByName
-
-  implements bubble sort to sort array of People by name in ascending order
-
-  Parameters:
-    rPeople: Person**
-    n: int - amount of people
-
-  Output:
-    return: none
*/

void sortPersonArrayByName(Person **rPeople, int n) {
    //bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //swap names
            if (rPeople[j]->name > rPeople[j + 1]->name) {
                swap(rPeople[j], rPeople[j + 1]);
            }
        }
    }
}

/**
-  findAPerson
-
-  implements linear search to find a specific Person
-
-  Parameters:
-    rPeople: Person**
-    n: int - amount of people
-    pName: string - name of person being searched for
-
-  Output:
-    return: Person* unless Person not found; return: nullptr
*/

Person* findAPerson(Person **rPeople, int n, string pName) {
    int i = 0;
    //linear search to find person
    while (i < n and rPeople[i]->name != pName) {
        i++;
    }

    //if person found, return person pointer
    if (rPeople[i]->name == pName) {
        return rPeople[i];
    }
    else {
        return nullptr;
    }
}

/**
-  displayAPerson
-
-  writes a single Person to the stream
-
-  Parameters:
-    out: ostream
-    ppl: Person*
-
-  Output:
-    return: none
*/

void displayAPerson(ostream &out, const Person *ppl) {
    out << ppl->name << ", " << ppl->age << endl;
}