#include "for_statement.h"

For_statement::For_statement(Statement_block* assign, Expression* cond, Statement_block* incr, Statement_block* body) {
  m_assign = assign;
  m_cond = cond;
  m_incr = incr;
  m_body = body;
}

void For_statement::execute() {
  m_assign->execute();
  while(m_cond->eval_int()) {
    m_body->execute();
    m_incr->execute();
  }
}

