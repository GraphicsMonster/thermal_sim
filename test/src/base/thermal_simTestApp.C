//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "thermal_simTestApp.h"
#include "thermal_simApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
thermal_simTestApp::validParams()
{
  InputParameters params = thermal_simApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

thermal_simTestApp::thermal_simTestApp(InputParameters parameters) : MooseApp(parameters)
{
  thermal_simTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

thermal_simTestApp::~thermal_simTestApp() {}

void
thermal_simTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  thermal_simApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"thermal_simTestApp"});
    Registry::registerActionsTo(af, {"thermal_simTestApp"});
  }
}

void
thermal_simTestApp::registerApps()
{
  registerApp(thermal_simApp);
  registerApp(thermal_simTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
thermal_simTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  thermal_simTestApp::registerAll(f, af, s);
}
extern "C" void
thermal_simTestApp__registerApps()
{
  thermal_simTestApp::registerApps();
}
