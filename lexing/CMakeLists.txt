set(LIBRARY_NAME ${PROJECT_NAME}_Lexing)

set(SOURCES
    jwl_lexer.cpp
)

# Create JWL_Lexing.so
add_library(${LIBRARY_NAME}
SHARED
    ${SOURCES}
)

target_include_directories(${LIBRARY_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}
)

# Setup for JWL_Lexer
set(EXE_NAME ${PROJECT_NAME}_Lexer)

set(SOURCES
    jwl_lexer_main.cpp
)

# Create JWL_Lexer
add_executable(${EXE_NAME}
    ${SOURCES}
)

target_include_directories(${EXE_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${EXE_NAME}
PUBLIC
    ${LIBRARY_NAME}
)
