/*
 * main.cpp
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */

#include <iostream>
#include "ClockData.h"
#include "CLIClock.h"

using namespace std;

int main(int argc, char* argv[]) {
	ClockData *c = new ClockData();
	CLIClock *cc = new CLIClock();

	c->MethodType = ClockData::mLocalSystem;
	if(argc>=2) {
		int tl = atoi(argv[1]);
		cc->setTimelineLen(tl);
	}

	while(true) {
		c->_get();

		//cout << c->getHour() << ":" << c->getMinute() << endl;
		//cout << "Hour divider: " << c->getHourDivider() << ", minute divider: " << c->getMinuteDivider() << endl;

		cc->setHourPos(c->getHourDivider());
		cc->setMinPos(c->getMinuteDivider());
		cc->setSecPos(c->getSecondDivider());
		cc->setHour(c->getHour());
		cc->setMinute(c->getMinute());
		cc->setSecond(c->getSecond());

		cc->show();
		Sleep(500);
	}

	delete cc;
	delete c;
}
