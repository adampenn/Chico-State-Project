#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "expression.h"
#include "statement.h"

class Print_statement : public Statement {
  public:
    Print_statement(Expression* expr, int line);
    virtual void execute();
  private:
    int m_line;
    Expression* m_expr;
};

#endif // PRINT_STATEMENT_H
