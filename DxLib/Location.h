#pragma once
typedef struct  Location
{
	float x;
	float y;

	Location operator +(Location location)
	{
		x += location.x;
		y += location.y;
		return *this;
	}

	Location operator -(Location location)
	{
		x -= location.x;
		y -= location.y;
		return *this;
	}
}Location;

