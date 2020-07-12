#include <bits/stdc++.h>
using namespace std;

int sumLengthOfWords(vector<string> words) {
    // Gets total length of words in vector
    int sum = 0;
    for (auto i : words) {
        sum += i.length();
    }
    return sum + words.size() - 1; // Length of words + spaces amount
}

int findAllOccurencesInWord(string s, string word) {
    // Find amount of occurences of words s in word
    int occurences = 0;
    size_t found = word.find(s);
    while (found != string::npos && found < word.length()) {
        occurences++;
        found = word.find(s, found+1);
    }
    return occurences;
}

int getLenghtAfterDeleting(string s, vector<string> &words) {
    // Tries to delete all occurences of string from word
    int occurences = 0;
    for (int i = 0; i < words.size(); i++) {
        occurences += findAllOccurencesInWord(s, words[i]);
    }
    return sumLengthOfWords(words) - s.length() * occurences;
}

pair<int, int> minimal(int results[3]) {
    // Gets the minimal value from array of 3 results.
    int m = results[0], x = 0;
    for (int i = 1; i < 3; i++) {
        if (results[i] < m) {
            m = results[i];
            x = i;
        }
    }
    pair<int, int> result = make_pair(m, x);
    return result;
}

pair<int, int> solution(string combinations[3], vector<string> &words) {
    // Tries deleting 3 different combinations and gets the minimal result.
    int results[3];
    for (int i = 0; i < 3; i++) {
        results[i] = getLenghtAfterDeleting(combinations[i], words);
    }
    pair<int, int> result = minimal(results);
    return result;
}

int main() {
    int len;

    cin >> len;

    string combinations[3];
    for (int i = 0; i < 3; i++) {
        cin >> combinations[i];
    }

    vector<string> words;
    for (int i = 0; i < len; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    pair<int, int> result = solution(combinations, words);
    cout << result.second << ' ' << result.first << endl;
    return 0;
}
