#pragma once
class InputManager
{


private:

	bool key_Up_was_pressed;
	bool key_Left_was_pressed;
	bool key_Right_was_pressed;
	bool key_D_was_pressed;
	bool key_F_was_pressed;
	bool key_O_was_pressed;
	bool key_P_was_pressed;
	bool key_R_was_pressed;
	bool key_Space_was_pressed;

public:

	void setkey_Up_was_pressed(bool);
	void setkey_Left_was_pressed(bool);
	void setkey_Right_was_pressed(bool);
	void setkey_D_was_pressed(bool);
	void setkey_F_was_pressed(bool);
	void setkey_O_was_pressed(bool);
	void setkey_P_was_pressed(bool);
	void setkey_Space_was_pressed(bool);
	void setkey_R_was_pressed(bool);


	bool getkey_Up_was_pressed(void);
	bool getkey_Left_was_pressed(void);
	bool getkey_Right_was_pressed(void);
	bool getkey_D_was_pressed(void);
	bool getkey_F_was_pressed(void);
	bool getkey_O_was_pressed(void);
	bool getkey_P_was_pressed(void);
	bool getkey_Space_was_pressed(void);
	bool getkey_R_was_pressed(void);




	InputManager();
	~InputManager();
};

