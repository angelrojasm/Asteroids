#include "InputManager.h"



InputManager::InputManager()
{
	key_Up_was_pressed = false;
	key_Left_was_pressed = false;
	key_Right_was_pressed = false;
	key_P_was_pressed = false;
	key_O_was_pressed = false;
	key_D_was_pressed = false;
	key_F_was_pressed = false;
	key_Space_was_pressed = false;
	

}


InputManager::~InputManager()
{
}


void::InputManager::setkey_Up_was_pressed(bool newValue) {
	key_Up_was_pressed = newValue;
}
void::InputManager::setkey_Left_was_pressed(bool newValue) {
	key_Left_was_pressed = newValue;
}

void::InputManager::setkey_Right_was_pressed(bool newValue) {
	key_Right_was_pressed = newValue;
}

void::InputManager::setkey_D_was_pressed(bool newValue) {
	key_D_was_pressed = newValue;
}

void::InputManager::setkey_F_was_pressed(bool newValue) {
	key_F_was_pressed = newValue;
}

void::InputManager::setkey_O_was_pressed(bool newValue) {

	key_O_was_pressed = newValue;
}

void::InputManager::setkey_P_was_pressed(bool newValue) {
	key_P_was_pressed = newValue;
}

void::InputManager::setkey_Space_was_pressed(bool newValue) {
	key_Space_was_pressed = newValue;
}

bool::InputManager::getkey_Up_was_pressed() {
	return key_Up_was_pressed;
}

bool::InputManager::getkey_Left_was_pressed() {
	return key_Left_was_pressed;
}

bool::InputManager::getkey_Right_was_pressed() {
	return key_Right_was_pressed;
}

bool::InputManager::getkey_D_was_pressed() {
	return key_D_was_pressed;
}

bool::InputManager::getkey_F_was_pressed() {
	return key_F_was_pressed;
}

bool::InputManager::getkey_O_was_pressed() {
	return key_O_was_pressed;
}

bool::InputManager::getkey_P_was_pressed() {
	return key_P_was_pressed;
}

bool::InputManager::getkey_Space_was_pressed() {
	return key_Space_was_pressed;
}
