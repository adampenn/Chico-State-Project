#include "symbol_table.h"

/*static*/ Symbol_table *Symbol_table::m_instance = NULL;

Symbol_table::Symbol_table(){
  
}

/*static*/ Symbol_table* Symbol_table::instance() {
  if (m_instance == NULL)
    m_instance = new Symbol_table();
  return m_instance;
}

void Symbol_table::insert(string name, Symbol* symbol){
  mymap[name] = symbol;
}

Symbol* Symbol_table::lookup(string name){
  unordered_map<string,Symbol*>::const_iterator found = mymap.find (name);
  if ( found == mymap.end() )
    return NULL;
  else
    return found->second;
}

void Symbol_table::print(ostream &os){
  
}

