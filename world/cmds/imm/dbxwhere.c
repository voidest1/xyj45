// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <globals.h>

int main()
{
  mapping error;
  int i;

  if (!(error = this_player()->query_temp("error"))) return 1;
  printf("%sProgram: %s\n", error["error"], error["program"]);
  for (i=0; i<sizeof(error["trace"]); i++) {
    printf("%i: %s in %s:%i\n", i, error["trace"][i]["function"], error["trace"][i]["program"], error["trace"][i]["line"]);
  }
  return 1;
}
