/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_DOUBLE = 259,
    T_STRING = 260,
    T_TRIANGLE = 261,
    T_PIXMAP = 262,
    T_CIRCLE = 263,
    T_RECTANGLE = 264,
    T_TEXTBOX = 265,
    T_FORWARD = 266,
    T_INITIALIZATION = 267,
    T_TRUE = 268,
    T_FALSE = 269,
    T_TOUCHES = 270,
    T_NEAR = 271,
    T_ANIMATION = 272,
    T_IF = 273,
    T_FOR = 274,
    T_ELSE = 275,
    T_PRINT = 276,
    T_EXIT = 277,
    T_LPAREN = 278,
    T_RPAREN = 279,
    T_LBRACE = 280,
    T_RBRACE = 281,
    T_LBRACKET = 282,
    T_RBRACKET = 283,
    T_SEMIC = 284,
    T_COMMA = 285,
    T_PERIOD = 286,
    T_ASSIGN = 287,
    T_PLUS_ASSIGN = 288,
    T_MINUS_ASSIGN = 289,
    T_ASTERISK = 290,
    T_DIVIDE = 291,
    T_MOD = 292,
    T_PLUS = 293,
    T_MINUS = 294,
    T_SIN = 295,
    T_COS = 296,
    T_TAN = 297,
    T_ASIN = 298,
    T_ACOS = 299,
    T_ATAN = 300,
    T_SQRT = 301,
    T_FLOOR = 302,
    T_ABS = 303,
    T_RANDOM = 304,
    T_LESS = 305,
    T_GREATER = 306,
    T_LESS_EQUAL = 307,
    T_GREATER_EQUAL = 308,
    T_EQUAL = 309,
    T_NOT_EQUAL = 310,
    T_AND = 311,
    T_OR = 312,
    T_NOT = 313,
    T_ON = 314,
    T_SPACE = 315,
    T_LEFTARROW = 316,
    T_RIGHTARROW = 317,
    T_UPARROW = 318,
    T_DOWNARROW = 319,
    T_LEFTMOUSE_DOWN = 320,
    T_MIDDLEMOUSE_DOWN = 321,
    T_RIGHTMOUSE_DOWN = 322,
    T_LEFTMOUSE_UP = 323,
    T_MIDDLEMOUSE_UP = 324,
    T_RIGHTMOUSE_UP = 325,
    T_MOUSE_MOVE = 326,
    T_MOUSE_DRAG = 327,
    T_F1 = 328,
    T_AKEY = 329,
    T_SKEY = 330,
    T_DKEY = 331,
    T_FKEY = 332,
    T_HKEY = 333,
    T_JKEY = 334,
    T_KKEY = 335,
    T_LKEY = 336,
    T_WKEY = 337,
    T_ID = 338,
    T_INT_CONSTANT = 339,
    T_DOUBLE_CONSTANT = 340,
    T_STRING_CONSTANT = 341,
    T_ERROR = 342,
    IF_NO_ELSE = 343,
    UNARY_OPS = 344
  };
#endif
/* Tokens.  */
#define T_INT 258
#define T_DOUBLE 259
#define T_STRING 260
#define T_TRIANGLE 261
#define T_PIXMAP 262
#define T_CIRCLE 263
#define T_RECTANGLE 264
#define T_TEXTBOX 265
#define T_FORWARD 266
#define T_INITIALIZATION 267
#define T_TRUE 268
#define T_FALSE 269
#define T_TOUCHES 270
#define T_NEAR 271
#define T_ANIMATION 272
#define T_IF 273
#define T_FOR 274
#define T_ELSE 275
#define T_PRINT 276
#define T_EXIT 277
#define T_LPAREN 278
#define T_RPAREN 279
#define T_LBRACE 280
#define T_RBRACE 281
#define T_LBRACKET 282
#define T_RBRACKET 283
#define T_SEMIC 284
#define T_COMMA 285
#define T_PERIOD 286
#define T_ASSIGN 287
#define T_PLUS_ASSIGN 288
#define T_MINUS_ASSIGN 289
#define T_ASTERISK 290
#define T_DIVIDE 291
#define T_MOD 292
#define T_PLUS 293
#define T_MINUS 294
#define T_SIN 295
#define T_COS 296
#define T_TAN 297
#define T_ASIN 298
#define T_ACOS 299
#define T_ATAN 300
#define T_SQRT 301
#define T_FLOOR 302
#define T_ABS 303
#define T_RANDOM 304
#define T_LESS 305
#define T_GREATER 306
#define T_LESS_EQUAL 307
#define T_GREATER_EQUAL 308
#define T_EQUAL 309
#define T_NOT_EQUAL 310
#define T_AND 311
#define T_OR 312
#define T_NOT 313
#define T_ON 314
#define T_SPACE 315
#define T_LEFTARROW 316
#define T_RIGHTARROW 317
#define T_UPARROW 318
#define T_DOWNARROW 319
#define T_LEFTMOUSE_DOWN 320
#define T_MIDDLEMOUSE_DOWN 321
#define T_RIGHTMOUSE_DOWN 322
#define T_LEFTMOUSE_UP 323
#define T_MIDDLEMOUSE_UP 324
#define T_RIGHTMOUSE_UP 325
#define T_MOUSE_MOVE 326
#define T_MOUSE_DRAG 327
#define T_F1 328
#define T_AKEY 329
#define T_SKEY 330
#define T_DKEY 331
#define T_FKEY 332
#define T_HKEY 333
#define T_JKEY 334
#define T_KKEY 335
#define T_LKEY 336
#define T_WKEY 337
#define T_ID 338
#define T_INT_CONSTANT 339
#define T_DOUBLE_CONSTANT 340
#define T_STRING_CONSTANT 341
#define T_ERROR 342
#define IF_NO_ELSE 343
#define UNARY_OPS 344

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 46 "gpl.y" /* yacc.c:1909  */

 int            union_int;
 double		union_double;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)

#line 238 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
