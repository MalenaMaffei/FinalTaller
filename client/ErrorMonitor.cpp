#include <iostream>
#include <string>
#include "common_str_constants.h"
#include "server_ErrorMonitor.h"
using std::cerr;
using std::endl;

void ErrorMonitor::outputError(string error) {
  //    CRITICAL SECTION
  std::lock_guard<std::mutex> lock(m);
  cerr << error << endl;
}

void ErrorMonitor::outputCommand(string user, string command) {
  string command_name;
  if (command == codLm){
    command_name = listarMaterias;
  } else if (command == codLi){
    command_name = listarInscripciones;
  } else if (command == codIn){
    command_name = inscribir;
  } else if (command == codDe){
    command_name = desinscribir;
  }
  outputError(user + " ejecuta " + command_name + ".");
}

ErrorMonitor::ErrorMonitor() {}
