#include "exit_statement.h"

Exit_statement::Exit_statement(Expression *expr, int line) {
  m_line = line;
  m_expr = expr;
}

void Exit_statement::execute() {
  cout << "gpl[" << m_line << "]: exit(" << m_expr->eval_int() << ")" << endl;
  exit(m_expr->eval_int());
}
