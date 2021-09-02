// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

#include <ansi.h>

mapping obstacles = ([
  "wuzhuang"   : "  1. 五庄观／人参果",
  "baoxiang"   : "  2. 宝象国／碗子山",
  "pingding"   : "  3. 平顶山／莲花洞／压龙山／压龙洞",
  "wuji"       : "  4. 乌鸡国／宝林寺",
  "chechi"     : "  5. 车迟国／三清观",
  "tongtian"   : "  6. 通天河／陈家庄",
  "jindou"     : "  7. 金兜山／金兜洞",
  "nuerguo"    : "  8. 女儿国／解阳山",
  "dudi"       : "  9. 毒敌山／琵琶洞",
  "firemount"  : " 10. 火焰山／翠云山",
  "jilei"      : " 11. 积雷山／摩云洞",
  "jisaiguo"   : " 12. 祭赛国／碧波潭",
  "jingjiling" : " 13. 荆棘岭／木仙庵",
  "xiaoxitian" : " 14. 小西天／小雷音寺",
  "zhuzi"      : " 15. 朱紫国／麒麟山／獬豸洞",
  "pansi"      : " 16. 盘丝岭／盘丝洞／黄花观／紫云山",
  "biqiu"      : " 17. 比丘国／清华庄／清华洞",
  "wudidong"   : " 18. 无底洞／黑松林",
  "qinfa"      : " 19. 钦法国",
  "yinwu"      : " 20. 隐雾山／连环洞",
  "fengxian"   : " 21. 凤仙郡",
  "yuhua"      : " 22. 玉华县／豹头山／虎口洞／竹节山／九曲盘桓洞",
  "jinping"    : " 23. 金平府／青龙山／玄英洞",
  "tianzhu"    : " 24. 天竺国／毛颖山／三连穴",
]);

int do_read(string arg);
void create()
{
  set_name("《西游记西行求取真经指南》", ({"xyj qujing","xyj","qujing","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("value", 100);
    set("no_sell", 1);
    set("long", " 《西游记西行求取真经指南》 请用 read 阅读。\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me = this_player();
  object ob = this_object();
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *chapters = values(obstacles);
  int i, nb=0;

  chapters = (string *)sort_array (chapters, 1);
  ob->set("value", 0);

  if (arg == "new") return 0; 

  if (! arg ||
      sscanf(arg, "%d", nb)!=1)
  {
    write ("西游记现有如下西域地区：\n");
    for (i = 0; i < size; i++)
    {
      write ("  "+chapters[i]+"\n");
    }
    write ("请用 read <number> 参阅有关地区。\n");
    return 1;
  }

  if ( nb < 1 || nb > size)
    return notify_fail ("你要读哪一地区？\n");

  nb--;
  for (i = 0; i < size; i++)
  {
    if (obstacles[names[i]] == chapters[nb])
    {
      nb = i;
      break;
    }
  }

  write("\n");
  me->start_more(read_file("/d/qujing/"+names[nb]+"/"+names[nb]));
  write("\n");
  return 1;
}