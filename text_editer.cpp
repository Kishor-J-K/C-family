#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line;

    ofstream out_file;
    out_file.open("output.txt");
    if (!out_file)
    {
        cout << "out_file opening error";
        return 0;
    }

    ifstream in_file;
    in_file.open("input.txt");
    if (!in_file)
    {
        cout << "in_file opening error";
        return 0;
    }

    int r{0}, ascii{0}, x{0};
    char c{};

    while (in_file.get(c))
    {
        ascii = static_cast<int>(c);

        if (c == ' ')
        {
            r++;
        }
        else
        {
            r = 0;
        }

        if (r >= 2)
        {
            continue;
        }
        else if (ascii == 10)
        {
            x++;
            out_file << " ";
        }
        else
        {
            x = 0;
            out_file << c;
        }

        if (x > 1)
        {
            out_file << "\n";
        }
    }

    out_file.close();
    in_file.close();

    return 0;
}