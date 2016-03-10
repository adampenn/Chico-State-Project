#include "expression.h"
#include "variable.h"

Expression::Expression(int value) {
  m_kind = CONSTANT;
  m_variable = NULL;
  m_int = value;
  m_type = INT; 
  m_left = NULL;
  m_right = NULL;
}

Expression::Expression(double value) {
  m_kind = CONSTANT;
  m_variable = NULL;
  m_double = value;
  m_type = DOUBLE; 
  m_left = NULL;
  m_right = NULL; 
}

Expression::Expression(string value) {
  m_kind = CONSTANT;
  m_variable = NULL;
  m_string = value;
  m_type = STRING; 
  m_left = NULL;
  m_right = NULL; 
}

Expression::Expression(Expression* left, Operator_type oper, Expression* right) {
  m_kind = BINARY;
  m_variable = NULL;
  m_oper = oper;
  if (oper == LESS_THAN || oper == GREATER_THAN || oper == GREATER_THAN_EQUAL || oper == LESS_THAN_EQUAL || oper == AND || oper == NOT || oper == OR || oper == EQUAL || oper == NOT_EQUAL || oper == TOUCHES || oper == NEAR || oper == FLOOR || oper == RANDOM) {
    m_type = INT;
  } else if (oper == ABS && (left->get_type() == DOUBLE || right->get_type() == DOUBLE)) {
    m_type = DOUBLE;
  } else if (oper == ABS && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  } else if (oper == SIN || oper == COS || oper == TAN || oper == ASIN || oper == ACOS || oper == ATAN) {
    m_type = DOUBLE;
  } else if (oper == PLUS && (left->get_type() == STRING || right->get_type() == STRING)) {
    m_type = STRING;
  } else if (oper == PLUS && (left->get_type() == DOUBLE || right->get_type() == DOUBLE)) {
    m_type = DOUBLE;
  } else if (oper == PLUS && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  } else if (oper == MINUS && (left->get_type() == DOUBLE || right->get_type() == DOUBLE)) {
    m_type = DOUBLE;
  } else if (oper == MINUS && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  } else if (oper == DIVIDE && (left->get_type() == DOUBLE || right->get_type() == DOUBLE)) {
    m_type = DOUBLE;
  } else if (oper == DIVIDE && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  } else if (oper == MULTIPLY && (left->get_type() == DOUBLE || right->get_type() == DOUBLE)) {
    m_type = DOUBLE;
  } else if (oper == MULTIPLY && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  } else if (oper == MOD && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  } else if (oper == UNARY_MINUS && (left->get_type() == DOUBLE || right->get_type() == DOUBLE)) {
    m_type = DOUBLE;
  } else if (oper == UNARY_MINUS && (left->get_type() == INT || right->get_type() == INT)) {
    m_type = INT;
  }
  m_left = left;
  m_right = right;
}

Expression::Expression(Operator_type oper, Expression* left) {
  m_oper = oper;
  m_kind = UNARY;
  m_variable = NULL;
  m_left = left;
  m_right = NULL;
  if (oper == LESS_THAN || oper == GREATER_THAN || oper == GREATER_THAN_EQUAL || oper == LESS_THAN_EQUAL || oper == AND || oper == NOT || oper == OR || oper == EQUAL || oper == NOT_EQUAL || oper == TOUCHES || oper == NEAR || oper == FLOOR || oper == RANDOM) {
    m_type = INT;
  } else if (oper == ABS && left->get_type() == DOUBLE) {
    m_type = DOUBLE;
  } else if (oper == ABS && left->get_type() == INT) {
    m_type = INT;
  } else if (oper == SIN || oper == COS || oper == TAN || oper == ASIN || oper == ACOS || oper == ATAN) {
    m_type = DOUBLE;
  } else if (oper == PLUS && left->get_type() == STRING) {
    m_type = STRING;
  } else if (oper == PLUS && left->get_type() == DOUBLE) {
    m_type = DOUBLE;
  } else if (oper == PLUS && left->get_type() == INT) {
    m_type = INT;
  } else if (oper == MINUS && left->get_type() == DOUBLE) {
    m_type = DOUBLE;
  } else if (oper == MINUS && left->get_type() == INT) {
    m_type = INT;
  } else if (oper == DIVIDE && left->get_type() == DOUBLE) {
    m_type = DOUBLE;
  } else if (oper == DIVIDE && left->get_type() == INT) {
    m_type = INT;
  } else if (oper == MULTIPLY && left->get_type() == DOUBLE) {
    m_type = DOUBLE;
  } else if (oper == MULTIPLY && left->get_type() == INT) {
    m_type = INT;
  } else if (oper == MOD && left->get_type() == INT) {
    m_type = INT;
  } else if (oper == UNARY_MINUS && left->get_type() == DOUBLE) {
    m_type = DOUBLE;
  } else if (oper == UNARY_MINUS && left->get_type() == INT) {
    m_type = INT;
  }
}

