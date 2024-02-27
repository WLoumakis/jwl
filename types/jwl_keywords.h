#ifndef __JWL_KEYWORDS_H__
#define __JWL_KEYWORDS_H__

#include <types/jwl_tokens.h>

static char keyword_map[jwl::Token::KeywordCount][50] =
{
    "if",        // Token::IF
    "for",       // Token::FOR
    "do",        // Token::DO
    "while",     // Token::WHILE
    "switch",    // Token::SWITCH
    "template",  // Token::TEMPLATE
    "typename",  // Token::TYPENAME
    "bool",      // Token::BOOL
    "true",      // Token::TRUE
    "false",     // Token::FALSE
    "unsigned",  // Token::UNSIGNED
    "int",       // Token::INT
    "i8",        // Token::I8
    "i16",       // Token::I16
    "i32",       // Token::I32
    "i64",       // Token::I64
    "ui8",       // Token::UI8
    "ui16",      // Token::UI16
    "ui32",      // Token::UI32
    "ui64",      // Token::UI64
    "float",     // Token::FLOAT
    "f32",       // Token::F32
    "uf32",      // Token::UF32
    "double",    // Token::DOUBLE
    "f64",       // Token::F64
    "uf64",      // Token::UF64
    "string",    // Token::STRING
    "void",      // Token::VOID
    "class",     // Token::CLASS
    "private",   // Token::PRIVATE
    "protected", // Token::PROTECTED
    "public",    // Token::PUBLIC
    "include",   // Token::INCLUDE
};

#endif
