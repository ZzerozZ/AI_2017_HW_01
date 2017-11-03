#include "processing.h"

/*
Hàm lấy giao điểm hai đường thẳng
- Trả về một điểm là giao điểm
- Nếu hai đường thẳng song song trả về Point(-1, 0)
- Nếu hai đường thẳng trùng nhau trả về (-1, -1)
*/
Point get_intersection(Equation e1, Equation e2)
{
	// Trường hợp vô nghiệm và vô số nghiệm đều có e1.a=e2.a nên chỉ cần điều
	// kiện đó là đủ
	
	if (e1.a == e2.a)
	{
		if (e1.b == e1.b)
		{
			return Point(-1, -1);
		}
	}
	else if ((e1.a * e2.b) == (e1.b * e2.a))
	{
		return Point(-1, 0);
	}
	else if (e1.a == -100001)
	{
		return Point(e1.b, e2.a * e1.b + e2.b);
	}
	else if (e2.a == -100001)
	{
		return Point(e2.b, e1.a * e2.b + e1.b);
	}
	else
	{
		return Point((int)(e2.b - e1.b) / (e1.a - e2.a), (int)(e1.a * e2.b - e1.b * e2.a) / (e1.a - e2.a));
	}
}


/*
Hàm đếm số lần "đụng tường" nếu đi thẳng từ A đến B
- wall_list lấy từ Map().wall_list
- Trả về số lượng giao điểm
*/
int count_intersection(Point A, Point B, vector<Line> wall_list)
{
	Line lin(A, B);
	Equation eq = lin.get_equation();
	int count = 0;
	Point ptemp(0, 0);

	//count
	for (int i = 0; i < wall_list.size(); i++)
	{
		
		ptemp = get_intersection(eq, wall_list[i].get_equation());
		if (ptemp.x != -1)
		{
			count++;
			//cout << ptemp.x << ' ' << ptemp.y << endl;
		}
	}
	return count;
}


/*
Hàm tính khoảng cách hai điểm
*/
int distance_of(Point A, Point B)
{
	return (int)sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}


/*
Xác định điểm chặn của đường đi
- Trả về tối đa 2 điểm nằm ở 2 chiều di chuyển từ điểm A
- Nếu điểm tìm được có khoảng cách đến A nhỏ hơn 10 thì loại bỏ(xem như trùng với A)
-
*/
vector<Point> get_intersection_point(Point A, Equation e)
{
	return vector<Point>();
}


/*
Tạo ra 2 phương trình đường chéo đi qua điểm A
- Trả về một danh sách Equation
- Không trả về đường vừa đi để đến A
- Tham số last_move lưu đường vừa đi dạng enum LastMove(gồm: horizontal, vertical, left_crossover, right_crossover)
*/
vector<Equation> get_equation_list(Point A, LastMove last_move)
{
	vector<Equation> return_list;
	//Đường chéo chính:
	if(last_move != LastMove::left_crossover)
		return_list.push_back(Equation(1, A.y - A.x));
	//Đường chéo phụ:
	if (last_move != LastMove::right_crossover)
		return_list.push_back(Equation(-1, A.x - A.y));

	return return_list;
}


/*
Tìm tất cả điểm chặn hợp lệ trên 3(hoặc 4) đường thẳng từ điểm A
*/
vector<Point> get_all_next_point_from(Point A)
{
	return vector<Point>();
}


/*
Tìm điểm kế tiếp trên đường đi đến đích
- Nếu từ A có thể đi thẳng đến G thì thực hiện di chuyển A->G
- Nếu không trả về điểm tiếp theo sẽ đến
*/
Point next_point(Point A, LastMove last_move)
{
	return Point(0, 0);
}


/*
Tìm đường đi từ Start đến Goal
- Trả về danh sách các điểm đến
*/
vector<Point> find_the_way(Map map)
{
	return vector<Point>();
}
