#include "InputManager.hpp"



InputManager::InputManager() {
	keyUp = false;
	keyW = false;
	keyLeft = false;
	keyA = false;
	keyRight = false;
	keyD = false;
	keyU = false;
	keyJ = false;
	keySpace = false;
	keyP = false;
	keyF = false;

}
bool InputManager::GetKeyUp() {
	return keyUp;
}
bool InputManager::GetKeyW() {
	return keyW;
}
bool InputManager::GetKeyLeft() {
	return keyLeft;
}
bool InputManager::GetKeyA() {
	return keyA;
}
bool InputManager::GetKeyRight() {
	return keyRight;
}
bool InputManager::GetKeyD() {
	return keyD;
}
bool InputManager::GetKeyU() {
	return keyU;
}
bool InputManager::GetKeyJ() {
	return keyJ;
}
bool InputManager::GetKeyP() {
	return keyP;
}
bool InputManager::GetKeyF() {
	return keyF;
}
bool InputManager::GetKeySpace() {
	return keySpace;
}
void InputManager::SetKeyUp(bool status) {
	keyUp = status;
}
void InputManager::SetKeyW(bool status) {
	keyW = status;
}
void InputManager::SetKeyLeft(bool status) {
	keyLeft = status;
}
void InputManager::SetKeyA(bool status) {
	keyA = status;
}
void InputManager::SetKeyRight(bool status) {
	keyRight = status;
}
void InputManager::SetKeyD(bool status) {
	keyD = status;
}
void InputManager::SetKeyU(bool status) {
	keyU = status;
}
void InputManager::SetKeyJ(bool status) {
	keyJ = status;
}
void InputManager::SetKeySpace(bool status) {
	keySpace = status;
}
void InputManager::SetKeyP(bool status) {
	keyP = status;
}
void InputManager::SetKeyF(bool status) {
	keyF = status;
}
