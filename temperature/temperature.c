#include <stdio.h>
#define DAYS_WEEK 7
#define WEEKS 2

void human_days(int index, char **human_day) {
  char *days[8] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  *human_day = days[index];
}

void read_temp(float temperatures[WEEKS][DAYS_WEEK]) {
	int x, y;
  char *day;
  for(x = 0; x < WEEKS; x++) {
  	for(y = 0; y < DAYS_WEEK; y++) {
      human_days(y, &day);
      printf("type the temperatures to week %d on %s: ", (x + 1), day);
      scanf("%f", &temperatures[x][y]);
    }
	}
}

void show_greater_and_less(float greater_temp[WEEKS], float less_temp[WEEKS]) {
  int x;
  for(x = 0; x < WEEKS; x++) {
    printf("Week %d\n", (x + 1));
    printf("The greater temp is: %0.1f\n", greater_temp[x]);
    printf("The less temp is: %0.1f\n ", less_temp[x]);
  }
}

void greater_and_less(float temperatures[WEEKS][DAYS_WEEK], float greater_temp[WEEKS], float less_temp[WEEKS]) {
  int x, y;
  for(x = 0; x < WEEKS; x++) {
    for(y = 0; y < DAYS_WEEK; y++) {
      if(temperatures[x][y] > greater_temp[x]) greater_temp[x] = temperatures[x][y];
      if(less_temp[x] == 0 || temperatures[x][y] < less_temp[x]) less_temp[x] = temperatures[x][y];
    }
  }

  show_greater_and_less(greater_temp, less_temp);
}

void temp_greater_than(float temperatures[WEEKS][DAYS_WEEK]) {
  int x, y, qnt_temp_greater_than = 0;
  float temperature;

  printf("Ok, nice!!\n Now, type a temperature and see how many temperatures were higher this week: ");
  scanf("%f", &temperature);

  for(x = 0; x < WEEKS; x++) {
    for(y = 0; y < DAYS_WEEK; y++) {
      if(temperatures[x][y] > temperature) qnt_temp_greater_than++ ;
    }
  }

  printf("%d temperatures it was over %0.1f", qnt_temp_greater_than, temperature);
}

int main() {
  float temperatures[WEEKS][DAYS_WEEK],
        greater_temp[WEEKS] = {0 , 0},
        less_temp[WEEKS] = {0 , 0};

  read_temp(temperatures);
  greater_and_less(temperatures, greater_temp, less_temp);
  temp_greater_than(temperatures);
  return 0;
}
