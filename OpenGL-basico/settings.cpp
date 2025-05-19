#include "Settings.h"

settings* settings::instance = nullptr;

settings* settings::getInstance() {
	if (instance == nullptr) {
		instance = new settings();
	}
	return instance;
}