/* ASK TYSON:

   t106
     could fix by saying if ! NO_TYPE before issuing
     invalid left operand error
   t120
     Fixed by saying if ! NO_TYPE before issuing invalid
     init type error

*/

/*

  This file contains the input to the bison compiler generator.
  bison will use this file to generate a C/C++ parser.

  The default output file for bison is: y.tab.c

    $ bison gpl.y    will produce the file y.tab.c
*/

%{  // bison syntax to indicate the start of the header
    // the header is copied directly into y.tab.c (the generated parser)

extern int yylex();               // this lexer function returns next token
extern int yyerror(const char *); // used to print errors
extern int line_count;            // current line in the input; from record.l

#include "error.h"      // class for printing errors (used by gpl)
#include "parser.h"
#include <iostream>
#include <string>
using namespace std;
Symbol_table* table = Symbol_table::instance();
Game_object* cur_object_under_construction = NULL;
string cur_object_name = "";
// bison syntax to indicate the end of the header

// Error checking

Expression* create_binary_expression(Expression *left,
                               Operator_type oper,
                               Expression *right,
                               int legal_left,
                               int legal_right
                              ) {
  if (!(left->get_type() & legal_left) || !(right->get_type() & legal_right)) {
    if (!(left->get_type() & legal_left)) {
      Error::error(Error::INVALID_LEFT_OPERAND_TYPE, operator_to_string(oper));
    }
    if (!(right->get_type() & legal_right)) {
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string(oper));
    }
    return new Expression(0);
  } else {
    return new Expression(left, oper, right);
  }
}

Expression* create_unary_expression(Expression *left,
                               Operator_type oper,
                               int legal_left
                              ) {
  if (!(left->get_type() & legal_left)) {
    if (!(left->get_type() & legal_left)) {
      Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string(oper));
    }
    return new Expression(0);
  } else {
    return new Expression(oper, left);
  }
}

%} 

// The union is used to declare the variable yylval which is used to
// pass data between the flex generated lexer and the bison generated parser, 
// and to pass values up/down the parse tree.
// 
// A union is kind of like a structure or class, but you can only use one 
// field at a time.  Each line describes one item in the union.  The left hand
// side is the type, the right hand side is a name for the type.
// 
// Unions do not have any error checking.  For example, if you put an int in
// the following union  (my_union.union_int = 42)  and then attempt to use it
// as a string (cout << my_union.union_string) you will get garbage.

// The "%union" is bison syntax
// The "union_" is my convention to indicate a member of the union 
//     (it can be hard to tell what is a union field and what is not)
//
// In this example, the union only has one member (union_int).  You will
// be adding a double declaration to the union.

%union {
 int            union_int;
 double		union_double;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 enum Gpl_type	union_gpl_type;
 enum Operator_type	union_operator;
 Expression	*union_expression;
 Variable	*union_variable;
}

// turn on verbose (longer) error messages
%error-verbose

%token T_INT                 "int"
%token T_DOUBLE              "double"
%token T_STRING              "string"
%token T_TRIANGLE            "triangle"
%token T_PIXMAP              "pixmap"
%token T_CIRCLE              "circle"
%token T_RECTANGLE           "rectangle"
%token T_TEXTBOX             "textbox"
%token <union_int> T_FORWARD "forward" // value is line number
%token T_INITIALIZATION      "initialization"

%token T_TRUE                "true"
%token T_FALSE               "false"

%token T_TOUCHES             "touches"
%token T_NEAR                "near"

%token T_ANIMATION           "animation"

%token T_IF                  "if"
%token T_FOR                 "for"
%token T_ELSE                "else"
%token <union_int> T_PRINT   "print" // value is line number
%token <union_int> T_EXIT    "exit" // value is line number

%token T_LPAREN              "("
%token T_RPAREN              ")"
%token T_LBRACE              "{"
%token T_RBRACE              "}"
%token T_LBRACKET            "["
%token T_RBRACKET            "]"
%token T_SEMIC               ";"
%token T_COMMA               ","
%token T_PERIOD              "."

%token T_ASSIGN              "="
%token T_PLUS_ASSIGN         "+="
%token T_MINUS_ASSIGN        "-="

%token T_ASTERISK            "*"
%token T_DIVIDE              "/"
%token T_MOD                 "%"
%token T_PLUS                "+"
%token T_MINUS               "-"
%token T_SIN                 "sin"
%token T_COS                 "cos"
%token T_TAN                 "tan"
%token T_ASIN                "asin"
%token T_ACOS                "acos"
%token T_ATAN                "atan"
%token T_SQRT                "sqrt"
%token T_FLOOR               "floor"
%token T_ABS                 "abs"
%token T_RANDOM              "random"

