#include "jwl_lexer.h"

#include <types/jwl_keywords.h>

#include <cstring>

using namespace jwl;

Lexer::Lexer(const std::string& file_path):
    line(1),
    column(0)
{
    infile.open(file_path, std::fstream::in);
}

Lexer::~Lexer()
{
    if (infile.is_open())
    {
        infile.close();
    }
}

Token Lexer::lex()
{
    if (!infile.is_open())
    {
        return Token::INVALID;
    }

    char ch = getChar();

    switch (ch)
    {
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
        case '=': return Token::EQUALS;
        case '+': return Token::PLUS;
        default:
            if (isalpha(ch) || (ch == '_' && isValidIdentifierCharacter(lookAhead())))
            {
                // Put back the character so we can read the entire keyword or variable name
                infile.putback(ch);
                return lexKeywordOrIdentifier();
            }
            else if (isdigit(ch))
            {
                return lexNumber();
            }
            else if (ch == EOF)
            {
                return Token::END_OF_FILE;
            }
            else
            {
                return Token::INVALID;
            }
    }
}

char Lexer::getChar() {
    if (!infile.is_open())
    {
        return EOF;
    }

    int ch = infile.get();
    column++;

    // Skip whitespace TODO: and comments
    // char temp = ch;
    while (isspace(ch))
    {
        if (ch == '\n')
        {
            line++;
            column = 0;
        }

        ch = infile.get();
        column++;
    }

    return ch;
}

char Lexer::lookAhead() {
    if (!infile.is_open())
    {
        return EOF;
    }

    int ch = infile.get();
    infile.putback(ch);

    return ch;
}

Token Lexer::lexKeywordOrIdentifier()
{
    // Store things here for now
    char temp[MAX_TOKEN_LENGTH + 1] = {0};
    std::size_t i = 0;
    char ch;

    // We already know the first character is valid so use do-while
    do
    {
        ch = getChar();
        temp[i++] = ch;
    } while (isValidIdentifierCharacter(lookAhead()) && i <= MAX_TOKEN_LENGTH);

    // Keywords are a special subset of valid identifiers, so check if we have a keyword first
    Token keyword_match = matchKeyword(temp);
    if (keyword_match != Token::INVALID)
    {
        return keyword_match;
    }

    // Otherwise we have an identifier on our hands
    return Token::IDENTIFIER;
}

bool Lexer::isValidIdentifierCharacter(char ch) {
    bool valid = false;

    switch(ch)
    {
        case '_':
        case '/':
        case '?':
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
        case '=':
        case '+':
        case '\\':
        case '|':
            valid = true;
            break;
        default:
            valid = isalnum(ch);
            break;
    }

    return valid;
}

Token Lexer::matchKeyword(const char* str)
{
    if (str == nullptr)
    {
        return Token::INVALID;
    }

    for (int i = Token::KeywordMin; i < Token::KeywordCount; i++)
    {
        if (strcmp(str, keyword_map[i]) == 0)
        {
            return static_cast<Token>(i);
        }
    }

    return Token::INVALID;
}

Token Lexer::lexNumber()
{
    char temp[MAX_TOKEN_LENGTH + 1] = {0};
    std::size_t i = 0;
    bool foundDecimal = false;

    char ch = getChar();
    char look = lookAhead();

    // Check for hex, octal, or binary
    if (ch == '0' && (look == 'x' || look == 'o' || look == 'b'))
    {
        // Get rid of the 0 and x, o, or b
        ch = getChar();
        switch (ch)
        {
            case 'x': return lexHexadecimal();
            case 'o': return lexOctal();
            case 'b': return lexBinary();
        }
    }

    // At this point we now know the first character is a number and the type of number is decimal, so keep lexing it as such
    temp[i++] = ch;
    while ((isdigit(look) || (look == '.' && !foundDecimal)) && i <= MAX_TOKEN_LENGTH)
    {
        ch = getChar();
        
        // Make sure we only allow 1 decimal
        if (ch == '.')
        {
            foundDecimal = true;
        }

        temp[i++] = ch;
        look = lookAhead();
    }

    // Check to see if the user put 2 decimals in the number and error out if so
    if (look == '.' && foundDecimal)
    {
        return Token::INVALID;
    }

    // Check to see if the user ended the number with a decimal and error out if so
    if (ch == '.')
    {
        return Token::INVALID;
    }

    return Token::NUMBER;
}

Token Lexer::lexHexadecimal()
{
    return Token::INVALID;
}

Token Lexer::lexOctal()
{
    return Token::INVALID;
}

Token Lexer::lexBinary()
{
    return Token::INVALID;
}
