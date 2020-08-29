#pragma once

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace bst { class Data; }

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
namespace bst
{

	/**
	 *
	 * @author Hamza
	 */
	class node
	{
	public:
		Data *data;
		node *right, *left;
		virtual ~node()
		{
			delete data;
			delete right;
			delete left;
		}

		node(Data *x);
	};
	class Data
	{
	public:
		int start_time;
		int duration;
		int ctime;
		int total_time;
		Data(int start_time, int duration, int ctime);
	};

}
