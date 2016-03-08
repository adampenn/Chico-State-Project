#include "variable.h"

Variable::Variable(Symbol* symbol) {
  m_symbol = symbol;
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
  if (get_type() == INT_ARRAY) {
    
  }
  else if (get_type() == INT) {
    return m_symbol->get_int_value();
  }
  return INT_MIN;
}

double Variable::get_double_value() {
  if (get_type() == DOUBLE_ARRAY) {
    
  }
  else if (get_type() == DOUBLE) {
    return m_symbol->get_double_value();
  }
}

string Variable::get_string_value() {
  if (get_type() == STRING_ARRAY) {
    
  }
  else if (get_type() == STRING) {
    return m_symbol->get_string_value();
  }
}

