#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

//vector<string> splitLine(stringstream &line, char delim) {
vector<string> splitLine(vector<string> *tokens,string line, int delim_pos) {
    // Note - we should pass stringstream by reference because stream doesnt have copy constructors
    //vector<string> tokens;
    string item;
    smatch match;
    regex patt("[\\s]*(.+)$");
    stringstream line_stream(line);

    if (line[delim_pos] == '=') {
        if (std::regex_search(line, match, patt)) {
            int equal_pos = match.str(1).find('=');

            // for type var - "var name = value"
            if(match.str(1).substr(0, equal_pos - 1).find(' ') != -1) {
                int space_pos = match.str(1).substr(0, equal_pos - 1).find(' ');
                tokens->push_back(match.str(1).substr(0, space_pos));
                tokens->push_back(match.str(1).substr(space_pos + 1, equal_pos - space_pos - 1));
            }
            // enter ifs for cases of *= and /=
            if ((match.str(1)[equal_pos - 1]) == '+') {
                tokens->push_back("+=");
            }
            if ((match.str(1)[equal_pos - 1]) == '-') {
                tokens->push_back("-=");
            }
            if ((match.str(1)[equal_pos - 1]) == ' ') {
                tokens->push_back("=");
            }
            // +2 is for skipping space
            tokens->push_back(match.str(1).substr(equal_pos + 2));
        }
    }
    if (line[delim_pos] == ' ') {
        while (getline(line_stream, item, line[delim_pos])) {
            if(item.find('(') != -1) {
                // there is '('
                if (std::regex_search(item, match, patt)) {
                    int paren_pos = match.str(1).find('(');
                    if (paren_pos != 0) {
                        // it means there is a word before parenthisis so push it
                        tokens->push_back(match.str(1).substr(0, paren_pos));
                    }
                    // split by commas
                    // get all the items without the last char which is ')'
                    stringstream line_stream(match.str(1).substr(paren_pos + 1));
                    while (getline(line_stream, item, ',')) {
                        if (item.find(')') != -1) {
                            item = item.substr(0, item.size() - 1);
                        }
                        tokens->push_back(item);
                    }
                }
            } else {
                tokens->push_back(item);
            }
        }
    }

    if (line[delim_pos] == '(') {
        // there is '('
        if (std::regex_search(line, match, patt)) {
            int paren_pos = match.str(1).find('(');
            if (paren_pos != 0) {
                // it means there is a word before parenthisis so push it
                tokens->push_back(match.str(1).substr(0, paren_pos));
            }
            // split by commas
            // get all the items without the last char which is ')'
            stringstream line_stream(match.str(1).substr(paren_pos + 1));
            while (getline(line_stream, item, ',')) {
                if (item.find(')') != -1) {
                    item = item.substr(0, item.size() - 1);
                }
                tokens->push_back(item);
            }
        }
    }
}

vector<string> lexer(string file_name) {
    vector<string> tokens;
    string line;
    // open file in order to read it
    ifstream file_obj;
    file_obj.open(file_name, ios::in);
    if (!file_obj) {
        throw "Error: Couldn't open the file";
    }
    while (getline(file_obj, line)) {
        int space_pos = line.find(' ');
        if (line.find("while") != string::npos || line.find("if") != string::npos) {
            // enter while/if word
            tokens.push_back(line.substr(0, space_pos));
            // enter condition
            tokens.push_back(line.substr(space_pos + 1, line.size() - space_pos - 2));
            // enter '{'
            tokens.push_back(line.substr(line.size() - 1));
            getline(file_obj, line);
            while (line != "}") {
                int delim_pos = line.find('=');
                if (delim_pos == -1) {
                    delim_pos = line.find(' ');
                    if (delim_pos == -1) {
                        delim_pos = line.find('(');
                    }
                }
                splitLine(&tokens, line, delim_pos);
                getline(file_obj, line);
                if (line == "}") {
                    tokens.push_back("}");
                }


            }
        } else {
            int delim_pos = line.find('=');
            if (delim_pos == -1) {
                delim_pos = line.find(' ');
                if (delim_pos == -1) {
                    delim_pos = line.find('(');
                }
            }
            splitLine(&tokens, line, delim_pos);
        }

    } // end of while - reading line by line from file


    for (int j = 0; j < tokens.size(); j++) {
        cout << tokens[j] << endl;
    }
    return tokens;





}



