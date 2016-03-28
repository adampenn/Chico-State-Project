#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"

class Expression;

class Variable {
  public:
    Variable(Symbol* symbol);
    Variable(Symbol* symbol, Expression* expr);
    Variable(Animation_block* ab);
    Gpl_type get_type();
    int get_int_value();
    double get_double_value();
    string get_string_value();
    Animation_block* get_animation_block_value();
  private:
    Symbol* m_symbol;
    Expression* m_expr;
    Animation_block* m_animation_block;
    Gpl_type m_type;
};

#endif // VARIABLE_H
