#include "symbol.h"

Symbol::Symbol(string name, Animation_block* animation_block) {
  m_name = name;
  m_type = ANIMATION_BLOCK;
  m_size = UNDEFINED_INDEX;
  m_value = NULL;
  m_game_object = NULL;
  m_animation_block = animation_block;
}

Symbol::Symbol(string name, Gpl_type type, Game_object* game_object) {
  m_name = name;
  m_type = type;
  m_size = UNDEFINED_SIZE;
  m_value = NULL;
  m_game_object = game_object;
  m_animation_block = NULL;
}

Symbol::Symbol(string name, int size, Gpl_type type){
  m_name = name;
  m_type = type;
  m_size = size;
  if (type == INT_ARRAY) {
    m_value = new int[size];
    for (int i=0; i < m_size; i++) {
      ((int*)m_value)[i] = 0;
    }
  } else if (type == DOUBLE_ARRAY) {
    m_value = new double[size];
    for (int i=0; i < m_size; i++) {
      ((double*)m_value)[i] = 0.0;
    }
  } else if (type == STRING_ARRAY) {
    m_value = new string[size];
    for (int i=0; i < m_size; i++) {
      ((string*)m_value)[i] = "";
    }
  } else if (type & GAME_OBJECT_ARRAY) {
    m_value = NULL;
    switch (type) {
      case CIRCLE_ARRAY: {
        m_game_object = new Circle[size];
        break;
      } case TRIANGLE_ARRAY: {
        m_game_object = new Triangle[size];
        break;
      } case PIXMAP_ARRAY: {
        m_game_object = new Pixmap[size];
        break;
      } case RECTANGLE_ARRAY: {
        m_game_object = new Rectangle[size];
        break;
      } case TEXTBOX_ARRAY: {
        m_game_object = new Textbox[size];
        break;
      } default: {
        assert(false && "Error creating game object array");
      }
    }
  }
}
Symbol::Symbol(string name, int value){
  m_name = name;
  m_type = INT;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new int(value);
  m_game_object = NULL;
}

Symbol::Symbol(string name, double value){
  m_name = name;
  m_type = DOUBLE;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new double(value);
  m_game_object = NULL;
}

Symbol::Symbol(string name, string value){
  m_name = name;
  m_type = STRING;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new string(value);
  m_game_object = NULL;
}

Gpl_type Symbol::get_type(){
  return m_type;
}

string Symbol::get_name() const{
  return m_name;
}

Gpl_type Symbol::get_base_type(){
  if (m_type == INT || m_type == INT_ARRAY) {
    return INT;
  } else if (m_type == DOUBLE || m_type == DOUBLE_ARRAY) {
    return DOUBLE;
  } else if (m_type == STRING || m_type == STRING_ARRAY) {
    return STRING;
  }
  assert(false && "No type declared");
  return INT;
}

void Symbol::set(int value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    m_value = (void *) &value;
  } else {
    assert(m_type == INT_ARRAY);
    ((int *)m_value)[index] = value;
  }
}

void Symbol::set(double value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == DOUBLE);
    m_value = (void *) &value;
  } else {
    assert(m_type == DOUBLE_ARRAY);
    ((double *)m_value)[index] = value;
  }
}

void Symbol::set(string value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == STRING);
    m_value = (void *) &value;
  } else {
    assert(m_type == STRING_ARRAY);
    ((string *)m_value)[index] = value;
  }
}

int Symbol::get_int_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    return *((int *) m_value);
  } else {
    assert(m_type == INT_ARRAY);
    if (index > m_size) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return INT_MIN;
    } else {
      return ((int *)m_value)[index];
    }
  }
}

double Symbol::get_double_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == DOUBLE);
    return *((double *)m_value);
  } else {
    if (index > m_size) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return INT_MIN;
    } else {
      assert(m_type == DOUBLE_ARRAY);
      return ((double *)m_value)[index];
    }
  }
}

string Symbol::get_string_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == STRING);
    return *((string *)m_value);
  } else {
    if (index > m_size) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return "";
    } else {
      assert(m_type == STRING_ARRAY);
      return ((string *)m_value)[index];
    }
  }  
}

Game_object *Symbol::get_game_object_value() const{
  return m_game_object;
}

bool Symbol::is_game_object() {
  if (m_type & GAME_OBJECT) {
    return true; 
  }
  return false;
}

void Symbol::print(ostream &os) {
  if (m_type == INT) {
    os << "int " << m_name << " = " << *((int *) m_value) << endl;
  } else if (m_type == INT_ARRAY) {
    for (int i = 0; i < m_size; i++)
      os << "int " << m_name << "[" << i << "] = " << ((int *)m_value)[i] << endl;
  } else if (m_type == DOUBLE) {
    os << "double " << m_name << " = " << *((double *) m_value) << endl;
  } else if (m_type == DOUBLE_ARRAY) {
    for (int i = 0; i < m_size; i++)
      os << "double " << m_name << "[" << i << "] = " << ((double *)m_value)[i] << endl;
  } else if (m_type == STRING) {
    os << "string " << m_name << " = " << "\"" << *((string *) m_value) << "\"" << endl;
  } else if (m_type == STRING_ARRAY) {
    for (int i = 0; i < m_size; i++)
      os << "string " << m_name << "[" << i << "] = " << "\"" << ((string *)m_value)[i] << "\"" << endl;
  } else if (m_type & GAME_OBJECT) {
    m_game_object->print(m_name, os);
  } else if (m_type & GAME_OBJECT_ARRAY) {
    m_game_object->print(m_name, os);
  }
}