%token T_LESS                "<"
%token T_GREATER             ">"
%token T_LESS_EQUAL          "<="
%token T_GREATER_EQUAL       ">="
%token T_EQUAL               "=="
%token T_NOT_EQUAL           "!="

%token T_AND                 "&&"
%token T_OR                  "||"
%token T_NOT                 "!"

%token T_ON                  "on"
%token T_SPACE               "space"
%token T_LEFTARROW           "leftarrow"
%token T_RIGHTARROW          "rightarrow"
%token T_UPARROW             "uparrow"
%token T_DOWNARROW           "downarrow"
%token T_LEFTMOUSE_DOWN      "leftmouse_down"
%token T_MIDDLEMOUSE_DOWN    "middlemouse_down"
%token T_RIGHTMOUSE_DOWN     "rightmouse_down"
%token T_LEFTMOUSE_UP        "leftmouse_up"
%token T_MIDDLEMOUSE_UP      "middlemouse_up"
%token T_RIGHTMOUSE_UP       "rightmouse_up"
%token T_MOUSE_MOVE          "mouse_move"
%token T_MOUSE_DRAG          "mouse_drag"
%token T_F1                  "f1"
%token T_AKEY                "akey"
%token T_SKEY                "skey"
%token T_DKEY                "dkey"
%token T_FKEY                "fkey"
%token T_HKEY                "hkey"
%token T_JKEY                "jkey"
%token T_KKEY                "kkey"
%token T_LKEY                "lkey"
%token T_WKEY                "wkey"

%token <union_string>   	T_ID              "identifier"
%token <union_int>      	T_INT_CONSTANT    "int constant"
%token <union_double>   	T_DOUBLE_CONSTANT "double constant"
%token <union_string> 	  T_STRING_CONSTANT "string constant"
%type <union_gpl_type>	  simple_type
%type <union_gpl_type>	  object_type
%type <union_expression>  expression
%type <union_expression>  primary_expression
%type <union_expression>  optional_initializer
%type <union_variable>	  variable
%type <union_operator>	  math_operator


// special token that does not match any production
// used for characters that are not part of the language
%token T_ERROR               "error"

// pres stuff

%left 		T_OR
%left 		T_AND
%left 		T_EQUAL T_NOT_EQUAL
%left 		T_LESS T_GREATER T_GREATER_EQUAL T_LESS_EQUAL
%left 		T_PLUS T_MINUS
%left 		T_MOD T_DIVIDE T_ASTERISK
%nonassoc 	T_NOT

%nonassoc IF_NO_ELSE
%nonassoc T_ELSE

%nonassoc UNARY_OPS

%% // indicates the start of the rules

//---------------------------------------------------------------------
program:
    declaration_list block_list
    ;

//---------------------------------------------------------------------
declaration_list:
    declaration_list declaration
    | empty
    ;

//---------------------------------------------------------------------
declaration:
    variable_declaration T_SEMIC
    | object_declaration T_SEMIC
    | forward_declaration T_SEMIC
    ;

