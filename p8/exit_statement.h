#ifndef EXIT_STATEMENT_H
#define EXIT_STATEMENT_H

#include "expression.h"
#include "statement.h"

class Exit_statement : public Statement {
  public:
    Exit_statement(Expression* expr, int line);
    virtual void execute();
  private:
    int m_line;
    Expression* m_expr;
};

#endif // EXIT_STATEMENT_H
