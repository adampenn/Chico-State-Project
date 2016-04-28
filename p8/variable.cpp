#include "variable.h"

Variable::Variable(Symbol* symbol, string* field /* = NULL */) {
  m_symbol = symbol;
  m_value= NULL;
  m_expr = NULL;
  m_field = field;
  if (field != NULL) {
    symbol->get_game_object_value()->get_member_variable_type(*m_field, m_type);
  } else {
    if (m_symbol->get_base_type() & GAME_OBJECT) {
      m_type = m_symbol->get_type();
    } else {
      m_type = m_symbol->get_base_type();
    }
  }
}

Variable::Variable(Symbol* symbol, Expression* expr, string* field /* = NULL */) {
  m_value = NULL;
  m_symbol = symbol;
  m_expr = expr;
  m_field = field;
  if (field != NULL) {
    m_field = field;
    symbol->get_game_object_value(0)->get_member_variable_type(*m_field, m_type);
  } else {
    if (m_symbol->get_base_type() & GAME_OBJECT) {
      m_type = m_symbol->get_type();
    } else {
      m_type = m_symbol->get_base_type();
    }
  }
}

Gpl_type Variable::get_type() {
  return m_type;
}

string Variable::get_name() const {
  return m_symbol->get_name();
}

int Variable::get_int_value() {
  if (m_expr != NULL) {
    if (m_field != NULL) {
      if (m_expr->get_type() == DOUBLE) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      } else if (m_expr->get_type() == STRING) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      } else {
        int value;
        m_symbol->get_game_object_value(m_expr->eval_int())->get_member_variable(*m_field, value);
        return value;
      }
    } else {
      if (m_expr->get_type() == DOUBLE) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      } else if (m_expr->get_type() == STRING) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      } else {
        return m_symbol->get_int_value(m_expr->eval_int());
      }
    }
  } else {
    if (m_field != NULL) {
      int value;
      m_symbol->get_game_object_value()->get_member_variable(*m_field, value);
      return value;
    } else {
      return m_symbol->get_int_value();
    }
  }
  return INT_MIN;
}

double Variable::get_double_value() {
  if (m_expr != NULL) {
    if (m_field != NULL) {
      if (m_expr->get_type() == DOUBLE) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      } else if (m_expr->get_type() == STRING) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      } else {
        double value;
        m_symbol->get_game_object_value(m_expr->eval_int())->get_member_variable(*m_field, value);
        return value;
      }
    } else {
      if (m_expr->get_type() == DOUBLE) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      } else if (m_expr->get_type() == STRING) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      } else {
        return m_symbol->get_double_value(m_expr->eval_int());
      }
    }
  } else {
    if (m_field != NULL) {
      double value;
      m_symbol->get_game_object_value()->get_member_variable(*m_field, value);
      return value;
    } else {
      return m_symbol->get_double_value();
    }
  }
  return INT_MIN;
}

string Variable::get_string_value() {
  if (m_expr != NULL) {
    if (m_field != NULL) {
      if (m_expr->get_type() == DOUBLE) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      } else if (m_expr->get_type() == STRING) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      } else {
        string value;
        m_symbol->get_game_object_value(m_expr->eval_int())->get_member_variable(*m_field, value);
        return value;
      }
    } else {
      if (m_expr->get_type() == DOUBLE) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      } else if (m_expr->get_type() == STRING) {
	      Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      } else {
        return m_symbol->get_string_value(m_expr->eval_int());
      }
    }
  } else {
    if (m_field != NULL) {
      string value;
      m_symbol->get_game_object_value()->get_member_variable(*m_field, value);
      return value;
    } else {
      return m_symbol->get_string_value();
    }
  }
  return "FUCKED";
}

Animation_block* Variable::get_animation_block_value() {
  return m_symbol->get_animation_block_value();
}

void Variable::set(Expression* expr) {
  if (m_expr != NULL) {
    if (m_expr->get_type() == DOUBLE) {
	    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A double expression");
      return;
    } else if (m_expr->get_type() == STRING) {
	    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, m_symbol->get_name(), "A string expression");
      return;
    }
    if (m_expr->eval_int() >= m_symbol->get_size() || m_expr->eval_int() < 0) {
      stringstream index;
      index << m_expr->eval_int();
      Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_symbol->get_name(), index.str());
    }
    switch(m_symbol->get_base_type()) {
      case INT: {
        m_symbol->set(expr->eval_int(), m_expr->eval_int());
        break;
      } case DOUBLE: {
        m_symbol->set(expr->eval_double(), m_expr->eval_int());
        break;
      } case STRING: {
        m_symbol->set(expr->eval_string(), m_expr->eval_int());
        break;
      } case GAME_OBJECT: {
        if (m_field == NULL) {
          assert(false);
        }
        switch (expr->get_type()) {
          case INT: {
            m_symbol->get_game_object_value(m_expr->eval_int())->set_member_variable(*m_field, expr->eval_int());
            break;
          } case DOUBLE: {
            m_symbol->get_game_object_value(m_expr->eval_int())->set_member_variable(*m_field, expr->eval_double());
            break;
          } case STRING: {
            m_symbol->get_game_object_value(m_expr->eval_int())->set_member_variable(*m_field, expr->eval_string());
            break;
          } default: {
            assert(false && "Error");
          }
        }
        break;
      } default: {
        assert(false && "Error");
      }
    }
  } else {
    switch(m_symbol->get_base_type()) {
      case INT: {
        m_symbol->set(expr->eval_int());
        break;
      } case DOUBLE: {
        m_symbol->set(expr->eval_double());
        break;
      } case STRING: {
        m_symbol->set(expr->eval_string());
        break;
      } case GAME_OBJECT: {
        if (m_field == NULL) {
          assert(false);
        }
        switch (expr->get_type()) {
          case INT: {
            m_symbol->get_game_object_value()->set_member_variable(*m_field, expr->eval_int());
            break;
          } case DOUBLE: {
            m_symbol->get_game_object_value()->set_member_variable(*m_field, expr->eval_double());
            break;
          } case STRING: {
            m_symbol->get_game_object_value()->set_member_variable(*m_field, expr->eval_string());
            break;
          } default: {
            assert(false && "Error");
          }
        }
        break;
      } default: {
        assert(false && "Error");
      }
    }
  }
}