//---------------------------------------------------------------------
variable_declaration:
    simple_type  T_ID  optional_initializer
    {
      Expression *expression = $3;
      Symbol* symbol;
      if (table->lookup(*$2) == NULL) {
        if ($1 == INT) {
	        int initial_value = 0;
	        if ($3 != NULL) {
	          if ($3->get_type() != NO_TYPE) {
              if ($3->get_type() != INT) {
                Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, gpl_type_to_string(expression->get_type()), *$2, "int");
	            } else {
	              initial_value = $3->eval_int();
	            }
            }
	        }
	        symbol = new Symbol(*$2, initial_value);
	      } else if ($1 == DOUBLE) {
	        double initial_value = 0.0;
	        if ($3 != NULL) {
	          if ($3->get_type() == STRING) {
	            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, gpl_type_to_string(expression->get_type()), *$2, "double");
	          } else {
	            initial_value = $3->eval_double();
	          }
	        }
          symbol = new Symbol(*$2, initial_value);
        } else if ($1 == STRING) {
	        string initial_value = "";
	        if ($3 != NULL) {
	          initial_value = $3->eval_string();
	        }
          symbol = new Symbol(*$2, initial_value);
        }
	      table->insert(*$2, symbol);
      } else {
        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
      }
    }
    | simple_type  T_ID  T_LBRACKET expression T_RBRACKET
    {
      Symbol* symbol;
      if (table->lookup(*$2) == NULL) {
    	  if ($4->get_type() != INT) {
          stringstream ss;
          if ($4->get_type() == DOUBLE) {
            ss << $4->eval_double();
	          Error::error(Error::INVALID_ARRAY_SIZE, *$2, ss.str());
          } else if ( $4->get_type() == STRING) {
            ss << $4->eval_string();
	          Error::error(Error::INVALID_ARRAY_SIZE, *$2, ss.str());
          }
	      } else {
          int size = $4->eval_int();
          if ($4->eval_int() != 0) {
            if ($1 == INT) {
	            symbol = new Symbol(*$2, size, INT_ARRAY);
	          } else if ( $1 == DOUBLE) {
              symbol = new Symbol(*$2, size, DOUBLE_ARRAY);
	          } else if ($1 == STRING) {
              symbol = new Symbol(*$2, size, STRING_ARRAY);
            }
	          table->insert(*$2, symbol);
          } else {
	          Error::error(Error::INVALID_ARRAY_SIZE, *$2, "0");
          }
        }
      } else {
        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
      }
    }
    ;

//---------------------------------------------------------------------
simple_type:
    T_INT
    {
      $$ = INT;
    }
    | T_DOUBLE
    {
      $$ = DOUBLE;
    }
    | T_STRING
    {
      $$ = STRING;
    }
    ;

//---------------------------------------------------------------------
optional_initializer:
    T_ASSIGN expression
    {
      $$ = $2;
    }
    | empty
    {
      $$ = NULL;
    }
    ;

//---------------------------------------------------------------------
object_declaration:
    object_type T_ID
    {
      Symbol* symbol = table->lookup(*$2);
      if (symbol == NULL) {
        switch ($1) {
          case TRIANGLE: {
            cur_object_under_construction = new Triangle();
            break;
          } case PIXMAP: {
            cur_object_under_construction = new Pixmap();
            break;
          } case CIRCLE: {
            cur_object_under_construction = new Circle();
            break;
          } case RECTANGLE: {
            cur_object_under_construction = new Rectangle();
            break;
          } case TEXTBOX: {
            cur_object_under_construction = new Textbox();
            break;
          }
        }
        symbol = new Symbol(*$2, $1, cur_object_under_construction);
        table->insert(*$2, symbol);
      } else {
        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
      }
    }
    T_LPAREN parameter_list_or_empty T_RPAREN
    {
      cur_object_under_construction = NULL;
    }
    | object_type T_ID T_LBRACKET expression T_RBRACKET
    {
      Symbol* symbol = table->lookup(*$2);
      if (symbol == NULL) {
        int size = $4->eval_int();
        switch ($1) {
          case TRIANGLE:
	          symbol = new Symbol(*$2, size, TRIANGLE);
            break;
          case PIXMAP:
	          symbol = new Symbol(*$2, size, PIXMAP);
            break;
          case CIRCLE:
	          symbol = new Symbol(*$2, size, CIRCLE);
            break;
          case RECTANGLE:
	          symbol = new Symbol(*$2, size, RECTANGLE);
            break;
          case TEXTBOX:
	          symbol = new Symbol(*$2, size, TEXTBOX);
            break;
        }
        table->insert(*$2, symbol);
        cur_object_under_construction = NULL;
      } else {
        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *$2);
      }
    }
    ;

//---------------------------------------------------------------------
object_type:
    T_TRIANGLE
    {
      $$ = TRIANGLE;
    }
    | T_PIXMAP
    {
      $$ = PIXMAP;
    }
    | T_CIRCLE
    {
      $$ = CIRCLE;
    }
    | T_RECTANGLE
    {
      $$ = RECTANGLE;
    }
    | T_TEXTBOX
    {
      $$ = TEXTBOX;
    }
    ;

//---------------------------------------------------------------------
parameter_list_or_empty :
    parameter_list
    {
      //$$ = $1;
    }
    | empty
    {
      //$$ = $1;
    }
    ;

//---------------------------------------------------------------------
parameter_list :
    parameter_list T_COMMA parameter
    | parameter
    ;

