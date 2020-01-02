//
// Created by batel on 23/12/2019.
//
#include "Functions.h"


void Functions:: splitLine(vector<string> *tokens, string line, int delim_pos) {
    // Note - we should pass stringstream by reference because stream doesnt have copy constructors
    string item;
    smatch match;
    regex patt("[\\s]*(.+)$");
    stringstream line_stream(line);
    int equal_pos;

    if (line[delim_pos] == '=') {
        equal_pos = line.find('=');
        if (line.find(' ') != -1) {
            string tmp_line;
            if (line[0] == '\t') {
                // if there is tab at the beggining, skip it
                tmp_line = line.substr(1, equal_pos - 1);
            } else {
                tmp_line = line.substr(0, equal_pos - 1);
            }
            stringstream line_stream(tmp_line);
            // split by spaces until we see equal sign
            while (getline(line_stream, item, ' ')) {
                tokens->push_back(item);
            }
        } else {
            // a case when there is no space after name of variable
            stringstream line_stream(line.substr(0, equal_pos));
            while (getline(line_stream, item, ' ')) {
                tokens->push_back(item);
            }
        }

        if (std::regex_search(line, match, patt)) {
            int equal_pos = match.str(1).find('=');
            // enter ifs for cases of *= and /=
            if ((match.str(1)[equal_pos - 1]) == '+') {
                tokens->push_back("+=");
            }
            if ((match.str(1)[equal_pos - 1]) == '-') {
                tokens->push_back("-=");
            }
            if (match.str(1)[equal_pos - 1] != '-' && match.str(1)[equal_pos - 1] != '+') {
                tokens->push_back("=");
            }

            regex patt("[\\s]*(.*)");
            equal_pos = line.find('=');
            string tmp_line = line.substr(equal_pos + 1);
            if (std::regex_search(tmp_line, match, patt)) {
                tokens->push_back(match.str(1));
            }
        }
    }
    if (line[delim_pos] == '(') {
        int paren_pos = line.find('(');
        string tmp_line = line.substr(0, paren_pos);

        if(tmp_line.find(' ') != -1) {
            stringstream line_stream(tmp_line);
            while (getline(line_stream, item, ' ')) {
                tokens->push_back(item);
            }
        } else {
            regex patt("[\\s]*(.+)$");
            if (std::regex_search(line, match, patt)) {
                paren_pos = match.str(1).find('(');
                if (paren_pos != 0) {
                    // it means there is a word before brackets so push it
                    //tokens->push_back(tmp_line);
                    tokens->push_back(match.str(1).substr(0, paren_pos));
                }
            }
        }

        if (line.find(',') != -1) {
            //split by commas
            paren_pos = match.str(1).find('(');
            stringstream line_stream(match.str(1).substr(paren_pos + 1));
            while(getline(line_stream, item, ',')) {
                if(item.find(')') != -1) {
                    item = item.substr(0, item.size() - 1);
                }
                tokens->push_back(item);
            }
        } else {
            // take all the expression in brackets
            regex patt("[\\s]*\\((.*?)\\)");
            if (std::regex_search(line, match, patt)) {
                tokens->push_back(match.str(1));
            }
        }
    }
}

vector<string> Functions::lexer(string file_name) {
  vector<string> tokens;
  string line;
  smatch match;
  // open file in order to read it
  ifstream file_obj;
  file_obj.open(file_name, ios::in);
  if (!file_obj) {
    throw "Error: Couldn't open the file";
  }
  while (getline(file_obj, line)) {
    if (line.find("var") != -1 && line.find("{") != -1) {
        // enter the name of function
        int paren_pos = line.find('(');
        tokens.push_back(line.substr(0, paren_pos));
        // take all the expression in brackets
        regex patt("[\\s]*\\((.*?)\\)");
        string tmp_line = line.substr(paren_pos, line.length() - 2);
        if (std::regex_search(tmp_line, match, patt)) {
            tokens.push_back(match.str(1));
        }
        // enter '{'
        tokens.push_back("{");
        getline(file_obj, line);
        while (line != "}") {
            helper(file_obj, &tokens, line);
            getline(file_obj, line);
            if (line == "}") {
                tokens.push_back("}");
            }
        }
    } else {
        helper(file_obj, &tokens, line);
    }

  } // end of while - reading line by line from file

  for (int j = 0; j < tokens.size(); j++) {
    cout << tokens[j] << endl;
  }
  return tokens;
}

