#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <file1> <file2> ... <fileN>" << endl;
        return 1;
    }
    vector<long long int> v;
    for (int i = 1; i < argc; ++i)
    {
        filesystem::path file(argv[i]);

        if (filesystem::exists(file))
        {
            try
            {
                int sz = filesystem::file_size(file);
                cout << "File size of " << file << " is: "
                     << sz << " bytes" << endl;
                v.push_back(sz);
            }
            catch (const filesystem::filesystem_error &e)
            {
                cout << "Error accessing file " << file << ": " << e.what() << endl;
            }
        }
        else
        {
            cout << "File " << file << " does not exist." << endl;
        }
    }
    if(v.size()>=2){
        int percentage=100*v[v.size()-1]/v[v.size()-2];
        cout << "\033[34mThe file size has been reduced by " << percentage << "%\033[0m" << endl;
    }
    return 0;
}
