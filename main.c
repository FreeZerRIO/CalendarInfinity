//
//  main.c
//  Calendar Infinity
//
//  Created by Алексей Баринов on 10.12.2017.
//  Copyright © 2017 Era Company. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    int day=0;
    int month=0;
    int year=0;
    time_t rawtime;
    struct tm * timeinfo;
    printf("Введите день ");
    scanf("%d",&day);
    printf("Введите месяц ");
    scanf("%d",&month);
    printf("Введите год ");
    scanf("%d",&year);
    const char * weekday[] = { "Воскресение", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    
    
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    timeinfo->tm_year = year-1900;
    timeinfo->tm_mon = month-1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = 0;
    timeinfo->tm_min = 0;
    timeinfo->tm_sec = 0;
    timeinfo->tm_isdst = 0;
    
    mktime(timeinfo);
    printf("Это будет/было %s.\n", weekday[timeinfo->tm_wday]);
    return 0;
}

