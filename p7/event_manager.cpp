// updated 2/14/2016

#include "event_manager.h"
#include "gpl_assert.h"
using namespace std;

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

Event_manager::insert(Window::Keystroke keystroke, Statement_block*) {
  m_events[keystroke].push_back(statement_block);
}

void Event_manager::execute_handlers(Window::Keystroke keystroke)
{
/*
  switch(keystroke) {
    case SPACE: {
    } case LEFTARROW: {
    } case RIGHTARROW: {
    } case UPARROW: {
    } case DOWNARROW: {
    } case LEFTMOUSE_DOWN: {
    } case MIDDLEMOUSE_DOWN: {
    } case RIGHTMOUSE_DOWN: {
    } case LEFTMOUSE_UP: {
    } case MIDDLEMOUSE_UP: {
        RIGHTMOUSE_UP = 10,
        MOUSE_MOVE = 11,
        MOUSE_DRAG = 12,
        F1 = 13,
        AKEY = 14,
        SKEY = 15,
        DKEY = 16,
        FKEY = 17,
        HKEY = 18,
        JKEY = 19,
        KKEY = 20,
        LKEY = 21,
        WKEY = 22,
        INITIALIZE = 23,
        NUMBER_OF_KEYS = 24 // UPDATE to one more than last one if adding a key!!!  case 
  } 
  */
}
