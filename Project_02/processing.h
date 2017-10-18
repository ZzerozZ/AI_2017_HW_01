#pragma once
#include "file_processing.h"

/*
Hàm lấy giao điểm hai đường thẳng
- Trả về một điểm là giao điểm
- Nếu hai đường thẳng song song trả về Point(-1, 0)
- Nếu hai đường thẳng trùng nhau trả về (-1, -1)
*/
Point get_intersection(Equation e1, Equation e2);

/*
Hàm đếm số lần "đụng tường" nếu đi thẳng từ A đến B
- wall_list lấy từ Map().wall_list
- Trả về số lượng giao điểm
*/
int count_intersection(Point A, Point B, vector<Line> wall_list);

/*
Hàm tính khoảng cách hai điểm
*/
int distance_of(Point A, Point B);

/*
Xác định điểm chặn của đường đi
- Trả về tối đa 2 điểm nằm ở 2 chiều di chuyển từ điểm A
- Nếu điểm tìm được có khoảng cách đến A nhỏ hơn 10 thì loại bỏ(xem như trùng với A)
-
*/
vector<Point> get_intersection_point(Point A, Equation e);


/*
Tạo ra 3 hoặc 4 phương trình đường thẳng đi qua điểm A
- Trả về một danh sách Equation
- Không trả về đường vừa đi để đến A
- Tham số last_move lưu đường vừa đi dạng enum LastMove(gồm: horizontal, vertical, left_crossover, right_crossover)
*/
vector<Equation> get_equation_list(Point A, LastMove last_move);


/*
Tìm tất cả điểm chặn hợp lệ trên 3(hoặc 4) đường thẳng từ điểm A
*/
vector<Point> get_all_next_point_from(Point A);


/*
Tìm điểm kế tiếp trên đường đi đến đích
- Nếu từ A có thể đi thẳng đến G thì thực hiện di chuyển A->G
- Nếu không trả về điểm tiếp theo sẽ đến
*/
Point next_point(Point A);


/*
Tìm đường đi từ Start đến Goal
- Trả về danh sách các điểm đến
*/
vector<Point> find_the_way(Map map);
