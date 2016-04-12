#include "print_statement.h"

Print_statement::Print_statement(Expression *expr, int line) {
  m_line = line;
  m_expr = expr;
}

void Print_statement::execute() {
  cout << "print[" << m_line << "]: " << m_expr->eval_string() << endl;
}
