/*
 * ClockData.h
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */

#ifndef CLOCKDATA_H_
#define CLOCKDATA_H_

#include <string>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
	#include <windows.h>
	#include <time.h>
#else
	#include <sys/time.h>
#endif //WIN32

class ClockData {
private:
	int m_sec;  	//seconds after the minute	0-61*
	int m_min;  	//minutes after the hour	0-59
	int m_hour; 	//hours since midnight	0-23
	int m_mday;		//day of the month	1-31
	int m_mon;		//months since January	0-11
	int m_year;		//years since 1900
	int m_wday;		//days since Sunday	0-6
	int m_yday;		//days since January 1	0-365
	int m_isdst;	//Daylight Saving Time flag

	float m_hour_divider;
	float m_minute_divider;
	float m_second_divider;

	void calculateDividers(void);
	void getSystemLocalTime(void);
	void getDateTime(void);
public:
	enum rcvmethod_t {mLocalSystem = 0, mTestData} MethodType;

	ClockData();
	virtual ~ClockData();

	void _get(void);

	int getYear(void);
	int getMonth(void);
	int getDay(void);
	int getHour(void);
	int getMinute(void);
	int getSecond(void);

	float getHourDivider(void);
	float getMinuteDivider(void);
	float getSecondDivider(void);
};

#endif /* CLOCKDATA_H_ */
