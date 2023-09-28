/*
 * file: proj1-testmain.cpp
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
 * Tests functions to sort by age
 * Tests functions to sort by name
 * Tests functions to see if it can handle max people
 * Tests findAPerson
 */

#include "proj1-person.hpp"

using namespace std;

int main() {
    const int MAX_PEOPLE = 25;
    const int NUM_PPL = 7;
    Person thePeople[MAX_PEOPLE];
    Person *rThePeople[MAX_PEOPLE];
    Person *foundPerson;

    //fill pointer array
    for (int i = 0; i < MAX_PEOPLE; i++) {
        rThePeople[i] = &thePeople[i];
    }

    //fill person array
    thePeople[0].name = "Josh";
    thePeople[1].name = "Joe";
    thePeople[2].name = "Henry";
    thePeople[3].name = "Matt Smith";
    thePeople[4].name = "Matt";
    thePeople[5].name = "Matthew";
    thePeople[6].name = "Bella";

    thePeople[0].age = 23;
    thePeople[1].age = 54;
    thePeople[2].age = 21;
    thePeople[3].age = 21;
    thePeople[4].age = 76;
    thePeople[5].age = 12;
    thePeople[6].age = 8;

    //test sortPersonArrayByAge
    sortPersonArrayByAge(rThePeople, NUM_PPL);
    for (int i = 0; i < NUM_PPL; i++) {
        displayAPerson(cout, rThePeople[i]);
    }

    cout << endl;

    //test sortPersonArrayByName
    sortPersonArrayByName(rThePeople, NUM_PPL);
    for (int i = 0; i < NUM_PPL; i++) {
        displayAPerson(cout, rThePeople[i]);
    }

    cout << endl;

    //fill to max people (25)
    for (int i = 7; i < MAX_PEOPLE; i++) {
        thePeople[i].age = 10;
        thePeople[i].name = "Gary";
    }

    //test sortPersonArrayByName with more people
    sortPersonArrayByName(rThePeople, MAX_PEOPLE);
    for (int i = 0; i < MAX_PEOPLE; i++) {
        displayAPerson(cout, rThePeople[i]);
    }

    cout << endl;

    //test findAPerson
    foundPerson = findAPerson(rThePeople, MAX_PEOPLE, "Matt");
    displayAPerson(cout, foundPerson);
    foundPerson = findAPerson(rThePeople, MAX_PEOPLE, "Matt Smith");
    displayAPerson(cout, foundPerson);

    return 0;
}
