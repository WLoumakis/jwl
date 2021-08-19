# JWL Programming Language

This repository is the official location of the JWL Programming Language.

## About

The correct pronunciation of **JWL** is "jewel."  You might be wondering what **JWL** stands for; let me clear that up for you.  My name is **J**ohn **W**alton **L**oumakis, hence the name of the language.  It might be a bit self-centered, but who cares. I think it's a pretty cool name for a programming language so why the hell not?

**JWL** is a strongly-typed, statically-scoped, object-oriented programming language that will *hopefully* be the successor to C/C++ due to the fact that it will have remarkably similar functionality, but with some nice additions that make it a bit more user-friendly.  For example, in **JWL**, identifiers (variable/function names) allow special characters outside of the standard underscore (_), namely the hyphen (-), eroteme (?), and others (see the syntax specification section for identifiers, or view the grammar).

The reason for that is because I'm lazy. Kebab-case is the way of the future, whether you like it or not. Take the following as an example:
```
var kebab-case-rules = snake_case_sucks_because_of_pressing_shift + camelCaseIsEvenWorseSinceYouStillPressShift + whatHappensWithABCInitialisms
```
See? Kebab-case allows you to not have to press the shift key **EVER** and you are never confused where a word stops — unless it's a hyphenated word but other case types would struggle with that too. Regardless, kebab-case is amazing. If you're wondering how one would determine the difference between subtraction and variable name, it's really quite simple: **PAD YOUR OPERATORS WITH SPACES, YOU FUCKING MONSTER!!!**
```
// This an absolute travesty:
var c=a-b

// This is pleasing to the eyes and better conveys the message:
var c = a - b
```
But I digress. Let's get into the actual meat and potatoes.

[//]: # (TODO: add section number for identifier syntax and hyperlink to the grammar)
