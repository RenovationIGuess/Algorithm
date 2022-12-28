#include<stdio.h>
typedef struct wt {
	int totalrain; //in mm
	int hightemp; //in C
	int lowtemp;
} weather;
const int MONTH = 12;
int main() {
	weather data[MONTH];
	int i;
	char month[MONTH][10] = {"January", "February", "March", "April", "May", "June", "July", 
	"August", "September", "October", "November", "December"};
	int total_rain = 0;
	int max_temp = -100;
	int max_month = 0;
	int min_temp = 100;
	int min_month = 12;
	for(int i = 0; i < MONTH; i++) {
		printf("Weather data for %s: \n", month[i]);
		printf("Total rainfall (mm): "); scanf("%d", &data[i].totalrain);
		printf("High temperature (C): "); scanf("%d", &data[i].hightemp);
		printf("Low temperature (C): "); scanf("%d", &data[i].lowtemp);
	}
	for(int i = 0; i < MONTH; i++) {
		total_rain += data[i].totalrain;
		if(max_temp < data[i].hightemp) {
			max_temp = data[i].hightemp;
			max_month = i;
		}
		if(min_temp > data[i].lowtemp) {
			min_temp = data[i].lowtemp;
			min_month = i;
		}
	}
	printf ("\nWeather Statistic for the Year:\n");
	printf ("Total Rainfall: %d mm\n", total_rain);
	printf ("Monthly Rainfall: %2.3f mm\n", double(total_rain)/MONTH);
	printf ("Highest Temperature: "" : %d °C in %s \n", max_temp, month[max_month]);
	printf ("Lowest Temperature: "" : %d °C in %s \n", min_temp, month[min_month]);
	return 0;
}
