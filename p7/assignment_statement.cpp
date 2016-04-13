#include "assignment_statement.h"

Assignment_statement::Assignment_statement(Variable* left, Expression* right, Operator_type type) {
  m_left = left;
  m_right = right;
  m_type = type;
}

void Assignment_statement::execute() {
  if (m_type == EQUAL) {
    m_left->set(m_right);
  } else {
    assert(false && "FINISH THIS");
  }
}

