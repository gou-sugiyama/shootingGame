#pragma once
typedef struct  Location
{
	float x;
	float y;

	Location operator +(Location location)
	{
		Location w;
		w.x = this->x + location.x;
		w.y = this->y + location.y;
		return w;
	}

	Location operator -(Location location)
	{
		Location w;
		w.x = this->x - location.x;
		w.y = this->y - location.y;
		return w;
	}


	bool operator !=(Location location)
	{
		bool ret = true;
		//どちらか一つでも等しければfalseを返す
		ret = (!(this->x == location.x) || !(this->y == location.y));
	  

		return ret;
	}


}Location;

