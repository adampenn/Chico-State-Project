#ifndef FOR_STATEMENT_H
#define FOR_STATEMENT_H

#include "expression.h"
#include "statement.h"

class For_statement : public Statement {
  public:
    For_statement(Statement_block* assign, Expression* cond, Statement_block* incr, Statement_block* body);
    virtual void execute();
  private:
    Expression* m_cond;
    Statement_block* m_assign;
    Statement_block* m_incr;
    Statement_block* m_body;
};

#endif // FOR_STATEMENT_H
