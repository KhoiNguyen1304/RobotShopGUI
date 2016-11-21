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
#include <sstream>

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
#include <FL/Fl_Text_Display.H>


using namespace std;

vector<Torso> torso;
vector<Head> head;
vector<Arm> arm;
vector<Locomotor> loco;
vector<Battery> batt;

void create_torsoCB(Fl_Widget* w, void* p);
void cancel_torsoCB(Fl_Widget* w, void* p);
void create_headCB(Fl_Widget* w, void* p);
void cancel_headCB(Fl_Widget* w, void* p);
void create_armCB(Fl_Widget* w, void* p);
void cancel_armCB(Fl_Widget* w, void* p);
void create_locoCB(Fl_Widget* w, void* p);
void cancel_locoCB(Fl_Widget* w, void* p);
void create_battCB(Fl_Widget* w, void* p);
void cancel_battCB(Fl_Widget* w, void* p);

class Torso_Dialog;
class Head_Dialog;
class Arm_Dialog;
class Loco_Dialog;
class Batt_Dialog;

class Torso_Dialog {
	public:
 	Torso_Dialog() { // Create and populate the dialog (but don't show it!)
 		dialog = new Fl_Window(340, 300, "Create Torso");

 		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
 		rp_name->align(FL_ALIGN_LEFT);

 		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
 		rp_part_number->align(FL_ALIGN_LEFT);

 		rp_type = new Fl_Input(120, 70, 210, 25, "Type (0):");
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

class Head_Dialog {
	public:
 	Head_Dialog() { // Create and populate the dialog (but don't show it!)
 		dialog = new Fl_Window(340, 300, "Create Head");

 		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
 		rp_name->align(FL_ALIGN_LEFT);

 		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
 		rp_part_number->align(FL_ALIGN_LEFT);

 		rp_type = new Fl_Input(120, 70, 210, 25, "Type (1):");
 		rp_type->align(FL_ALIGN_LEFT);

 		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
 		rp_weight->align(FL_ALIGN_LEFT);

 		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
 		rp_cost->align(FL_ALIGN_LEFT);

 		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
 		rp_description->align(FL_ALIGN_LEFT);

 		rp_create = new Fl_Return_Button(145, 280, 120, 25, "Create");
 		rp_create->callback((Fl_Callback *)create_headCB, 0);

 		rp_cancel = new Fl_Button(270, 280, 60, 25, "Cancel");
 		rp_cancel->callback((Fl_Callback *)cancel_headCB, 0);
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

 	private:
 	Fl_Window *dialog;
 	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
 	Fl_Input *rp_type;
 	Fl_Input *rp_weight;
 	Fl_Input *rp_cost;
 	Fl_Input *rp_description;
 	Fl_Return_Button *rp_create;
 	Fl_Button *rp_cancel;
};

class Arm_Dialog {
	public:
 	Arm_Dialog() { // Create and populate the dialog (but don't show it!)
 		dialog = new Fl_Window(340, 300, "Create Arm");

 		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
 		rp_name->align(FL_ALIGN_LEFT);

 		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
 		rp_part_number->align(FL_ALIGN_LEFT);

 		rp_type = new Fl_Input(120, 70, 210, 25, "Type (2):");
 		rp_type->align(FL_ALIGN_LEFT);

 		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
 		rp_weight->align(FL_ALIGN_LEFT);

 		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
 		rp_cost->align(FL_ALIGN_LEFT);

 		rp_power = new Fl_Input(120, 160, 210, 25, "Power Consume:");
 		rp_power->align(FL_ALIGN_LEFT);

 		rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
 		rp_description->align(FL_ALIGN_LEFT);

 		rp_create = new Fl_Return_Button(145, 280, 120, 25, "Create");
 		rp_create->callback((Fl_Callback *)create_armCB, 0);

 		rp_cancel = new Fl_Button(270, 280, 60, 25, "Cancel");
 		rp_cancel->callback((Fl_Callback *)cancel_armCB, 0);
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
 	string power() {return rp_power->value();}

 	private:
 	Fl_Window *dialog;
 	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
 	Fl_Input *rp_type;
 	Fl_Input *rp_weight;
 	Fl_Input *rp_cost;
 	Fl_Input *rp_description;
 	Fl_Input *rp_power;
 	Fl_Return_Button *rp_create;
 	Fl_Button *rp_cancel;
};

class Loco_Dialog {
	public:
 	Loco_Dialog() { // Create and populate the dialog (but don't show it!)
 		dialog = new Fl_Window(340, 350, "Create Locomotor");

 		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
 		rp_name->align(FL_ALIGN_LEFT);

 		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
 		rp_part_number->align(FL_ALIGN_LEFT);

 		rp_type = new Fl_Input(120, 70, 210, 25, "Type (3):");
 		rp_type->align(FL_ALIGN_LEFT);

 		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
 		rp_weight->align(FL_ALIGN_LEFT);

 		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
 		rp_cost->align(FL_ALIGN_LEFT);

 		rp_power = new Fl_Input(120, 160, 210, 25, "Power Consume:");
 		rp_power->align(FL_ALIGN_LEFT);

 		rp_speed = new Fl_Input(120, 190, 210, 25, "Max speed:");
 		rp_speed->align(FL_ALIGN_LEFT);

 		rp_description = new Fl_Multiline_Input(120, 220, 210, 75, "Description:");
 		rp_description->align(FL_ALIGN_LEFT);

 		rp_create = new Fl_Return_Button(145, 310, 120, 25, "Create");
 		rp_create->callback((Fl_Callback *)create_locoCB, 0);

 		rp_cancel = new Fl_Button(270, 310, 60, 25, "Cancel");
 		rp_cancel->callback((Fl_Callback *)cancel_locoCB, 0);
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
 	string power() {return rp_power->value();}
 	string speed() {return rp_speed->value();}

 	private:
 	Fl_Window *dialog;
 	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
 	Fl_Input *rp_type;
 	Fl_Input *rp_weight;
 	Fl_Input *rp_cost;
 	Fl_Input *rp_description;
 	Fl_Input *rp_power;
 	Fl_Input *rp_speed;
 	Fl_Return_Button *rp_create;
 	Fl_Button *rp_cancel;
};

class Batt_Dialog {
	public:
 	Batt_Dialog() { // Create and populate the dialog (but don't show it!)
 		dialog = new Fl_Window(340, 300, "Create Battery");

 		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
 		rp_name->align(FL_ALIGN_LEFT);

 		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
 		rp_part_number->align(FL_ALIGN_LEFT);

 		rp_type = new Fl_Input(120, 70, 210, 25, "Type (4):");
 		rp_type->align(FL_ALIGN_LEFT);

 		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
 		rp_weight->align(FL_ALIGN_LEFT);

 		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
 		rp_cost->align(FL_ALIGN_LEFT);

 		rp_kilowatt = new Fl_Input(120, 160, 210, 25, "KiloWatt/hour:");
 		rp_kilowatt->align(FL_ALIGN_LEFT);

 		rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
 		rp_description->align(FL_ALIGN_LEFT);

 		rp_create = new Fl_Return_Button(145, 280, 120, 25, "Create");
 		rp_create->callback((Fl_Callback *)create_battCB, 0);

 		rp_cancel = new Fl_Button(270, 280, 60, 25, "Cancel");
 		rp_cancel->callback((Fl_Callback *)cancel_battCB, 0);
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
 	string kilowatt() {return rp_kilowatt->value();}

 	private:
 	Fl_Window *dialog;
 	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
 	Fl_Input *rp_type;
 	Fl_Input *rp_weight;
 	Fl_Input *rp_cost;
 	Fl_Input *rp_description;
 	Fl_Input *rp_kilowatt;
 	Fl_Return_Button *rp_create;
 	Fl_Button *rp_cancel;
};




Fl_Window *win;
Fl_Menu_Bar *menubar;
Fl_Window *dialog;
Torso_Dialog *torso_dlg;
Head_Dialog *head_dlg;
Arm_Dialog *arm_dlg;
Loco_Dialog *loco_dlg;
Batt_Dialog *batt_dlg;

void CB(Fl_Widget* w, void* p) { } // No action

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

void menu_create_torsoCB(Fl_Widget* w, void* p) {
 	torso_dlg->show();
}

void create_torsoCB(Fl_Widget* w, void* p) { // Replace with call to model!
 	torso.push_back(createTorso());
 	torso_dlg->hide();
}

void cancel_torsoCB(Fl_Widget* w, void* p) {
 	torso_dlg->hide();
}

Head createHead () {
	std::string oname = head_dlg->name();
	int opartNumber = atoi(head_dlg->part_number().c_str());
	double oweight = atof(head_dlg->weight().c_str());
	double ocost = atof(head_dlg->cost().c_str());
	std::string odescription = head_dlg->description();
	int opartType = atoi(head_dlg->type().c_str());
	return Head(oname, opartNumber, oweight, ocost, odescription, opartType);
}

void menu_create_headCB(Fl_Widget* w, void* p) {
 	head_dlg->show();
}

void create_headCB(Fl_Widget* w, void* p) {
	head.push_back(createHead());
	head_dlg->hide();
}

void cancel_headCB(Fl_Widget* w, void* p) {
	head_dlg->hide();
}

Arm createArm () {
	std::string oname = arm_dlg->name();
	int opartNumber = atoi(arm_dlg->part_number().c_str());
	double oweight = atof(arm_dlg->weight().c_str());
	double ocost = atof(arm_dlg->cost().c_str());
	std::string odescription = arm_dlg->description();
	int opartType = atoi(arm_dlg->type().c_str());
	double opower = atof(arm_dlg->power().c_str());

	return Arm(oname, opartNumber, oweight, ocost, odescription, opartType, opower);
}

void menu_create_armCB(Fl_Widget* w, void* p) {
 	arm_dlg->show();
}

void create_armCB(Fl_Widget* w, void* p) { // Replace with call to model!
 	arm.push_back(createArm());
 	arm_dlg->hide();
}

void cancel_armCB(Fl_Widget* w, void* p) {
 	arm_dlg->hide();
}

Locomotor createLoco () {
	std::string oname = loco_dlg->name();
	int opartNumber = atoi(loco_dlg->part_number().c_str());
	double oweight = atof(loco_dlg->weight().c_str());
	double ocost = atof(loco_dlg->cost().c_str());
	std::string odescription = loco_dlg->description();
	int opartType = atoi(loco_dlg->type().c_str());
	double opower = atof(loco_dlg->power().c_str());
	double ospeed = atof(loco_dlg->speed().c_str());

	return Locomotor(oname, opartNumber, oweight, ocost, odescription, opartType, opower, ospeed);
}

void menu_create_locoCB(Fl_Widget* w, void* p) {
 	loco_dlg->show();
}

void create_locoCB(Fl_Widget* w, void* p) { // Replace with call to model!
 	loco.push_back(createLoco());
 	loco_dlg->hide();
}

void cancel_locoCB(Fl_Widget* w, void* p) {
 	loco_dlg->hide();
}

Battery createBatt () {
	std::string oname = batt_dlg->name();
	int opartNumber = atoi(batt_dlg->part_number().c_str());
	double oweight = atof(batt_dlg->weight().c_str());
	double ocost = atof(batt_dlg->cost().c_str());
	std::string odescription = batt_dlg->description();
	int opartType = atoi(batt_dlg->type().c_str());
	double okilowatt = atof(batt_dlg->kilowatt().c_str());

	return Battery(oname, opartNumber, oweight, ocost, odescription, opartType, okilowatt);
}

void menu_create_battCB(Fl_Widget* w, void* p) {
 	batt_dlg->show();
}

void create_battCB(Fl_Widget* w, void* p) { // Replace with call to model!
 	batt.push_back(createBatt());
 	batt_dlg->hide();
}

void cancel_battCB(Fl_Widget* w, void* p) {
 	batt_dlg->hide();
}

void closeCB(Fl_Widget *w, void* p)
{
	Fl_Window *win = (Fl_Window *)w;

	if (fl_choice("Unsaved file, exit anyway", fl_no, fl_yes, 0) == 1)
	{
		win->hide();
	}
}

void report_partsCB(Fl_Widget *w, void* p) {

	std::ostringstream oss_torso, oss_head, oss_arm, oss_loco, oss_batt;

	dialog = new Fl_Window(640, 340, "Robot Part");

	Fl_Multiline_Output* output_torso = new Fl_Multiline_Output(100, 10, 200, 100, "Torso list:");
	for(std::size_t i=0; i < torso.size();i++) {

		oss_torso << torso[i].print() << endl;
	}
	output_torso->value(oss_torso.str().c_str());

	Fl_Multiline_Output* output_head = new Fl_Multiline_Output(100, 120, 200, 100, "Head list:");
	for(std::size_t i=0; i < head.size();i++) {

		oss_head << head[i].print() << endl;
	}
	output_head->value(oss_head.str().c_str());

	Fl_Multiline_Output* output_arm = new Fl_Multiline_Output(400, 10, 200, 100, "Arm list:");
	for(std::size_t i=0; i < arm.size();i++) {

		oss_arm << arm[i].print() << endl;
	}
	output_arm->value(oss_arm.str().c_str());

	Fl_Multiline_Output* output_loco = new Fl_Multiline_Output(400, 120, 200, 100, "Loco list:");
	for(std::size_t i=0; i < loco.size();i++) {

		oss_loco << loco[i].print() << endl;
	}
	output_loco->value(oss_loco.str().c_str());

	Fl_Multiline_Output* output_batt = new Fl_Multiline_Output(250, 230, 200, 100, "Battery list:");
	for(std::size_t i=0; i < batt.size();i++) {

		oss_batt << batt[i].print() << endl;
	}
	output_batt->value(oss_batt.str().c_str());

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
			{ "&Head",0, (Fl_Callback*)menu_create_headCB },
			{ "&Arm",0, (Fl_Callback*)menu_create_armCB },
			{ "&Locomotor",0, (Fl_Callback*)menu_create_locoCB },
			{ "&Battery",0, (Fl_Callback*)menu_create_battCB },
			{0},
			{0},
	{"&Report", 0,0,0,FL_SUBMENU},
	{"&Order",0,(Fl_Callback*)orderCB},
	{ "&Customer",0,(Fl_Callback*)customerCB },
	{ "&Sale Associate",0,(Fl_Callback*)saleCB },
	{ "&Robot Model",0,(Fl_Callback*)robotModelCB },
	{ "&Robot Component",0,(Fl_Callback*)report_partsCB},
	{0},
	{0}
};

int main () {
	
	// Create dialogs
 	torso_dlg = new Torso_Dialog{};
 	head_dlg = new Head_Dialog{};
 	arm_dlg = new Arm_Dialog{};
 	loco_dlg = new Loco_Dialog{};
 	batt_dlg = new Batt_Dialog{};

	win = new Fl_Window(640, 480, "Robot Robbie Shop");

	menubar = new Fl_Menu_Bar(0, 0, 640, 30);
	menubar->menu(menuitems);

	win->callback(closeCB);

	win->end();
	win->show();
	return(Fl::run());
}