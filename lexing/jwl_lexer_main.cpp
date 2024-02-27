#include <lexing/jwl_lexer.h>

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace jwl;

std::string associate(Token t)
{
    switch (t)
    {
        case Token::INVALID:            return "!INVALID!";
        case Token::IDENTIFIER:         return "IDENTIFIER";
        case Token::NUMBER:             return "NUMBER";
        case Token::COMMA:              return "COMMA";
        case Token::LESS_THAN:          return "LESS_THAN";
        case Token::DOT:                return "DOT";
        case Token::GREATER_THAN:       return "GREATER_THAN";
        case Token::FORWARD_SLASH:      return "FORWARD_SLASH";
        case Token::QUESTION_MARK:      return "QUESTION_MARK";
        case Token::SEMI_COLON:         return "SEMI_COLON";
        case Token::COLON:              return "COLON";
        case Token::APOSTROPHE:         return "APOSTROPHE";
        case Token::QUOTATION_MARK:     return "QUOTATION_MARK";
        case Token::LEFT_BRACKET:       return "LEFT_BRACKET";
        case Token::LEFT_BRACE:         return "LEFT_BRACE";
        case Token::RIGHT_BRACKET:      return "RIGHT_BRACKET";
        case Token::RIGHT_BRACE:        return "RIGHT_BRACE";
        case Token::BACKWARD_SLASH:     return "BACKWARD_SLASH";
        case Token::PIPE:               return "PIPE";
        case Token::BACKTICK:           return "BACKTICK";
        case Token::TILDE:              return "TILDE";
        case Token::BANG:               return "BANG";
        case Token::AT_SYMBOL:          return "AT_SYMBOL";
        case Token::OCTOTHORPE:         return "OCTOTHORPE";
        case Token::DOLLAR:             return "DOLLAR";
        case Token::PERCENT:            return "PERCENT";
        case Token::CARET:              return "CARET";
        case Token::AMPERSAND:          return "AMPERSAND";
        case Token::ASTERISK:           return "ASTERISK";
        case Token::LEFT_PARENTHESIS:   return "LEFT_PARENTHESIS";
        case Token::RIGHT_PARENTHESIS:  return "RIGHT_PARENTHESIS";
        case Token::HYPHEN:             return "HYPHEN";
        case Token::EQUALS:             return "EQUALS";
        case Token::PLUS:               return "PLUS";
        case Token::END_OF_FILE:        return "END_OF_FILE";
    }

    // If we somehow made it here, indicate it by using a unique string
    return "~UNKNOWN~";
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Error: Usage ./JWL_Lexer some_file.jwl" << std::endl;
        exit(1);
    }

    std::string filepath{argv[1]};
    std::cout << "Lexing " << filepath << std::endl;

    Lexer lexer(filepath);
    Token t;
    while ((t = lexer.lex()) != Token::END_OF_FILE)
    {
        std::cout << associate(t) << std::endl;
    }

    std::cout << associate(t) << std::endl;

    return 0;
}
