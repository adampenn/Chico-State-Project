#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include "expression.h"
#include "statement.h"

class If_statement : public Statement {
  public:
    If_statement(Expression* expr, Statement_block* then, Statement_block* n_else);
    virtual void execute();
  private:
    Expression* m_expr;
    Statement_block* m_then;
    Statement_block* m_else;
};

#endif // IF_STATEMENT_H
