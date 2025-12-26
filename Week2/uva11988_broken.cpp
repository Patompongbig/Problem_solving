#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        deque<string> segments;
        string buffer;
        bool insert_front = false;

        for (char c : line) {
            if (c == '[' || c == ']') {
                if (!buffer.empty()) {
                    if (insert_front) {
                        segments.push_front(buffer);
                    } else {
                        segments.push_back(buffer);
                    }
                    buffer.clear();
                }
                insert_front = (c == '[');
            } else {
                buffer += c;
            }
        }

        if (!buffer.empty()) {
            if (insert_front) {
                segments.push_front(buffer);
            } else {
                segments.push_back(buffer);
            }
        }

        string result;
        for (const auto& seg : segments) {
            result += seg;
        }

        cout << result << '\n';
    }

    return 0;
}