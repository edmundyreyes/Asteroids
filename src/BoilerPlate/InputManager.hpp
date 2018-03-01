#pragma once
class InputManager
{
public:
	InputManager();

	bool GetKeyUp(void);
	void SetKeyUp(bool);
	bool GetKeyW(void);
	void SetKeyW(bool);
	bool GetKeyLeft(void);
	void SetKeyLeft(bool);
	bool GetKeyA(void);
	void SetKeyA(bool);
	bool GetKeyRight(void);
	void SetKeyRight(bool);
	bool GetKeyD(void);
	void SetKeyD(bool);
	bool GetKeyU(void);
	void SetKeyU(bool);
	bool GetKeyJ(void);
	void SetKeyJ(bool);
	bool GetKeySpace(void);
	void SetKeySpace(bool);
	bool GetKeyP(void);
	void SetKeyP(bool);
	bool GetKeyF(void);
	void SetKeyF(bool);

//private:
	bool keyUp; //
	bool keyW;  //
	bool keyLeft; // 
	bool keyA;   //
	bool keyRight;//
	bool keyD; //

	bool keyU; //
	bool keyJ; //
	bool keySpace; //

	bool keyP;
	bool keyF;
	
};

