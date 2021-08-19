#ifndef __JWL_LEXER_H__
#define __JWL_LEXER_H__

#include "types/jwl_tokens.h"

#include <fstream>
#include <string>

namespace jwl {
    /**
     * The JWL Lexer; reads a file and returns JWL tokens contained within the file
     */
    class Lexer {
    public:
        /**
         * Constructs a Lexer with a supplied path to a file; prints to std::cout
         * @param file_path The absolute file path to the JWL file
         */
        Lexer(const std::string& file_path);

        /**
         * Deconstructs the Lexer object
         */
        virtual ~Lexer();

        /**
         * Reads a token from the stream and interprets it as a token
         * @returns A matching JWL token
         */
        Token lex();
    
    protected:
        /**
         * Steps forward in the stream and returns that character
         * @returns The current character in the stream
         */
        char getChar();

        /**
         * Looks ahead and grabs the next character, then steps back
         * @returns The next character in the stream
         */
        char lookAhead();

        /**
         * Determines if the supplied character is valid for an identifier
         * @param ch The character to check
         * @returns true if the character is a valid character for identifiers, false otherwise
         */
        bool isValidIdentifierCharacter(char ch);

    private:
        std::fstream infile;
        uint64_t line;
    };
}

#endif // __JWL_LEXER_H__