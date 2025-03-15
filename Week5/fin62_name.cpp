#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name, text;
    int index = 0, value = 0;
    cin >> name;

    int max = name.size() - 1;
    cin >> text;

    for (int i = 0; i < text.size(); i++)
    {
        if (!text.empty() && text[i] == name[index])
        {
            index++;

            if (index > max) {
                value++;
                index = 0;
            }
        }
    }
    cout << value;

    return 0;
}