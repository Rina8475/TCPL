/* 练习 5-8 对程序 P05-day2year.c 进行修改 加上错误检查 */
#define ISDYEAR(x)  (((x) % 4 == 0 && (x) % 100 != 0) || (x) % 400 == 0)        // 判断是否是闰年
#define YEARDAY     365         // 一年的天数
#define MONTH       12          // 一年的月数

static char daytab[2][13] = {               // 二维数组初始化
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* 将某月某日的日期表示形式转换为某年中第几天的表示形式 */
int day_of_year(int year, int month, int day) {
    int leap = ISDYEAR(year);

    if (month > MONTH || day > daytab[leap][month])   return -1;      // 日期出界
    while (--month > 0)
        day += daytab[leap][month];
    return day;
}

/* 将某年某日的日期表示形式转换为某月某日的表现形式 */
void month_day(int year, int day, int *pmonth, int *pday) {
    int i, leap = ISDYEAR(year);

    if (day > YEARDAY + leap)   return;         // 日期出界
    for (i = 1; day > daytab[leap][i]; i++)
        day -= daytab[leap][i];
    *pmonth = i;
    *pday = day;
}