Expression::Expression(Variable* variable) {
  m_variable = variable;
  m_left = m_right = NULL;
  m_type = m_variable->get_type();
  m_kind = VARIABLE;
}

Gpl_type Expression::get_type() {
  return m_type;
}

int Expression::eval_int() {
  if (m_kind == CONSTANT) {
    assert(m_type == INT);
    return m_int;
  } else if (m_kind == VARIABLE) {
    return m_variable->get_int_value();
  } else if (m_kind == BINARY) {
    switch (m_oper) {
      case MULTIPLY: {
        return m_left->eval_int() * m_right->eval_int();
        break;
      }
      case PLUS: {
        return m_left->eval_int() + m_right->eval_int();
        break;
      }
      default:
        assert(false && "Finish this shit cracker");
    }
  } else if (m_kind == UNARY) {
    switch (m_oper) {
      case ABS: {
        return abs (m_left->eval_int());
      } case FLOOR: {
        return floor (m_left->eval_int());
      } case SQRT: {
        return sqrt (m_left->eval_int());
      } case MINUS: {
        return -(m_left->eval_int());
        break;
      }
    }
  }
  
  /*
    what type of node are we - int, double, string, var, unary, binary
      -make type for this - assert for that
      int return
      variable return get int
      binary evaluate left and right
      unary evaluate 
    switch on m_oper
      case PLUS
        int left_value = m_left->eval_int()
        int right_value = m_right->eval_int()
        return left_val + right_val;
      case greater_than
        check to see what type
        int left_value = m_left->eval_string()
        int right_value = m_right->eval_string() 
        return left_vale > right_val


     eval_string() {
       if (m_type == INT) {
         int v = eval_int();
         use to string or sprintf
       }
     }
  */
  assert(m_type == INT);
  assert(false && "WRITE THIS FUNCTION");
  return INT_MIN;
}

double Expression::eval_double() {
  if (m_type == INT) {
    return eval_int();
  }
  if (m_kind == CONSTANT) {
    assert(m_type == DOUBLE);
    return m_double;
  } else if (m_kind == VARIABLE) {
    return m_variable->get_double_value();
  } else if (m_kind == BINARY) {
    switch (m_oper) {
      case MULTIPLY: {
        return m_left->eval_double() * m_right->eval_double();
        break;
      }
      case PLUS: {
        return m_left->eval_double() + m_right->eval_double();
        break;
      }
      default:
        assert(false && "Finish this shit cracker");
    }
  } else if (m_kind == UNARY) {
    switch (m_oper) {
      case MINUS: {
        return -(m_left->eval_double());
        break;
      } case SIN: {
        return sin (m_left->eval_double()*M_PI/180);
        break;
      } case COS: {
        return cos (m_left->eval_double()*M_PI/180);
        break;
      } case TAN: {
        return tan (m_left->eval_double()*M_PI/180);
        break;
      } case ASIN: {
        return asin (m_left->eval_double()) * 180 / M_PI;
        break;
      } case ACOS: {
        return acos (m_left->eval_double()) * 180 / M_PI;
        break;
      } case ATAN: {
        return atan (m_left->eval_double()) * 180 / M_PI;
        break;
      } case SQRT: {
        return sqrt (m_left->eval_double());
        break;
      } case ABS: {
        return abs (m_left->eval_double());
        break;
      } case FLOOR: {
        return floor (m_left->eval_double());
        break;
      } default:
        return INT_MIN;
        //assert(false && "Finish this shit cracker");
    }
  }
 assert(false && "WRITE THIS FUNCTION");
  return INT_MIN;
}

string Expression::eval_string() {
  if (m_kind == CONSTANT) {
    assert(m_type == STRING);
    return m_string;
  } else if (m_kind == VARIABLE) {
    return m_variable->get_string_value();
  } else if (m_kind == BINARY) {
    switch (m_oper) {
      case PLUS: {
        return m_left->eval_string() + m_right->eval_string();
        break;
      }
      default:
        assert(false && "Finish this shit cracker");
    }
  }
 
  
  return "";
  assert(false && "WRITE THIS FUNCTION");
}


