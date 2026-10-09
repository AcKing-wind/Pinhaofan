#pragma once

#include"meal.h"

#include<SDL.h>

class CursorMgr
{
public:
	static CursorMgr* instance();

	void on_input(const SDL_Event& event);
	void on_render(SDL_Renderer* renderer);

	void set_picked(Meal meal);
	Meal get_picked();

private:
	CursorMgr();
	~CursorMgr();

private:
	static CursorMgr* manager;

	Meal meal_picked = Meal::None;
	SDL_Point pos_cursor = { 0 };
	bool is_mouse_lbtn_down = false;
};