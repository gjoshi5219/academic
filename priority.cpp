
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Resource {
    int id;
    string subject;
    string topic;
    int priority;
};

struct ComparePriority {
    bool operator()(const Resource& a, const Resource& b) const {
        if (a.priority == b.priority)
            return a.id > b.id;
        return a.priority < b.priority;
    }
};

void addResource(priority_queue<Resource, vector<Resource>,
                ComparePriority>& pq) {
    Resource r;

    cout << "Enter resource ID: ";
    cin >> r.id;
    cout << "Enter subject: ";
    cin >> ws;
    getline(cin, r.subject);
    cout << "Enter topic: ";
    getline(cin, r.topic);
    cout << "Enter priority (1-10): ";
    cin >> r.priority;

    if (r.id < 1 || r.priority < 1 || r.priority > 10) {
        cout << "Invalid ID or priority.\n";
        return;
    }

    pq.push(r);
    cout << "Resource added successfully.\n";
}

void displayTopResources(
    priority_queue<Resource, vector<Resource>, ComparePriority> pq) {

    if (pq.empty()) {
        cout << "No resources available.\n";
        return;
    }

    int n;
    cout << "How many top resources? ";
    cin >> n;

    if (n <= 0) {
        cout << "Enter a positive number.\n";
        return;
    }

    cout << "\nHighest-priority resources:\n";

    for (int i = 0; i < n && !pq.empty(); i++) {
        Resource r = pq.top();
        pq.pop();

        cout << i + 1 << ". ID: " << r.id
             << " | Subject: " << r.subject
             << " | Topic: " << r.topic
             << " | Priority: " << r.priority << "\n";
    }
}

int main() {
    priority_queue<Resource, vector<Resource>, ComparePriority> pq;
    int choice;

    do {
        cout << "\n--- Resource Priority Management ---\n";
        cout << "1. Add Resource\n2. Show Top Resources\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addResource(pq);
                break;
            case 2:
                displayTopResources(pq);
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