void Functions::helper(ifstream &file_obj, vector<string> *tokens, string line) {
    //remove trailing spaces from line
    int start = line.find_first_not_of(" \t");
    line = line.substr(start);
    int space_pos = line.find(' ');
    if (line.find("while") != string::npos || line.find("if") != string::npos) {
        // enter while/if word
        tokens->push_back(line.substr(0, space_pos));
        // enter condition
        tokens->push_back(line.substr(space_pos + 1, line.size() - space_pos - 2));
        // enter '{'
        tokens->push_back(line.substr(line.size() - 1));
        getline(file_obj, line);
        while (line != "}") {
            int delim_pos = line.find('=');
            if (delim_pos == -1) {
                delim_pos = line.find('(');
            }
            splitLine(tokens, line, delim_pos);
            getline(file_obj, line);
            //remove trailing spaces from line
            int start = line.find_first_not_of(" \t");
            line = line.substr(start);
            if (line == "}") {
                tokens->push_back("}");
            }
        }
    } else {
        int delim_pos = line.find('=');
        if (delim_pos == -1) {
            delim_pos = line.find('(');
        }
        splitLine(tokens, line, delim_pos);
    }
}

























double Functions::shuntingYard(string expression_string) {
  Singleton* singleton = Singleton::getInstance();

  // check if expression_string is already a number
  string temp_expression = expression_string; // make a copy because its helps to check if expression_string is a negative number
  regex is_num("[0-9]+\\.[0-9]+|[0-9]+");
  // if the Expression is a negative number:
  if(temp_expression[0] == '-') {
    temp_expression.erase(0, 1);
  }
  if(regex_match(temp_expression, is_num)) {
    double value = stod(expression_string);
    return value;
  }

  // now it is the case that expression_string isnt a pure number.
  Interpreter* inter = new Interpreter();
  Expression* exp = nullptr;
  string variable = "";
  regex is_part_of_var_name("[A-Za-z0-9_]");
  regex is_first_char_of_var_name("[A-Za-z_]");
  // passing each char in the expression_string and try to find variables there.
  for(int i = 0; i < expression_string.size(); i++) {
    // convert the char to be a string
    string s(1, expression_string[i]);
    // if the char is a letter or _ so it is can be the first char from the variable name
    if(variable.empty() && regex_match(s ,is_first_char_of_var_name)) {
      variable += s; // add the char to variable name.
    } else {
      // this case mean that the char is a part of a variable name.
      if((!variable.empty()) &&regex_match(s ,is_part_of_var_name)) {
        variable += s; // add the char to variable name.
      } else {
        // mean that we finished to build the name of var and now it is another char.
        // (attention: number will not enter to this case but it will never be the first char after a variable name.)
        if(!variable.empty() && !regex_match(s ,is_part_of_var_name)) {
          Var* variable_data = singleton->getfromSymbolTable(variable);
          double variable_value = variable_data->getValue();
          string value_string = to_string(variable_value);
          //try {
            inter->setVariables(variable + "=" + value_string);
          //} catch (const char* e) {
            //delete inter;
          //}
          variable = ""; // delete the variable name that we finish to deal with.
        }
      }
    }
  }
  //last check
  if(!variable.empty()) {
    Var* variable_data = singleton->getfromSymbolTable(variable);
    double variable_value = variable_data->getValue();
    string value_string = to_string(variable_value);
    //try {
    inter->setVariables(variable + "=" + value_string);
    //} catch (const char* e) {
    //delete inter;
    //}
    variable = ""; // delete the variable name that we finish to deal with.
  }
  // remove the spaces from the expression_string string.
  expression_string.erase(remove(expression_string.begin(), expression_string.end(), ' '), expression_string.end());
  double val;
  //try {
    exp = inter->interpret(expression_string);
    val = exp->calculate();
    delete exp;
    delete inter;
  //}catch(const char* e) {
    //delete exp;
  //}
  return val;
}