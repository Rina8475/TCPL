/* 对应教材 S5.7 编写一个日期转换程序 
   将某月某日这种日期形式转换为某年中第几天的形式 反之亦然 */
#define ISDYEAR(x)  (((x) % 4 == 0 && (x) % 100 != 0) || (x) % 400 == 0)        // 判断是否是闰年

static char daytab[2][13] = {               // 二维数组初始化
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* 将某月某日的日期表示形式转换为某年中第几天的表示形式 */
int day_of_year(int year, int month, int day) {
    int leap = ISDYEAR(year);

    while (--month > 0)
        day += daytab[leap][month];
    return day;
}

/* 将某年某日的日期表示形式转换为某月某日的表现形式 */
void month_day(int year, int day, int *pmonth, int *pday) {
    int i, leap = ISDYEAR(year);

    for (i = 1; day > daytab[leap][i]; i++)
        day -= daytab[leap][i];
    *pmonth = i;
    *pday = day;
}