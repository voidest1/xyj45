inherit NPC;
 
void create()
{
        set_name("娟姐", ({ "Jane","jane" }) );
        set("gender", "女性" );
         set("age",37);
        set("long", @TEXT
TEXT
);
        set("attitude", "peaceful");
       set("class", "dancer");
       set("combat_exp", 5000000);
       set("score", 7000);
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set("force", 7000);
        set("max_force", 7000);
        set("force_factor", 30);
        create_family("晚月庄", 1, "前辈");

        setup();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/redbelt")->wear();
}

void attempt_apprentice(object ob)
{
     command("say 拜师! 不敢当，我都老了!你去找「芷萍」好了，看她收不收你? ");
     return 0;
}
