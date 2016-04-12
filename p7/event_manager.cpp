// updated 2/14/2016

#include "event_manager.h"
#include "gpl_assert.h"

/* static */ Event_manager *Event_manager::m_instance = 0;

/* static */ Event_manager * Event_manager::instance()
{
  if (!m_instance)
    m_instance = new Event_manager();
  return m_instance;
}

Event_manager::Event_manager()
{
}

Event_manager::~Event_manager()
{
}

void Event_manager::insert(int key, Statement_block* statement_block) {
  m_events[key].push_back(statement_block);
}

void Event_manager::execute_handlers(Window::Keystroke keystroke)
{
  int size = m_events[keystroke].size();
  for (int i = 0; i < size; i++) {
    m_events[keystroke][i]->execute();
  }
}
