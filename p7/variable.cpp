#include "variable.h"

Variable::Variable(Symbol* symbol, string* field /* = NULL */) {
  m_symbol = symbol;
  m_value= NULL;
  m_expr = NULL;
  if (field != NULL) {
    m_field = field;
    symbol->get_game_object_value()->get_member_variable_type(*m_field, m_type);
  } else {
    m_type = m_symbol->get_base_type();
  }
}

Variable::Variable(Symbol* symbol, Expression* expr, string* field /* = NULL */) {
  m_value = NULL;
  m_symbol = symbol;
  m_expr = expr;
  if (field != NULL) {
    m_field = field;
    symbol->get_game_object_value(expr->eval_int())->get_member_variable_type(*m_field, m_type);
  } else {
    m_type = m_symbol->get_base_type();
  }
}

Gpl_type Variable::get_type() {
  return m_type;
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

