namespace jwl {
    enum class Token {
        // An invalid token
        INVALID = -1,

        // Catch-alls
        LETTER,
        DIGIT,

        // Symbols
        COMMA,
        LESS_THAN,

        DOT,
        GREATER_THAN,

        FORWARD_SLASH,
        QUESTION_MARK,

        SEMI_COLON,
        COLON,

        APOSTROPHE,
        QUOTATION_MARK,

        LEFT_BRACKET,
        LEFT_BRACE,

        RIGHT_BRACKET,
        RIGHT_BRACE,

        BACKWARD_SLASH,
        PIPE,

        BACKTICK,
        TILDE,

        BANG,
        AT_SYMBOL,
        OCTOTHORPE,
        DOLLAR,
        PERCENT,
        CARET,
        AMPERSAND,
        ASTERISK,
        LEFT_PARENTHESIS,
        RIGHT_PARENTHESIS,

        HYPHEN,
        UNDERSCORE,

        EQUALS,
        PLUS,

        // Concatenation of some of the previous
        IDENTIFIER,

        // Keywords
        IF,
        INT,
        REAL,
        STRING,
        BOOLEAN,

        // End-of-file        
        END_OF_FILE
    };
}