#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"

class Expression;

class Variable {
  public:
    Variable(int value);
    Variable(double value);
    Variable(string value);
    Variable(Symbol* symbol);
    Variable(Symbol* symbol, Expression* expr);
    Gpl_type get_type();
    int get_int_value();
    double get_double_value();
    string get_string_value();
    Animation_block* get_animation_block_value();
  private:
    Symbol* m_symbol;
    void* m_value;
    Expression* m_expr;
    Gpl_type m_type;
};

#endif // VARIABLE_H
