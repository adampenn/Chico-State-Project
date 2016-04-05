#include "Event_manager.h"

/*static*/ Event_manager* Event_manager::m_instance = NULL;

Event_manager::Event_manager() {
}

/*static*/ Event_manager* instance() {
  if (m_instance == NULL) {
    m_instance = new Event_manager();
  }
  return m_instance;
}

void Event_manager::execute_handlers(Keystroke keystroke) {
  switch (keystroke) {
    case SPACE: {
      break;
    } case LEFTARROW: {
      break;
    } case RIGHTARROW: {
      break;
    } case UPARROW: {
      break;
    } case DOWNARROW: {
      break;
    } case LEFTMOUSE_DOWN: {
      break;
    } case MIDDLEMOUSE_DOWN: {
      break;
    } case RIGHTMOUSE_DOWN: {
      break;
    } case LEFTMOUSE_UP: {
      break;
    } case MIDDLEMOUSE_UP: {
      break;
    } case RIGHTMOUSE_UP: {
      break;
    } case MOUSE_MOVE: {
      break;
    } case MOUSE_DRAG: {
      break;
    } case F1: {
      break;
    } case AKEY: {
      break;
    } case SKEY: {
      break;
    } case DKEY: {
      break;
    } case FKEY: {
      break;
    } case HKEY: {
      break;
    } case JKEY: {
      break;
    } case KKEY: {
      break;
    } case LKEY: {
      break;
    } case WKEY: {
      break;
    } default: {
      assert(false && "Error should not be here");
      break;
    }
  }
}

