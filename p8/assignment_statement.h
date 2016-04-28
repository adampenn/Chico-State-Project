#ifndef ASSIGNMENT_STATEMENT_H
#define ASSIGNMENT_STATEMENT_H

#include "expression.h"
#include "statement.h"
#include "variable.h"

class Assignment_statement : public Statement {
  public:
    Assignment_statement(Variable* left, Expression* right, Operator_type type);
    virtual void execute();
  private:
    Variable* m_left;
    Expression* m_right;
    Operator_type m_type;
};

#endif // ASSIGNMENT_STATEMENT_H
