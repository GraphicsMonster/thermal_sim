#include "thermal_simApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
thermal_simApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

thermal_simApp::thermal_simApp(InputParameters parameters) : MooseApp(parameters)
{
  thermal_simApp::registerAll(_factory, _action_factory, _syntax);
}

thermal_simApp::~thermal_simApp() {}

void 
thermal_simApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<thermal_simApp>(f, af, s);
  Registry::registerObjectsTo(f, {"thermal_simApp"});
  Registry::registerActionsTo(af, {"thermal_simApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
thermal_simApp::registerApps()
{
  registerApp(thermal_simApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
thermal_simApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  thermal_simApp::registerAll(f, af, s);
}
extern "C" void
thermal_simApp__registerApps()
{
  thermal_simApp::registerApps();
}
