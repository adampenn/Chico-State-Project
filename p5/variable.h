#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"

class Expression;

class Variable {
  public:
    Variable(Symbol* symbol);
    Variable(Symbol* symbol, Expression* expr);
    Gpl_type get_type();
    int get_int_value();
    double get_double_value();
    string get_string_value();
  private:
    Symbol* m_symbol;
    Expression* m_expr;
    Gpl_type m_type;
};

#endif // VARIABLE_H
