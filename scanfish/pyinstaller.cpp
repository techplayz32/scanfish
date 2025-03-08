// pyinstaller.cpp: detects if program made with python and compiled with pyinstaller
//

#include "pyinstaller.h"
#include "scanfish.h"

using namespace std;

#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#endif

void extractPyinstaller() {
    std::string command = "pyinstxtractor-ng.exe --one-dir " + filename;

    FILE* pipe = popen(command.c_str(), "r");
    if (pipe) {
        string output;
        char buffer[128];

        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            output += buffer;
        }
        pclose(pipe);

        cout << "[*] PyInstxtractor output:\n" << output << endl;
    }
    else {
        cerr << "Failed to run command." << endl;
    }

    // getting pycdc decompyle every .pyc file
	cout << "[*] PyInstaller extraction completed." << endl;
    system
}
