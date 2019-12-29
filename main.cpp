// Headers files

#include "Singleton.h"
#include "Parser.h"
#include <string>
#include <vector>
#include <iostream>




using namespace std;


int main(int argc, char *argv[]) {
    vector<string> tokens;
    Singleton* singleton = Singleton::getInstance();
    if  (argc == 2) {
        //lexer(argv[1]);
    } else {
        cout << "File name is not supplied\n";
    }
    // use parser with try & catch!!!

    tokens = Functions::lexer("flyCopy.txt");
    Parser *parser = new Parser(tokens);
    parser->parser();

    /*
    vector<thread> threads = singleton->getThreads();
    for(auto &thread : threads) {
        thread.join();
    }
    */
    return 0;
}