//---------------------------------------------------------------------
parameter:
    T_ID T_ASSIGN expression
    {
      Gpl_type type = $3->get_type();
      if (type == INT) {
        switch (cur_object_under_construction->set_member_variable(*$1, $3->eval_int())) {
          case MEMBER_NOT_OF_GIVEN_TYPE:
            Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_name, *$1);
            break;
          case MEMBER_NOT_DECLARED:
            Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER, cur_object_name, *$1);
            break;
        }
      } else if (type == DOUBLE) {
        switch (cur_object_under_construction->set_member_variable(*$1, $3->eval_double())) {
          case MEMBER_NOT_OF_GIVEN_TYPE:
            assert(false && "MEMBER NOT OF GIVEN TYPE ERROR");
            break;
          case MEMBER_NOT_DECLARED:
            assert(false && "MEMBER NOT DECLARED");
            break;
        }
      } else if (type == STRING) {
        switch (cur_object_under_construction->set_member_variable(*$1, $3->eval_string())) {
          case MEMBER_NOT_OF_GIVEN_TYPE:
            assert(false && "MEMBER NOT OF GIVEN TYPE ERROR");
            break;
          case MEMBER_NOT_DECLARED:
            assert(false && "MEMBER NOT DECLARED");
            break;
        }
      }
    }
    ;

//---------------------------------------------------------------------
forward_declaration:
    T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
    ;

//---------------------------------------------------------------------
block_list:
    block_list block
    | empty
    ;

//---------------------------------------------------------------------
block:
    initialization_block
    | animation_block
    | on_block
    ;

//---------------------------------------------------------------------
initialization_block:
    T_INITIALIZATION statement_block
    ;

//---------------------------------------------------------------------
animation_block:
    T_ANIMATION T_ID T_LPAREN check_animation_parameter T_RPAREN T_LBRACE { } statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
animation_parameter:
    object_type T_ID
    ;

//---------------------------------------------------------------------
check_animation_parameter:
    T_TRIANGLE T_ID
    | T_PIXMAP T_ID
    | T_CIRCLE T_ID
    | T_RECTANGLE T_ID
    | T_TEXTBOX T_ID
    ;

//---------------------------------------------------------------------
on_block:
    T_ON keystroke statement_block
    ;

//---------------------------------------------------------------------
keystroke:
    T_SPACE
    | T_UPARROW
    | T_DOWNARROW
    | T_LEFTARROW
    | T_RIGHTARROW
    | T_LEFTMOUSE_DOWN
    | T_MIDDLEMOUSE_DOWN
    | T_RIGHTMOUSE_DOWN
    | T_LEFTMOUSE_UP
    | T_MIDDLEMOUSE_UP
    | T_RIGHTMOUSE_UP
    | T_MOUSE_MOVE
    | T_MOUSE_DRAG
    | T_AKEY 
    | T_SKEY 
    | T_DKEY 
    | T_FKEY 
    | T_HKEY 
    | T_JKEY 
    | T_KKEY 
    | T_LKEY 
    | T_WKEY 
    | T_F1
    ;

//---------------------------------------------------------------------
if_block:
    statement_block_creator statement end_of_statement_block
    | statement_block
    ;

//---------------------------------------------------------------------
statement_block:
    T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
statement_block_creator:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
end_of_statement_block:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
statement_list:
    statement_list statement
    | empty
    ;

//---------------------------------------------------------------------
statement:
    if_statement
    | for_statement
    | assign_statement T_SEMIC
    | print_statement T_SEMIC
    | exit_statement T_SEMIC
    ;

//---------------------------------------------------------------------
if_statement:
    T_IF T_LPAREN expression T_RPAREN if_block %prec IF_NO_ELSE
    | T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block
    ;

//---------------------------------------------------------------------
for_statement:
    T_FOR T_LPAREN statement_block_creator assign_statement end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement end_of_statement_block T_RPAREN statement_block
    ;

//---------------------------------------------------------------------
print_statement:
    T_PRINT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
exit_statement:
    T_EXIT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
assign_statement:
    variable T_ASSIGN expression
    | variable T_PLUS_ASSIGN expression
    | variable T_MINUS_ASSIGN expression
    ;

