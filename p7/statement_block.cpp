// updated 2/14/16

#include "statement_block.h"
#include "gpl_assert.h"
using namespace std;


Statement_block::Statement_block()
{

}

void Statement_block::insert(Statement* statement) {
  m_statements.push_back(statement);
}

void Statement_block::execute()
{
  int size = m_statements.size();
  for(int i = 0; i < size; i++) {
    m_statements[i]->execute();
  }
}
