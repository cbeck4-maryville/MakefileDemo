#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <xmlfile>\n";
        return 1;
    }

    const char* filename = argv[1];

    XMLDocument doc;
    XMLError err = doc.LoadFile(filename);

    if (err != XML_SUCCESS) {
        cout << "Error reading XML file: " << filename << "\n";
        return 1;
    }

    // Get root element
    XMLElement* root = doc.RootElement();
    if (!root) {
        cout << "No root element\n";
        return 1;
    }

    // Look for all <title> elements anywhere in document
    XMLElement* title = root->FirstChildElement("book");
    while (title) {
        XMLElement* t = title->FirstChildElement("title");
        if (t && t->GetText()) {
            cout << t->GetText() << endl;
        }
        title = title->NextSiblingElement("book");
    }

    return 0;
}
