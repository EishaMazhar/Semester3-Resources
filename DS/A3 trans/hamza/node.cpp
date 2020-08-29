#include "node.h"

namespace bst
{

	node::node(Data *x)
	{
		this->data = x;
		this->right = nullptr;
		this->left = nullptr;
	}

	Data::Data(int start_time, int duration, int ctime)
	{
		this->start_time = start_time;
		this->duration = duration;
		this->ctime = ctime;
		this->total_time = start_time + duration + ctime;
	}
}
