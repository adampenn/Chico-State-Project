#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"

class Expression;

class Variable {
  public:
    Variable(int value);
    Variable(double value);
    Variable(string value);
    Variable(Symbol* symbol, string* field = NULL);
    Variable(Symbol* symbol, Expression* expr, string* field = NULL);
    Gpl_type get_type();
    int get_int_value();
    double get_double_value();
    string get_string_value();
    Animation_block* get_animation_block_value();
    void set(Expression* expr);
    string get_name() const;
  private:
    Symbol* m_symbol;
    void* m_value;
    string* m_field;
    Expression* m_expr;
    Gpl_type m_type;
};

#endif // VARIABLE_H