/*
void lexer(string file_name) {
    vector<string> tokens;
    vector<string> spaces_tokens;
    vector<string> paren_tokens;
    vector<string> while_tokens;
    string line;
    int paren_pos;


    // open file in order to read it
    ifstream file_obj;
    file_obj.open(file_name, ios::in);
    if (!file_obj) {
        throw "Error: Couldn't open the file";
    }
    while (getline(file_obj, line)) {
        // while section
        if (line.find("while") != string::npos) {
            int space_pos = line.find(' ');
            // enter while word
            tokens.push_back(line.substr(0, space_pos));
            // enter condition
            tokens.push_back(line.substr(space_pos + 1, line.size() - space_pos - 2));
            // enter '{'
            tokens.push_back(line.substr(line.size() - 1));
            while (line != "}") {
                int delim_pos = line.find('=');

                int equal_pos = line.find('=');
                if (equal_pos >= 0) {
                    if (std::regex_search(line, match, patt)) {
                        // get the first group of match
                        tokens.push_back(match.str(1).substr(0, equal_pos - 1));
                        if ((match.str(1)[equal_pos - 1]) == '+') {
                            tokens.push_back("+=");
                        }
                        if((match.str(1)[equal_pos - 1]) == '-') {
                            tokens.push_back("-=");
                        }
                        if((match.str(1)[equal_pos - 1]) == ' ') {
                            tokens.push_back("=");
                        }
                        tokens.push_back(match.str(1).substr(equal_pos + 1, match.str(1).size()));
                    }

                splitLine(line, delim_pos);
                } else {
                    paren_pos = line.find('(');
                    // there is '('
                    if (paren_pos >= 0) {
                        if (std::regex_search(line, match, patt)) {
                            if (paren_pos != 0) {
                                // it means there is a word before parenthisis so push it
                                tokens.push_back(match.str(1).substr(0, paren_pos - 1));
                            }
                            // split by commas
                            // get all the items without the last char which is ')'
                            stringstream line_paren_stream(match.str(1).substr(paren_pos,
                                                                               match.str(1).size() - paren_pos - 1));
                            paren_tokens = splitLine(line_paren_stream, ',');

                        }
                    }
                    if(paren_tokens.size() != 0) {
                        // merge tokens and paren_tokens
                        tokens.reserve(tokens.size() + paren_tokens.size());
                        tokens.insert(tokens.end(), paren_tokens.begin(), paren_tokens.end());
                        // after merging, clear the vector for the next parenthisis
                        paren_tokens.clear();
                    }


                }
                getline(file_obj, line);
                if(line == "}") {
                    tokens.push_back("}");
                }
            }
        }

        // split lines by spaces
        stringstream line_stream(line);
        spaces_tokens = splitLine(line_stream, ' ');
        for (int i = 0; i < spaces_tokens.size(); i++) {
            paren_pos = spaces_tokens[i].find('(');
            if (paren_pos == string::npos && spaces_tokens[i] != "while") {
                // there isn't '('
                tokens.push_back(spaces_tokens[i]);
            } else {
                // there is '('
                if (paren_pos >= 0) {
                    if (paren_pos != 0) {
                        // it means there is a word before parenthisis so push it
                        tokens.push_back(spaces_tokens[i].substr(0, paren_pos));
                    }
                    // split by commas
                    // get all the items without the last char which is ')'
                    stringstream line_paren_stream(spaces_tokens[i].substr(paren_pos + 1,
                            spaces_tokens[i].size() - paren_pos - 2));
                    paren_tokens = splitLine(line_paren_stream, ',');

                }
                if(paren_tokens.size() != 0) {
                    // merge tokens and paren_tokens
                    tokens.reserve(tokens.size() + paren_tokens.size());
                    tokens.insert(tokens.end(), paren_tokens.begin(), paren_tokens.end());
                    // after merging, clear the vector for the next parenthisis
                    paren_tokens.clear();
                }


            }
        }

        for (int j = 0; j < tokens.size(); j++) {
            cout << tokens[j] << endl;
        }
    }
};
*/

int main(int argc, char *argv[]) {
    //lexer(argv[1]);
    lexer("flyCopy.txt");
    return 0;
}