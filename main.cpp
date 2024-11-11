#include <iostream>
#include "LinkList.h"
#include "date.h"
using namespace std;

int main() {
    LinkList<int> list;
    list.addFirst(10);
    list.addLast(20);
    list.addAfter(10, 19);
    
    cout << "List after additions: " << list << endl;

    list.deleteFirst();
    cout << "List after deleting first: " << list << endl;

    list.deleteLast();
    cout << "List after deleting last: " << list << endl;

    list.addLast(30);
    list.addValue(25);
    list.addValue(30); // Will not be added since it exists
    cout << "List after adding values: " << list << endl;

    list.sortAscending();
    cout << "List after sorting ascending: " << list << endl;

    list.sortDescending();
    cout << "List after sorting descending: " << list << endl;

    return 0;
}
