#pragma once
#include <ostream>
#include <vector>

static int get_nearest_two_power(int);

namespace adt {
	class segment_tree {
	private:
		int arr_size;
		std::vector<int> arr;
		std::vector<int> tree;
		void build(int, int, int);
		void update_helper(int, int, int, int, int);
		int query_helper(int, int, int, int, int);
	public:
		segment_tree(std::vector<int>);
		void update(int, int);
		int query(int, int);
		void print();
	};
}
