#include "jwl_lexer.h"

using namespace jwl;

Lexer::Lexer(const std::string& file_path):
    line(1)
{
    infile.open(file_path, std::fstream::in | std::fstream::out);
}

Lexer::~Lexer() {
    if (infile.is_open()) {
        infile.close();
    }
}

Token Lexer::lex() {
    if (!infile.is_open()) {
        return Token::INVALID;
    }

    char ch = getChar();

    switch (ch) {
        case ',': return Token::COMMA;
        case '<': return Token::LESS_THAN;
        case '.': return Token::DOT;
        case '>': return Token::GREATER_THAN;
        case '/': return Token::FORWARD_SLASH;
        case '?': return Token::QUESTION_MARK;
        case ';': return Token::SEMI_COLON;
        case ':': return Token::COLON;
        case '\'': return Token::APOSTROPHE;
        case '"': return Token::QUOTATION_MARK;
        case '[': return Token::LEFT_BRACKET;
        case '{': return Token::LEFT_BRACE;
        case ']': return Token::RIGHT_BRACKET;
        case '}': return Token::RIGHT_BRACE;
        case '\\': return Token::BACKWARD_SLASH;
        case '|': return Token::PIPE;
        case '`': return Token::BACKTICK;
        case '~': return Token::TILDE;
        case '!': return Token::BANG;
        case '@': return Token::AT_SYMBOL;
        case '#': return Token::OCTOTHORPE;
        case '$': return Token::DOLLAR;
        case '%': return Token::PERCENT;
        case '^': return Token::CARET;
        case '&': return Token::AMPERSAND;
        case '*': return Token::ASTERISK;
        case '(': return Token::LEFT_PARENTHESIS;
        case ')': return Token::RIGHT_PARENTHESIS;
        case '-': return Token::HYPHEN;
        case '_': return Token::UNDERSCORE;
        case '=': return Token::EQUALS;
        case '+': return Token::PLUS;
        default:
            if (isalpha(ch)) {
                return Token::LETTER;
            } else if (isdigit(ch)) {
                return Token::DIGIT;
            } else if (ch == EOF) {
                return Token::END_OF_FILE;
            } else {
                return Token::INVALID;
            }
    }
}

char Lexer::getChar() {
    if (!infile.is_open()) {
        return -1;
    }

    int ch = infile.get();
    if (ch == '\n') {
        line++;
    }

    return ch;
}

char Lexer::lookAhead() {
    if (!infile.is_open()) {
        return -1;
    }

    int ch = infile.get();
    infile.putback(ch);
    return ch;
}

bool Lexer::isValidIdentifierCharacter(char ch) {
    bool valid;
    switch(ch) {
        case '/':
        case '?':
        case '\'':
        case '"':
        case '{':
        case '}':
        case '\\':
        case '|':
        case '`':
        case '~':
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
        case '-':
        case '_':
        case '=':
        case '+':
            valid = true;
            break;
        default:
            valid = isalnum(ch);
            break;
    }
    return valid;
}