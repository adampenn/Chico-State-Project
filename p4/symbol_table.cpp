#include "symbol_tabel.h"

static Symbol_table *Symbol_table::m_instance = NULL;

Symbol_table::Symbol_table(){
  
}

static Symbol_table *Symbol_table::instance() {
  if (m_instance == NULL)
    m_instance = new Symbol_table();
  return m_instance;
}

Symbol *Symbol_table::lookup(string name){
  
}

void Symbol_table::print(ostream &os){
  
}

