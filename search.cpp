#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Resource {
    int id;
    string subject;
    string topic;
    string content;
};

struct Result {
    Resource resource;
    int score;
};

string toLowerCase(string s) {
    for (char& c : s)
        c = (char)tolower((unsigned char)c);
    return s;
}

int countMatches(string text, string keyword) {
    text = toLowerCase(text);
    keyword = toLowerCase(keyword);

    if (keyword.empty()) return 0;

    int count = 0;
    size_t pos = 0;

    while ((pos = text.find(keyword, pos)) != string::npos) {
        count++;
        pos += keyword.length();
    }

    return count;
}

int relevanceScore(const Resource& r, string keyword) {
    return 3 * countMatches(r.topic, keyword)
         + 2 * countMatches(r.subject, keyword)
         + countMatches(r.content, keyword);
}

void searchResources(const vector<Resource>& resources) {
    string keyword;
    cout << "Enter search keyword: ";
    getline(cin, keyword);

    if (keyword.empty()) {
        cout << "Keyword cannot be empty.\n";
        return;
    }

    vector<Result> results;

    for (const Resource& r : resources) {
        int score = relevanceScore(r, keyword);
        if (score > 0)
            results.push_back({r, score});
    }

    if (results.empty()) {
        cout << "No matching resources found.\n";
        return;
    }

    for (int i = 0; i < (int)results.size() - 1; i++) {
        for (int j = 0; j < (int)results.size() - i - 1; j++) {
            if (results[j].score < results[j + 1].score)
                swap(results[j], results[j + 1]);
        }
    }

    cout << "\nSearch results:\n";

    for (const Result& result : results) {
        cout << "ID: " << result.resource.id
             << " | Subject: " << result.resource.subject
             << " | Topic: " << result.resource.topic
             << " | Score: " << result.score << "\n";
    }
}

int main() {
    vector<Resource> resources = {
        {1, "DSA", "Binary Search", "Searching in a sorted array"},
        {2, "DSA", "Linked List", "Nodes and pointers"},
        {3, "Programming", "Binary Search Tree",
         "Tree data structure and searching"},
        {4, "DSA", "Sorting Algorithms",
         "Bubble sort and selection sort"}
    };

    cout << "--- Academic Resource Search ---\n";
    cout << "Available sample resources: 4\n";

    string again;

    do {
        searchResources(resources);
        cout << "\nSearch again? (yes/no): ";
        cin >> again;
        cin.ignore(10000, '\n');
    } while (toLowerCase(again) == "yes");

    return 0;
}