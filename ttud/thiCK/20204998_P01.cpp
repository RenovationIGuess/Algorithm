#include <bits/stdc++.h>
#define MAX (int)1e5
using namespace std;

int totalTrips = 0;                                 // Tong so luong chuyen giao hang
int totalQuantity = 0;                              // Tra ve tong so luong goi hang
vector<string> date;                                // Luu chuoi ngay cua phan 1
map<string, int> customerCargo;                     // Luu so goi hang cua khach hang
map<string, vector<pair<string, string>>> tripInfo; // Thong tin nhung chuyen giao hang co trong ngay - ngay va gio
map<string, pair<string, string>> tripBeginTime;    // Luu thoi gian bat dau cua cac chuyen giao hang
map<string, pair<string, string>> tripEndTime;      // Luu thoi gian ket thuc cua cac chuyen giao hang
map<string, priority_queue<int>> tripTime;          // Tong thoi gian giao hang
map<string, vector<pair<string, int>>> dateCargo;   // Luu so luong goi hang cua 1 ngay - <thoi gian, qty>

// int dateTo
int convertStringToNum(string s)
{
  int multiplier = 1;
  int result = 0;
  for (int i = s.length() - 1; i >= 0; --i)
  {
    result += (int)(s[i] - '0') * multiplier;
    multiplier *= 10;
  }
  return result;
}

int compareDate(string deliDate1, string deliDate2)
{
  int month1, year1, date1;
  int month2, year2, date2;
  // int hour, minute, second;
  int cntDeliDate1 = 0;
  int cntDeliDate2 = 0;
  // int cntDeliTime = 0;
  string dateS1, dateS2;
  // Phan tach thong tin ngay 1
  for (int i = 0; i < deliDate1.length(); i++)
  {
    if (deliDate1[i] == '-')
    {
      cntDeliDate1++;
      if (cntDeliDate1 == 1)
      {
        year1 = convertStringToNum(dateS1);
      }
      else if (cntDeliDate1 == 2)
      {
        month1 = convertStringToNum(dateS1);
      }
      dateS1 = "";
    }
    else
    {
      dateS1 += deliDate1[i];
    }
  }
  date1 = convertStringToNum(dateS1);

  // Phan tach thong tin ngay 2
  for (int i = 0; i < deliDate2.length(); i++)
  {
    if (deliDate2[i] == '-')
    {
      cntDeliDate2++;
      if (cntDeliDate2 == 1)
      {
        year2 = convertStringToNum(dateS2);
      }
      else if (cntDeliDate2 == 2)
      {
        month2 = convertStringToNum(dateS2);
      }
      dateS2 = "";
    }
    else
    {
      dateS2 += deliDate2[i];
    }
  }
  date2 = convertStringToNum(dateS2);

  if (year1 > year2)
  {
    return 1; // 1 hon 2
  }
  else if (year1 < year2)
  {
    return -1;
  }
  else
  {
    if (month1 > month2)
      return 1;
    else if (month1 < month2)
      return -1;
    else
    {
      if (date1 > date2)
        return 1;
      else if (date1 < date2)
        return -1;
      else
        return 0;
    }
  }
}

int compareTime(string deliTime1, string deliTime2)
{
  int hour1, minute1, second1;
  int hour2, minute2, second2;

  int cntDeliTime1 = 0, cntDeliTime2 = 0;

  string timeS1, timeS2;
  // Phan tach thong tin thoi gian 1
  for (int i = 0; i < deliTime1.length(); i++)
  {
    if (deliTime1[i] == ':')
    {
      cntDeliTime1++;
      if (cntDeliTime1 == 1)
      {
        hour1 = convertStringToNum(timeS1);
      }
      else if (cntDeliTime1 == 2)
      {
        minute1 = convertStringToNum(timeS1);
      }
      timeS1 = "";
    }
    else
    {
      timeS1 += deliTime1[i];
    }
  }
  second1 = convertStringToNum(timeS1);

  // Phan tach thong tin thoi gian 2
  for (int i = 0; i < deliTime2.length(); i++)
  {
    if (deliTime2[i] == ':')
    {
      cntDeliTime2++;
      if (cntDeliTime2 == 1)
      {
        hour2 = convertStringToNum(timeS2);
      }
      else if (cntDeliTime2 == 2)
      {
        minute2 = convertStringToNum(timeS2);
      }
      timeS2 = "";
    }
    else
    {
      timeS2 += deliTime2[i];
    }
  }
  second2 = convertStringToNum(timeS2);

  if (hour1 > hour2)
  {
    return 1; // 1 hon 2
  }
  else if (hour1 < hour2)
  {
    return -1;
  }
  else
  {
    if (minute1 > minute2)
      return 1;
    else if (minute1 < minute2)
      return -1;
    else
    {
      if (second1 > second2)
        return 1;
      else if (second1 < second2)
        return -1;
      else
        return 0;
    }
  }
}

int calculateTime(string time)
{
  int hour, minute, second;
  string timeS;
  int cntTime = 0;
  for (int i = 0; i < time.length(); i++)
  {
    if (time[i] == ':')
    {
      cntTime++;
      if (cntTime == 1)
      {
        hour = convertStringToNum(timeS);
      }
      else if (cntTime == 2)
      {
        minute = convertStringToNum(timeS);
      }
      timeS = "";
    }
    else
    {
      timeS += time[i];
    }
  }
  second = convertStringToNum(timeS);

  return hour * 3600 + minute * 60 + second;
}

