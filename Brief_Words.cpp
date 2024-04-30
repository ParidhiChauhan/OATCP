#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate all subsequences of length 1 to 4 for a given word
vector<string> generateShortForms(const string& word) {
    vector<string> shortForms;

    for (int i = 0; i < word.length(); ++i) {
        for (int j = i; j < word.length(); ++j) {
            string sub = word.substr(i, j - i + 1);
            if (sub.length() <= 4) {
                shortForms.push_back(sub);
            }
        }
    }

    return shortForms;
}

int main() {
    // Input words from the user
    int n;
    cout << "Enter the number of words in the dictionary: ";
    cin >> n;

    vector<string> dictionary(n);
    cout << "Enter the words in the dictionary:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> dictionary[i];
    }

    // Mapping from words to their shortened forms
    unordered_map<string, vector<string>> shortenedForms;

    // Generating shortened forms for each word in the dictionary
    for (const string& word : dictionary) {
        vector<string> shortForms = generateShortForms(word);
        shortenedForms[word] = shortForms;
    }

    // Displaying the shortened forms
    cout << "\nShortened forms for each word in the dictionary:" << endl;
    for (const auto& entry : shortenedForms) {
        cout << entry.first << ": ";
        for (const string& shortForm : entry.second) {
            cout << shortForm << " ";
        }
        cout << endl;
    }

    return 0;
}
