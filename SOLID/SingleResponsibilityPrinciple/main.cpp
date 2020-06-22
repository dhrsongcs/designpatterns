#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct NoteBook {
    string title;
    vector<string> entries;

    //constructor
    NoteBook(const string &title) : title(title) {}

    //add a note the notebook
    void add_note(const string &note) {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count) + ": " + note);
        count++;
    }

    //what if you want to let the Notebook to save the entries to a file
    void save(const string &filename) {
        //Open a file output steam
        ofstream ofs(filename);
        //write all the note entries to the file
        for (auto &entry:entries) {
            ofs << entry << endl;
        }
    }
};

struct PersistenceConnector {
    static void save(const NoteBook &noteBook, const string &filename) {
        ofstream ofs(filename);
        //write all the note entries to the file
        for (auto &entry:noteBook.entries) {
            ofs << entry << endl;
        }
    }
};


int main() {
    std::cout << "Single Responsibility Principle Example" << std::endl;
    NoteBook notebook{"Study Diligently"};
    notebook.add_note("We need to understand the principles.");
    notebook.add_note("We need to do lots of hands-on work!");

    //Single Responsibility Principle is broken
    //notebook.save("notebook.txt");
    //Instead, we use the PersistenceConnector to handle the persistence.
    PersistenceConnector pc;
    pc.save(notebook, "notebook.txt");
    return 0;
}
