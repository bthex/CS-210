#include <Python.h>
#include <iostream>
#include <cmath>
#include <string>
#include "header_files/cpp_modules.h"
using namespace std;

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
    char *procname = new char[proc.length() + 1];
    std::strcpy(procname, proc.c_str());

    char *paramval = new char[param.length() + 1];
    std::strcpy(paramval, param.c_str());


    PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
    // Initialize the Python Interpreter
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("import os");
    PyRun_SimpleString("sys.path.append(os.getcwd())");
    //PyObject* my_module = PyImport_ImportModule("python_modules.PythonCode")
    // Build the name object
    pName = PyUnicode_FromString((char*)"python_modules.PythonCode");
    // Load the module object
    pModule = PyImport_Import(pName);
    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);
    // pFunc is also a borrowed reference
    pFunc = PyDict_GetItemString(pDict, procname);
    if (PyCallable_Check(pFunc))
    {
        pValue = Py_BuildValue("(z)", paramval);
        PyErr_Print();
        presult = PyObject_CallObject(pFunc, pValue);
        PyErr_Print();
    }
    else
    {
        PyErr_Print();
    }
    //printf("Result is %d\n", _PyLong_AsInt(presult));
    Py_DECREF(pValue);
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    // Finish the Python Interpreter
    Py_Finalize();

    // clean
    delete[] procname;
    delete[] paramval;


    return _PyLong_AsInt(presult);
}

int main() {

    char quitcommand = 'a';
    int userSel;
    string item;

    while (quitcommand != 'q') {
        try {
            showMenu();
            userSel = collectUserInput();

            if (userSel == 1) {
                cout << "\033[2J\033[1;1H" << endl;
                cout << callIntFunc("purchaseAmounts", "items_purchases.txt");
                cout << endl << endl;
            }
            if (userSel == 2) {
                cout << "\033[2J\033[1;1H";
                cout << "Select an item: ";
                cin >> item;
                cout << endl;
                cout << callIntFunc("findItem", item);
                cout << endl << endl;
            }
            if (userSel == 3) {
                cout << callIntFunc("createHistogramData", "items_purchases.txt");
                cout << "\033[2J\033[1;1H";
                printHistogram();
            }
            if (userSel == 4) {
                cout << endl << endl;
                cout << "Thank you for using program.";
                quitcommand = 'q';
            }
        }
        catch (runtime_error& except) {
            cout << "Oops! Something went wrong. Exception: " <<  except.what() << endl;
        }

    }
    return 0;
}
