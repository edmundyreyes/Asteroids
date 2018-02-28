#pragma once
class InputManager
{
public:
	InputManager();

	bool GetKeyUp(void);
	inline void ToggleKeyUp() { keyUp = !keyUp; }
	bool GetKeyW(void);
	inline void ToggleKeyW() { keyW = !keyW; }
	bool GetKeyLeft(void);
	inline void ToggleKeyLeft() { keyLeft = !keyLeft; }	
	bool GetKeyA(void);
	inline void ToggleKeyA() { keyA = !keyA; }
	bool GetKeyRight(void);
	inline void ToggleKeyRight() { keyRight = !keyRight; }
	bool GetKeyD(void);
	inline void ToggleKeyD() { keyD = !keyD; }
	bool GetKeyU(void);
	inline void ToggleKeyU() { keyU = !keyU; }
	bool GetKeyJ(void);
	inline void ToggleKeyJ() { keyJ = !keyJ; }
	bool GetKeySpace(void);
	inline void ToggleKeySpace() { keySpace = !keySpace; }


	//inline void ToggleKey() { key = !key; }

private:
	bool keyUp;
	bool keyW;
	bool keyLeft;
	bool keyA;
	bool keyRight;
	bool keyD;
	bool keyU;
	bool keyJ;
	bool keySpace;
	//9
};