//---------------------------------------------------------------------
variable:
    T_ID
    {
      Symbol* symbol = table->lookup(*$1);
      if (symbol != NULL) {
        $$ = new Variable(symbol);
      } else {
        Error::error(Error::UNDECLARED_VARIABLE, *$1);
        $$ = new Variable(new Symbol(*$1, 0));
      }
    }
    | T_ID T_LBRACKET expression T_RBRACKET
    {
      Symbol* symbol = table->lookup(*$1);
      if (symbol == NULL) {
       Error::error(Error::UNDECLARED_VARIABLE, *$1);
      } else {
        if (!(symbol->get_type() & ARRAY)) {
	        Error::error(Error::VARIABLE_NOT_AN_ARRAY, *$1);
          $$ = new Variable(symbol);
        } else {
          $$ = new Variable(symbol, $3);
        }
      }
    }
    | T_ID T_PERIOD T_ID
    {
      assert(false && "THIS IS FOR P6");
    }
    | T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
    {
      assert(false && "THIS IS FOR P6");
    }
    ;

//---------------------------------------------------------------------
expression:
    primary_expression
    {
      $$ = $1;
    }
    | expression T_OR expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    OR,
                                    $3,
                                    INT | DOUBLE,
                                    INT | DOUBLE
                                   );
    }
    | expression T_AND expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    AND,
                                    $3,
                                    INT | DOUBLE,
                                    INT | DOUBLE
                                   );
    }
    | expression T_LESS_EQUAL expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    LESS_THAN_EQUAL,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_GREATER_EQUAL  expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    GREATER_THAN_EQUAL,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_LESS expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    LESS_THAN,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_GREATER  expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    GREATER_THAN,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_EQUAL expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    EQUAL,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_NOT_EQUAL expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    NOT_EQUAL,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_PLUS expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    PLUS,
                                    $3,
                                    INT | DOUBLE | STRING,
                                    INT | DOUBLE | STRING
                                   );
    }
    | expression T_MINUS expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    MINUS,
                                    $3,
                                    INT | DOUBLE,
                                    INT | DOUBLE
                                   );
    }
    | expression T_ASTERISK expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    MULTIPLY,
                                    $3,
                                    INT | DOUBLE,
                                    INT | DOUBLE
                                   );
    }
    | expression T_DIVIDE expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    DIVIDE,
                                    $3,
                                    INT | DOUBLE,
                                    INT | DOUBLE
                                   );
    }
    | expression T_MOD expression
    {
      $$ = create_binary_expression(
                                    $1,
                                    MOD,
                                    $3,
                                    INT,
                                    INT
                                   );
    }
    | T_MINUS expression %prec UNARY_OPS
    {
      $$ = create_unary_expression(
                                    $2,
                                    MINUS,
                                    INT | DOUBLE
                                   );
    }
    | T_NOT expression %prec UNARY_OPS
    {
      $$ = create_unary_expression(
                                    $2,
                                    NOT,
                                    INT | DOUBLE
                                   );
    }
    | math_operator T_LPAREN expression T_RPAREN
    {
      $$ = create_unary_expression(
                                    $3,
                                    $1,
                                    INT | DOUBLE
                                   );
    }
    | variable geometric_operator variable
    {
      assert(false && "P6");
    }
    ;

//---------------------------------------------------------------------
primary_expression:
    T_LPAREN  expression T_RPAREN
    {
      $$ = $2;
    }
    | variable
    { 
      
      $$ = new Expression($1);
    }
    | T_INT_CONSTANT
    {
      $$ = new Expression($1);
    }
    | T_TRUE
    {
      $$ = new Expression(1);
    }
    | 
    T_FALSE
    {
      $$ = new Expression(0);
    }
    | T_DOUBLE_CONSTANT
    {
      $$ = new Expression($1);
    }
    | T_STRING_CONSTANT
    {
      $$ = new Expression(*$1);
    }
    ;

//---------------------------------------------------------------------
geometric_operator:
    T_TOUCHES
    | T_NEAR
    ;

//---------------------------------------------------------------------
math_operator:
    T_SIN
    {
      $$ = SIN;
    }
    | T_COS
    {
      $$ = COS;
    }
    | T_TAN
    {
      $$ = TAN;
    }
    | T_ASIN
    {
      $$ = ASIN;
    }
    | T_ACOS
    {
      $$ = ACOS;
    }
    | T_ATAN
    {
      $$ = ATAN;
    }
    | T_SQRT
    {
      $$ = SQRT;
    }
    | T_ABS
    {
      $$ = ABS;
    }
    | T_FLOOR
    {
      $$ = FLOOR;
    }
    | T_RANDOM
    {
      $$ = RANDOM;
    }
    ;

//---------------------------------------------------------------------
empty:
    // empty goes to nothing so that you can use empty in productions
    // when you want a production to go to nothing
    ;
