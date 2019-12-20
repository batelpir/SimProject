// Headers files
#include "Lexer.h"
#include "Parser.h"
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
    vector<string> tokens;
    //lexer(argv[1]);
    tokens = Lexer::lexer("flyCopy.txt");
    new Parser(tokens);
    return 0;
}