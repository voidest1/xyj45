// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// look.c
// "per" parts modified by none at 96/10/02

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

string *per_msg_male1 = ({
        CYN "长得伟岸英挺，顾盼之间，神采飞扬。\n" NOR,
        CYN "丰姿英伟，气宇轩昂，确实是人中龙凤。\n" NOR,
});

string *per_msg_male2 = ({
        CYN "英俊潇洒，风度翩翩。\n" NOR,
        CYN "相貌出众，面目俊朗。\n" NOR,
        CYN "面貌清奇，丰姿非俗。\n" NOR,
});
string *per_msg_male3 = ({
        CYN "相貌平平，没什么好看的。\n" NOR,
        CYN "相貌凶恶，满脸横肉。\n" NOR,
        CYN "暴睛环眼，嘴脸凶顽。\n" NOR,
});
string *per_msg_male4 = ({
        CYN "长得一副姥姥不疼，舅舅不爱的模样。\n" NOR,
        CYN "长得蔫蔫的，一副无精打采的模样。 \n" NOR, 
        CYN "五短三粗，肥头大耳，大概是猪八戒的本家。 \n" NOR, 
});
string *per_msg_female1 = ({
        CYN "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 \n" NOR,
        CYN "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。 \n" NOR,
        CYN "风情万种，楚楚动人，当真是我见犹怜。 \n" NOR, 
});
string *per_msg_female2 = ({
        CYN "婷婷玉立，容色秀丽，风姿动人。 \n" NOR,
        CYN "玉面娇容花含露，纤足细腰柳带烟。 \n" NOR,
        CYN "面带晕红，眼含秋波。举手投足之间，确有一番风韵。 \n" NOR,
});
string *per_msg_female3 = ({
        CYN "虽算不上绝世佳人，也颇有几份姿色。 \n" NOR,
        CYN "长得还不错，颇有几份姿色。  \n" NOR,
});
string *per_msg_female4 = ({
        CYN "长得比较难看。 \n" NOR,
        CYN "长得………唉！  \n" NOR,
});

string *per_msg_kid1 = ({
        CYN "月眉星眼，灵气十足。\n" NOR,
        CYN "机灵活泼，神态非凡。\n" NOR,
        CYN "面若秋月，色如晓花。\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "隆额大眼，脸色红润。\n" NOR,
        CYN "胖胖嘟嘟，逗人喜欢。\n" NOR,
        CYN "细皮嫩肉，口齿伶俐。\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "身材矬矮，傻里傻气。\n" NOR,
        CYN "肥肥胖胖，小鼻小眼。\n" NOR,
        CYN "呆头呆脑，笨手笨脚。\n" NOR,
});

string *per_msg_kid4 = ({
        CYN "蓬头垢脚，脸黄肌瘦。\n" NOR,
        CYN "神如木鸡，面有病色。\n" NOR,
        CYN "五官不整，四肢不洁。\n" NOR,
});

// snowcat 12/20/97
string ride_suffix (object me)
{
  string ridemsg = "";
  object ridee = 0;

  if (ridee = me->query_temp("ridee")) { 
    if (environment(ridee) != environment(me) ||
        ! living(ridee) ||
        ! living(me)) {
     me->set_temp("ridee",0);
     ridee->set_temp("rider",0);
     ridee = 0;
    }
    else
      ridemsg = " <"+ridee->query("ride/msg")+"在"+ridee->name()+"上>";
  }
  if (! ridee) {
    me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
    me->set_temp("ride/dodge",0);
  }
  return ridemsg;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
   object obj;
   int result;

   if( !arg ) result = look_room(me, environment(me));
   else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
     if( obj->is_character() ) result = look_living(me, obj);
     else result = look_item(me, obj);
   } else result = look_room_item(me, arg);

   return result;
}

