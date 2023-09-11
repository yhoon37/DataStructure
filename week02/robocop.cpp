#include <iostream>
#include <vector>

class point{
public:
    point(int x, int y): x(x), y(y) {}
    int x;
    int y;
//    bool operator == (point other) {
//        if(x == other.x && y == other.y) {
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    void move_right(){x++;}
//    void move_left(){x--;}
//    void move_up(){y++;}
//    void move_down(){y--;}
};

std::ostream& operator << (std::ostream& os, const point p){
    os << p.x << " " << p.y;
    return os;
}

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<point> points;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        points.push_back(point(x,y));
    }
    //다를때만 추가하는거 넣을까 말까
    points.push_back(points[0]);

    int total_distance = 0;
    for(int i=0; i<k; i++){
        total_distance += abs(points[i].x - points[i+1].x) + abs(points[i].y - points[i+1].y);
    }

    int times[5];
    cin >> times[0] >> times[1] >> times[2] >> times[3] >> times[4];
    for(int i=0; i<5; i++) {
        times[i] = times[i]%total_distance;
    }

    for(auto& time : times) {
        int index = 0;
        point result = points[0];//default constructor

        while(time>0) {
            point p1 = points[index];
            point p2 = points[index+1];
            if(p1.x == p2.x) {
                if(p1.y < p2.y) {
                    result.y++;
                    //result.move_up();
                }
                else{
                    result.y--;
                    //result.move_down();
                }
            }
            else{
                if(p1.x < p2.x) {
                    result.x++;
                    //result.move_right();
                }
                else{
                    result.x--;
                    //result.move_left();
                }
            }
            if(result.x == p2.x && result.y == p2.y) {//result == p2
                index++;
            }
            time--;
        }
        cout << result << endl;
    }
}
