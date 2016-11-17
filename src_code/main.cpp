#include "RobotPart.h"
#include "RobotModel.h"
#include "TrackingParts.h"
#include "Torso.h"
#include "Head.h"
#include "Arm.h"
#include "Locomotor.h"
#include "Battery.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

using namespace std;

void create_torsoCB(Fl_Widget* w, void* p);
void cancel_torsoCB(Fl_Widget* w, void* p);
class Torso_Dialog;
class Torso_Output;

class Torso_Dialog {
	public:
 	Torso_Dialog() { // Create and populate the dialog (but don't show it!)
 		dialog = new Fl_Window(340, 300, "Robot Part");

 		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
 		rp_name->align(FL_ALIGN_LEFT);

 		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
 		rp_part_number->align(FL_ALIGN_LEFT);

 		rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
 		rp_type->align(FL_ALIGN_LEFT);

 		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
 		rp_weight->align(FL_ALIGN_LEFT);

 		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
 		rp_cost->align(FL_ALIGN_LEFT);

 		rp_batteryComp = new Fl_Input(120, 160, 210, 25, "Battery Comp #:");
 		rp_batteryComp->align(FL_ALIGN_LEFT);

 		rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
 		rp_description->align(FL_ALIGN_LEFT);

 		rp_create = new Fl_Return_Button(145, 280, 120, 25, "Create");
 		rp_create->callback((Fl_Callback *)create_torsoCB, 0);

 		rp_cancel = new Fl_Button(270, 280, 60, 25, "Cancel");
 		rp_cancel->callback((Fl_Callback *)cancel_torsoCB, 0);
 		dialog->end();
 		dialog->set_non_modal();
    }

	void show() {dialog->show();}
 	void hide() {dialog->hide();}
 	string name() {return rp_name->value();}
 	string part_number() {return rp_part_number->value();}
 	string type() {return rp_type->value();}
 	string weight() {return rp_weight->value();}
 	string cost() {return rp_cost->value();}
 	string description() {return rp_description->value();}
 	string batteryComp() {return rp_batteryComp->value();}

 	private:
 	Fl_Window *dialog;
 	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
 	Fl_Input *rp_type;
 	Fl_Input *rp_weight;
 	Fl_Input *rp_cost;
 	Fl_Input *rp_description;
 	Fl_Input *rp_batteryComp;
 	Fl_Return_Button *rp_create;
 	Fl_Button *rp_cancel;
};

Fl_Window *win;
Fl_Menu_Bar *menubar;
Fl_Window *dialog;
Torso_Dialog *torso_dlg; // The dialog of interest!
Torso_Output *torso_output_dlg;
vector<Torso> torso;

void CB(Fl_Widget* w, void* p) { } // No action

void menu_create_torsoCB(Fl_Widget* w, void* p) {
 	torso_dlg->show();
}

Torso createTorso () {
	std::string oname = torso_dlg->name();
	int opartNumber = atoi(torso_dlg->part_number().c_str());
	double oweight = atof(torso_dlg->weight().c_str());
	double ocost = atof(torso_dlg->cost().c_str());
	std::string odescription = torso_dlg->description();
	int opartType = atoi(torso_dlg->type().c_str());
	int oBatteryCompartments = atoi(torso_dlg->batteryComp().c_str());

	return Torso(oname, opartNumber, oweight, ocost, odescription, opartType, oBatteryCompartments);
}

void create_torsoCB(Fl_Widget* w, void* p) { // Replace with call to model!
 	cout << "### Creating robot part" << endl;
 	cout << "Name : " << torso_dlg->name() << endl;
 	cout << "Part # : " << torso_dlg->part_number() << endl;
 	cout << "Type : " << torso_dlg->type() << endl;
 	cout << "Weight : " << torso_dlg->weight() << endl;
 	cout << "Cost : " << torso_dlg->cost() << endl;
 	cout << "Battery Compartments: " << torso_dlg->batteryComp() << endl;
 	cout << "Descript: " << torso_dlg->description() << endl;

 	torso.push_back(createTorso());

 	torso_dlg->hide();
}

void cancel_torsoCB(Fl_Widget* w, void* p) {
 	torso_dlg->hide();
}

void closeCB(Fl_Widget *w, void* p)
{
	Fl_Window *win = (Fl_Window *)w;

	if (fl_choice("Unsaved file, exit anyway", fl_no, fl_yes, 0) == 1)
	{
		win->hide();
	}
}

/*class Torso_Output {
	public:
		Torso_Output () {
		dialog = new Fl_Window(340, 300, "Robot Part");

		output = new Fl_Multiline_Output(100, 10, 400, 100, "Torso list:");
		output->value(torso[0].print().c_str());

		 dialog->end();
 		dialog->set_non_modal();
	}
	private:
		Fl_Multiline_Output * output;
}; */

