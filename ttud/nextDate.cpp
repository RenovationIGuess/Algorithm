#include <bits/stdc++.h>

using namespace std;

struct Date {
  int year;
  int month;
  int day;

  Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
};

struct Time {
  int hour;
  int minute;
  int second;

  Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
  }

  int addSecond(int second) {
    int dayafter = 0;
    this->second += second;
    if (this->second >= 60) {
      this->minute += this->second / 60;
      this->second %= 60;
    }
    if (this->minute >= 60) {
      this->hour += this->minute / 60;
      this->minute %= 60;
    }
    if (this->hour >= 24) {
      int hour = this->hour;
      this->hour %= 24;
      dayafter += hour / 24;
    }
    return dayafter;
  }
};

vector<Date> date;

int main(int argc, char const *argv[]) {
  string x;

  do {
    cin >> x;
    if (x == "*") break;
    // substring year, month, day in x by format "yyyy-mm-dd"
    int year = atoi(x.substr(0, 4).c_str());
    int month = atoi(x.substr(5, 2).c_str());
    int day = atoi(x.substr(8, 2).c_str());
    date.push_back(Date(year, month, day));
  } while (1);

  do {
    string result = "";
    cin >> x;
    if (x == "***") break;
    int year = atoi(x.substr(0, 4).c_str());
    int month = atoi(x.substr(5, 2).c_str());
    int day = atoi(x.substr(8, 2).c_str());
    Date d(year, month, day);
    string time;
    cin >> time;
    int hour = atoi(time.substr(0, 2).c_str());
    int minute = atoi(time.substr(3, 2).c_str());
    int second = atoi(time.substr(6, 2).c_str());
    int offset;
    cin >> offset;
    // calculate next date and time by offset seconds from current date and time
    Time t(hour, minute, second);
    int dayafter = t.addSecond(offset);
    if (dayafter > 0) {
      int i = 0;
      while (i < date.size()) {
        if (date[i].year == d.year && date[i].month == d.month && date[i].day == d.day) {
          d = date[i+dayafter];
          break;
        }
        i++;
      }
    }
    // print result
    result += to_string(d.year);
    result += "-";
    if (d.month < 10) result += "0";
    result += to_string(d.month);
    result += "-";
    if (d.day < 10) result += "0";
    result += to_string(d.day);
    result += " ";
    if (t.hour < 10) result += "0";
    result += to_string(t.hour);
    result += ":";
    if (t.minute < 10) result += "0";
    result += to_string(t.minute);
    result += ":";
    if (t.second < 10) result += "0";
    result += to_string(t.second);
    cout << result << endl;
  } while (1);
  return 0;
}
