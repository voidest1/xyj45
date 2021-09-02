// blackthorn.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("苍绒剑", ({ "whitethorn sword", "whitethorn", "sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",
			"这是一把通体灰白的重剑，上面生满了尖锐的倒钩，乃是乔阴柳家\n"
			"历代相传的宝剑，据说这把剑杀人见血，永远不沾杀气。\n");
		set("value", 2400);
		set("material", "greysteel");
		set("wield_msg", "只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(63);
	setup();
}
