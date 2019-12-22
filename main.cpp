// Headers files
#include "Lexer.h"
#include "Parser.h"
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
    vector<string> tokens;
    if  (argc == 2) {
        //lexer(argv[1]);
    } else {
        cout << "File name is not supplied";
    }
    tokens = Lexer::lexer("flyCopy.txt");
    new Parser(tokens);
    return 0;
}