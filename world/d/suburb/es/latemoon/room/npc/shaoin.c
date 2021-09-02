inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("龙韶吟", ({ "shaoin","shao" }) );
        set("title", "晚月庄第三代弟子");
        set("gender", "女性" );
        set("age",17);
        set("long", @TEXT
TEXT
);
       set("class", "dancer");
        set("combat_exp", 20000);
        set_skill("unarmed", 70);
        set_skill("dodge", 50);
        set_skill("stormdance", 50);
         set_skill("tenderzhi", 50);
         map_skill("dodge","stormdance");
         map_skill("unarmed","tenderzhi");
        set_skill("force",100);
        set("force", 900);
        set("max_force",450);
        set("force_factor", 5);
        set_temp("apply/armor", 70);
        setup();
}
void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
     if ((string)ob->query("gender") == "男性" ) {
          say( HIY "韶吟惊慌生气的怒斥： 喂! 兄台不要乱闯! \n" NOR);
           say( HIM "她的眼神骤变，隐约中似乎让人神智渐模糊! \n" NOR);
          ob->receive_damage("sen", 20);
          ob->apply_condition("rose_poison", 2);
       this_object()->add("force", 50);
          command("close door");
          return;
    }
       command("close door");
       return;
}

int hit_ob(object ob1, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("rose_poison") < 20 ) {
                ob->apply_condition("rose_poison", 10);
                tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
        }
}
