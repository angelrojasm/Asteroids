#pragma once
#include "Color.h"
class Paint
{
public:
	Paint();
	~Paint();
	Color bleu = Color(0, 0, 1, 0);
	Color vert = Color(0, 1, 0, 0);
	Color rouge = Color(1, 0, 0, 0);
	Color jaune = Color(1, 1, 0, 0);
	Color blanche = Color(1, 1, 1, 0);
};

