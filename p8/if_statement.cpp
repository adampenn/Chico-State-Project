#include "if_statement.h"

If_statement::If_statement(Expression* expr, Statement_block* then, Statement_block* n_else) {
  m_expr = expr;
  m_then = then;
  m_else = n_else;
}

void If_statement::execute() {
  if (m_expr->eval_int()) {
    m_then->execute();
  } else {
    if (m_else != NULL) {
      m_else->execute();
    }
  }
}