void torsoOPCB(Fl_Widget* w, void* p) {
	dialog = new Fl_Window(340, 300, "Robot Part");

	Fl_Multiline_Output* output = new Fl_Multiline_Output(100, 10, 400, 100, "Torso list:");
	output->value(torso[0].print().c_str());
	dialog->end();
 	dialog->set_non_modal();
 	dialog->show();
}

void torsoCB(Fl_Widget *w, void* p)
{}

void headCB(Fl_Widget *w, void* p)
{}

void armCB(Fl_Widget *w, void* p)
{}

void locomotorCB(Fl_Widget *w, void* p)
{}

void batteryCB(Fl_Widget *w, void* p)
{}

void newCB(Fl_Widget *w, void* p)
{}

void openCB(Fl_Widget *w, void* p)
{}

void saveCB(Fl_Widget *w, void* p)
{}

void orderCB(Fl_Widget *w, void* p)
{}

void saleCB(Fl_Widget *w, void* p)
{}

void customerCB(Fl_Widget *w, void* p)
{}

void robotModelCB(Fl_Widget *w, void* p)
{}

void robotCompCB(Fl_Widget *w, void* p)
{}

Fl_Menu_Item menuitems[] = {
	{"&File", 0,0,0,FL_SUBMENU},
	{"&New", FL_ALT + 'n', (Fl_Callback*)newCB},
	{ "&Open", FL_ALT + 'o', (Fl_Callback*)openCB },
	{ "&Save", FL_ALT + 's', (Fl_Callback*)saveCB },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback*)closeCB },
	{0},
	{"&Edit",0,0,0, FL_SUBMENU},
	{0},
	{"&Create",0,0,0,FL_SUBMENU},
		{"&Order",0,(Fl_Callback*)orderCB},
		{ "&Customer",0,(Fl_Callback*)customerCB },
		{ "&Sale Associate",0,(Fl_Callback*)saleCB },
		{ "&Robot Model",0,(Fl_Callback*)robotModelCB },
		{ "&Robot Component",0,0,0, FL_SUBMENU},
			{"&Torso",0, (Fl_Callback *)menu_create_torsoCB},
			{ "&Head",0, (Fl_Callback*)headCB },
			{ "&Arm",0, (Fl_Callback*)armCB },
			{ "&Locomotor",0, (Fl_Callback*)locomotorCB },
			{ "&Battery",0, (Fl_Callback*)batteryCB },
			{0},
			{0},
	{"&Report", 0,0,0,FL_SUBMENU},
	{"&Order",0,(Fl_Callback*)orderCB},
	{ "&Customer",0,(Fl_Callback*)customerCB },
	{ "&Sale Associate",0,(Fl_Callback*)saleCB },
	{ "&Robot Model",0,(Fl_Callback*)robotModelCB },
	{ "&Robot Component",0,(Fl_Callback*)torsoOPCB},
	 /*{ "&File", 0, 0, 0, FL_SUBMENU },
 { "&New", FL_ALT + 'n', (Fl_Callback *)CB },
 { "&Open", FL_ALT + 'o', (Fl_Callback *)CB },
 { "&Save", FL_ALT + 's', (Fl_Callback *)CB },
 { "Save As", FL_ALT + 'S', (Fl_Callback *)CB },
 { "&Quit", FL_ALT + 'q', (Fl_Callback *)CB },
 { 0 },
 { "&Edit", 0, 0, 0, FL_SUBMENU },
 { "&Undo", 0, (Fl_Callback *)CB },
 { "Cu&t", 0, (Fl_Callback *)CB },
 { "&Copy", 0, (Fl_Callback *)CB },
 { "&Paste", 0, (Fl_Callback *)CB },
 { 0 },
 { "&Create", 0, 0, 0, FL_SUBMENU },
 { "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
 { "Customer", 0, (Fl_Callback *)CB },
 { "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
 { "Robot Part", 0, (Fl_Callback *)menu_create_torsoCB },
 { "Robot Model", 0, (Fl_Callback *)CB },*/
	{0},
	{0}
};

int main () {

	/*vector<RobotModel> rbmodel;
	vector<TrackingParts> tp;
	vector<Customer> cus;
	vector<RobotOrder> order;

	vector<Torso> torso;
	vector<Head> head;
	vector<Arm>	arm;
	vector<Locomotor> loco;
	vector<Battery> batt; */

	// Create dialogs
 	torso_dlg = new Torso_Dialog{};
 	//torso_output_dlg = new Torso_Output{};

	win = new Fl_Window(640, 480, "Robot Robbie Shop");

	menubar = new Fl_Menu_Bar(0, 0, 640, 30);
	menubar->menu(menuitems);

	win->callback(closeCB);

	win->end();
	win->show();
	return(Fl::run());
	
	return 0;
}