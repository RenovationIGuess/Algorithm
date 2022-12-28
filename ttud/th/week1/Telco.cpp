#include <bits/stdc++.h>

using namespace std;

bool check_phone_number(string num)
{
	int strLength = num.length();
	if (strLength != 10)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < strLength; ++i)
		{
			int value = num[i] - '0';
			if (num[i] > 9 && num[i] < 0)
			{
				return false;
			}
		}
	}
	return true;
}

int countTime(string stime, string etime)
{
	int startTime = 3600 * ((stime[0] - '0') * 10 + stime[1] - '0') + 60 * ((stime[3] - '0') * 10 + stime[4] - '0') + ((stime[6] - '0') * 10 + stime[7] - '0');
	int endTime = 3600 * ((etime[0] - '0') * 10 + etime[1] - '0') + 60 * ((etime[3] - '0') * 10 + etime[4] - '0') + ((etime[6] - '0') * 10 + etime[7] - '0');
	return endTime - startTime;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, int> phoneNumber, callTime;
	int totalCalls = 0;
	int checkPhoneNumber = 0; // use to check if there is any invalid phone number
	string type = "";

	// Input part
	do
	{
		cin >> type;
		if (type == "#")
			continue;
		totalCalls++;
		string fnum, tnum, date, stime, etime;
		cin >> fnum >> tnum >> date >> stime >> etime;
		if (checkPhoneNumber == 0) {
			if (check_phone_number(fnum) || check_phone_number(tnum)) {
				checkPhoneNumber = 1;
			}
		}
		phoneNumber[fnum]++;
		callTime[fnum] += countTime(stime, etime);
	} while (type != "#");

	// Query part
	do
	{
		cin >> type;
		if (type == "#")
			continue;
		if (type == "?check_phone_number")
		{
			cout << checkPhoneNumber << endl;
		}
		else if (type == "?number_calls_from")
		{
			string numberToCheck;
			cin >> numberToCheck;
			cout << phoneNumber[numberToCheck] << endl;
		}
		else if (type == "?number_total_calls")
		{
			// string numberToCheck; cin >> numberToCheck;
			cout << totalCalls << endl;
		}
		else
		{
			string numberToCheck;
			cin >> numberToCheck;
			cout << callTime[numberToCheck] << endl;
		}
	} while (type != "#");
	return 0;
}