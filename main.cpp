// Headers files
#include "Parser.h"
#include "Command.h"
#include "UpdatingCommand.h"
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
    vector<string> tokens;
    if  (argc == 2) {
        //lexer(argv[1]);
    } else {
        cout << "File name is not supplied\n";
    }
    // use parser with try & catch!!!

    tokens = Functions::lexer("flyCopy.txt");
    /*
    Singleton* singleton = Singleton::getInstance();
    cout <<singleton->getfromSymbolTable("var")->getValue()<< endl;
    Command* c = new UpdatingCommand();
    c->execute(tokens,3);

    cout <<singleton->getfromSymbolTable("var")->getValue()<< endl;
*/
    //new Parser(tokens);
    return 0;
}