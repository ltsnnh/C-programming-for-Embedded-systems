#include "userincl.h"

int main()
{
    enum week_day {SUNDAY, MONDAY, TUESDAY, WEDSDAY, THURSDAY, FRIDAY, SATURDAY} day;
    enum week_day yesterday;

    printf("sizeof(enum week_day) = %ld = %ld = %ld\n", sizeof(day), sizeof(yesterday), sizeof(SUNDAY));
    printf("SUNDAY = %d\nMONDAY = %d\nTUESDAY = %d\nWEDSDAY = %d\nTHURSDAY = %d\nFRIDAY = %d\nSATURDAY = %d\n", \
           SUNDAY, MONDAY, TUESDAY, WEDSDAY, THURSDAY, FRIDAY, SATURDAY);

    return 0;
}