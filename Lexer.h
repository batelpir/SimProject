//
// Created by shaked on 18/12/2019.
//

#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;
class Lexer {
public:
    static void splitLine(vector<string> *tokens, string line, int delim_pos) {
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
                if (match.str(1).substr(0, equal_pos - 1).find(' ') != -1) {
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
                /*
                if ((match.str(1)[equal_pos - 1]) == ' ') {
                    tokens->push_back("=");
                }*/
                if (match.str(1)[equal_pos - 1] != '-' && match.str(1)[equal_pos - 1] != '+') {
                    tokens->push_back("=");
                }
                // +2 is for skipping space
                tokens->push_back(match.str(1).substr(equal_pos + 2));
            }
        }
        if (line[delim_pos] == ' ') {
            while (getline(line_stream, item, line[delim_pos])) {
                if (item.find('(') != -1) {
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

    static vector<string> lexer(string file_name) {
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

};

#endif //EX3_LEXER_H
