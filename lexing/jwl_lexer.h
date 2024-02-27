#ifndef __JWL_LEXER_H__
#define __JWL_LEXER_H__

#include "types/jwl_tokens.h"

#include <fstream>
#include <string>
#include <stdint.h>

namespace jwl
{
    /// \class The JWL Lexer; reads a file and returns JWL tokens contained within the file
    class Lexer
    {
    public:
        /// \brief Constructs a Lexer with a supplied path to a file; prints to \c std::cout
        /// \param[in] file_path The absolute file path to the JWL file
        Lexer(const std::string& file_path);

        /// \brief Deconstructs the Lexer object
        virtual ~Lexer();

        /// \brief Reads a token from the stream and interprets it as a token
        /// \returns A matching JWL token
        Token lex();

        /// \brief Gets the current line position of the file
        std::uint64_t getLine() const;

        /// \brief Gets the current column position of the file
        std::uint64_t getColumn() const;

        /// \brief The maximum number of characters that can belong to a single token. Not sure why anyone would ever use 3000 characters, but yada yada future-proofing
        static const std::size_t MAX_TOKEN_LENGTH = 3000;

    protected:
        /// \brief Steps forward in the stream and returns that character
        /// \returns The current character in the stream
        char getChar();

        /// \brief Looks ahead and grabs the next character, then steps back
        /// \returns The next character in the stream
        char lookAhead();

        // TODO: This is pretty useless right now. Once Lexemes get added this will make more sense
        /// \brief Reads an entire string of identifier characters until it reaches an invalid identifier character
        /// \returns A corresponding keyword \c Token if it matches, \c Token::IDENTIFIER otherwise
        Token lexKeywordOrIdentifier();

        /// \brief Determines if the supplied character is valid for an identifier
        /// \param[in] ch The character to check
        /// \returns true if the character is a valid character for identifiers, false otherwise
        bool isValidIdentifierCharacter(char ch);

        /// \brief Searches the list of keywords to see if \c str matches
        /// \param[in] str The string to try to match
        /// \returns The corresponding \c Token if \c str matches, \c Token::INVALID otherwise
        Token matchKeyword(const char* str);

        // TODO: This is pretty useless right now. Once Lexemes get added this will make more sense
        /// \brief Reads an entire string of numeric characters until it reaches an invalid numeric character
        /// \returns \c Token::NUMBER if successfully meeting the criteria of being a number, \c Token::INVALID otherwise
        Token lexNumber();

        // TODO: This is pretty useless right now. Once Lexemes get added this will make more sense
        /// \brief Reads an entire string of hexadecimal characters until it reaches an invalid hexadecimal character
        /// \returns \c Token::NUMBER if successfully meeting the criteria of being a hexadecimal number, \c Token::INVALID otherwise
        Token lexHexadecimal();

        // TODO: This is pretty useless right now. Once Lexemes get added this will make more sense
        /// \brief Reads an entire string of octal characters until it reaches an invalid octal character
        /// \returns \c Token::NUMBER if successfully meeting the criteria of being an octal number, \c Token::INVALID otherwise
        Token lexOctal();

        // TODO: This is pretty useless right now. Once Lexemes get added this will make more sense
        /// \brief Reads an entire string of binary characters until it reaches an invalid binary character
        /// \returns \c Token::NUMBER if successfully meeting the criteria of being a binary number, \c Token::INVALID otherwise
        Token lexBinary();

    private:
        std::fstream infile;
        std::uint64_t line;
        std::uint64_t column;
    };
}

#endif // __JWL_LEXER_H__
