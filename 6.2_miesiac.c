#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void write_month(int beginning, int end)
{
    printf("Pn\tWt\tSr\tCz\tPt\tSo\tNd\n");
    for(int i=0, day=1; i<(beginning+end); ++i)
    {
        if(i<beginning)
	    printf("\t");
	else
	{
	    printf("%2d\t", day);
	    ++day;
	}
	if(i%7==0)
	    printf("\n");
    }
    printf("\n");
}

int days_in_month(int year, int month)
{
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        return 31;   
    else if(month==4 || month==6 || month==9 || month==11)
	return 30;
    else
    {
        bool leap;

        if(year%400==0 || (year%4==0 && year%100!=0))
            leap=true;
        else
	    leap=false;
    
        if(leap==true)
            return 29;
	else
            return 28;
    }
}

void actual_year_and_month(struct tm *loc_time, int tab[])
{
    char buf[3];
    char buf2[5];
    strftime(buf,3, "%m", loc_time);
    strftime(buf2,5,"%Y",loc_time);
    
    int const month=atoi(buf);
    int const year=atoi(buf2);

    char const months[12][15]={"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec",
     "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};
    printf("Aktualny miesiac i rok to: %s %d.\n", months[month-1], year);

    tab[0]=month;
    tab[1]=year;
}

int main(void)
{
    time_t curtime;
    struct tm * loc_time;
    curtime = time(NULL);
    loc_time = localtime(&curtime);
    
    int tab[2];
    actual_year_and_month(loc_time, tab);

    int const whole_day=24*60*60;
    while(loc_time->tm_mday>1)
    {
        curtime-=whole_day;
	loc_time=localtime(&curtime);
    }
    int first_day_of_month=loc_time->tm_wday;
    
    write_month(first_day_of_month, days_in_month(tab[1], tab[0]));
}
