// pyinstaller.cpp: detects if program made with python and compiled with pyinstaller
//

#include "pyinstaller.h"
#include "scanfish.h"

using namespace std;
namespace fs = std::filesystem;

#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#endif

void extractPyinstaller() {
	// step 1 - extract the pyinstaller file (if it is) with pyinstxtractor
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
        cerr << "[!] Failed to run command due file being compiled with Nukita or something else, or other error." << endl;
    }
	cout << "[*] PyInstaller extraction completed." << endl;

	// step 2 - getting pycdc decompyle every .pyc file and finding the regexs
	// currently only one
	const regex tokenRegex(R"([MN][\w-]{23,25}\.[\w-]{6}\.[\w-]{27,39})");
	bool tokenFound = false;
	string foundToken;

	string something = filesystem::path(filename).filename().string();
	string path = something + "_extracted";
	for (const auto& entry : fs::directory_iterator(path)) {
		if (entry.path().extension() == ".pyc") {
			string command = "pycdc.exe " + entry.path().string();
			FILE* pipe = popen(command.c_str(), "r");
			if (pipe) {
				string output;
				char buffer[128];
				while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
					output += buffer;
				}
				int exitCode = pclose(pipe);

				smatch match;
				// TODO: continue making now

				cout << "[*] PyCDC output:\n" << output << endl;
			}
			else {
				cerr << "[!] Failed to run command." << endl;
			}
		}
	}
}
