#include "variable.h"

Variable::Variable(Symbol* symbol) {
  m_symbol = symbol;
  m_expr = NULL;
  m_type = m_symbol->get_base_type();
}

Variable::Variable(Symbol* symbol, Expression* expr) {
  m_symbol = symbol;
  m_expr = expr;
  m_type = m_symbol->get_base_type();
}

Gpl_type Variable::get_type() {
  return m_type;
}

int Variable::get_int_value() {
  if (m_expr != NULL) {
    stringstream ss;
    if (m_expr->get_type() == DOUBLE) {
	    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
    } else if (m_expr->get_type() == STRING) {
	    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
    } else {
      return m_symbol->get_int_value(m_expr->eval_int());
    }
  }
  else {
    return m_symbol->get_int_value();
  }
  return INT_MIN;
}

double Variable::get_double_value() {
  if (m_expr != NULL) {
     return m_symbol->get_double_value(m_expr->eval_int());
  }
  else {
    return m_symbol->get_double_value();
  }
}

string Variable::get_string_value() {
  if (m_expr != NULL) {
     return m_symbol->get_string_value(m_expr->eval_int());
  }
  else {
    return m_symbol->get_string_value();
  }
}

