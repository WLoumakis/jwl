#ifndef __JWL_TOKENS_H__
#define __JWL_TOKENS_H__

namespace jwl
{
    enum Token
    {
        // An invalid token
        INVALID = -1,

        // Keywords
        KeywordMin,

        IF = KeywordMin,    // "if"
        FOR,                // "for"
        DO,                 // "do"
        WHILE,              // "while"
        SWITCH,             // "switch"

        TEMPLATE,           // "template"
        TYPENAME,           // "typename"

        BOOL,               // "bool"
        TRUE,               // "true"
        FALSE,              // "false"

        UNSIGNED,           // "unsigned"

        INT,                // "int"
        I8,                 // "i8"
        I16,                // "i16"
        I32,                // "i32"
        I64,                // "i64"
        UI8,                // "ui8"
        UI16,               // "ui16"
        UI32,               // "ui32"
        UI64,               // "ui64"

        FLOAT,              // "float"
        F32,                // "f32"
        UF32,               // "uf32"

        DOUBLE,             // "double"
        F64,                // "f64"
        UF64,               // "uf64"

        STRING,             // "string"
        VOID,               // "void"

        CLASS,              // "class"
        PRIVATE,            // "private"
        PROTECTED,          // "protected"
        PUBLIC,             // "public"

        INCLUDE,            // "include"

        KeywordMax = INCLUDE,
        KeywordCount,

        // Complex strings
        IDENTIFIER,         // [_a-zA-Z][_a-zA-Z0-9/\?'\"~!@#$%\^&\*\-=\+\\\|]*
        NUMBER,             // hexadecimal, decimal, octal, or binary

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

        EQUALS,             // '='
        PLUS,               // '+'

        // End-of-file
        END_OF_FILE         // EOF
    };
}

#endif // __JWL_TOKENS_H__
