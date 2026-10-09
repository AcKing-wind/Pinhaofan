#pragma once

#include"meal.h"
#include"timer.h"
#include"region.h"

class MicrowaveOven : public Region
{
public:
	MicrowaveOven(int x, int y);
	~MicrowaveOven() = default;

	void on_cursor_up() override;
	void on_cursor_down() override;
	void on_update(float delta) override;
	void on_render(SDL_Renderer* renderer) override;

private:
	Timer timer;
	bool is_working = false;
	Meal meal_target = Meal::None;

private:
	bool can_place(Meal target);

};