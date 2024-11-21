#include "LibApp.h"
namespace seneca {
    LibApp::LibApp()
        : m_changed(false),
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_mainMenu << "Add New Publication" << "Remove Publication"
            << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu confirmMenu(message);
        confirmMenu << "Yes"; 
        return confirmMenu.run() == 1;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl; 
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) { 
            m_changed = true;
            cout << "Publication added" << endl << endl;
        }
        else {
            cout << endl;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) { 
            m_changed = true;
            cout << "Publication removed" << endl << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) { 
            m_changed = true;
            cout << "Publication checked out" << endl << endl;
        }
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            int selection = m_mainMenu.run();
            if (selection == 0) {
               // cout << endl; 
            }
            switch (selection) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    int exitSelection = m_exitMenu.run();
                    switch (exitSelection) {
                    case 1:
                        save();
                        done = true;
                        break;
                    case 2:
                        cout << endl;
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) { 
                            done = true;
                        }
                        break;
                    }
                }
                else {
                    done = true;
                }
                break;
            }
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}
