// scanfish.cpp: определяет точку входа для приложения.
//

#include "scanfish.h"
#include "pyinstaller.h"

using namespace std;

string filename;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "No arguments provided. Use --help for usage." << endl;
        return 1;
    }

    bool fileFound = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            cout << "Usage: scanfish [options] [file]\n"
                << "Options:\n"
                << "  --help\t\tShow this help message\n"
                << "  -v\t\t\tShow version\n";
            return 0;
        }
        else if (strcmp(argv[i], "-v") == 0) {
            cout << "SCANFISH v0.0.1" << endl;
            return 0;
        }
		else if (argv[i][0] != '-') {

			filename = argv[i];
			fileFound = true;
		}
        else {
            cout << "Unknown option: " << argv[i] << endl;
            return 1;
        }
    }

    if (!fileFound) {
		cout << "No file specified" << endl;
        return 1;
    }

	cout << "[*] Processing file, wait a moment..." << endl;
    extractPyinstaller();

    return 0;
}
