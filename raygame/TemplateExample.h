#pragma once
template<typename D>
class Hero {
public:
	Hero(D val);
	D getHealth();

private:
	D health;
};

template<typename D>
Hero<D>::Hero(D val)
{
	health = val;
}

template<typename D>
D Hero<D>::getHealth()
{
	return D();
}