int findTravelTime(string tripCode)
{
  int beginDate, endDate;
  string beginDateS, endDateS;
  for (int i = tripEndTime[tripCode].first.length() - 2; i < tripEndTime[tripCode].first.length(); ++i)
  {
    endDateS += tripEndTime[tripCode].first[i];
  }
  for (int i = tripBeginTime[tripCode].first.length() - 2; i < tripBeginTime[tripCode].first.length(); ++i)
  {
    beginDateS += tripBeginTime[tripCode].first[i];
  }
  endDate = convertStringToNum(endDateS);
  beginDate = convertStringToNum(beginDateS);

  int totalTime = (endDate - beginDate - 1) * 24 * 3600 + calculateTime(tripEndTime[tripCode].second) + (24 * 3600 - calculateTime(tripBeginTime[tripCode].second));
  return totalTime;
}

int findMaxPeriod(string beginDate, string endDate, string beginTime, string endTime)
{
  int result = 0;
  for (int i = 0; i < date.size(); ++i)
  {
    if (compareDate(date[i], beginDate) >= 0 && compareDate(date[i], endDate) <= 0) {
    for (int j = 0; j < dateCargo[date[i]].size(); ++j)
    {
      if (compareDate(beginDate, endDate) == -1)
      {
        if (compareDate(date[i], endDate) < 0)
        {
          if (compareTime(dateCargo[date[i]][j].first, beginTime) >= 0)
          {
            if (result < dateCargo[date[i]][j].second)
            {
              result = dateCargo[date[i]][j].second;
            }
          }
        }
        else if (compareDate(date[i], endDate) == 0)
        {
          if (compareTime(dateCargo[date[i]][j].first, endTime) <= 0)
          {
            if (result < dateCargo[date[i]][j].second)
            {
              result = dateCargo[date[i]][j].second;
            }
          }
        }
      } else if (compareDate(beginDate, endDate) == 0) {
        if (compareTime(dateCargo[date[i]][j].first, beginTime) >= 0 && compareTime(dateCargo[date[i]][j].first, endTime) <= 0)
          {
            if (result < dateCargo[date[i]][j].second)
            {
              result = dateCargo[date[i]][j].second;
            }
          }
      }
    }
    }
  }
  return result;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  // Phan 1
  do
  {
    cin >> s;
    if (s == "*")
      continue;
    date.push_back(s);
  } while (s != "*");

  // Phan 2
  string tripCode, customerCode, date, time;
  int qty;
  do
  {
    cin >> tripCode;
    if (tripCode == "***")
      continue;
    cin >> customerCode >> date >> time >> qty;
    // totalTrips++;
    customerCargo[customerCode] += qty; // Tang so goi hang khach hang nhan duoc len 1
    totalQuantity += qty;
    tripInfo[tripCode].push_back(make_pair(date, time));
    if (tripBeginTime[tripCode].first == "")
    {
      tripBeginTime[tripCode] = make_pair(date, time);
    }
    else
    {
      if (compareDate(date, tripBeginTime[tripCode].first) == -1)
      {
        tripBeginTime[tripCode] = make_pair(date, time);
      }
      else if (compareDate(date, tripBeginTime[tripCode].first) == 0)
      {
        if (compareTime(time, tripBeginTime[tripCode].second) == -1)
        {
          tripBeginTime[tripCode] = make_pair(date, time);
        }
      }
    }

    if (tripEndTime[tripCode].first == "")
    {
      tripEndTime[tripCode] = make_pair(date, time);
    }
    else
    {
      if (compareDate(date, tripEndTime[tripCode].first) == 1)
      {
        tripEndTime[tripCode] = make_pair(date, time);
      }
      else if (compareDate(date, tripEndTime[tripCode].first) == 0)
      {
        if (compareTime(time, tripEndTime[tripCode].second) == 1)
        {
          tripEndTime[tripCode] = make_pair(date, time);
        }
      }
    }

    // Date Cargo
    dateCargo[date].push_back(make_pair(time, qty));
  } while (tripCode != "***");

  // Phan 3
  string query;
  do
  {
    cin >> query;
    if (query == "***")
      continue;
    if (query == "TOTAL_QTY")
    {
      cout << totalQuantity << endl;
    }
    else if (query == "QTY_CUSTOMER")
    {
      string reqCustomerCode;
      cin >> reqCustomerCode;
      cout << customerCargo[reqCustomerCode] << endl;
    }
    else if (query == "QTY_MAX_PERIOD")
    {
      string beginDate, beginTime, endDate, endTime;
      cin >> beginDate >> beginTime >> endDate >> endTime;
      cout << findMaxPeriod(beginDate, endDate, beginTime, endTime) << endl;
    }
    else if (query == "TOTAL_TRIPS")
    {
      cout << tripInfo.size() << endl;
    }
    else if (query == "TRAVEL_TIME_TRIP")
    {
      string reqTripCode;
      cin >> reqTripCode;
      cout << findTravelTime(reqTripCode) << endl;
    }
    else if (query == "MAX_CONFLICT_TRIP")
    {
    }
  } while (query != "***");
  return 0;
}