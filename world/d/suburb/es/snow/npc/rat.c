// fly.c

inherit NPC;

void create()
{
        set_name("老鼠", ({ "rat" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只贼头贼脑的大老鼠。\n");

        set("limbs", ({ "头部", "身体"}) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 120);

        setup();
}
