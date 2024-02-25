#ifndef __JWL_TOKENS_H__
#define __JWL_TOKENS_H__

namespace jwl {
    enum Token {
        // An invalid token
        INVALID = -1,

        // Complex strings
        IDENTIFIER,         // [_a-zA-Z][_a-zA-Z0-9/\?'\"~!@#$%\^&\*\-=\+\\\|]*
        NUMBER,             // hexadecimal, decimal, octal, or binary

        // Whitespace
        SPACE,              // ' '
        TAB,                // '\t'
        NEWLINE,            // '\n'
        CARRIAGE_RETURN,    // '\r'

        // Symbols
        COMMA,              // ','
        LESS_THAN,          // '<'

        DOT,                // '.'
        GREATER_THAN,       // '>'

        FORWARD_SLASH,      // '/'
        QUESTION_MARK,      // '?'

        SEMI_COLON,         // ';'
        COLON,              // ':'

        APOSTROPHE,         // '\''
        QUOTATION_MARK,     // '"'

        LEFT_BRACKET,       // [
        LEFT_BRACE,         // {

        RIGHT_BRACKET,      // ]
        RIGHT_BRACE,        // }

        BACKWARD_SLASH,     // '\'
        PIPE,               // '|'

        BACKTICK,           // '`'
        TILDE,              // '~'

        BANG,               // '!'
        AT_SYMBOL,          // '@'
        OCTOTHORPE,         // '#'
        DOLLAR,             // '$'
        PERCENT,            // '%'
        CARET,              // '^'
        AMPERSAND,          // '&'
        ASTERISK,           // '*'
        LEFT_PARENTHESIS,   // '('
        RIGHT_PARENTHESIS,  // ')'

        HYPHEN,             // '-'
        UNDERSCORE,         // '_'

        EQUALS,             // '='
        PLUS,               // '+'

        // End-of-file
        END_OF_FILE         // EOF
    };
}

#endif // __JWL_TOKENS_H__
