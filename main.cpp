// Headers files

#include "Singleton.h"
#include "Parser.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 * takes the name of the file from argv and lexing + parsing it.
 * in the end, waits to the threads to finish running.
 */
int main(int argc, char *argv[]) {

    vector<string> tokens;
    Singleton* singleton = Singleton::getInstance();

    if  (argc == 2) {
        tokens = Functions::lexer(argv[1]);
    } else {
        cout << "File name is not supplied\n";
    }
    Parser *parser = new Parser(tokens);
    parser->parser();
    vector<thread*> threads = singleton->getThreads();
    for(auto thread : threads) {
        thread->join();
    }

    return 0;
}