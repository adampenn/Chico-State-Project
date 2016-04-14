#include "assignment_statement.h"

Assignment_statement::Assignment_statement(Variable* left, Expression* right, Operator_type type) {
  m_left = left;
  m_right = right;
  m_type = type;
}

void Assignment_statement::execute() {
  if (m_type == EQUAL) {
    m_left->set(m_right);
  } else if (m_type == PLUS) {
    switch (m_left->get_type()) {
      case INT: {
        int init_val = m_left->get_int_value();
        int add_val = m_right->eval_int();
        Expression* expr = new Expression(add_val+init_val);
        m_left->set(expr);
        break;
      } case DOUBLE: {
        double init_val = m_left->get_double_value();
        double add_val = m_right->eval_double();
        Expression* expr = new Expression(init_val+add_val);
        m_left->set(expr);
        break;
      } case STRING: {
        string init_val = m_left->get_string_value();
        string add_val = m_right->eval_string();
        Expression* expr = new Expression(init_val+add_val);
        m_left->set(expr);
        break;
      } default: {
        assert(false && "incorrect type");
      }
    }
  } else if (m_type == MINUS) {
    switch (m_left->get_type()) {
      case INT: {
        int init_val = m_left->get_int_value();
        int minus_val = m_right->eval_int();
        Expression* expr = new Expression(init_val-minus_val);
        m_left->set(expr);
        break;
      } case DOUBLE: {
        double init_val = m_left->get_double_value();
        double minus_val = m_right->eval_double();
        Expression* expr = new Expression(init_val-minus_val);
        m_left->set(expr);
        break;
      } default: {
        assert(false && "incorrect type");
      }
    }
  } else {
    assert(false && "FINISH THIS");
  }
}

