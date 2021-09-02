// poison_dust.c

inherit COMBINED_ITEM;

void create()
{

	set_name("蒙汗药", ({ "menghan yao", "yao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是极普通的蒙汗药\n" );
		set("unit", "包");
		set("base_value", 700);
		set("base_unit", "