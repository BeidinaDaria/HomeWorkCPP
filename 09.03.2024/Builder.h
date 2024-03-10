#pragma once

class House {
	friend class HouseBuilder;
	int windows = 0, doors = 0, rooms = 0, garages = 0, 
		swimpools = 0, statues = 0, gardensquare = 0;
public:
	void show();
};

class Builder{
public:
	virtual void buildWindows(int k) = 0;
	virtual void buildDoors(int k) = 0;
	virtual void buildRooms(int k) = 0;
	virtual void buildGarages(int k) = 0;
	virtual void buildSwimPools(int k) = 0;
	virtual void buildGarden(int k) = 0;
	virtual void buildStatues(int k) = 0;
};

class HouseBuilder:public Builder {
	House home=House();
public:
	void buildWindows(int k){
		home.windows = k;
	}
	void buildDoors(int k) {
		home.doors = k;
	}
	void buildRooms(int k) {
		home.rooms = k;
	}
	void buildGarages(int k) {
		home.garages = k;
	}
	void buildSwimPools(int k) {
		home.swimpools = k;
	}
	void buildGarden(int k) {
		home.gardensquare = k;
	}
	void buildStatues(int k) {
		home.statues = k;
	}
	House result() { return home; }
};