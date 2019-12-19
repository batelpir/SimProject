//
// Created by batel on 19/12/2019.
//
#include "Interpreter.h"

void Interpreter::setVariables(string string1){
  // making a list of variables and their value.
  vector<string> stringVector;
  stringstream ss(string1);
  string segment;
  while(getline(ss, segment, ';'))
  {
    stringVector.push_back(segment);
  }
  for (string& str : stringVector) {
    string var = "";
    string val = "";
    string tempVal;
    int pos = str.find("=");
    var = str.substr(0, pos);
    val = str.substr(pos+1);
    tempVal = val; // for the negative numbers.
    regex a("[A-Za-z_][A-Za-z0-9_]*");
    regex b("[0-9]+\\.[0-9]+|[0-9]+");
    // check if the name of the var is valid:
    if(regex_match(var,a)){
      // check if the name of the val is valid:
      // first, check the option of negative number.

      if(val[0] == '-') {
        tempVal.erase(0, 1);
      }
      if(regex_match(tempVal,b)) {
        // the var didnt exist
        double value = stod(val);
        if(this->variables.find(var) == this->variables.end()) {
          this->variables.insert({var,value});
        } else {
          this->variables[var] = value; // or this->variables.at(var) = value;
        }
      }else {
        throw "Error";
      }
    } else {
      throw "Error";
    }
  }
}
Expression* Interpreter:: interpret(string str){
  stack<string> myStack;
  queue<string> myQueue;
  string numberString = "";
  string varString = "";
  regex reg1("[0-9]+\\.[0-9]+|[0-9]+");
  regex reg2("[A-Za-z_][A-Za-z0-9_]*");
  int i = 0;
  int len = str.length();
  while(i < len) {
    if(str[i] == '(') {
      myStack.push("(");
    }
    if (str[i] == ')') {
      while (!myStack.empty() && (myStack.top() != "(")) {
        myQueue.push(myStack.top());
        myStack.pop();
      }
      if(myStack.empty()) {
        throw "Error";
      }
      myStack.pop();
    }
    if(str[i] == '+') {
      if(i == len -1 || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '/' || str[i+1] == '*') {
        throw "Error";
      }
      if( i == 0 || str[i-1] == '(') {
        string s(1,str[i+1]);
        // if the next char is a variable or a begining of a variable:
        if(regex_match(s,reg2)) {
          throw "Error";
        }
        myStack.push("$"); // unary plus.
      } else {
        while(!myStack.empty() && (myStack.top() == "*" || myStack.top() == "/" ||
            myStack.top() == "$" || myStack.top() == "#" )) {
          myQueue.push(myStack.top());
          myStack.pop();
        }
        myStack.push("+");
      }

    }
    if(str[i] == '-') {
      if(i == len -1 || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '/' || str[i+1] == '*') {
        throw "Error";
      }
      if(i == 0 || str[i-1] == '(') {
        string s(1,str[i+1]);
        // if the next char is a variable or a begining of a variable:
        if(regex_match(s,reg2)) {
          throw "Error";
        }
        myStack.push("#"); // unary minus.
      } else {
        while(!myStack.empty() && (myStack.top() == "*" || myStack.top() == "/" ||
            myStack.top() == "$" || myStack.top() == "#")) {
          myQueue.push(myStack.top());
          myStack.pop();
        }
        myStack.push("-");
      }
    }
    if(str[i] == '*') {
      if(i == len -1 || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '/' || str[i+1] == '*') {
        throw "Error";
      }
      while(!myStack.empty() && (myStack.top() == "$" || myStack.top() == "#")) {
        myQueue.push(myStack.top());
        myStack.pop();
      }
      myStack.push("*");
    }
    if(str[i] == '/') {
      if(i == len -1 || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '/' || str[i+1] == '*') {
        throw "Error";
      }
      while(!myStack.empty() && (myStack.top() == "$" || myStack.top() == "#")) {
        myQueue.push(myStack.top());
        myStack.pop();
      }
      myStack.push("/");
    }
    if(str[i] =='.' || isdigit(str[i])) {
      numberString += str[i];
      if (str[i+1] != '.' && !isdigit(str[i+1])){
        if(regex_match(numberString,reg1)) {
          myQueue.push(numberString);
          numberString = "";
        } else {
          throw "Error";
        }
      }
    }
    if(str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '/' &&
        str[i] != '*' && !isdigit(str[i]) && str[i] != '.') {
      varString += str[i];
      if(i == len -1) {
        myQueue.push(varString);
      } else {
        int  j = i + 1;
        while(j != len && str[j] != '+' && str[j] != '-' && str[j] != '/' &&
            str[j] != '*' && str[j] != '(' && str[j] != ')') {
          varString += str[j];
          j++;
          i++;
        }
        // if the var is not in the map:
        if(this->variables.find(varString) == this->variables.end()) {
          throw "Error";
        }
        myQueue.push(varString);
        varString = "";
      }
    }
    i++;
  }
  while(!myStack.empty()) {
    if(myStack.top() == ")" || myStack.top() == "(" ) {
      throw "Error";
    }
    myQueue.push(myStack.top());
    myStack.pop();
  }
  // make expressions:
  stack<Expression*> newStack;
  Expression *right;
  Expression *left;
  while(!myQueue.empty()) {
    right = nullptr;
    left = nullptr;
    string element = myQueue.front();
    // if it is a number
    if(regex_match(element,reg1)) {
      Expression *exp = new Value(stod(element));
      newStack.push(exp);
    }
    // if it is a variable
    if(regex_match(element,reg2)) {
      Expression *exp = new Variable(element, this->variables.at(element));
      newStack.push(exp);
    }
    if(element == "#") {
      right = newStack.top();
      newStack.pop();
      Expression *unaryMinus = new UMinus(right);
      Expression *res = new Value(unaryMinus->calculate());
      newStack.push(res);
      delete unaryMinus;
    }
    if(element == "$") {
      right = newStack.top();
      newStack.pop();
      Expression *unaryPlus = new UPlus(right);
      Expression *res = new Value(unaryPlus->calculate());
      newStack.push(res);
      delete unaryPlus;
    }
    if(element == "+") {
      right = newStack.top();
      newStack.pop();
      left = newStack.top();
      newStack.pop();
      Expression *plus = new Plus(left, right);
      Expression *res = new Value(plus->calculate());
      newStack.push(res);
      delete plus;
    }
    if(element == "-") {
      right = newStack.top();
      newStack.pop();
      left = newStack.top();
      newStack.pop();
      Expression *minus = new Minus(left, right);
      Expression *res = new Value(minus->calculate());
      newStack.push(res);
      delete(minus);
    }
    if(element == "*") {
      right = newStack.top();
      newStack.pop();
      left = newStack.top();
      newStack.pop();
      Expression *mul = new Mul(left, right);
      Expression *res = new Value(mul->calculate());
      newStack.push(res);
      delete mul;
    }
    if(element == "/") {
      right = newStack.top();
      newStack.pop();
      left = newStack.top();
      newStack.pop();
      Expression *div = new Div(left, right);
      Expression *res = new Value(div->calculate());
      newStack.push(res);
      delete(div);
    }
    myQueue.pop();
  }
  return newStack.top();

}