int look_room(object me, object env)
{
   int i;
   object *inv;
   mapping exits;
   string str, *dirs;

   if( !env ) {
     write("你的四周灰蒙蒙地一片，什么也没有。\n");
     return 1;
   }
   str = sprintf( "%s - %s\n    %s%s",
     env->query("short")?env->query("short"): "",
     wizardp(me)? file_name(env): "",
     env->query("long")? env->query("long"): "\n",
     env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

   if( mapp(exits = env->query("exits")) ) {
     dirs = keys(exits);
     for(i=0; i<sizeof(dirs); i++)
        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
          dirs[i] = 0;
     dirs -= ({ 0 });
     if( sizeof(dirs)==0 )
        str += "    这里没有任何明显的出路。\n";
     else if( sizeof(dirs)==1 )
        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
     else
        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
          implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
   }
//   str += env->door_description();

   inv = all_inventory(env);
   for(i=0; i<sizeof(inv); i++) {
     if( inv[i]==me ) continue;
     if( !me->visible(inv[i]) ) continue;
     str += "  " + inv[i]->short() + ride_suffix(inv[i])+ " " +
            base_name(inv[i])+"\n";
   }

   write(str);
   return 1;
}

int look_item(object me, object obj)
{
   mixed *inv;

//   write(obj->long());
   me->start_more(obj->long());
   inv = all_inventory(obj);
   if( sizeof(inv) ) {
     inv = map_array(inv, "inventory_look", this_object() );
     message("vision", sprintf("里面有：\n  %s\n",
        implode(inv, "\n  ") ), me);
   }
   return 1;
}
string per_status_msg(int age, int per, string gender)
{
   // added by snowcat 
   if (age < 14) {
     if ( per>=25 )
        return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
     else if ( per>=20 )
        return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
     else if ( per>=15 )
        return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
     else    return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
     }
     
   if ( gender == "男性" ) {
     if ( per>=25 )
        return ( per_msg_male1[random(sizeof(per_msg_male1))]);
     else if ( per>=20 )
        return ( per_msg_male2[random(sizeof(per_msg_male2))]);
     else if ( per>=15 )
        return ( per_msg_male3[random(sizeof(per_msg_male3))]);
     else    return ( per_msg_male4[random(sizeof(per_msg_male4))]);
     }
     
   if ( gender == "女性" ) {
     if ( per>=25 )
                           return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                   else if ( per>=20 )
                           return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                   else if ( per>=15 )
                           return ( per_msg_female3[random(sizeof(per_msg_female3))]);
         else   return ( per_msg_female4[random(sizeof(per_msg_female4))]);
                }
   else return "";
//   else return "长得怎样你没什么概念。\n";
}

int look_living(object me, object obj)
{
   string str, limb_status, pro;
   mixed *inv;
   mapping my_fam, fam;
// added for bian by mon.
        mapping ofamily;
   string ogender,orace;
   int oage;
 
   if(obj->query_temp("d_mana")>0) {
     ofamily=obj->query_temp("family");
     ogender=obj->query_temp("gender");
     orace=obj->query_temp("race");
     oage=obj->query_temp("age");
        } else {
     ofamily=obj->query("family");
     ogender=obj->query("gender");
     orace=obj->query("race");
     oage=obj->query("age");
//fake_age is set as the age when player gets dao-xing:不堕轮回。
//so later on, he/she always looks like the age of that time:)
//but need a "look" to activate all the relatived settings...weiqi
//only when one is not in the status of "bian", check his/her
//fake_age. mon 9/4/97
     if(obj->query("always_young") ) { 
        if(oage>obj->query("fake_age")) {
        //if "age" is less than fake_age, reset fake_age.
        //mon 9/4/97
     oage=obj->query("fake_age");
             } else {
               obj->set("fake_age", oage);
        }
     }
     else{
     if(obj->query("combat_exp") > 729000){
        obj->set("always_young", 1);
        obj->set("fake_age", oage);
     }     
     }
//done with fake_age.
        }


   if( me!=obj )
     message("vision", me->name() + "正盯着你看，不知道打些什么主意。\n", obj);

   str = obj->long();
   str = replace_string(str, "。\n", ride_suffix(obj)+"。\n");

   str = replace_string(str, "$n", me->name());
   str = replace_string(str, "$N", obj->name());
    str = replace_string(str, "$C", RANK_D->query_respect(obj));
    str = replace_string(str, "$c", RANK_D->query_rude(obj));
   str = replace_string(str, "$R", RANK_D->query_respect(me));
   str = replace_string(str, "$r", RANK_D->query_rude(me));


   pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

        if(obj->query_temp("d_mana")==0 || obj->query_temp("is_character")) {
   
   if( orace=="人类"
   &&   intp(oage) )
     if(oage<10) {
        str += sprintf("%s看起来显然还不到十岁。\n", pro);
     }
     else{
        str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(oage / 10 * 10));
     }

   //check about wife and husband
   if((obj->parse_command_id_list())[0]==me->query("couple/id") ) {
     if( (string)me->query("gender")=="女性" ){
     str += sprintf("%s是你的丈夫。\n", pro);
     }
     else{
        str += sprintf("%s是你的妻子。\n", pro);
     }
   }
   // If we both has family, check if we have any relations.
   if( obj!=me
   &&   mapp(fam = ofamily)
   &&   mapp(my_fam = me->query("family")) 
   &&   fam["family_name"] == my_fam["family_name"] ) {
   
     if( fam["generation"]==my_fam["generation"] ) {
        if( ogender == "男性" )
          str += sprintf( pro + "是你的%s%s。\n",
             my_fam["master_id"] == fam["master_id"] ? "": "同门",
             my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
        else
          str += sprintf( pro + "是你的%s%s。\n",
             my_fam["master_id"] == fam["master_id"] ? "": "同门",
             my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
     } else if( fam["generation"] < my_fam["generation"] ) {
        if( member_array(my_fam["master_id"],
            obj->parse_command_id_list())>-1  )
          str += pro + "是你的师父。\n";
        else if( my_fam["generation"] - fam["generation"] > 1 )
          str += pro + "是你的同门长辈。\n";
        else if( fam["enter_time"] < my_fam["enter_time"] )
          str += pro + "是你的师伯。\n";
        else
          str += pro + "是你的师叔。\n";
     } else {
        if( fam["generation"] - my_fam["generation"] > 1 )
          str += pro + "是你的同门晚辈。\n";
        else if( fam["master_id"] == me->query("id") )
          str += pro + "是你的弟子。\n";
        else
          str += pro + "是你的师侄。\n";
     }
   }

/*   if( obj->query("max_kee") )
     str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";
*/

//here, if per>=100, no rong-mao description, it'll be necessary sometimes.
//return special looking first if he/she has one.

   if( obj->query("looking") ){
     str += pro + (string)obj->query("looking") + "\n";
   } else {
     string looking= per_status_msg((int)obj->query("age"),
            (int)obj->query_per(), ogender);
              if( strlen(looking)>1 && obj->query("per") < 100 )
                    str += pro + looking;
   }
   inv = all_inventory(obj);
   if( sizeof(inv) ) {
     inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
     inv -= ({ 0 });
     if( sizeof(inv) )
        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带着：\n%s\n",
          pro, implode(inv, "\n") );
   }
        
   }

        me->start_more(str);

   if( obj!=me 
   &&   living(obj)
   &&   random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
     write( obj->name() + "突然转过头来瞪你一眼。\n");
     COMBAT_D->auto_fight(obj, me, "berserk");
     return 1;
   }

//this part is  taken from attack.c
//mon 1/22/98
   if( obj!=me 
   && living(obj)
   && userp(obj)
        && random((int)obj->query("bellicosity")/40) > (int)obj->query("cps") ) 
     COMBAT_D->auto_fight(obj, me, "berserk");


   return 1;
}

string inventory_look(object obj, int flag)
{
   string str;

   str = obj->short();
   if( obj->query("equipped") )
     str = HIC "  □" NOR + str;
   else if( !flag )
     str = "    " + str;
   else
     return 0;

   return str;
}

int look_room_item(object me, string arg)
{
   object env;
   mapping item, exits;

   if( !objectp(env = environment(me)) )
     return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");

   if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
     if( stringp(item[arg]) )
        write(item[arg]);
     else if( functionp(item[arg]) )
        write((string)(*item[arg])(me));
        
     return 1;
   }
   if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
     if( objectp(env = load_object(exits[arg])) )
        look_room(me, env);
     else {
       return notify_fail("你什么也看不见。\n");
     }
     return 1;
   }
   return notify_fail("你要看什么？\n");
}

int help (object me)
{
   write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
HELP
);
   return 1;
}
