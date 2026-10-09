#pragma once

#include"meal.h"
#include"timer.h"
#include"region.h"

#include<vector>

class DeliveryDriver : public Region
{
public:
	DeliveryDriver(int x, int y);
	~DeliveryDriver() = default;

	void on_cursor_up() override;
	void on_update(float delta) override;
	void on_render(SDL_Renderer* renderer) override;

private:
	enum class Status
	{
		Waiting,
		Completed
	};

private:
	Timer timer_refresh;
	float time_waited = 0;
	bool is_waiting = false;
	bool is_meituan = false; //是否为美团外卖员
	std::vector<Meal> meal_list;
	std::vector<Status> status_list;
	int num_drink = 0, num_dish = 0;
	const float time_waited_limit = 40; //♥心动值♥上限

private:
	void refresh();
	bool check_and_place(Meal target);

};