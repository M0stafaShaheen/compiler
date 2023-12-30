#include <bits/stdc++.h>
using namespace std;

enum TokenType {
    KEYWORD,        //0
    IDENTIFIER,     //1
    OPERATOR,       //2
    CONST,          //3
    COMMENT,        //4
    SPECIALCHAR,    //5
    INVALID         //6
};


struct Token {
    TokenType type;
    string val;
};


Token getNextToken(string& statement, int& pos) {
    Token token;
    token.type = INVALID;


    while (pos < statement.length() && isspace(statement[pos])) {
        pos++;
    }


    if (pos >= statement.length()) {
        token.type = INVALID;
        return token;
    }


    if (statement.substr(pos, 3) == "int") {
        token.type =KEYWORD;
        token.val = "int";
        pos += 3;
        return token;
    }


    if (statement[pos] == '=') {
        token.type = OPERATOR;
        token.val = "=";
        pos++;
        return token;
    }


    if (statement[pos] == '+') {
        token.type = OPERATOR;
        token.val = "+";
        pos++;
        return token;
    }


    if (statement[pos] == ';') {
        token.type = SPECIALCHAR;
        token.val = ";";
        pos++;
        return token;
    }


    if (isdigit(statement[pos])) {
        token.type = CONST;
        while (pos < statement.length() && isdigit(statement[pos])) {
            token.val += statement[pos];
            pos++;
        }
        return token;
    }


    if (isalpha(statement[pos])) {
        token.type = IDENTIFIER;
        while (pos < statement.length() && (isalnum(statement[pos]) || statement[pos] == '_')) {
            token.val += statement[pos];
            pos++;
        }
        return token;
    }


    return token;
}

int main() {
    string statement = "int x = 2 + 3;";
    int pos = 0;

    Token token;
    cout << " Token Class\tToken Value\n";
    do {
        token = getNextToken(statement, pos);
        cout <<"\t"<<token.type+1<<"\t  " << token.val << endl;

    }while (pos < statement.length());

    return 0;
}
