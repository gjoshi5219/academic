#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Record {
    int id;
    string subject, topic, content;
    int priority;
};

int findRecord(const vector<Record>& records, int id) {
    for (int i = 0; i < (int)records.size(); i++)
        if (records[i].id == id) return i;
    return -1;
}

void addRecord(vector<Record>& records) {
    Record r;

    cout << "Enter ID: ";
    cin >> r.id;

    if (findRecord(records, r.id) != -1) {
        cout << "ID already exists.\n";
        return;
    }

    cin.ignore(10000, '\n');
    cout << "Enter subject: ";
    getline(cin, r.subject);
    cout << "Enter topic: ";
    getline(cin, r.topic);
    cout << "Enter content: ";
    getline(cin, r.content);
    cout << "Enter priority (1-10): ";
    cin >> r.priority;

    if (r.priority < 1 || r.priority > 10) {
        cout << "Invalid priority.\n";
        return;
    }

    records.push_back(r);
    cout << "Record added successfully.\n";
}

void displayRecords(const vector<Record>& records) {
    if (records.empty()) {
        cout << "No records available.\n";
        return;
    }

    for (const Record& r : records) {
        cout << "\nID: " << r.id
             << "\nSubject: " << r.subject
             << "\nTopic: " << r.topic
             << "\nContent: " << r.content
             << "\nPriority: " << r.priority << "\n";
    }
}

void searchRecord(const vector<Record>& records) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    int index = findRecord(records, id);

    if (index == -1) {
        cout << "Record not found.\n";
        return;
    }

    const Record& r = records[index];
    cout << "Found: " << r.subject << " - " << r.topic
         << "\nContent: " << r.content
         << "\nPriority: " << r.priority << "\n";
}

int main() {
    vector<Record> records;
    int choice;

    do {
        cout << "\n--- Academic Record Management ---\n";
        cout << "1. Add Record\n2. Display Records\n";
        cout << "3. Search by ID\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(records); break;
            case 2: displayRecords(records); break;
            case 3: searchRecord(records); break;
            case 0: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}