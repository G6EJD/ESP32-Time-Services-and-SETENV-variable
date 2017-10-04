# ESP32-Time-Services-and-SETENV-variable
How to get time and use SETENV variable for Time Zones and DST

See:

https://github.com/espressif/esp-idf/blob/master/examples/protocols/sntp/README.md

https://www.gnu.org/software/libc/manual/html_node/TZ-Variable.html

 GMTGMT-1, M3.4.0/1,M10.4.0/2
 GMTGMT-1 is the name of the time zone
 GMT-1 is the abbreviation used when DST is off
 1 hour is the time difference from GMT
 GMT is the abbreviation used when DST is on
 ,M3 is the third month
 .4 is the forth occurrence of the day in the month when DST starts
 .0 is Sunday
 /1 is the time in hours when DST starts
 ,M10 is the tenth month
 .4 is the forth occurrence of the day in the month when DST ends
 .0 is Sunday
 /2 is the time in hours when DST ends

 // Set timezone to British DST
 setenv("TZ","GMTGMT-1,M3.4.0/01,M10.4.0/02",1);
 
See: https://www.timeanddate.com/time/zones/  for your country code
