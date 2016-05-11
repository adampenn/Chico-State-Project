#include "symbol.h"

Symbol::Symbol(string name, Animation_block* animation_block) {
  m_name = name;
  m_type = ANIMATION_BLOCK;
  m_size = UNDEFINED_INDEX;
  m_value = (void *)animation_block;
}

Symbol::Symbol(string name, Gpl_type type, Game_object* game_object) {
  m_name = name;
  m_type = type;
  m_size = UNDEFINED_SIZE;
  m_value = (void *)game_object;
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
    switch (type) {
      case CIRCLE_ARRAY: {
        Circle** game;
        game = new Circle*[size];
        for (int i = 0; i < size; i++) {
          game[i] = new Circle();
        }
        m_value = (void *)game;
        break;
      } case TRIANGLE_ARRAY: {
        Triangle** game;
        game = new Triangle*[size];
        for (int i = 0; i < size; i++) {
          game[i] = new Triangle();
        }
        m_value = (void *)game;
        break;
      } case PIXMAP_ARRAY: {
        Pixmap** game;
        game = new Pixmap*[size];
        for (int i = 0; i < size; i++) {
          game[i] = new Pixmap();
        }
        m_value = (void *)game;
        break;
      } case RECTANGLE_ARRAY: {
        Rectangle** game;
        game = new Rectangle*[size];
        for (int i = 0; i < size; i++) {
          game[i] = new Rectangle();
        }
        m_value = (void *)game;
        break;
      } case TEXTBOX_ARRAY: {
        Textbox** game;
        game = new Textbox*[size];
        for (int i = 0; i < size; i++) {
          game[i] = new Textbox();
        }
        m_value = (void *)game;
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
}

Symbol::Symbol(string name, double value){
  m_name = name;
  m_type = DOUBLE;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new double(value);
}

Symbol::Symbol(string name, string value){
  m_name = name;
  m_type = STRING;
  m_size = UNDEFINED_SIZE;
  m_value = (void *) new string(value);
}

Gpl_type Symbol::get_type(){
  return m_type;
}

string Symbol::get_name() const {
  return m_name;
}

int Symbol::get_size() const {
  return m_size;
}

Gpl_type Symbol::get_base_game_object_type() const {
  if (m_type == CIRCLE || m_type == CIRCLE_ARRAY) {
    return CIRCLE;
  } else if (m_type == RECTANGLE || m_type == RECTANGLE_ARRAY) {
    return RECTANGLE;
  } else if (m_type == TRIANGLE || m_type == TRIANGLE_ARRAY) {
    return TRIANGLE;
  } else if (m_type == TEXTBOX || m_type == TEXTBOX_ARRAY) {
    return TEXTBOX;
  } else if (m_type == PIXMAP || m_type == PIXMAP_ARRAY) {
    return PIXMAP;
  }
  assert(false && "No type declared");
  return INT;
}

Gpl_type Symbol::get_base_type(){
  if (m_type == INT || m_type == INT_ARRAY) {
    return INT;
  } else if (m_type == DOUBLE || m_type == DOUBLE_ARRAY) {
    return DOUBLE;
  } else if (m_type == STRING || m_type == STRING_ARRAY) {
    return STRING;
  } else if (m_type & GAME_OBJECT || m_type & GAME_OBJECT_ARRAY) {
    return GAME_OBJECT;
  } else if (m_type == ANIMATION_BLOCK) {
    return ANIMATION_BLOCK;
  }
  assert(false && "No type declared");
  return INT;
}

void Symbol::set(int value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    *((int *) m_value) = value;
  } else {
    assert(m_type == INT_ARRAY);
    if (index >= m_size || index < 0) {
      index = 0;
    }
    ((int *)m_value)[index] = value;
  }
}

void Symbol::set(double value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == DOUBLE);
    *((double *) m_value) = value;
  } else {
    assert(m_type == DOUBLE_ARRAY);
    if (index >= m_size || index < 0) {
      index = 0;
    }
    ((double *)m_value)[index] = value;
  }
}

void Symbol::set(string value, int index) {
  if (index == UNDEFINED_INDEX) {
    assert(m_type == STRING);
    *((string *) m_value) = value;
  } else {
    assert(m_type == STRING_ARRAY);
    if (index >= m_size || index < 0) {
      index = 0;
    }
    ((string *)m_value)[index] = value;
  }
}

void Symbol::set_game_object(Game_object* game_object) {
  m_value = (void *)game_object;
}

int Symbol::get_int_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    assert(m_type == INT);
    return *((int *) m_value);
  } else {
    assert(m_type == INT_ARRAY);
    if (index > m_size || index < 0) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return ((int *)m_value)[0];
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
    if (index > m_size || index < 0) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return ((double *)m_value)[0];
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
    if (index > m_size || index < 0) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return ((string *)m_value)[0];
    } else {
      assert(m_type == STRING_ARRAY);
      return ((string *)m_value)[index];
    }
  }  
}

Game_object *Symbol::get_game_object_value(int index) const{
  if (index == UNDEFINED_INDEX) {
    return (Game_object *) m_value;
  } else {
    if (index > m_size || index < 0) {
      stringstream ss;
      ss << index;
	    Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, m_name, ss.str());
      return ((Game_object**)m_value)[0];
    } else {
      assert(m_type & GAME_OBJECT_ARRAY);
      return ((Game_object**)m_value)[index];
    }
  }
}

Animation_block* Symbol::get_animation_block_value() const{
  return (Animation_block *) m_value;
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
  } else if (m_type & ARRAY && m_type & GAME_OBJECT) {
    for (int i = 0; i < m_size; i++) {
      stringstream ss;
      ss << m_name << "[" << i << "]";
      ((Game_object **)m_value)[i]->print(ss.str(), os);
    }
  } else if (m_type & GAME_OBJECT) {
    ((Game_object *)m_value)->print(m_name, os);
  } else if (m_type == ANIMATION_BLOCK) {
    os << "animation_block " << m_name << endl;
  } else {
    assert(false && "Not defined in print statement");
  }
}

