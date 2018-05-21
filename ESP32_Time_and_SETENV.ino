#include <WiFi.h>
#include "time.h"
String time_str;
const char* ssid     = "yourSSID";
const char* password = "yourPASSWORD";

void setup() { 
  Serial.begin(115200);
  Start_WiFi(ssid,password);
  configTime(0, 0, "pool.ntp.org");
}

void loop() {
  //See: https://www.gnu.org/software/libc/manual/html_node/TZ-Variable.html
  // CST6CDT, M3.2.0/2:00:00, M11.1.0/2:00:00
  // CST6CDT is the name of the time zone
  // CST is the abbreviation used when DST is off
  // 6 hours is the time difference from GMT
  // CDT is the abbreviation used when DST is on
  // ,M3 is the third month
  // .2 is the second occurrence of the day in the month
  // .0 is Sunday
  // /2:00:00 is the time
  // ,M11 is the eleventh month
  // .1 is the first occurrence of the day in the month
  // .0 is Sunday
  // 2:00:00 is the time

  // Set timezone to British DST
  setenv("TZ", "GMT0BST,M3.5.0/01,M10.5.0/02",1); // You must include '0' after first designator e.g. GMT0GMT-1, ',1' is true or ON
  Serial.println("      UK Time = "+printLocalTime());

  // Set timezone to Eastern Standard Time
  setenv("TZ", "EST5EDT,M3.2.0/2,M11.1.0", 1);
  Serial.println("US (EST) Time = "+printLocalTime());

  // Set timezone to Indian Standard Time
  setenv("TZ", "UTC-05:30", 1);
  Serial.println("  INDIAN Time = "+printLocalTime());
  
  // Set timezone to China Standard Time
  setenv("TZ", "CST-8CDT-9,M4.2.0/2,M9.2.0/3", 1);
  Serial.println("  CHINA Time  = "+printLocalTime());
  Serial.println();
  delay(2000);
}

String printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return "Time Error";
  }
  //See http://www.cplusplus.com/reference/ctime/strftime/
  char output[80];
  strftime(output, 80, "%d-%b-%y, %H:%M:%S", &timeinfo);
  time_str = String(output);
  return String(output);
}

int Start_WiFi(const char* ssid, const char* password){
 int connAttempts = 0;
 Serial.println("\r\nConnecting to: "+String(ssid));
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED ) {
   delay(500);
   Serial.print(".");
   if(connAttempts > 20) return -5;
   connAttempts++;
 }
 return 1;
}
 

