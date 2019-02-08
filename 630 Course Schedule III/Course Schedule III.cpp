class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort( courses.begin(), courses.end(), []( vector<int>& a, vector<int>& b ) {
            return a[ 1 ] < b[ 1 ];
        } );
        priority_queue<int> taken;
        int current = 0;
        for ( vector<int>& course : courses ) {
            if ( current + course[ 0 ] <= course[ 1 ] ) {
                taken.push(  course[ 0 ] );
                current += course[ 0 ];
            } else if ( taken.size() && course[ 0 ] < taken.top() ) {
                current = current - taken.top() + course[ 0 ];
                taken.pop();
                taken.push( course[ 0 ] );
            }
        }
        return taken.size();
    }
};