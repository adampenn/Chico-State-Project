#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "error.h"
#include "symbol.h"

class Variable;

// TYSON PLEASE READ THIS AND THEN EMAIL HIM SO HE KNOWS YOU READ IT
// this is a comment so justin will shut the fuck up.

class Expression {
  public:
    Expression(int value);
    Expression(double value);
    Expression(string value);
    Expression(Expression* left, Operator_type oper, Expression* right);
    Expression(Operator_type oper, Expression* left);
    Expression(Variable* variable);
    Gpl_type get_type();
    Variable* get_variable() const;
    int eval_int();//+-*/<>...
    double eval_double();
    string eval_string();//+
    Animation_block* eval_animation_block();
  private:
    enum Tree_kinds {EXPRESSION, CONSTANT, VARIABLE, UNARY, BINARY};
    Tree_kinds m_kind;
    Variable* m_variable;
    Operator_type m_oper;
    int m_int;
    double m_double;
    string m_string;
    Gpl_type m_type;
    Expression* m_left;
    Expression* m_right;
};

#endif // EXPRESSION_H

